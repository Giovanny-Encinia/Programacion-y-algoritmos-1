#ifndef IOMATRIX
#define IOMATRIX
double **read_matrix(char *name, int *m_c, int *n_c);
void imprimir_matrix(double **matrix, int m, int n);
void free_matrix(double **matrix);
#endif /*IOMATRIX*/
