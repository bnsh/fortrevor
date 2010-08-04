#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "levenberg_marquardt.H"
#include "svdecomposition.H"

void levenberg_marquardt::reallocate(int n) {
	_allocated = 2*(n + 1);
	function **_newly_allocated = new function *[_allocated];
	if (_functions) {
		for (int i = 0; i < _allocated; ++i) {
			if (i < n) _newly_allocated[i] = _functions[i];
			else _newly_allocated[i] = NULL;
		}
		delete[] _functions;
	}
	_functions = _newly_allocated;
}

void levenberg_marquardt::add(function *f) {
	if ((_number_of_functions + 1) >= _allocated) reallocate(_number_of_functions+1);
	if (_number_of_parameters < f->number_of_parameters()) _number_of_parameters = f->number_of_parameters();
	_functions[_number_of_functions++] = f;
}
