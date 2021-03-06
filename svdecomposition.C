#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "svdecomposition.H"

static double pythag(double a, double b) {
	double absa, absb;
	absa = fabs(a);
	absb = fabs(b);
	if (absa > absb) return(absa*sqrt(1.0+(absb/absa)*(absb/absa)));
	else return(absb == 0.0 ? 0.0 : absb*sqrt(1.0+(absa/absb)*(absa/absb)));
}

void svdcmp(double *a[], int m, int n, double w[], double *v[]) {
	int flag, i, its, j, jj, k, l = 0, nm;
	double anorm, c, f, g, h, s, scale, x, y, z;
	double rv1[n];

	g = scale = anorm = 0.0;
	for (i = 0; i < n; ++i) {
		l = 1+i;
		rv1[i] = scale * g;
		g = s = scale = 0.0;

		if (i < m) {
			for (k = i; k < m; ++k) scale = scale + fabs(a[k][i]);
			if (scale) {
				for (k = i; k < m; ++k) {
					a[k][i] = a[k][i] / scale;
					s = s + a[k][i] * a[k][i];
				}
				f = a[i][i];
				// (Basically, multiply sqrt(s) by sign(f)
				// I think the fabs is unneccessary.
				if (f >= 0.0) g = -fabs(sqrt(s));
				else g = fabs(sqrt(s));
				h = f*g-s;
				a[i][i] = f - g;
				for (j = l; j < n; ++j) {
					s = 0.0;
					for (k = i; k < m; ++k) s = s + a[k][i]*a[k][j];
					f = s/h;
					for (k = i; k < m; ++k) a[k][j] = a[k][j] + f * a[k][i];
				}
				for (k = i; k < m; ++k) a[k][i] = a[k][i] * scale;
			}
		}
		w[i] = scale * g;
		g = s = scale = 0.0;
		if (i < m && i != (n-1)) {
			for (k = l; k < n; ++k) scale = scale + fabs(a[i][k]);
			if (scale) {
				for (k = l; k < n; ++k) {
					a[i][k] = a[i][k] / scale;
					s = s + a[i][k] * a[i][k];
				}
				f = a[i][l];
				// (Basically, multiply sqrt(s) by sign(f)
				// I think the fabs is unneccessary.
				if (f >= 0.0) g = -fabs(sqrt(s));
				else g = fabs(sqrt(s));
				h = f*g-s;
				a[i][l] = f - g;
				for (k = l; k < n; ++k) rv1[k] = a[i][k] / h;
				for (j = l; j < m; ++j) {
					s = 0.0;
					for (k = l; k < n; ++k) s = s + a[j][k]*a[i][k];
					for (k = l; k < n; ++k) a[j][k] = a[j][k] + s * rv1[k];
				}
				for (k = l; k < n; ++k) a[i][k] = a[i][k] * scale;
			}
		}

		// Got rid of FMAX.
		double tmp = (fabs(w[i])+fabs(rv1[i]));
		if (anorm <= tmp) anorm = tmp;
	}
	for (i = (n-1); i >= 0; --i) {
		if (i < n-1) { // Pay attention. Differs from NRC.
			if (g) {
				for (j = l; j < n; ++j) v[j][i] = (a[i][j]/a[i][l])/g;
				for (j = l; j < n; ++j) {
					s = 0.0;
					for (k = l; k < n; ++k) s = s + a[i][k] * v[k][j];
					for (k = l; k < n; ++k) v[k][j] = v[k][j] + s*v[k][i];
				}
			}
			for (j = l; j < n; ++j) v[i][j] = v[j][i] = 0.0;
		}
		v[i][i] = 1.0;
		g = rv1[i];
		l = i;
	}
	for (i = ((m < n) ? m : n)-1; i >= 0; --i) {
		l = i+1;
		g = w[i];
		for (j = l; j < n; ++j) a[i][j] = 0.0;
		if (g) {
			g = 1.0 / g;
			for (j = l; j < n; ++j) {
				s = 0.0;
				for (k = l; k < m; ++k) s = s + a[k][i] * a[k][j];
				f = (s / a[i][i]) * g;
				for (k = i; k < m; ++k) a[k][j] = a[k][j] + f*a[k][i];
			}
			for (j = i; j < m; ++j) a[j][i] = a[j][i] * g;
		}
		else for (j = i; j < m; ++j) a[j][i] = 0.0;
		++a[i][i];
	}
	for (k = (n-1); k >= 0; --k) {
		for (its = 0; its < 30; ++its) {
			flag = 1;
			for (l = k; l >= 0; --l) {
				nm = l-1;
				if ((fabs(rv1[l])+anorm) == anorm) {
					flag = 0;
					break;
				}
				if ((fabs(w[nm])+anorm) == anorm) break;
			}
			if (flag) {
				c = 0.0;
				s = 1.0;
				for (i = l; i <= k; ++i) { // Pay attention. I'm not sure about that <=
					f = s * rv1[i];
					rv1[i] = c * rv1[i];
					if ((fabs(f)+anorm) == anorm) break;
					g = w[i];
					h = pythag(f,g);
					w[i] = h;
					h = 1.0 / h;
					c = g * h;
					s = -f * h;
					for (j = 0; j < m; ++j) {
						y = a[j][nm];
						z = a[j][i];
						a[j][nm] = y * c + z * s;
						a[j][i] = z * c - y * s;
					}
				}
			}
			z = w[k];
			if (l == k) {
				if (z < 0.0) {
					w[k] = -z;
					for (j = 0; j < n; ++j) v[j][k] = -v[j][k];
				}
				break;
			}
			if (its == 30) { // We have to abort here. write code. 
			}
			x = w[l];
			nm = k-1;
			y = w[nm];
			g = rv1[nm];
			h = rv1[k];
			f = ((y-z) * (y+z) + (g-h) * (g+h)) / (2.0*h*y);
			g = pythag(f,1.0);
// Blech. SIGN
// Got rid of SIGN.
			double tmp = fabs(g);
			if (f < 0.0) tmp = -fabs(g);
			f = ((x-z)*(x+z)+h*((y/(f+tmp))-h))/x;
			c = s = 1.0;
			for (j = l; j <= nm; ++j) { // Pay Attention.
				i = j+1;
				g = rv1[i];
				y = w[i];
				h = s*g;
				g = c*g;
				z = pythag(f,h);
				rv1[j] = z;
				c = f/z;
				s = h/z;
				f = x*c + g*s;
				g = g*c - x*s;
				h = y*s;
				y = y * c;
				for (jj = 0; jj < n; ++jj) {
					x = v[jj][j];
					z = v[jj][i];
					v[jj][j] = x*c + z*s;
					v[jj][i] = z*c - x*s;
				}
				z = pythag(f,h);
				w[j] = z;
				if (z) {
					z = 1.0/z;
					c = f*z;
					s = h*z;
				}
				f = c*g + s*y;
				x = c*y - s*g;
				for (jj = 0; jj < m; ++jj) {
					y = a[jj][j];
					z = a[jj][i];
					a[jj][j] = y*c + z*s;
					a[jj][i] = z*c - y*s;
				}
			}
			rv1[l] = 0.0;
			rv1[k] = f;
			w[k] = x;
		}
	}
}

void svbksb(const double * const *u, const double w[], const double * const *v, int m, int n, const double b[], double x[]) {
	int jj,j,i;
	double s;
	double tmp[n];

	for (j = 0; j < n; ++j) {
		s = 0.0;
		if (w[j]) {
			for (i = 0; i < m; ++i) s = s + u[i][j] * b[i];
			s = s / w[j];
		}
		tmp[j] = s;
	}
	for (j = 0; j < n; ++j) {
		s = 0.0;
		for (jj = 0; jj < n; ++jj) s = s + v[j][jj] * tmp[jj];
		x[j] = s;
	}
}

/* This is Binesh's own concoction. */
static void svd_singleround(const double * const *a, int m, int n, const double b[], double x[]) {
// Make a _copy_ of both a and b. u is what gets passwd to svdcmp as a, because
// svdcmp rewrites u into it's "a". never shit where you eat, *sigh* Stupid NRC
	double *u[m];
	for (int i = 0; i < m; ++i) {
		u[i] = new double[n];
		for (int j = 0; j < n; ++j) u[i][j] = a[i][j];
	}

	for (int i = 0; i < n; ++i) x[i] = b[i];

	double w[n];
	double *v[n];
	for (int i = 0; i < n; ++i) {
		w[i] = 0.0;
		v[i] = new double[n];
		for (int j = 0; j < n; ++j) v[i][j] = 0.0;
	}

	svdcmp(u, m, n, w, v);
	double wmax = 0.0;
	for (int i = 0; i < n; ++i) if ((w[i]) > wmax) wmax = (w[i]);
	double wmin = (wmax * 1.0e-15);
	int zeroed = 0;
	for (int i = 0; i < n; ++i) {
		if (w[i] < wmin) {
			w[i] = 0.0;
			zeroed++;
		}
	}
	svbksb(u, w, v, m, n, b, x);

	for (int i = 0; i < m; ++i) { delete[] u[i]; u[i] = NULL; }
	for (int i = 0; i < n; ++i) { delete[] v[i]; v[i] = NULL; }
}

void just_svd(const double * const *a, int n, const double b[], double x[]) { just_svd(a,n,n,b,x); }
void just_svd(const double * const *a, int m, int n, const double b[], double x[]) {
	svd_singleround(a, m, n, b, x);
// Great. But, let's polish it some more, with mprove.

/* I'm leaving this here, in case we get the same bright idea again.
 * We can't polish with ludcmp. Why? Because, the whole point of using
 * svdcmp is because you probably have a singular matrix. ludcmp has
 * a problem with singular matrices. So, you'll get a good answer with
 * svbksb, and then fuck it all up by "refining" it with LU decomposition.
 * -- Addendum 2009-03-29
 * However, we can still use the same _principle_ as mprove, just using svbksb, can't
 * we?
 * So, now we have an x that purports to match a x == b. Call this x "purportedx"
 * a purportedx = actualb
 * purportedx = x + dx, actualb = b + db
 * So,
 * a (x + dx) = b + db eq 1
 * a x + a dx = b + db eq 2
 * a x = b , so subtract this from eq 2 yielding
 * a dx = db
 * solve for dx and add to x, while Transpose[dx] dx > epsilon.
 * We'll call it contaminant, so we're clear whether to add or subtract. (as opposed to "delta")
 */
	double *contaminant_b = new double[m];
	double *contaminant_x = new double[n];
	int done = 1;
	int iters = 100;

	do {
		done = 0;
		for (int i = 0; i < m; ++i) {
			double actual_b = 0.0;
			for (int j = 0; j < n; ++j) {
				actual_b += a[i][j] * x[j];
			}
// b + contaminantb = actualb
//     contaminantb = actualb - b
			contaminant_b[i] = actual_b - b[i];
		}
		svd_singleround(a,m,n,contaminant_b,contaminant_x);

		double cTc = 0.0;
		for (int i = 0; i < n; ++i) {
			x[i] = x[i] - contaminant_x[i];
			cTc = cTc + (contaminant_x[i] * contaminant_x[i]);
		}
		done = (-1e-8 < cTc) && (cTc < 1e-8);
	} while ((!done) && (iters-- > 0));

	delete[] contaminant_b; contaminant_b = NULL;
	delete[] contaminant_x; contaminant_x = NULL;

}

/* This is Binesh's own concoction. */
void invert_matrix(const double * const *a, double **y, int n) {
	double *col = new double[n];
	double *Y = new double[n];
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) col[i] = 0.0;
		col[j] = 1.0;

		just_svd(a,n,col,Y);

		for (int i = 0; i < n; ++i) y[i][j] = Y[i];
	}
	delete[] Y; Y = NULL;
	delete[] col; col = NULL;
}

/*
 * linear_weights will compute
 * the set of weights W that will result in the least error
 * for X . W = Y
 * How? Like so:
 * X . W = Y
 *
 *  T       T
 * X X W = X Y
 *
 *   T  -1  T        T  -1  T
 * (X X)   X X W = (X X)   X Y
 *
 *                   T  -1  T
 *             W = (X X)   X Y
 * This works, because
 * effectively, this is the set of equations that would result from
 * doing the multiplication for
 * X . W - Y = E
 *            T
 * computing E E
 *                  T
 * and multiplying E E by a one vector of appropriate length
 * and differentiating with respect to each component of W.
 * So,
 *     X is of size K x M
 *     W is of size M x D
 *     Y is of size K x D
 */

static double **new_matrix(int r, int c) {
	double **m = new double *[r];
	for (int i = 0; i < r; ++i) {
		m[i] = new double[c];
		for (int j = 0; j < c; ++j) m[i][j] = 0.0;
	}
	return(m);
}

static void free_matrix(double **m, int r, int) {
	for (int i = 0; i < r; ++i) { if (m[i]) delete[] m[i]; m[i] = NULL; }
	delete[] m; m = NULL;
}

static void print_matrix(const char *label, const double * const *m, int r, int c) __attribute__ ((unused));
static void print_matrix(const char *label, const double * const *m, int r, int c) {
	printf("%s = {",label);
	for (int i = 0; i < r; ++i) {
		if (i) printf(",");
		printf("\n	{ ");
		for (int j = 0; j < c; ++j) {
			if (j) printf(", ");
			printf("%.7f",m[i][j]);
		}
		printf(" }");
	}
	printf("\n}\n");
}

static void print_vector(const char *label, const double *v, int cols) __attribute__ ((unused));
static void print_vector(const char *label, const double *v, int cols) {
	if (label) printf("%s = ",label);
	printf("{");
	for (int c = 0; c < cols; ++c) {
		if (c) printf(",");
		printf("%.17f",v[c]);
	}
	printf("}");
	if (label) printf("\n");
}

void linear_weights(int K, int M, const double *const *X, int D, double **W, const double *const *Y) {
/*
	OK, we want the best fit W to solve
		X W == Y.
	So, let's solve this instead. It is what would result from doing this whole dance:
		X W == Y + E
	compute Transpose[E] . E to get the sum of all the squared errors, and differentiate
	with respect to each component in W.
		 T        T
		X X W == X Y
 */
	double **XTX = new_matrix(M,M);

	for (int mt = 0; mt < M; ++mt) {
		for (int m = 0; m < M; ++m) {
			XTX[mt][m] = 0.0;
			for (int k = 0; k < K; ++k) {
				XTX[mt][m] += X[k][mt] * X[k][m];
			}
		}
	}
	double *XTYcolumnd = new double[M];
	double *Wcolumnd = new double[M];
	for (int d = 0; d < D; ++d) {
		for (int m = 0; m < M; ++m) {
			XTYcolumnd[m] = 0.0;
			for (int k = 0; k < K; ++k) {
				XTYcolumnd[m] += X[k][m] * Y[k][d];
			}
		}
		just_svd(XTX,M,XTYcolumnd,Wcolumnd);
		for (int m = 0; m < M; ++m) W[m][d] = Wcolumnd[m];
	}
	delete[] XTYcolumnd; XTYcolumnd = NULL;
	delete[] Wcolumnd; Wcolumnd = NULL;

	free_matrix(XTX,M,M); XTX = NULL;
}
