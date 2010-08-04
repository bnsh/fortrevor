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
#include "bsmodels/bsmodel_10_vr.H"

/*
 * OK, this computes like so:
 * Call[S,K,r,V[S,K,t,v,a,b,c,d,e,f,g,h],t]
 * where
 * V[S,K,t,v,a,b,c,d,e,f,g,h] is the parametrized volatility, and
 * 	v is the "underlying volatility"
 * It's parametrized, to try to estimate the "smile".
 * V[S,K,t,v,a,b,c,d,e,f,g,h] =
 * 	v (
 *		(a     X X + b     X + 1    )
 *		(c Y   X X + d Y   X + e Y  ) +
 *		(f Y Y X X + g Y Y X + h Y Y) +
 *	)
 * where X = Log[S/K] and Y = t.
 * That way, if a..h are all 0's, it translates to the plain vanilla "constant" volatility.
 * params[0] = v,
 * params[1] = r,
 * params[2] = a,
 * params[3] = b,
 * params[4] = c,
 * params[5] = d,
 * params[6] = e,
 * params[7] = f,
 * params[8] = g,
 * params[9] = h,
 */

bsmodel_10_vr::bsmodel_10_vr(const cboe_option_quote& coq) :
	bsmodel_base(coq, 10) {
}

bsmodel_10_vr::~bsmodel_10_vr() {
}

double bsmodel_10_vr::d(int pno, const double params[]) {
	if (pno == 0) return(vega(params));
	else if (pno == 1) return(rho(params));
	else if (pno == 2) return(da(params));
	else if (pno == 3) return(db(params));
	else if (pno == 4) return(dc(params));
	else if (pno == 5) return(dd(params));
	else if (pno == 6) return(de(params));
	else if (pno == 7) return(df(params));
	else if (pno == 8) return(dg(params));
	else if (pno == 9) return(dh(params));
	else return(0.0);
}

double bsmodel_10_vr::df(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double dVdf = (T*T*v*log(S/K)*log(S/K));
	double retVal = black_vega * dVdf;
	return(retVal);
}

double bsmodel_10_vr::dc(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double dVdc = (T*v*log(S/K)*log(S/K));
	double retVal = black_vega * dVdc;
	return(retVal);
}

double bsmodel_10_vr::da(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double v = params[0];
	double dVda = (v*log(S/K)*log(S/K));
	double retVal = black_vega * dVda;
	return(retVal);
}


double bsmodel_10_vr::dg(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double dVdg = (T*T*v*log(S/K));
	double retVal = black_vega * dVdg;
	return(retVal);
}

double bsmodel_10_vr::dd(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double dVdd = (T*v*log(S/K));
	double retVal = black_vega * dVdd;
	return(retVal);
}

double bsmodel_10_vr::db(const double params[]) const {
	double black_vega = blackvega(params);
	double S = current();
	double K = strike();
	double v = params[0];
	double dVdb = (v*log(S/K));
	double retVal = black_vega * dVdb;
	return(retVal);
}

double bsmodel_10_vr::dh(const double params[]) const {
	double black_vega = blackvega(params);
	double T = time_to_expiration();
	double v = params[0];
	double dVdh = (T*T*v);
	double retVal = black_vega * dVdh;
	return(retVal);
}

double bsmodel_10_vr::de(const double params[]) const {
	double black_vega = blackvega(params);
	double T = time_to_expiration();
	double v = params[0];
	double dVde = (T*v);
	double retVal = black_vega * dVde;
	return(retVal);
}

double bsmodel_10_vr::risk_free_rate(const double params[]) const { return(params[1]); }
double bsmodel_10_vr::volatility(const double params[]) const {
/* volatility is "parametrized" volatility. */
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double e = params[6];
	double f = params[7];
	double g = params[8];
	double h = params[9];
	double X = log(S/K);
	double Y = T;
	double retVal = v * (
		(a * X * X         + b * X         + 1) +
		(c * X * X * Y     + _d * X * Y     + e * Y) +
		(f * X * X * Y * Y + g * X * Y * Y + h * Y * Y)
	);
	return(retVal);
}

