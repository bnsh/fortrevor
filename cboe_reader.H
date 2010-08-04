#ifndef CBOE_READER_H
#define CBOE_READER_H

/*
 * What defines an quote, forgetting about black scholes stuff?
 * an quote has a symbol
 * an quote is a call or a put,
 * an quote has a strike price,
 * an quote has an expiration
 * an quote has a bid,
 * an quote has an ask
 * an quote belongs to an exchange.
 */
class cboe_option_quote {
	public:
		cboe_option_quote() :
			_quote_time(0),
			_underlying_symbol(NULL),
			_option_symbol(NULL),
			_type(0),
			_strike(0.0),
			_underlying_bid(0.0),
			_underlying_ask(0.0),
			_expiration(0),
			_bid(0.0),
			_ask(0.0) { }
		cboe_option_quote(time_t qt, const char *us,const char *sym, int tp, double str, double ub, double ua,time_t exprtn, double bi, double as) :
			_quote_time(qt),
			_underlying_symbol(NULL),
			_option_symbol(NULL),
			_type(tp),
			_strike(str),
			_underlying_bid(ub),
			_underlying_ask(ua),
			_expiration(exprtn),
			_bid(bi),
			_ask(as) { _underlying_symbol = strdup(us); _option_symbol = strdup(sym); }
		~cboe_option_quote();
		cboe_option_quote(const cboe_option_quote&);
		cboe_option_quote& operator=(const cboe_option_quote&);

		time_t quote_time() const { return(_quote_time); }
		const char *underlying_symbol() const { return(_underlying_symbol); }
		const char *option_symbol() const { return(_option_symbol); }
		int type() const { return(_type); }
		double strike() const { return(_strike); }
		double underlying_current() const { return((_underlying_bid+_underlying_ask)/2.0); }
		double underlying_bid() const { return(_underlying_bid); }
		double underlying_ask() const { return(_underlying_ask); }
		time_t expiration() const { return(_expiration); }
		double bid() const { return(_bid); }
		double ask() const { return(_ask); }

		cboe_option_quote& quote_time(time_t v) { _quote_time = v; return((*this)); }
		cboe_option_quote& underlying_symbol(const char *sym) { if (_underlying_symbol) free(_underlying_symbol); _underlying_symbol = strdup(sym); return((*this)); }
		cboe_option_quote& underlying_bid(double v) { _underlying_bid = v; return((*this)); }
		cboe_option_quote& underlying_ask(double v) { _underlying_ask = v; return((*this)); }
		cboe_option_quote& option_symbol(const char *sym) { if (_option_symbol) free(_option_symbol); _option_symbol = strdup(sym); return((*this)); }
		cboe_option_quote& type(int v) { _type = v; return((*this)); }
		cboe_option_quote& strike(double v) { _strike = v; return((*this)); }
		cboe_option_quote& expiration(time_t v) { _expiration = v; return((*this)); }
		cboe_option_quote& bid(double v) { _bid = v; return((*this)); }
		cboe_option_quote& ask(double v) { _ask = v; return((*this)); }
		int operator==(const cboe_option_quote& c) const;
	private:
		time_t _quote_time;
		char *_underlying_symbol;
		char *_option_symbol;
		int _type;
		double _strike;
		double _underlying_bid;
		double _underlying_ask;
		time_t _expiration;
		double _bid;
		double _ask;

};

class cboe_reader {
	public:
		cboe_reader() :
			_filename(NULL),
			_underlying_symbol(NULL),
			_num_options(0),
			_allocated(0),
			_options(NULL) { }
		~cboe_reader();

		void read_file(const char *fn);

		const char *filename() const { return(_filename); }
		const char *underlying_symbol() const { return(_underlying_symbol); }
		double underlying_current() const { return((_underlying_bid+_underlying_ask)/2.0); }
		double underlying_bid() const { return(_underlying_bid); }
		double underlying_ask() const { return(_underlying_ask); }
		time_t quote_time() const { return(_quote_time); }
		int num_options() const { return(_num_options); }
		cboe_option_quote *options() const { return(_options); }
		int num_expirations() const { return(_num_expirations); }
		const time_t *expirations() const { return(_expirations); }
		const cboe_option_quote *find(const cboe_option_quote& c) const;
		const cboe_option_quote *find(const char *c) const;
	protected:
		void compute_expirations_cache();
		void process_line(char buffer[],int& line_no);
		void read_text(const char *fn);
		void read_bz2(const char *fn);
		void reallocate(int);

		char *_filename;
		char *_underlying_symbol;
		double _underlying_bid;
		double _underlying_ask;
		time_t _quote_time;

		int _num_options;
		int _allocated;
		cboe_option_quote *_options;
		int _num_expirations;
		time_t _expirations[1024]; 

		cboe_reader(const cboe_reader&);
		cboe_reader& operator=(const cboe_reader&);
};

#endif
