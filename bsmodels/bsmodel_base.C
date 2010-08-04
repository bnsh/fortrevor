#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "cboe_reader.H"
#include "levenberg_marquardt.H"
#include "bsmodel.H"
#include "bsmodels/bsmodel_base.H"

bsmodel_base::bsmodel_base(const cboe_option_quote& coq, int n) :
	bsmodel(coq, n) {
}

bsmodel_base::~bsmodel_base() {
}

double bsmodel_base::value(const double params[]) {
	double S = current();
	double K = strike();
	double r = risk_free_rate(params);
	double T = time_to_expiration();
	double D1 = d1(params);
	double D2 = d2(params);
	double tp = type();

	double retVal = -1.0;
// This could be simplified into
// tp * (S * cdf(tp*D1) - K * exp(-r * T) * cdf(tp*D2))
// But, A. That would be confusing later, and
// B. you'd have to do the same thing with every other derivative. (Which can be done,
// But, I think A would apply to each of the derivatives. Plus, I wouldn't be able to 
// refer to http://en.wikipedia.org/wiki/Black-Scholes#The_formula
// as verification.
	if (tp == 1) retVal =   S * cdf(params, D1) - K * exp(-r * T) * cdf(params, D2);
	else         retVal = - S * cdf(params,-D1) + K * exp(-r * T) * cdf(params,-D2);
	return(retVal);
}

double bsmodel_base::cdf(const double [], double z) const {
	return((1.0 + erf(z / sqrt(2.0))) / 2.0);
}

double bsmodel_base::pdf(const double [], double z) const {
	return(exp(-z*z/2.0)/sqrt(2.0*M_PI));
}

double bsmodel_base::d1(const double params[]) const {
	double retVal = (((log(current()) - log(strike())) + (risk_free_rate(params) + (volatility(params)*volatility(params)/2.0)) * time_to_expiration()) / (volatility(params) * sqrt(time_to_expiration())));
	return(retVal);
}

double bsmodel_base::d2(const double params[]) const {
	double retVal = d1(params) - volatility(params) * sqrt(time_to_expiration());
	return(retVal);
}

double bsmodel_base::blackdelta(const double params[]) const { return(blackdS(params)); }
double bsmodel_base::blackgamma(const double params[]) const { return(blackdSdS(params)); }
double bsmodel_base::blackvega(const double params[]) const { return(blackdv(params)); }
double bsmodel_base::blackrho(const double params[]) const { return(blackdr(params)); }
double bsmodel_base::blacktheta(const double params[]) const { return(blackdT(params)); }

double bsmodel_base::delta(const double params[]) const { return(dS(params)); }
double bsmodel_base::gamma(const double params[]) const { return(dSdS(params)); }
double bsmodel_base::vega(const double params[]) const { return(dv(params)); }
double bsmodel_base::rho(const double params[]) const { return(dr(params)); }
double bsmodel_base::theta(const double params[]) const { return(dT(params)); }

