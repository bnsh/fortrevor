#ifndef MATRIX_H
#define MATRIX_H

/* This will just be a set of utilities that I've found useful when doing linear algebra
 * Probably matrix multipliers, matrix addition, ... whatever I find useful
 * We will stick to straight C and array manipulation in the interests of speed. But,
 * it will still be C++, in that it _will_ use some function overloading.
 */

double **matrix_allocate(int m, int n, double initial_value);
double **matrix_biased_allocate(int m, int n, double initial_value);
double **matrix_allocate_identity(int m);
void matrix_free(double **m);
void matrix_dump_mathematica(FILE *fp, const char *variable, int m, int n, const double * const *A);
void matrix_dump_mathematica(FILE *fp, const char *variable, int m, const double *v);

double *vector_allocate(int m, double inital_value);
double *vector_biased_allocate(int m, double inital_value);
void vector_free(double *v);
void vector_dump_mathematica(FILE *fp, const char *variable, int m, const double *v);

// this will multiply the amXan A matrix by the bmxbn B matrix, and place the result in AB
// Because, matrix multiplication _requires_ an == bm, if this is _not_ so,
// it will abort.
void matrix_multiply(int am, int an, const double * const *A, int bm, int bn, const double * const *B, int abm, int abn, double **AB);
void matrix_multiply(int am, int an, const double * const *A, int bm, const double *B, int abm, double *AB);

void matrix_copy(int am, int an, double **Acpy, int bm, int bn, const double * const *A);
void matrix_inverse(int am, int an, const double * const *A, int bm, int bn, double **Ainverse);
void matrix_transpose(int am, int an, const double * const *A, int bm, int bn, double **Atranspose);

void matrix_mass_assign(int am, int an, double **A, double v);

#endif
