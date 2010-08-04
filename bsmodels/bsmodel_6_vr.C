#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "levenberg_marquardt.H"
#include "cboe_reader.H"
#include "bsmodel.H"
#include "bsmodels/bsmodel_base.H"
#include "bsmodels/bsmodel_6_vr.H"

/*
 * OK, this computes like so:
 * Call[S,K,r,V[S,K,t,v,a,b,c,d,e,f,g,h],t]
 * where
 * V[S,K,t,v,a,b,c,d,e,f,g,h] is the parametrized volatility, and
 * 	v is the "underlying volatility"
 * It's parametrized, to try to estimate the "smile".
 * V[S,K,t,v,a,b,c,d,e,f,g,h] =
 * 	v (
 *		(a     X X + b     X + 1    ) +
 *		(c     Y Y + d     Y + 1    )
 *	)
 * where X = Log[S/K] and Y = t.
 * That way, if a..h are all 0's, it translates to the plain vanilla "constant" volatility.
 * params[0] = v,
 * params[1] = r,
 * params[2] = a,
 * params[3] = b,
 * params[4] = c,
 * params[5] = d,
 */

bsmodel_6_vr::bsmodel_6_vr(const cboe_option_quote& coq) :
	bsmodel_base(coq, 6) {
}

bsmodel_6_vr::~bsmodel_6_vr() {
}

double bsmodel_6_vr::d(int pno, const double params[]) {
	if (pno == 0) return(vega(params));
	else if (pno == 1) return(rho(params));
	else if (pno == 2) return(da(params));
	else if (pno == 3) return(db(params));
	else if (pno == 4) return(dc(params));
	else if (pno == 5) return(dd(params));
	else return(0.0);
}

double bsmodel_6_vr::da(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double c = params[4];
	double _d = params[5];
	double dVda = (1 + T*(_d + c*T))*v*(log(S/K)*log(S/K));
	double retVal = black_vega * dVda;
	return(retVal);
}

double bsmodel_6_vr::db(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double c = params[4];
	double _d = params[5];
	double dVdb = (1 + T*(_d + c*T))*v*log(S/K);
	double retVal = black_vega * dVdb;
	return(retVal);
}

double bsmodel_6_vr::dc(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double dVdc = T*T*v*(1 + log(S/K)*(b + a*log(S/K)));
	double retVal = black_vega * dVdc;
	return(retVal);
}

double bsmodel_6_vr::dd(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double dVdd = T*v*(1 + log(S/K)*(b + a*log(S/K)));
	double retVal = black_vega * dVdd;
	return(retVal);
}

double bsmodel_6_vr::risk_free_rate(const double params[]) const { return(params[1]); }
double bsmodel_6_vr::volatility(const double params[]) const {
/* volatility is "parametrized" volatility. */
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double X = log(S/K);
	double Y = T;
	double retVal = v * (
		(a * X * X         + b * X         + 1) *
		(c * Y * Y         + _d * Y         + 1)
	);
	return(retVal);
}

