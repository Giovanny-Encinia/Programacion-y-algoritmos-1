//Giovanny Encinia
//31/08/2021
#include <stdio.h>
#include "functions.h"
#define ZERO 0
#define ONE 1
#define SIZE 20

int main()
{
    int a[SIZE], b[SIZE], c[SIZE + SIZE];
    int a_c[SIZE], b_c[SIZE];
    int tamanio_1, tamanio_2;
    char option;

    printf("\t\t****Primer arreglo****\n");
    tamanio_1 = write_copia_comprueba(a, a_c);

    if(!tamanio_1)
        return ZERO;

    printf("\t\t****Segundo arreglo****\n");
    tamanio_2 = write_copia_comprueba(b, b_c);

    if(!tamanio_2)
        return ZERO;

    printf("\t\tEl arreglo a[] es \n");
    print_array(a, tamanio_1);

    printf("\t\tEl arreglo b[] es \n");
    print_array(b, tamanio_2);


    merge(a, tamanio_1, b,\
           tamanio_2, c, tamanio_1+tamanio_2);

    printf("\t\tEl arreglo merge es: \n");
    print_array(c, tamanio_1 + tamanio_2);

    printf("\t\tDesea ordenar en \
orden creciente?(si: 1, no: other)\n\t\t");
    scanf(" %c", &option);

    if(option == '1')
    {
        merge_sort(c, ZERO,\
        tamanio_1 + tamanio_2 - ONE, ONE);
        printf("\t\tEl arreglo ordenado es\n");
        print_array(c, tamanio_1+tamanio_2);
    }

    return ZERO;
}
