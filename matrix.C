#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "matrix.H"

double **matrix_allocate(int m, int n, double iv) {
	double *raw = new double[m*n];
	double **retVal = new double *[m];

	for (int i = 0; i < m; ++i) {
		retVal[i] = raw + (i*n);
		for (int j = 0; j < n; ++j) retVal[i][j] = iv;
	}
	return(retVal);
}

double **matrix_biased_allocate(int m, int n, double iv) {
	double **retVal = matrix_allocate(m,n,iv);

	retVal[m-1][n-1] = 1.0;
	return(retVal);
}

double **matrix_allocate_identity(int m) {
	double **retVal = matrix_allocate(m,m,0.0);
	for (int i = 0; i < m; ++i) retVal[i][i] = 1.0;
	return(retVal);
}

void matrix_free(double **m) {
	if (m) {
		if (m[0]) delete[] m[0]; m[0] = NULL;
		delete[] m;
	}
	m = NULL;
}

void matrix_dump_mathematica(FILE *fp, const char *variable, int m, int n, const double * const *A) {
	fprintf(fp,"%s = {", variable);
	for (int i = 0; i < m; ++i) {
		if (i) fprintf(fp,",");
		fprintf(fp,"\n	{");
		for (int j = 0; j < n; ++j) {
			if (j) fprintf(fp,",");
			fprintf(fp," %.7f",A[i][j]);
		}
		fprintf(fp," }");
	}
	fprintf(fp,"\n};\n");
}

void matrix_dump_mathematica(FILE *fp, const char *variable, int m, const double *v) {
	fprintf(fp,"%s = {", variable);
	for (int i = 0; i < m; ++i) {
		if (i) fprintf(fp,",");
		fprintf(fp," %.7f",v[i]);
	}
	fprintf(fp,"};\n");
}

double *vector_allocate(int m, double iv) {
	double *retVal = new double[m];
	for (int i = 0; i < m; ++i) retVal[i] = iv;
	return(retVal);
}

double *vector_biased_allocate(int m, double iv) {
	double *retVal = vector_allocate(m,iv);
	retVal[m-1] = 1.0;
	return(retVal);
}

void vector_free(double *m) {
	if (m) delete[] m; m = NULL;
}

void vector_dump_mathematica(FILE *fp, const char *variable, int n, const double *A) {
	fprintf(fp,"%s = {", variable);
	for (int j = 0; j < n; ++j) {
		if (j) fprintf(fp,",");
		fprintf(fp," %.7f",A[j]);
	}
	fprintf(fp,"};\n");
}

void matrix_multiply(int am, int an, const double *const *A, int bm, int bn, const double * const *B, int abm, int abn, double **AB) {
	assert(an == bm);
	assert(am = abm);
	assert(bn == abn);
	for (int i = 0; i < am; ++i) {
		for (int j = 0; j < bn; ++j) {
			AB[i][j] = 0.0;
			for (int k = 0; k < bm; ++k) AB[i][j] += A[i][k] * B[k][j];
		}
	}
}

void matrix_multiply(int am, int an, const double *const *A, int bm, const double *B, int abm, double *AB) {
	assert(an == bm);
	assert(am == abm);
	for (int i = 0; i < abm; ++i) {
		AB[i] = 0.0;
		for (int j = 0; j < an; ++j) AB[i] += A[i][j] * B[j];
	}
}

void matrix_copy(int am, int an, double **Acpy, int bm, int bn, const double * const *A) {
// A and Acpy must have the same size.
	assert(am == bm);
	assert(an == bn);

	for (int i = 0; i < am; ++i)
		for (int j = 0; j < an; ++j) Acpy[i][j] = A[i][j];
}

static inline void swapdouble(double& a, double& b) {
	double swap = a;
	a = b;
	b = swap;
}

void matrix_inverse(int am, int an, const double *const *A, int bm, int bn, double **Ainverse) {
// A and A inverse must both be square and have the same size.
	assert(am == an);
	assert(bm == bn);
	assert(am == bm);
	assert(an == bn);

	matrix_copy(bm, bn, Ainverse, am, an, A); // Ainverse = A

// Now, do gaussj (NRC: pp 39) for Ainverse.
	{
		int *indxc, *indxr, *ipiv;
		int i, icol = 0, irow = 0, j, k, l, ll;
		double big, dum, pivinv;

		double **a = Ainverse;
		double **b = matrix_allocate(am,1,0.0);
		int n = am;
		int m = 1;

		indxc = new int[n];
		indxr = new int[n];
		ipiv = new int[n];

		for (j = 0; j < n; ++j) ipiv[j] = 0.0;
		for (i = 0; i < n; ++i) {
			big = 0.0;
			for (j = 0; j < n; ++j) {
				if (ipiv[j] != 1) {
					for (k = 0; k < n; ++k) {
						if (ipiv[k] == 0) {
							if (fabs(a[j][k]) >= big) {
								big = fabs(a[j][k]);
								irow = j;
								icol = k;
							}
						}
					}
				}
			}
			++ipiv[icol];
			if (irow != icol) {
				for (l = 0; l < n; ++l) swapdouble(a[irow][l],a[icol][l]);
				for (l = 0; l < m; ++l) swapdouble(b[irow][l],b[icol][l]);
			}
			indxr[i] = irow;
			indxc[i] = icol;
			if (a[icol][icol] == 0.0) {
				fprintf(stderr,"%s: %d: %s: a[%d][%d] == 0.0: singular matrix.\n",__FILE__,__LINE__,__PRETTY_FUNCTION__,icol,icol);
				assert(a[icol][icol] != 0.0);
			}
			pivinv = 1.0 / a[icol][icol];
			a[icol][icol] = 1.0;
			for (l = 0; l < n; ++l) a[icol][l] = a[icol][l] * pivinv;
			for (l = 0; l < m; ++l) b[icol][l] = b[icol][l] * pivinv;

			for (ll = 0; ll < n; ++ll) {
				if (ll != icol) {
					dum = a[ll][icol];
					a[ll][icol] = 0.0;
					for (l = 0; l < n; ++l) a[ll][l] = a[ll][l] - a[icol][l] * dum;
					for (l = 0; l < m; ++l) b[ll][l] = b[ll][l] - b[icol][l] * dum;
				}
			}
		}
		for (l = (n-1); l >= 0; --l) {
			if (indxr[l] != indxc[l]) {
				for (k = 0; k < n; ++k) {
					swapdouble(a[k][indxr[l]],a[k][indxc[l]]);
				}
			}
		}

		delete[] ipiv; ipiv = NULL;
		delete[] indxr; indxr = NULL;
		delete[] indxc; indxc = NULL;
		matrix_free(b); b = NULL;
	}

}

void matrix_mass_assign(int am, int an, double **A, double v) {
	for (int i = 0; i < am; ++i) {
		for (int j = 0; j < an; ++j) A[i][j] = v;
	}
}

void matrix_transpose(int am, int an, const double *const *A, int bm, int bn, double **Atranspose) {
	assert(am == bn);
	assert(an == bm);

	for (int i = 0; i < am; ++i) {
		for (int j = 0; j < an; ++j) Atranspose[j][i] = A[i][j];
	}
}
