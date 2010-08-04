#ifndef SVDCMP_H
#define SVDCMP_H

void svdcmp(double *a[], int m, int n, double w[], double *v[]);
void svbksb(const double * const *u, const double w[], const double * const *v, int m, int n, const double b[], double x[]);
void just_svd(const double * const *a, int n, const double b[], double x[]);
void just_svd(const double * const *a, int n, int m, const double b[], double x[]);
void invert_matrix(const double *const *a, double **y, int n);

void linear_weights(int K, int M, const double *const *X, int D, double **W, const double *const *Y);

#endif
