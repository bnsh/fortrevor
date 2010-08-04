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

/* From here on out is generated code. How? By running a few mathematica scripts, specifically
 * gen.m to generate the blackd... derivatives,
 * pgen.m followed by the lex program postprocess to generate the parametrized derivatives
 * vgen.m to generate the derivatives for the volatility with parameters.
 * rgen.m to generate the derivatives for the rates with parameters.
 */

double bsmodel_6_vr::VdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = ((1 + T*(_d + c*T))*v*(b + 2*a*log(S/K)))/S;
	return(retVal);
}

double bsmodel_6_vr::VdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = -(((1 + T*(_d + c*T))*v*(-2*a + b + 2*a*log(S/K)))/pow(S,2));
	return(retVal);
}

double bsmodel_6_vr::VdSdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = (2*(1 + T*(_d + c*T))*v*(-3*a + b + 2*a*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_6_vr::VdSdSdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = (-2*(1 + T*(_d + c*T))*v*(-11*a + 3*b + 6*a*log(S/K)))/pow(S,4);
	return(retVal);
}

double bsmodel_6_vr::VdSdSdSdr(const double []) const { return(0); }
double bsmodel_6_vr::VdSdSdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = (2*(1 + T*(_d + c*T))*(-3*a + b + 2*a*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_6_vr::VdSdSdSdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = (2*(_d + 2*c*T)*v*(-3*a + b + 2*a*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_6_vr::VdSdSdr(const double []) const { return(0); }
double bsmodel_6_vr::VdSdSdrdr(const double []) const { return(0); }
double bsmodel_6_vr::VdSdSdrdv(const double []) const { return(0); }
double bsmodel_6_vr::VdSdSdrdT(const double []) const { return(0); }
double bsmodel_6_vr::VdSdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = -(((1 + T*(_d + c*T))*(-2*a + b + 2*a*log(S/K)))/pow(S,2));
	return(retVal);
}

double bsmodel_6_vr::VdSdSdvdv(const double []) const { return(0); }
double bsmodel_6_vr::VdSdSdvdT(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = -(((_d + 2*c*T)*(-2*a + b + 2*a*log(S/K)))/pow(S,2));
	return(retVal);
}

double bsmodel_6_vr::VdSdSdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = -(((_d + 2*c*T)*v*(-2*a + b + 2*a*log(S/K)))/pow(S,2));
	return(retVal);
}

double bsmodel_6_vr::VdSdSdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double retVal = (-2*c*v*(-2*a + b + 2*a*log(S/K)))/pow(S,2);
	return(retVal);
}

double bsmodel_6_vr::VdSdr(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdr(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdrdr(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdrdv(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdrdT(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdv(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdvdv(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdvdT(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdT(const double []) const { return(0); }
double bsmodel_6_vr::VdSdrdTdT(const double []) const { return(0); }
double bsmodel_6_vr::VdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = ((1 + T*(_d + c*T))*(b + 2*a*log(S/K)))/S;
	return(retVal);
}

double bsmodel_6_vr::VdSdvdv(const double []) const { return(0); }
double bsmodel_6_vr::VdSdvdvdv(const double []) const { return(0); }
double bsmodel_6_vr::VdSdvdvdT(const double []) const { return(0); }
double bsmodel_6_vr::VdSdvdT(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = ((_d + 2*c*T)*(b + 2*a*log(S/K)))/S;
	return(retVal);
}

double bsmodel_6_vr::VdSdvdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double retVal = (2*c*(b + 2*a*log(S/K)))/S;
	return(retVal);
}

double bsmodel_6_vr::VdSdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = ((_d + 2*c*T)*v*(b + 2*a*log(S/K)))/S;
	return(retVal);
}

double bsmodel_6_vr::VdSdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double retVal = (2*c*v*(b + 2*a*log(S/K)))/S;
	return(retVal);
}

double bsmodel_6_vr::VdSdTdTdT(const double []) const { return(0); }
double bsmodel_6_vr::Vdr(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdr(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdrdr(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdrdrdr(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdrdrdv(const double []) const { return(0); }
double bsmodel_6_vr::VdrdrdrdT(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdrdv(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdrdvdv(const double []) const { return(0); }
double bsmodel_6_vr::VdrdrdvdT(const double []) const { return(0); }
double bsmodel_6_vr::VdrdrdT(const double []) const { return(0); }
double bsmodel_6_vr::VdrdrdTdT(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdv(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdvdv(const double []) const { return(0); }
double bsmodel_6_vr::Vdrdvdvdv(const double []) const { return(0); }
double bsmodel_6_vr::VdrdvdvdT(const double []) const { return(0); }
double bsmodel_6_vr::VdrdvdT(const double []) const { return(0); }
double bsmodel_6_vr::VdrdvdTdT(const double []) const { return(0); }
double bsmodel_6_vr::VdrdT(const double []) const { return(0); }
double bsmodel_6_vr::VdrdTdT(const double []) const { return(0); }
double bsmodel_6_vr::VdrdTdTdT(const double []) const { return(0); }
double bsmodel_6_vr::Vdv(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = (1 + T*(_d + c*T))*(1 + log(S/K)*(b + a*log(S/K)));
	return(retVal);
}

double bsmodel_6_vr::Vdvdv(const double []) const { return(0); }
double bsmodel_6_vr::Vdvdvdv(const double []) const { return(0); }
double bsmodel_6_vr::Vdvdvdvdv(const double []) const { return(0); }
double bsmodel_6_vr::VdvdvdvdT(const double []) const { return(0); }
double bsmodel_6_vr::VdvdvdT(const double []) const { return(0); }
double bsmodel_6_vr::VdvdvdTdT(const double []) const { return(0); }
double bsmodel_6_vr::VdvdT(const double params[]) const {
	double S = current();
	double K = strike();
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = (_d + 2*c*T)*(1 + log(S/K)*(b + a*log(S/K)));
	return(retVal);
}

double bsmodel_6_vr::VdvdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double retVal = 2*c*(1 + log(S/K)*(b + a*log(S/K)));
	return(retVal);
}

double bsmodel_6_vr::VdvdTdTdT(const double []) const { return(0); }
double bsmodel_6_vr::VdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double T = time_to_expiration();
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double _d = params[5];
	double retVal = (_d + 2*c*T)*v*(1 + log(S/K)*(b + a*log(S/K)));
	return(retVal);
}

double bsmodel_6_vr::VdTdT(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double c = params[4];
	double retVal = 2*c*v*(1 + log(S/K)*(b + a*log(S/K)));
	return(retVal);
}

double bsmodel_6_vr::VdTdTdT(const double []) const { return(0); }
double bsmodel_6_vr::VdTdTdTdT(const double []) const { return(0); }
