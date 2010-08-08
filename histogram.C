#include <stdio.h>
#include "histogram.H"

histogram::histogram(int sz, const double *fenceposts) :
	_sz(sz),
	_total(0.0),
	_fenceposts(NULL),
	_counts(NULL)
{
	_fenceposts = new double[_sz+1];
	for (int i = 0; i < _sz+1; ++i) _fenceposts[i] = fenceposts[i];
	_counts = new double[_sz];
	for (int i = 0; i < _sz; ++i) _counts[i] = 0.0;
}

histogram::~histogram() {
	if (_fenceposts) delete[] _fenceposts; _fenceposts = NULL;
	if (_counts) delete[] _counts; _counts = NULL;
}

void histogram::accumulate(double x, double weight) {
	for (int i = 0; i < _sz; ++i) {
		if ((_fenceposts[i] <= x) && (x < _fenceposts[i+1])) {
			_counts[i] += weight;
			_total += weight;
		}
	}
}

void histogram::dump(FILE *fp) const {
	for (int i = 0; i < _sz; ++i) {
		fprintf(fp,"%g",_fenceposts[i]);
		fprintf(fp,"	");
		fprintf(fp,"%g",_fenceposts[i+1]);
		fprintf(fp,"	");
		fprintf(fp,"%g",_counts[i]);
		fprintf(fp,"\n");
	}
}
