#include <stdio.h>
#include <stdlib.h>
#include "moving_3_3.h"
#include "print_read/io_matrix.h"

int main()
{
    int m , n;
    double **matrix_c, **matrix, **matrix2;
    double (*f)(double*, int);
    double (*f_medi)(double*, int);

    f = &promedio;
    f_medi = &mediana;

    matrix = read_matrix("matriz.txt", &m, &n);
    printf("La matriz original es:\n");
    imprimir_matrix(matrix, m, n);
    matrix_c = moving_3_3(matrix, m, n, f);
    printf("\nLa matriz generada con los promedios es:\n");
    imprimir_matrix(matrix_c, m, n);

    matrix2 = moving_3_3(matrix, m, n, f_medi);
    printf("\nLa matriz generada con las medianas es:\n");
    imprimir_matrix(matrix2, m, n);

    free_matrix(matrix2);
    free_matrix(matrix);
    free_matrix(matrix_c);

    return ZERO;
}
