#include <stdio.h>
#include <stdlib.h>
#ifndef ZERO
#define ZERO 0
#endif /*ZERO*/

#ifndef ONE
#define ONE 1
#endif /*ONE*/

void free_matrix(double **matrix)
{
    free(*(matrix));
    free(matrix);

}

double **read_matrix(char *name, int *m_c, int *n_c)
{
    int m, n, i, j;
    double **matrix;
    FILE* file = fopen(name, "r");

    fscanf(file, "%d %d", &m, &n);
    *m_c = m;
    *n_c = n;

    matrix = (double **)malloc(m * sizeof(double *));

    if(matrix == NULL)
    {
        printf("Memory full");
        return NULL;
    }

    *matrix = (double *)malloc(m * n * sizeof(double));

    /*se reserva espacio en memoria para cada fila*/
    for(i = ONE; i < m; i++)
    {
        *(matrix + i) = *(matrix + i - ONE) + n;
    }

    /*se llena memoria*/
    for(i=ZERO; i < m; i++)
    {

        for(j=ZERO; j < n; j++)
        {
            fscanf(file, "%lf", (*(matrix + i) + j));

        }

    }

    return matrix;

}

void imprimir_matrix(double **matrix, int m, int n)
{
    int i, j;

    for(i=ZERO; i< m; i++)
    {
        for(j=ZERO;j<n;j++)
        {
            printf("%lf ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

}
