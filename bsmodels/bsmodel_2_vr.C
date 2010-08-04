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
#include "bsmodels/bsmodel_2_vr.H"

bsmodel_2_vr::bsmodel_2_vr(const cboe_option_quote& coq) :
	bsmodel_base(coq, 2) {
}

bsmodel_2_vr::~bsmodel_2_vr() {
}

double bsmodel_2_vr::d(int pno, const double params[]) {
	if (pno == 0) return(blackvega(params));
	else if (pno == 1) return(blackrho(params));
	else return(0.0);
}

double bsmodel_2_vr::risk_free_rate(const double params[]) const { return(params[1]); }
double bsmodel_2_vr::volatility(const double params[]) const { return(params[0]); }
