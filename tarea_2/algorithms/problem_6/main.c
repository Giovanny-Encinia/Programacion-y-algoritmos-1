//Giovanny Encinia
//24-08-2021
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ZERO 0
#define SIZE 31
#define CORRE 48 //corresponde al simbolo 1 en ANSI
#define CORRE_2 55// suma7 para llegar a A

void conversion(int number, int base);

void conversion(int number, int base)
{

    int i = ZERO;
    int arreglo[SIZE];

    printf("El numero %d en base %d es:\n", number, base);

    while(number >  ZERO)
    {

        arreglo[i] = number%base;
        number /= base;
        i++;
    }

    i--;



        while(i >= ZERO)
    {
        if(arreglo[i] > 9)
            printf("%c", arreglo[i] +  CORRE_2);
        else
            printf("%c", arreglo[i] +  CORRE);
        i--;
    }

}

int main(void)
{
    int i = ZERO, base, number;
    int *result;

    printf("Ingresa el  numero a transformar\n");
    scanf("%d", &number);
    printf("Ingresa la base en la que se requiere transformar\n");
    scanf("%d", &base);
    printf("\n");
    conversion(number, base);
    printf("\n");

    return ZERO;
}
