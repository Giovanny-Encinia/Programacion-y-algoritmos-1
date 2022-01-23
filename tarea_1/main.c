//Giovanny Encinia
//17 agosto 2021
//suma de fracciones

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>
#include <string.h>
#define ZERO  0
#define ONE 1
#define TAMANIO 24
#define TAMANIO_2 12
#define TEN 10


int mcd(long a, long b);
int separador_input(char  *nombre, char *forma, int termino);

long a, b, c, d; // variable global, se almacenan los inputs



int mcd(long a, long b)
{
    /*Encuentra el maximo comun divisor de dos numeros*/
    long temp;

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

int separador_input(char  *nombre, char *forma, int termino)
{
    /*Esta funcion separa el numerador y el denominador del input
    tomando en cuenta que existe el simbolo /
    si hay mas de este simbolo o algun caracter que no
    sea un entero, pide al usuario que ingrese de nuevo
    los datos

    Parametros
    ===========
    char *nombre: hace referencia el termino de la suma, primer o segundo
    cahr *forma: pide datos a/b o c/d
    int termino: un flag para saber donde guardar el resultado

    Return
    =========
    int ciclo: retorna 1 o 0, si el caracter no esta permitido retorna 1
    */
    int count_slash = ZERO, ciclo = ONE;
    int index_sep;
    int aprobado_1 = ONE, aprobado_2 = ONE;
    char x[TAMANIO], x_1[TAMANIO_2], x_2[TAMANIO_2];
    int i = ZERO, j = ZERO, k = ZERO;

    count_slash = ZERO;
    printf("Ingrese la %s fraccion en la forma %s\n", nombre, forma);
    scanf("%s", x);


    while(x[i] != '\0') //recorre la cadena
    {

        if(x[i] == '/') //  busca el / para separar denom y num
        {
            count_slash++; // cuenta cuantos slash hay
            index_sep = i; // guarda el indice del /
        }

        i++;
    }

    while(j < index_sep)  //se guarda el numerador
    {
        x_1[j] = x[j];

        if(!isdigit(x_1[j]))
        {

            if(j== 0 && x_1[j] == '-') //asegura negativos - al inicio
            {
                aprobado_1 = ONE;
            }
            else
            {
                aprobado_1 = ZERO;
            }

        }

        j++;
    }

    x_1[j] = '\0';
    j++;

    while(x[j] != '\0') // lo que queda del original
    {

        x_2[k] = x[j]; // se guarda el denominador

        if(!isdigit(x_2[k]))
        {
            //asegura negativos -
            if((j == index_sep + 1) && (x_2[k] == '-'))
            {
                aprobado_2 = ONE;
            }
            else
            {
                aprobado_2 =ZERO;
            }

        }

        j++;
        k++;

    }
    x_2[k] = '\0';

    if(count_slash != ONE || \
       aprobado_1 == ZERO || aprobado_2 == ZERO)//comprobacion
    {
        ciclo = ONE;
        printf("Ingresa valores validos\n");
    }
    else
    {
        ciclo = ZERO;

        if(termino == ONE)
        {
            a = (long) strtol(x_1, NULL, TEN);
            b = (long) strtol(x_2, NULL, TEN);
        }
        else
        {
            c = (long) strtol(x_1, NULL, TEN);
            d = (long) strtol(x_2, NULL, TEN);
        }

    }
    return   ciclo;
}

int main()
{
    int ciclo = ONE;
    long numerador, denominador, divisor;

    while(ciclo)
    { // mientras haya inconsistencias ciclo
        ciclo = separador_input("primera", "a/b", ONE);

        if(ciclo == ONE)
        {
            continue;
        }

        ciclo += separador_input("segunda", "c/d", 2);
    }

    numerador = a * d + b * c;
    denominador = b * d;
    // lo usaremos para simplificar
    divisor = mcd(fabs(numerador), fabs(denominador));
    numerador /= divisor;
    denominador /= divisor;

    printf("\n==============================================\
========================\n");
    printf("\n                       \
%ld/%ld + %ld/%ld = \%ld/%ld\n\n", \
           a, b, c, d, numerador, denominador);
    printf("==================================================\
====================\n");

    return 0;
}
