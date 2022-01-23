/*Giovanny Encinia*/
#include <stdlib.h>
#include <stdio.h>
#include "metricas_estadisticas/medidas_central.h"
#define ZERO 0
#define ONE 1
#define NINE 9

double **moving_3_3(double **matrix, int m, int n, double (*f)(double *array, int size))
{
    int i, j, k, l, r, size = NINE;
    double value;
    double *array = (double *)malloc(NINE * sizeof(double));
    double **mat = (double **)malloc(m * sizeof(double *));

    /*en esta matriz se guardaran los resultados*/
    *mat = (double *)malloc(m * n * sizeof(double));

    /*separa espacio en memoria*/
    for(i=ONE; i < m; i++)
    {
        *(mat + i) = *(mat + i - ONE) + n;
    }

    /*llena los laterales*/
    for(j =ZERO; j < n; j++)
    {
        *(*(mat) + j) = *(*(matrix) + j);
        *(*(mat + m - ONE) + j) = *(*(matrix + m - ONE) + j);
    }

    /*llenado dela parte superior e inferior*/
    for(i = ONE; i< m - ONE; i++)
    {
        **(mat + i) = **(matrix + i);
        *(*(mat + i) + n - ONE) = *(*(matrix + i) + n - ONE);
    }


    for(i = ZERO; i <= m - 3; i++)
    {

        for(j = ZERO; j <= n - 3; j++)
        {
            r = ZERO;

            /*simula la matriz 3 x 3*/
            for(k=i; k < i + 3; k++)
            {
                for(l=j; l < j + 3; l++)
                {
                    *(array + r) = *(*(matrix + k) + l);
                    r++;
                }
            }/*termina de recorrer matriz 3x3*/

            value = f(array, size);
            *(*(mat + i + ONE) + j + ONE) = value;

        }
    }

    return mat;
}
