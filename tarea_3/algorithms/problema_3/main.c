#include <stdio.h>
#define ZERO 0
#define ONE 1
#define SIZE 50

void products(int [], int [], int lenght);
void print_array(int a[], int lenght);

void print_array(int ar[], int lenght)
{
    /*funcion que umprime el arreglo*/
    int i = 0;

    printf("\t\t");
    while(i < lenght)
    {
        printf("%d ",ar[i++]);
    }

    printf("\n\n");
}

void products(int a[], int product[], int lenght)
{
    int i = 0;

    //el primer elemento de product es el
    //primer elemento de a
    product[i] = a[i];
    i++;

    while(i < lenght)
    {
        // el elemento anterior de prod
        // por el elemento equi de a
        product[i] = product[i - ONE] * a[i];
        i++;
    }

    printf("\t\tEl arreglo original es:\n");
    print_array(a, lenght);
    printf(\
    "\t\tEl arreglo con producto acumulado es:\n");
    print_array(product, lenght);
}

int main()
{
    int a[SIZE], tamanio, product[SIZE], i = 0;

    printf("\t\tCuantos elementos tendra \
el arreglo (maximo 50)?\n");
    scanf(" %d", &tamanio);

    while(i < tamanio)
    {
        printf("Agregue el elemento %d\n", i);
        scanf(" %d", &a[i++]);
    }

    products(a, product, i);

    return ZERO;
}
