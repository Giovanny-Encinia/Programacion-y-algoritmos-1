//Giovanny Encinia
// 23-08-2021
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20
#define ZERO 0

void voltea_numero(char *number, int place)
{
    /*funcion recursiva que imprime un numero
    al reves*/

    //mientras no termine el string
    if(number[place] != '\0')
    {
        //recorre el arreglo
        voltea_numero(number, place + 1);
        printf("%c", number[place]);
    }
}

int main(void)
{
    char number[SIZE];
    int i = ZERO;

    printf("Ingresa un numero\n");
    scanf(" %s", number);

    //Comprueba que el valor ingresado es numero
    while(number[i] != '\0')
    {
        if(!isdigit(number[i]))
        {
            printf("El valor ingresado no es un numero\n");
            return ZERO;
        }

        i++;
    }

    printf("El numero al reves es: ");
    voltea_numero(number, ZERO);
    printf("\n");

    return ZERO;
}
