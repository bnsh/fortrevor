#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "matrix.H"
#include "svdecomposition.H"
#include "histogram.H"
#include "jackwerth.H"

jackwerth::jackwerth() :
	_r(-1.0),
	_q(-1.0),
	_S(-1.0),
	_t(-1.0),
	_num_observed(0),
	_allocated_observed(0),
	_observed_strikes(NULL),
	_observed_volatilities(NULL) {
	reallocate_observed(1024);
}

jackwerth::~jackwerth() {
	_num_observed = 0;
	_allocated_observed = 0;

	if (_observed_strikes) delete[] _observed_strikes; _observed_strikes = NULL;
	if (_observed_volatilities) delete[] _observed_volatilities; _observed_volatilities = NULL;
}

void jackwerth::reallocate_observed(int n) {
	assert(n > _num_observed);
	double *new_strikes = new double[n];
	double *new_volatilities = new double[n];

	for (int i = 0; i < n; ++i) {
		new_strikes[i] = 0.0;
		new_volatilities[i] = 0.0;
	}

	for (int i = 0; i < _num_observed; ++i) {
		if (_observed_strikes) new_strikes[i] = _observed_strikes[i];
		if (_observed_volatilities) new_volatilities[i] = _observed_volatilities[i];
	}
	_allocated_observed = n;

	if (_observed_strikes) delete[] _observed_strikes; _observed_strikes = NULL;
	if (_observed_volatilities) delete[] _observed_volatilities; _observed_volatilities = NULL;

	_observed_strikes = new_strikes;
	_observed_volatilities = new_volatilities;
}

jackwerth& jackwerth::option(double strike, double iv) {
	if (_num_observed >= _allocated_observed) reallocate_observed(_allocated_observed*2);
	_observed_strikes[_num_observed] = strike;
	_observed_volatilities[_num_observed] = iv;
	_num_observed++;
	return((*this));
}

static double pdf(double z) {
	return(exp(-z*z/2.0)/sqrt(2*M_PI));
}

histogram *jackwerth::compute_histogram(double lo, double hi, double increment) {
	volatile double lokappa = 0.0;
	volatile double hikappa = 1.0;
	int done = 0;

// OK, first we need to calculate "J" the number of entries in the computed
// volatilities array. (And, the matrix size as well)
	int J = 1+(int)(1+((hi - lo) / increment));
// I is the number of observed values, so that's simply _num_observed.
	double **baseA = matrix_allocate(J,J,0.0);
	double **A = matrix_allocate(J,J,0.0);
	double *X = vector_allocate(J,0.0);
	double *B = vector_allocate(J,0.0);
	double final_probs[J];


	for (int j = 0; j < J; ++j) {
		int values[] = { 1,-4,6,-4,1};
		for (int k = -2; k <= 2; ++k) {
			int actual_k = j + k;
			int offset = values[k+2];
			if (actual_k <  0) actual_k = 0;
			if (actual_k >= J) actual_k = (J-1);
			baseA[j][actual_k] = offset;
		}
	}

	int iters = 128;
	while (!done) {
		double kappa = lokappa + (hikappa - lokappa) / 2.0;
		double prop = (kappa - lokappa) / (hikappa - lokappa);
		done = (prop == 0.0);
// OK, Kappa is _Binesh's_ invention. Kappa relates to lambda like so:
// kappa = lambda / (1+lambda).
// so, lambda = kappa / (1-kappa)
// Why? This way Kappa = 0 is effectively reducing lambda to 0.
// Kappa = 1 tho, would be lambda at a "infinite" value. (In reality, we'd
// likely start at kappa = 0.9 and work till we didn't have any negative values.
		double lambda = kappa / (1-kappa);
		for (int i = 0; i < J; ++i) {
			B[i] = 0.0;
			for (int j = 0; j < J; ++j) A[i][j] = baseA[i][j];
		}
// Now, we have to add all the I's.
// we have to make sure that each option here is actually
// exactly on our "grid" (or rather on our discretized line).
		double coeff = lambda * (J * 1.0) / (_num_observed * increment * increment * increment * increment);
		for (int i = 0; i < _num_observed; ++i) {
			int index = (int)(0.5+((_observed_strikes[i] - lo) / increment));
// Now, _observed_strikes[i] - (index * increment + lo) should be "close" to zero.
			double trust_but_verify = _observed_strikes[i] - (index * increment + lo);
			if (!(((-increment/100) < trust_but_verify) && (trust_but_verify < (increment/100)))) {
				fprintf(stderr,"%s: %d: _observed_strikes[%d] = %.7g\n",__FILE__,__LINE__,i,_observed_strikes[i]);
				fprintf(stderr,"%s: %d: lo = %.7g\n",__FILE__,__LINE__,lo);
				fprintf(stderr,"%s: %d: index = %d\n",__FILE__,__LINE__,index);
				fprintf(stderr,"%s: %d: increment = %.7g\n",__FILE__,__LINE__,increment);
				fprintf(stderr,"%s: %d: trust_but_verify = %.7g\n",__FILE__,__LINE__,trust_but_verify);
			}
			assert(((-increment/100) < trust_but_verify) && (trust_but_verify < (increment/100)));
			double Aii = A[index][index];
			double Bi = B[index];
			A[index][index] = Aii+coeff;
			B[index] = Bi+coeff*_observed_volatilities[i];
		}
// OK, now we have to solve for X.
		just_svd(A,J,B,X);

/*
Now, the probabilities, according to page 66 of Jackwerth are
Exp[r T] D[D[BS[S,K,r,q,V[K],T],K],K] if I read that right. I don't _like_
his version, because it uses r as the percentaged based return rather than an
Exp[r] type r (ditto for q, the dividend yield.) Hopefully, mine will return the
same results. We'll see in a minute. (I'm also not so sure I understand
_why_ the equation works. _If_ it works, I'll have to look into _why_.)
My version (or rather, mathematica's version _does_ work. However, Jackwerth's
A. also works, B. is provably _equal_ to the mathematica version (implement
both, and subtracting mathematica from jackwerth yields 0 in mathematica) and 
C. is less prone to numeric errors.
 */
		const double *volatility = X; // just a renaming of the variable, really.

		double probs[J];
		probs[0] = 0.0;
		probs[(J-1)] = 0.0;
		double total = 0.0;
		for (int j = 1; j < (J-1); ++j) {
			double V_K = volatility[j];
			double dVdK = (volatility[j+1] - volatility[j-1]) / (2*increment);
			double dV2dK2 = (volatility[j-1] - 2*volatility[j] + volatility[j+1]) / (increment*increment);
			double q = _q;
			double r = _r;
			double T = _t;
			double S = _S;
			double K = lo + increment * j;

			double d1j = (log(S/K) + (r - q + V_K*V_K / 2.0) * T) / (V_K * sqrt(T));
			double d2j = d1j - V_K * sqrt(T);
			probs[j] = (
				(pdf(d2j)*(1+2*K * sqrt(T)*d1j*dVdK)/(K*V_K*sqrt(T))) + (S * exp(T*(r-q))*sqrt(T)*pdf(d1j)*(dV2dK2 + d1j*d2j * dVdK*dVdK / V_K))
			);
			total += probs[j];
		}
		int negative_probs = 0;
		for (int j = 0; j < J; ++j) {
			probs[j] = probs[j] / total;
			if (probs[j] < 0.0) negative_probs = 1;
		}
		if (!negative_probs) {
			for (int j = 0; j < J; ++j) final_probs[j] = probs[j];
		}

		if (negative_probs) { done = 0; hikappa = kappa; }
		else lokappa = kappa;

		iters--;
		if (iters < 0) done = 1;
	}
	vector_free(B); B = NULL;
	vector_free(B); B = NULL;
	vector_free(X); X = NULL;
	matrix_free(baseA); baseA = NULL;
	matrix_free(A); A = NULL;

/*
 * OK, final_probs should contain our list of final probabilities.
 * Build a histogram:
 * The histogram will contain J bins, so it has to contain J+1 fenceposts.
 * The fenceposts should be log(K/S) values.
 */
	double fenceposts[J+1];
/* Binesh - 2008-10-10 - Ugh.  for (int j = 0; j < J+1; ++j) yields a "cannot optimize possibly infinite loops" error. So, that's why there's a "volatile" in front of int. */
	for (volatile int j = 0; j < J+1; ++j) {
		double K = lo + increment * j - increment/2.0;
		double S = _S;
		double l = log(K/S);
		fenceposts[j] = l;
	}
	histogram *retVal = new histogram(J,fenceposts);
	for (int j = 0; j < J; ++j) {
		double K = lo + increment * j - increment/2.0;
		double S = _S;
		double l = log(K/S);
		retVal->accumulate(l,final_probs[j]);
	}

	return(retVal);
}
