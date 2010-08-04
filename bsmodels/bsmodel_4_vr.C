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
#include "bsmodels/bsmodel_4_vr.H"

/*
 * OK, this computes like so:
 * Call[S,K,r,V[S,K,v,a,b],t]
 * where
 * V[S,K,v,a,b] is the parametrized volatility, and
 * 	v is the "underlying volatility"
 * It's parametrized, to try to estimate the "smile".
 * V[S,K,v,a,b] =
 * 	v * (a X X + b X X + 1)
 * where X = Log[S/K]
 * That way, if a..h are all 0's, it translates to the plain vanilla "constant" volatility.
 * params[0] = v,
 * params[1] = r,
 * params[2] = a,
 * params[3] = b,
 */

bsmodel_4_vr::bsmodel_4_vr(const cboe_option_quote& coq) :
	bsmodel_base(coq, 4) {
}

bsmodel_4_vr::~bsmodel_4_vr() {
}

double bsmodel_4_vr::d(int pno, const double params[]) {
	if (pno == 0) return(vega(params));
	else if (pno == 1) return(rho(params));
	else if (pno == 2) return(da(params));
	else if (pno == 3) return(db(params));
	else return(0.0);
}

double bsmodel_4_vr::da(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double v = params[0];
	double dVda = v*log(S/K)*log(S/K);
	double retVal = black_vega * dVda;
	return(retVal);
}

double bsmodel_4_vr::db(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double v = params[0];
	double dVdb = v*log(S/K);
	double retVal = black_vega * dVdb;
	return(retVal);
}

double bsmodel_4_vr::risk_free_rate(const double params[]) const { return(params[1]); }
double bsmodel_4_vr::volatility(const double params[]) const {
/* volatility is "parametrized" volatility. */
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double X = log(S/K);
	double retVal = v * (a * X * X + b * X + 1);
	return(retVal);
}

