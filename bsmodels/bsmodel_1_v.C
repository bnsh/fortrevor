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
#include "bsmodels/bsmodel_1_v.H"

bsmodel_1_v::bsmodel_1_v(const cboe_option_quote& coq, double rfr) :
	bsmodel_base(coq, 1),
	_risk_free_rate(rfr) {
}

bsmodel_1_v::~bsmodel_1_v() {
}

double bsmodel_1_v::d(int pno, const double params[]) {
	if (pno >= 1) fprintf(stderr,"%s: %d: bsmodel_1_v only has 1 parameter. Asked for derivative at parameter[%d]\n",__FILE__,__LINE__,pno);
	assert(pno < 1);
	return(blackvega(params));
}

double bsmodel_1_v::risk_free_rate(const double []) const { return(_risk_free_rate); }
double bsmodel_1_v::volatility(const double params[]) const { return(params[0]); }
