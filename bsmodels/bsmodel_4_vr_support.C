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

/* From here on out is generated code. How? By running a few mathematica scripts, specifically
 * gen.m to generate the blackd... derivatives,
 * pgen.m followed by the lex program postprocess to generate the parametrized derivatives
 * vgen.m to generate the derivatives for the volatility with parameters.
 * rgen.m to generate the derivatives for the rates with parameters.
 */

double bsmodel_4_vr::VdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double retVal = (v*(b + 2*a*log(S/K)))/S;
	return(retVal);
}

double bsmodel_4_vr::VdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double retVal = -((v*(-2*a + b + 2*a*log(S/K)))/pow(S,2));
	return(retVal);
}

double bsmodel_4_vr::VdSdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double retVal = (2*v*(-3*a + b + 2*a*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_4_vr::VdSdSdSdS(const double params[]) const {
	double S = current();
	double K = strike();
	double v = params[0];
	double a = params[2];
	double b = params[3];
	double retVal = (-2*v*(-11*a + 3*b + 6*a*log(S/K)))/pow(S,4);
	return(retVal);
}

double bsmodel_4_vr::VdSdSdSdr(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double a = params[2];
	double b = params[3];
	double retVal = (2*(-3*a + b + 2*a*log(S/K)))/pow(S,3);
	return(retVal);
}

double bsmodel_4_vr::VdSdSdSdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdr(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdrdr(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdrdv(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdrdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double a = params[2];
	double b = params[3];
	double retVal = -((-2*a + b + 2*a*log(S/K))/pow(S,2));
	return(retVal);
}

double bsmodel_4_vr::VdSdSdvdv(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdSdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdr(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdr(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdrdr(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdrdv(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdrdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdv(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdvdv(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdrdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdv(const double params[]) const {
	double S = current();
	double K = strike();
	double a = params[2];
	double b = params[3];
	double retVal = (b + 2*a*log(S/K))/S;
	return(retVal);
}

double bsmodel_4_vr::VdSdvdv(const double []) const { return(0); }
double bsmodel_4_vr::VdSdvdvdv(const double []) const { return(0); }
double bsmodel_4_vr::VdSdvdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdvdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdSdTdTdT(const double []) const { return(0); }
double bsmodel_4_vr::Vdr(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdr(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdrdr(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdrdrdr(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdrdrdv(const double []) const { return(0); }
double bsmodel_4_vr::VdrdrdrdT(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdrdv(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdrdvdv(const double []) const { return(0); }
double bsmodel_4_vr::VdrdrdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdrdrdT(const double []) const { return(0); }
double bsmodel_4_vr::VdrdrdTdT(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdv(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdvdv(const double []) const { return(0); }
double bsmodel_4_vr::Vdrdvdvdv(const double []) const { return(0); }
double bsmodel_4_vr::VdrdvdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdrdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdrdvdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdrdT(const double []) const { return(0); }
double bsmodel_4_vr::VdrdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdrdTdTdT(const double []) const { return(0); }
double bsmodel_4_vr::Vdv(const double params[]) const {
	double S = current();
	double K = strike();
	double a = params[2];
	double b = params[3];
	double retVal = 1 + log(S/K)*(b + a*log(S/K));
	return(retVal);
}

double bsmodel_4_vr::Vdvdv(const double []) const { return(0); }
double bsmodel_4_vr::Vdvdvdv(const double []) const { return(0); }
double bsmodel_4_vr::Vdvdvdvdv(const double []) const { return(0); }
double bsmodel_4_vr::VdvdvdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdvdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdvdvdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdvdT(const double []) const { return(0); }
double bsmodel_4_vr::VdvdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdvdTdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdT(const double []) const { return(0); }
double bsmodel_4_vr::VdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdTdTdT(const double []) const { return(0); }
double bsmodel_4_vr::VdTdTdTdT(const double []) const { return(0); }
