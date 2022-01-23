//Giovanny Encinia
//24-08-2021
#include <stdio.h>
#include <stdlib.h>
#define ZERO 0

int mcd(int a, int b);

int mcd(int a, int b)
{
    /*Encuentra el maximo comun divisor de dos numeros*/
    int temp;

    if(b == ZERO)
    {
        return a;
    }

    else
    {
        if(b > a)
        {
            temp = a;
            a = b;
            b = temp;
        }
        return mcd(b, a % b);
    }
}

int main(void)
{
    int a, b, den;
    char div;

    printf("Ingrese una fraccion de la forma a/b\n");
    scanf(" %d %c %d", &a, &div, &b);

    if(div != '/')
    {
        printf("Ingrese una valor valido\n");
        printf("Fraccion en la  forma a/b\n");

        return 0;
    }

    den = mcd(a, b);
    printf("=================================================\n");
    printf("       %d/%d = %d/%d\n",  a, b, a/den, b/den);
    printf("=================================================\n");

    return 0;
}
