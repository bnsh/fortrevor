#ifndef JACKWERTH_H
#define JACKWERTH_H

class jackwerth {
	public:
		jackwerth();
		virtual ~jackwerth();

		jackwerth& risk_free_rate(double r) { _r = r; return((*this)); }
		jackwerth& dividend_yield(double q) { _q = q; return((*this)); }
		jackwerth& underlying_current(double S) { _S = S; return((*this)); }
		jackwerth& expiration(double t) { _t = t; return((*this)); }

		jackwerth& option(double strike, double implied_volatility);
		histogram *compute_histogram(double lo, double hi, double increment);
	private:
		void reallocate_observed(int n);

		double _r;
		double _q;
		double _S;
		double _t;
		int _num_observed;
		int _allocated_observed;
		double *_observed_strikes;
		double *_observed_volatilities;

		jackwerth(const jackwerth& );
		jackwerth& operator=(const jackwerth& );
};

#endif
