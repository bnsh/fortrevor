#ifndef BSMODEL_H
#define BSMODEL_H

class bsmodel : public function {
	public:
		bsmodel(const cboe_option_quote& coq, int num_params);
		virtual ~bsmodel();

// derivative(2,coq,params) will take the derivative of the call with respect to parameter 2
// (0 based, of course, so the _third_ parameter.)

// value(coq, params) will return the price as expected by the model.
		virtual double value(const double params[]) = 0;
		virtual double operator()(const double params[]);

// Time to expiration in years.
		virtual double time_to_expiration() const;

		virtual double current() const;
		virtual time_t quote_time() const;
		virtual double actual_price() const;
		virtual time_t expiration() const;
		virtual const char *option_symbol() const;
		virtual const char *underlying_symbol() const;
		virtual double strike() const;
		virtual int type() const;

		bsmodel& current(double c) { _current = c; return((*this)); }
		bsmodel& quote_time(time_t t) { _quote_time = t; return((*this)); }
		const cboe_option_quote& quote() const { return(_cboe_option_quote); }

		virtual double blackgamma(const double params[]) const = 0;
		virtual double blackdelta(const double params[]) const = 0;
		virtual double blackvega(const double params[]) const = 0;
		virtual double blackrho(const double params[]) const = 0;
		virtual double blacktheta(const double params[]) const = 0;

		virtual double gamma(const double params[]) const = 0;
		virtual double delta(const double params[]) const = 0;
		virtual double vega(const double params[]) const = 0;
		virtual double rho(const double params[]) const = 0;
		virtual double theta(const double params[]) const = 0;

		double implied_volatility(const double params[]);
	protected:
		double _current;
		time_t _quote_time;
		char *_underlying_symbol; // underlying symbol
		char *_option_symbol; // option symbol
		double _actual_price;
		cboe_option_quote _cboe_option_quote;	// This will be a _copy_ of what was
							// given to us in constructor.
	private:
		bsmodel(const bsmodel&);
		bsmodel& operator=(const bsmodel&);
};

#endif
