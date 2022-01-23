//Giovanny Encinia
// 23-08-2021
#include <stdio.h>
#include <stdlib.h>

void resultado(int a,  int b, char operation, int c, int d, \
               int resul, int denom)
{
    /*Funcion para imprimir el resultado*/

    printf("====================================================\n\n");
    printf("          %d/%d%c%d/%d = %d/%d\n\n"\
           , a, b, operation, c, d, resul, denom);
    printf("====================================================\n");
}

int main(void)
{
    int a, b, c, d;
    char div_1, operation, div_2;

    printf("Ingresa operacion fracciones (+, -, *, /)\n");
    printf("a/b o c/b\n");
    scanf(" %d %c %d %c %d %c %d"\
        , &a, &div_1, &b, &operation, &c, &div_2, &d);

    if(b != d)
    {
        printf("Ingresa un valor de denominadores igual\n");
    }

    if(div_1 == '/' && div_2 == '/')
    {
        switch(operation)
        {

            case '+':
                resultado(a, b, operation, c, d, a+c, b);
                break;
            case '-':
                resultado(a, b, operation, c, d, a-c, b);
                break;
            case '*':
                resultado(a, b, operation, c, d, a*c, b * b);
                break;
            case '/':
                resultado(a, b, operation, c, d, a, c);
                break;
            default:
                printf("Ingresa un valor valido\n\n");
        }

        }
    else
        {
            printf("Ingresa valores validos\n\n");

        }

    return 0;
}
