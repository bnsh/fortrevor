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

/* From here on out is generated code. How? By running a few mathematica scripts, specifically
 * gen.m to generate the blackd... derivatives,
 * pgen.m followed by the lex program postprocess to generate the parametrized derivatives
 * vgen.m to generate the derivatives for the volatility with parameters.
 * rgen.m to generate the derivatives for the rates with parameters.
 */

double bsmodel_10_vr::VdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (v*(b + T*(d_ + g*T) + 2*(a + T*(c + f*T))*log(S/K)))/S;
	return(retVal);
}

double bsmodel_10_vr::VdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (v*(2*a - b - T*(-2*c + d_ - 2*f*T + g*T) - 2*(a + T*(c + f*T))*log(S/K)))/pow(S,2);
	return(retVal);
}

double bsmodel_10_vr::VdSdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (2*v*(-3*a + b + T*(-3*c + d_ - 3*f*T + g*T) + 2*(a + T*(c + f*T))*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_10_vr::VdSdSdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (2*v*(11*a - 3*b + T*(11*c - 3*d_ + 11*f*T - 3*g*T) - 6*(a + T*(c + f*T))*log(S/K)))/pow(S,4);
	return(retVal);
}

double bsmodel_10_vr::VdSdSdSdr(const double []) const { return(0); }
double bsmodel_10_vr::VdSdSdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (2*(-3*a + b + T*(-3*c + d_ - 3*f*T + g*T) + 2*(a + T*(c + f*T))*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_10_vr::VdSdSdSdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (2*v*(-3*c + d_ - 6*f*T + 2*g*T + 2*(c + 2*f*T)*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_10_vr::VdSdSdr(const double []) const { return(0); }
double bsmodel_10_vr::VdSdSdrdr(const double []) const { return(0); }
double bsmodel_10_vr::VdSdSdrdv(const double []) const { return(0); }
double bsmodel_10_vr::VdSdSdrdT(const double []) const { return(0); }
double bsmodel_10_vr::VdSdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = -((-2*a + b + T*(-2*c + d_ - 2*f*T + g*T) + 2*(a + T*(c + f*T))*log(S/K))/pow(S,2));
	return(retVal);
}

double bsmodel_10_vr::VdSdSdvdv(const double []) const { return(0); }
double bsmodel_10_vr::VdSdSdvdT(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = -((-2*c + d_ - 4*f*T + 2*g*T + 2*(c + 2*f*T)*log(S/K))/pow(S,2));
	return(retVal);
}

double bsmodel_10_vr::VdSdSdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = -((v*(-2*c + d_ - 4*f*T + 2*g*T + 2*(c + 2*f*T)*log(S/K)))/pow(S,2));
	return(retVal);
}

double bsmodel_10_vr::VdSdSdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double f = params[7];
	double g = params[8];
	double retVal = (-2*v*(-2*f + g + 2*f*log(S/K)))/pow(S,2);
	return(retVal);
}

double bsmodel_10_vr::VdSdr(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdr(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdrdr(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdrdv(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdrdT(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdv(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdvdv(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdvdT(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdT(const double []) const { return(0); }
double bsmodel_10_vr::VdSdrdTdT(const double []) const { return(0); }
double bsmodel_10_vr::VdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (b + T*(d_ + g*T) + 2*(a + T*(c + f*T))*log(S/K))/S;
	return(retVal);
}

double bsmodel_10_vr::VdSdvdv(const double []) const { return(0); }
double bsmodel_10_vr::VdSdvdvdv(const double []) const { return(0); }
double bsmodel_10_vr::VdSdvdvdT(const double []) const { return(0); }
double bsmodel_10_vr::VdSdvdT(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (d_ + 2*g*T + 2*(c + 2*f*T)*log(S/K))/S;
	return(retVal);
}

double bsmodel_10_vr::VdSdvdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double f = params[7];
	double g = params[8];
	double retVal = (2*(g + 2*f*log(S/K)))/S;
	return(retVal);
}

double bsmodel_10_vr::VdSdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double c = params[4];
	double d_ = params[5];
	double f = params[7];
	double g = params[8];
	double retVal = (v*(d_ + 2*g*T + 2*(c + 2*f*T)*log(S/K)))/S;
	return(retVal);
}

double bsmodel_10_vr::VdSdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double f = params[7];
	double g = params[8];
	double retVal = (2*v*(g + 2*f*log(S/K)))/S;
	return(retVal);
}

double bsmodel_10_vr::VdSdTdTdT(const double []) const { return(0); }
double bsmodel_10_vr::Vdr(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdr(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdrdr(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdrdrdr(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdrdrdv(const double []) const { return(0); }
double bsmodel_10_vr::VdrdrdrdT(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdrdv(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdrdvdv(const double []) const { return(0); }
double bsmodel_10_vr::VdrdrdvdT(const double []) const { return(0); }
double bsmodel_10_vr::VdrdrdT(const double []) const { return(0); }
double bsmodel_10_vr::VdrdrdTdT(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdv(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdvdv(const double []) const { return(0); }
double bsmodel_10_vr::Vdrdvdvdv(const double []) const { return(0); }
double bsmodel_10_vr::VdrdvdvdT(const double []) const { return(0); }
double bsmodel_10_vr::VdrdvdT(const double []) const { return(0); }
double bsmodel_10_vr::VdrdvdTdT(const double []) const { return(0); }
double bsmodel_10_vr::VdrdT(const double []) const { return(0); }
double bsmodel_10_vr::VdrdTdT(const double []) const { return(0); }
double bsmodel_10_vr::VdrdTdTdT(const double []) const { return(0); }
double bsmodel_10_vr::Vdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double d_ = params[5];
	double e = params[6];
	double f = params[7];
	double g = params[8];
	double h = params[9];
	double retVal = 1 + T*(e + h*T) + log(S/K)*(b + T*(d_ + g*T) + (a + T*(c + f*T))*log(S/K));
	return(retVal);
}

double bsmodel_10_vr::Vdvdv(const double []) const { return(0); }
double bsmodel_10_vr::Vdvdvdv(const double []) const { return(0); }
double bsmodel_10_vr::Vdvdvdvdv(const double []) const { return(0); }
double bsmodel_10_vr::VdvdvdvdT(const double []) const { return(0); }
double bsmodel_10_vr::VdvdvdT(const double []) const { return(0); }
double bsmodel_10_vr::VdvdvdTdT(const double []) const { return(0); }
double bsmodel_10_vr::VdvdT(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double c = params[4];
	double d_ = params[5];
	double e = params[6];
	double f = params[7];
	double g = params[8];
	double h = params[9];
	double retVal = e + 2*h*T + log(S/K)*(d_ + 2*g*T + (c + 2*f*T)*log(S/K));
	return(retVal);
}

double bsmodel_10_vr::VdvdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double f = params[7];
	double g = params[8];
	double h = params[9];
	double retVal = 2*(h + log(S/K)*(g + f*log(S/K)));
	return(retVal);
}

double bsmodel_10_vr::VdvdTdTdT(const double []) const { return(0); }
double bsmodel_10_vr::VdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double c = params[4];
	double d_ = params[5];
	double e = params[6];
	double f = params[7];
	double g = params[8];
	double h = params[9];
	double retVal = v*(e + 2*h*T + log(S/K)*(d_ + 2*g*T + (c + 2*f*T)*log(S/K)));
	return(retVal);
}

double bsmodel_10_vr::VdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double f = params[7];
	double g = params[8];
	double h = params[9];
	double retVal = 2*v*(h + log(S/K)*(g + f*log(S/K)));
	return(retVal);
}

double bsmodel_10_vr::VdTdTdT(const double []) const { return(0); }
double bsmodel_10_vr::VdTdTdTdT(const double []) const { return(0); }
