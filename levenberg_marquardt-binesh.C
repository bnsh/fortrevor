#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "levenberg_marquardt.H"
#include "svdecomposition.H"

void levenberg_marquardt_binesh::refine(const double best_guess[], double refined[]) {
// This is levenberg_marquardt. See the wiki article:
// 	http://en.wikipedia.org/wiki/Levenberg-Marquardt_algorithm
// SKIP the Numeric Recipes in C chapter, it's... not really inaccurate, but
// just not very clear.
// We want to minimize f(P), so if we're doing least squares, f(P) should be
// the _deltas_, not the function itself to be fitted. So, if this were
// for black scholes, (although this function is _not_ limited to black scholes
// computations.) each f(P) would be (say) callvalue(params) - actualcallprice.
// So, we take the Jacobian, which is the derivative of each parameter for each
// f(P). (with P as the best guess, initially.)
//                   T
// we then take A = J J + (lambda)I
//           T
// and b = -J f
// and solve A q = b for q
// q is our delta for P, so we do P = P + q
// and try again, till we're "done"
// 
	double *p = refined;

	double *block_J   = new double[_number_of_functions*_number_of_parameters];
	double *block_JTJ = new double[_number_of_parameters*_number_of_parameters];
	double *block_A   = new double[_number_of_parameters*_number_of_parameters];

	double *J[_number_of_functions];
	double *JTJ[_number_of_parameters];
	double *A[_number_of_parameters];
	double *B = new double[_number_of_parameters];
	double *q = new double[_number_of_parameters];
	double *F = new double[_number_of_functions];

	for (int i = 0; i < _number_of_functions; ++i) J[i] = &block_J[i*_number_of_parameters];
	for (int i = 0; i < _number_of_parameters; ++i) {
		JTJ[i] = &block_JTJ[i*_number_of_parameters];
		A[i] = &block_A[i*_number_of_parameters];
	}

	double lambda0 = 0.001;
	double lambda = lambda0;
	double v = 1.5;
	double lastS = 0.0;
	int done = 0;
	int improving = 0;

	for (int i = 0; i < _number_of_parameters; ++i) p[i] = best_guess[i];

	for (int i = 0; i < _number_of_functions; ++i) {
		F[i] = (*_functions[i])(p);
		if(isnan(F[i])) {
			fprintf(stderr,"functions[%d](%.7f,%.7f) = %.7f\n",i,p[0],p[1],F[i]);
			assert(!isnan(F[i]));
		}
		lastS = lastS + F[i] * F[i];
	}

	do {
		for (int j = 0; j < _number_of_parameters; ++j) {
			B[j] = 0.0;
			for (int i = 0; i < _number_of_parameters; ++i) {
				JTJ[i][j] = 0.0;
				A[i][j] = 0.0;
			}
		}
		for (int j = 0; j < _number_of_parameters; ++j) {
			B[j] = 0.0;
			for (int i = 0; i < _number_of_functions; ++i) {
				J[i][j] = _functions[i]->derivative(j, p);
				B[j] = B[j] - F[i] * J[i][j];
			}
			q[j] = B[j];
		}
		for (int j = 0; j < _number_of_parameters; ++j) {
			for (int k = 0; k < _number_of_parameters; ++k) {
				JTJ[j][k] = 0.0;
				for (int i = 0; i < _number_of_functions; ++i) {
					JTJ[j][k] = JTJ[j][k] + J[i][j] * J[i][k];
				}
			}
		}
		for (int j = 0; j < _number_of_parameters; ++j) {
			for (int k = 0; k < _number_of_parameters; ++k) {
				A[j][k] = JTJ[j][k];
				if (j == k) A[j][k] = A[j][k] + lambda;
			}
		}
		double dp[_number_of_parameters];
// *sigh* double ** vs double[][]
		double *fakeA[_number_of_parameters];
		for (int i = 0; i < _number_of_parameters; ++i) fakeA[i] = A[i];
		just_svd(fakeA,_number_of_parameters,q,dp);
/*
		int indx[_number_of_parameters];
		double d;
		ludcmp(fakeA,_number_of_parameters,indx,d);
		lubksb(fakeA,_number_of_parameters,indx,q);
 */
		double newp[_number_of_parameters];
		double newF[_number_of_functions];
		for (int i = 0; i < _number_of_parameters; ++i) {
			newp[i] = p[i] + dp[i];
		}
		double S = 0.0;
		for (int i = 0; i < _number_of_functions; ++i) {
			newF[i] = (*_functions[i])(newp);
			S = S + newF[i] * newF[i];
		}
//		fprintf(stderr,"S=%.7f	lastS=%.7f	lambda=%.7f\n",S,lastS, lambda);
		if (lastS < S) {
			lambda = lambda * v; // increased error.
			improving = 0;
		}
		else {
			lambda = lambda / v;
			for (int i = 0; i < _number_of_parameters; ++i) p[i] = newp[i];
			for (int i = 0; i < _number_of_functions; ++i) F[i] = newF[i];
			done = ((((lastS - S) / S) < 1e-12) || (S < 1e-12));
			lastS = S;
			improving = 1;
		}
	} while (!done);

	delete[] block_J;
	delete[] block_JTJ;
	delete[] block_A;
	delete[] B;
	delete[] q;
	delete[] F;
}
