#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cboe_reader.H"
#include "levenberg_marquardt.H"
#include "bsmodel.H"

bsmodel::bsmodel(const cboe_option_quote& coq, int num_params) :
	function(num_params),
	_current(0.0),
	_quote_time(0),
	_underlying_symbol(NULL),
	_option_symbol(NULL),
	_cboe_option_quote(coq) {
	_current = coq.underlying_current();
	_quote_time = coq.quote_time();
	_underlying_symbol = strdup(coq.underlying_symbol());
	_option_symbol = strdup(coq.option_symbol());
	_actual_price = (coq.bid() + coq.ask()) / 2.0;
}

bsmodel::~bsmodel() {
	if (_underlying_symbol) free(_underlying_symbol); _underlying_symbol = NULL;
	if (_option_symbol) free(_option_symbol); _option_symbol = NULL;
	_current = 0.0;
	_quote_time = 0;
}

double bsmodel::time_to_expiration() const {
	double left = ((expiration() - _quote_time) / (365.25*86400.0));
	return(left);
}

double bsmodel::current() const { return(_current); }
double bsmodel::actual_price() const { return(_actual_price); }
time_t bsmodel::quote_time() const { return(_quote_time); }
const char *bsmodel::option_symbol() const { return(_option_symbol); }
const char *bsmodel::underlying_symbol() const { return(_underlying_symbol); }

double bsmodel::strike() const { return(_cboe_option_quote.strike()); }
int bsmodel::type() const { return(_cboe_option_quote.type()); }
time_t bsmodel::expiration() const { return(_cboe_option_quote.expiration()); }

double bsmodel::operator()(const double params[]) {
	double retVal = value(params) - _actual_price;
	return(retVal);
}

double bsmodel::implied_volatility(const double params[]) {
	double cparams[_number_of_parameters];
	for (int i = 0; i < _number_of_parameters; ++i) cparams[i] = params[i];
	double start_volatility = cparams[0];
	double lo_volatility = 0.0;
	double hi_volatility = start_volatility;
	cparams[0] = hi_volatility;

	do {
		hi_volatility = cparams[0] = 2*cparams[0];
	} while (value(cparams) < _actual_price);

	for (unsigned int i = 0; i < sizeof(double)*8; ++i) {
		double mid_volatility = (lo_volatility + (hi_volatility - lo_volatility) / 2.0);
		cparams[0] = mid_volatility;
		if (value(cparams) < _actual_price) lo_volatility = cparams[0];
		else hi_volatility = cparams[0];
	}
	return(cparams[0]);
}
