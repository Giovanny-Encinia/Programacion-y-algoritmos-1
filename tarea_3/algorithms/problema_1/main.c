#include <stdio.h>
#define TEN 10
#define ONE 1
#define ZERO 0

long potencia(int number, int  n)
{
    /*Una funcion para efectuar la potencia de un numero
    unicamente se le da el numero y la potencia a elevar*/

    int  i = ZERO;
    long result = ONE;

    while(i < n)
    {
        result *= number;
        i++;
    }

    return result;
}

long invierte_numero(long n_number)
{

    long resultado, ten, sum = ZERO;
    int i = ZERO, j = ZERO;

    ten = TEN;

    //encuentra el numero de veces que debe ser dividido
    //por diez para poder llegar a una unidad con el primer digito
    resultado = n_number / ten;

    while(resultado != ZERO)
    {
        // el ultimo evento es cuando ten hace que halla decimales
        ten *= TEN;
        resultado = n_number / ten;
        i++;

    }

    ten /= TEN; // regresa a cuando ten deja una unidad

    while(j <= i)
    {
        resultado = n_number / ten; // obtener los digitos
        // n_number es el resto despues de obtener el digito
        // ahora ten debe ser menor ej. antes eran centenas,
        //ahora decenas las que se obtendran
        n_number %= ten;

        ten /= TEN;
        //cada uno de los dijitos multiplicalos por la potencia
        //correspondiente de diez
        //de tal manera que see  vayan inviertiendo los numeros
        sum += resultado * potencia(TEN, j++);
    }

    // al final solo nos falta agregar la unidad la cual sera
    //el ultimo numero n_number
    // que es el resultado del modulo del numero original entre
    //la potencia mas grande que deja
    // la unidad y asi se invierte el numero
    sum += n_number * potencia(TEN, j);

    return sum;
}

int main()
{
    long number, invertido;

    printf("\t\tIngrese un numero positivo\n");
    scanf("%ld", &number);
    invertido =  invierte_numero(number);
    printf("\n\tEl numero es %ld\n", number);
    printf("\tEl numero invertido es %ld\n", invertido);

    if(number == invertido)
    {
        printf("\t%ld es palindromo\n", number);
    }
    else
    {
        printf("\tNo es palindromo u.u\n");
    }

    return ZERO;
}
