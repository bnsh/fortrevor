#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "cboe_reader.H"
#include "time2str.H"

static time_t next_expiration_friday(time_t t) {
	static time_t last_input = -1;
	static time_t last_retVal = -1;
	if (last_input == t) return(last_retVal);
	else {
/*
 * So, Hopefully, this one's _day_ of the month is 1. We want 17:30 on the third friday after
 * we hit day 1.
 */
		last_input = t;
		char buffer[1024];
		strftime(buffer,1024,"%d",localtime(&t));
		int day = atoi(buffer);

		while (day != 1) {
			t += 3600;
			strftime(buffer,1024,"%d",localtime(&t));
			day = atoi(buffer);
		}
		strftime(buffer,1024,"%a",localtime(&t));
		while (strcmp(buffer,"Fri") != 0) {
			t += 3600;
			strftime(buffer,1024,"%a",localtime(&t));
		}
/* That's the _first_ friday. The third, should be 2 weeks from then. */
		t += 14 * 86400;
		struct tm *ts = localtime(&t);
		ts->tm_hour = 17;
		ts->tm_min = 30;
		t = mktime(ts);
		strftime(buffer,1024,"%a",localtime(&t));
		assert(0 == strcmp(buffer,"Fri"));
		last_retVal = t;
		return(t);
	}
}

static time_t parse_symbol_for_expiration(const char *sym, double strike_p, int year_p, int month_p) {
// So, first situate ourselves with the last expiration month code.
	int month = -1;
	const char *month_code;
	const char *p;
	for (p = sym; ((*p)); ++p) if (('A' <= (*p)) && ((*p) <= 'X')) month_code = p;
	     if ((*month_code) == 'A') month =  0; // January
	else if ((*month_code) == 'B') month =  1; // February
	else if ((*month_code) == 'C') month =  2; // March
	else if ((*month_code) == 'D') month =  3; // April
	else if ((*month_code) == 'E') month =  4; // May
	else if ((*month_code) == 'F') month =  5; // June
	else if ((*month_code) == 'G') month =  6; // July
	else if ((*month_code) == 'H') month =  7; // August
	else if ((*month_code) == 'I') month =  8; // September
	else if ((*month_code) == 'J') month =  9; // October
	else if ((*month_code) == 'K') month = 10; // November
	else if ((*month_code) == 'L') month = 11; // December
	else if ((*month_code) == 'M') month =  0; // January
	else if ((*month_code) == 'N') month =  1; // February
	else if ((*month_code) == 'O') month =  2; // March
	else if ((*month_code) == 'P') month =  3; // April
	else if ((*month_code) == 'Q') month =  4; // May
	else if ((*month_code) == 'R') month =  5; // June
	else if ((*month_code) == 'S') month =  6; // July
	else if ((*month_code) == 'T') month =  7; // August
	else if ((*month_code) == 'U') month =  8; // September
	else if ((*month_code) == 'V') month =  9; // October
	else if ((*month_code) == 'W') month = 10; // November
	else if ((*month_code) == 'X') month = 11; // December

	p = month_code+1;
	double strike = atof(p);

	p = month_code-4;
	char yrstr[3], dystr[3];
	strncpy(yrstr,p  ,2); yrstr[2] = 0;
	strncpy(dystr,p+2,2); dystr[2] = 0;
	int year = 2000 + atoi(yrstr);
	int day = atoi(dystr);
	time_t retVal = -1;

	if ((month == month_p) && (year == year_p) && (strike == strike_p)) {
		struct tm T;
		memset(&T,'\0',sizeof(struct tm)); T.tm_isdst = -1; // Time zone insanity.
		T.tm_year = year - 1900;
		T.tm_mon = month;
		T.tm_mday = day;
		T.tm_hour = 17;
		T.tm_min = 30;
		retVal = mktime(&T);
	}
	return(retVal);
}

static const char *parse_option(const char *raw, time_t& exp, double& strike, char sym[],char exchange[]) {
	struct tm T;
	char *scratch = NULL;

	memset(&T,'\0',sizeof(struct tm)); T.tm_isdst = -1; // Time zone insanity.
	char *rest = strptime(raw,"%y %b",&T);
	if ((rest) && (rest > raw)) {
		char *sstrike = strtok_r(rest, "()", &scratch);
		char *symbol = strtok_r(NULL,"()",&scratch);
		rest = strtok_r(NULL,"()",&scratch);
		const char *S = strtok_r(symbol,"-",&scratch);
		if (S) strcpy(sym,S);
		else sym[0] = '\0';
		const char *e = strtok_r(NULL,"-",&scratch);
		if (e) strcpy(exchange,e);
		else exchange[0] = '\0';
		strike = atof(sstrike);
		time_t expd = parse_symbol_for_expiration(sym, strike, 1900+T.tm_year, T.tm_mon);
		time_t expf = next_expiration_friday(mktime(&T));
		if (expd != -1) exp = expd;
		else expd = expf;
	}
	else rest = NULL;
	return(rest);
}

int cboe_option_quote::operator==(const cboe_option_quote& c) const {
	int retVal = 0;
	if (
		(
			((_option_symbol == NULL) && (c._option_symbol == NULL)) ||
			((_option_symbol != NULL) && (c._option_symbol != NULL) && (0 == strcmp(c._option_symbol,_option_symbol)))
		) &&
		(
			((_underlying_symbol == NULL) && (c._underlying_symbol == NULL)) ||
			((_underlying_symbol != NULL) && (c._underlying_symbol != NULL) && (0 == strcmp(c._underlying_symbol,_underlying_symbol)))
		) &&
		(_type == c._type) &&
		(_strike == c._strike) &&
		(_expiration == c._expiration)
	) retVal = 1;
	return(retVal);
}

cboe_reader::~cboe_reader() {
	if (_filename) free(_filename); _filename = NULL;
	if (_underlying_symbol) free(_underlying_symbol); _underlying_symbol = NULL;
	if (_options) delete[] _options; _options = NULL;
}

void cboe_reader::reallocate(int n) {
	cboe_option_quote *newly_allocated = new cboe_option_quote[n];
	if (_options) {
		for (int i = 0; i < _num_options; ++i) newly_allocated[i] = _options[i];
		delete[] _options; _options = NULL;
	}
	_options = newly_allocated;
	_allocated = n;
}

void cboe_reader::process_line(char parambuffer[],int& line_no) {
	char *scratch = NULL;
	line_no++;
	strtok_r(parambuffer,"\r\n",&scratch);
	if (line_no == 1) {
		const char *sym = strtok_r(parambuffer,",",&scratch);
		if (_underlying_symbol) free(_underlying_symbol); _underlying_symbol = NULL;
		_underlying_symbol = strdup(sym);
	}
	else if (line_no == 2) {
		char *tm = strtok_r(parambuffer,",",&scratch);
		strtok_r(NULL,",",&scratch); // Skip Text "Bid"
		const char *bidprice = strtok_r(NULL,",",&scratch);
		strtok_r(NULL,",",&scratch); // Skip Text "Ask"
		const char *askprice = strtok_r(NULL,",",&scratch);
		struct tm T;

		memset(&T,'\0',sizeof(struct tm)); T.tm_isdst = -1; // Time zone insanity.
		strptime(tm,"%b %d %Y @ %H:%M",&T);
		_quote_time = mktime(&T);
		_underlying_bid = atof(bidprice);
		_underlying_ask = atof(askprice);
	}
	else if (line_no == 3) { /* Eat this comment */ }
	else {
		char *callopt = strtok_r(parambuffer,",",&scratch); if (callopt) {
			char *calllast = strtok_r(NULL,",",&scratch); if (calllast) { /* compiler bliss */ }
			char *callnet = strtok_r(NULL,",",&scratch); if (callnet) { /* compiler bliss */ }
			char *callbid = strtok_r(NULL,",",&scratch); if (callbid) { /* compiler bliss */ }
			char *callask = strtok_r(NULL,",",&scratch); if (callask) { /* compiler bliss */ }
			char *callvol = strtok_r(NULL,",",&scratch); if (callvol) { /* compiler bliss */ }
			char *calloi = strtok_r(NULL,",",&scratch); if (calloi) { /* compiler bliss */ }

			char *putopt = strtok_r(NULL,",",&scratch); if (putopt) {
				char *putlast = strtok_r(NULL,",",&scratch); if (putlast) { /* compiler bliss */ }
				char *putnet = strtok_r(NULL,",",&scratch); if (putnet) { /* compiler bliss */ }
				char *putbid = strtok_r(NULL,",",&scratch); if (putbid) { /* compiler bliss */ }
				char *putask = strtok_r(NULL,",",&scratch); if (putask) { /* compiler bliss */ }
				char *putvol = strtok_r(NULL,",",&scratch); if (putvol) { /* compiler bliss */ }
				char *putoi = strtok_r(NULL,",",&scratch); if (putoi) { /* compiler bliss */ }
		/* We're only really interested in opt, bid and ask. */
				char buffer[1024];
				time_t call_expiration = 0;
				double call_strike = 0.0;
				double call_bid = atof(callbid);
				double call_ask = atof(callask);
				char call_symbol[1024];
				char call_exchange[1024];
				memset(call_symbol,'\0',sizeof(call_symbol));
				memset(call_exchange,'\0',sizeof(call_exchange));
				parse_option(callopt, call_expiration, call_strike, call_symbol, call_exchange);
				strftime(buffer,1024,"%Y-%m-%d %H:%M:%S",localtime(&call_expiration));
				if ((call_exchange[0] == '\0') && (call_ask >= call_bid) && ((call_ask > 0.0) || (call_bid > 0.0)) && ((0 != strncmp(call_symbol,"UDL",3)) && (0 != strncmp(call_symbol,"OOF",3)) && (0 != strncmp(call_symbol,"UQQ",3))) && (call_expiration > _quote_time)) {
					int found = -1;
					for (int i = 0; (i < _num_options) && (found < 0); ++i) {
						cboe_option_quote& coq = _options[i];
						if (0 == strcmp(coq.option_symbol(),call_symbol)) found=i;
					}
					if (found < 0) {
						if ((_num_options+1) > _allocated - 10) reallocate((_num_options+1) * 2);
						_options[_num_options++]
							.quote_time(_quote_time)
							.underlying_symbol(_underlying_symbol)
							.underlying_bid(_underlying_bid)
							.underlying_ask(_underlying_ask)
							.option_symbol(call_symbol)
							.type(1)
							.strike(call_strike)
							.expiration(call_expiration)
							.bid(call_bid)
							.ask(call_ask);
					}
					else {
						fprintf(stderr,"%s: %d: %s Dropping option %s (Duplicate)\n",__FILE__,__LINE__,_filename, call_symbol);
						cboe_option_quote& coq = _options[found];
						int errs = 0;

						if (coq.strike() != call_strike) { fprintf(stderr,"%s: %d: Found duplicate %s with differing strikes.\n",__FILE__,__LINE__,call_symbol); errs++; }
						if (coq.expiration() != call_expiration) { fprintf(stderr,"%s: %d: Found duplicate %s with differing expirations.\n",__FILE__,__LINE__,call_symbol); errs++; }
						if (coq.bid() != call_bid) { fprintf(stderr,"%s: %d: Found duplicate %s with differing bids.\n",__FILE__,__LINE__,call_symbol); errs++; }
						if (coq.ask() != call_ask) { fprintf(stderr,"%s: %d: Found duplicate %s with differing asks.\n",__FILE__,__LINE__,call_symbol); errs++; }

						assert(
							(coq.strike() == call_strike) &&
							(coq.expiration() == call_expiration) &&
							(coq.bid() == call_bid) &&
							(coq.ask() == call_ask)
						);
					}

				}

				time_t put_expiration = 0;
				double put_strike = 0.0;
				double put_bid = atof(putbid);
				double put_ask = atof(putask);
				char put_symbol[1024];
				char put_exchange[1024];
				memset(put_symbol,'\0',sizeof(put_symbol));
				memset(put_exchange,'\0',sizeof(put_exchange));
				parse_option(putopt, put_expiration, put_strike, put_symbol, put_exchange);
				strftime(buffer,1024,"%Y-%m-%d %H:%M:%S",localtime(&put_expiration));
				if ((put_exchange[0] == '\0') && (put_ask >= put_bid) && ((put_ask > 0.0) || (put_bid > 0.0)) && ((0 != strncmp(put_symbol,"UDL",3)) && (0 != strncmp(put_symbol,"OOF",3)) && (0 != strncmp(put_symbol,"UQQ",3))) && (put_expiration > _quote_time)) {
					int found = -1;
					for (int i = 0; (i < _num_options) && (found < 0); ++i) {
						cboe_option_quote& coq = _options[i];
						if (0 == strcmp(coq.option_symbol(),put_symbol)) found=i;
					}
					if (found < 0) {
						if ((_num_options+1) > _allocated - 10) reallocate((_num_options+1) * 2);
						_options[_num_options++]
							.quote_time(_quote_time)
							.underlying_symbol(_underlying_symbol)
							.underlying_bid(_underlying_bid)
							.underlying_ask(_underlying_ask)
							.option_symbol(put_symbol)
							.type(-1)
							.strike(put_strike)
							.expiration(put_expiration)
							.bid(put_bid)
							.ask(put_ask);
					}
					else {
						fprintf(stderr,"%s: %d: %s Dropping option %s (Duplicate)\n",__FILE__,__LINE__,_filename, put_symbol);
						cboe_option_quote& coq = _options[found];
						int errs = 0;

						if (coq.strike() != put_strike) { fprintf(stderr,"%s: %d: Found duplicate %s with differing strikes.\n",__FILE__,__LINE__,put_symbol); errs++; }
						if (coq.expiration() != put_expiration) { fprintf(stderr,"%s: %d: Found duplicate %s with differing expirations.\n",__FILE__,__LINE__,put_symbol); errs++; }
						if (coq.bid() != put_bid) { fprintf(stderr,"%s: %d: Found duplicate %s with differing bids.\n",__FILE__,__LINE__,put_symbol); errs++; }
						if (coq.ask() != put_ask) { fprintf(stderr,"%s: %d: Found duplicate %s with differing asks.\n",__FILE__,__LINE__,put_symbol); errs++; }

						assert(
							(coq.strike() == put_strike) &&
							(coq.expiration() == put_expiration) &&
							(coq.bid() == put_bid) &&
							(coq.ask() == put_ask)
						);
					}
				}
			}
		}
	}
}

void cboe_reader::read_file(const char *fn) {
	_filename = strdup(fn);
	read_text(fn);
	compute_expirations_cache(); // Overkill. But, hopefully not to expensive.
}

void cboe_reader::read_text(const char *fn) {
	FILE *fp = fopen(fn,"r");
	if (fp) {
		char buffer[1024];
		int line_no = 0;
		while (NULL != fgets(buffer, 1024, fp)) {
			process_line(buffer,line_no);
		}
		fclose(fp); fp = NULL;
	}
	else fprintf(stderr,"%s: %d: Can't open file %s\n",__FILE__,__LINE__,fn);
	compute_expirations_cache();
}

cboe_option_quote::~cboe_option_quote() {
	if (_underlying_symbol) free(_underlying_symbol); _underlying_symbol = NULL;
	if (_option_symbol) free(_option_symbol); _option_symbol = NULL;
}

cboe_option_quote::cboe_option_quote(const cboe_option_quote& coq) :
	_underlying_symbol(NULL),
	_option_symbol(NULL) {
	quote_time(coq.quote_time())
		.underlying_symbol(coq.underlying_symbol())
		.option_symbol(coq.option_symbol())
		.type(coq.type())
		.strike(coq.strike())
		.underlying_bid(coq.underlying_bid())
		.underlying_ask(coq.underlying_ask())
		.expiration(coq.expiration())
		.bid(coq.bid())
		.ask(coq.ask())
	;
}

cboe_option_quote& cboe_option_quote::operator=(const cboe_option_quote& coq) {
	if (&coq != this) {
		quote_time(coq.quote_time())
		.underlying_symbol(coq.underlying_symbol())
		.underlying_bid(coq.underlying_bid())
		.underlying_ask(coq.underlying_ask())
		.option_symbol(coq.option_symbol())
		.type(coq.type())
		.strike(coq.strike())
		.expiration(coq.expiration())
		.bid(coq.bid())
		.ask(coq.ask())
		;
	}
	return((*this));
}

const cboe_option_quote *cboe_reader::find(const cboe_option_quote& c) const {
	const cboe_option_quote *retVal = NULL;

	for (int i = 0; i < _num_options; ++i) {
		if (_options[i] == c) retVal = &_options[i];
	}

	return(retVal);
}

const cboe_option_quote *cboe_reader::find(const char *c) const {
	const cboe_option_quote *retVal = NULL;

	for (int i = 0; i < _num_options; ++i) {
		if (strcmp(c,_options[i].option_symbol()) == 0) retVal = &_options[i];
	}

	return(retVal);
}

void cboe_reader::compute_expirations_cache() {
	_num_expirations = 0;
	for (int i = 0; i < num_options(); ++i) {
		{
			time_t s = _options[i].expiration();
			time_t found = 0;
			int insert_after = -1;
			int lo = 0;
			int hi = _num_expirations;

			while ((lo < hi) && (!found)) {
				int pivot = lo + (hi-lo)/2;
				int cmp = _expirations[pivot]-s;
				if (cmp == 0) {
					found = _expirations[pivot];
					insert_after = -1;
				}
				else if (cmp > 0) {
					hi = pivot;
				}
				else if (cmp < 0) {
					insert_after = pivot;
					lo = pivot+1;
				}
			}

			if (found == 0) {
				_num_expirations++;
				for (int j = (_num_expirations-1); (j-1) > insert_after; --j) {
					_expirations[j] = _expirations[j-1];
				}
				_expirations[insert_after+1] = s;
			}
		}
	}
}
