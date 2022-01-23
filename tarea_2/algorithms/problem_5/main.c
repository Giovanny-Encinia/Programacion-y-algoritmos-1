//giovanny Encinia
//23-08-2021
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100// terms number of the mclaurin's serie
#define ONE 1
#define  ZERO 0
#define E_R(e_x, result) (fabs(e_x - result)/fabs(e_x))


long factorial(long n, long *memo_fact);
double potencia(long n, double x, double *memo_pot);
double serie(long *memo_fact, double *memo_pot, double x, long n);

long factorial(long n, long *memo_fact)
{
    /*Calcula el factorial de manera recursiva
    Parametros
    ===========
    n: termino del factorial
    memo_fact: es el arreglo donde se guardaran los resultados*/

    double result;

    if(memo_fact[n])
    {
        result = memo_fact[n];
    }
    else
    {
        result = n * factorial(n - ONE, memo_fact);
    }

    memo_fact[n] = result;

    return result;
}

double potencia(long n, double x, double *memo_pot)
{

    /*Calcula la potencia de manera recursiva
    Parametros
    ===========
    n: termino del factorial
    x: es el numero que se estara elevando
    memo_pot: es el arreglo donde se guardaran los resultados

    */

    double result;


    if(memo_pot[n])
    {

        result = memo_pot[n];
    }
    else
    {
        result = potencia(n - ONE, x, memo_pot) * x;

    }

    memo_pot[n] = result;
    return result;

}

double serie(long *memo_fact, double *memo_pot, double x, long n)
{
    /*Calcula la serie, esta esta limitada a SIZE/2 terminos*/

    long i = 0;
    double result;

    while(i <= n)
    {
        if(i % 2 == 0)
        {
            result += potencia(2*i, x, memo_pot) / factorial(i, memo_fact);
        }
        else
        {
            result -= potencia(2*i, x, memo_pot) / factorial(i, memo_fact);
        }

        i++;
    }

    return result;

}

int main(void)
{
    long *memo_fact = (long *)calloc(SIZE, sizeof(long));
    double *memo_pot = (double *)calloc(SIZE, sizeof(double));

    double x, result, real;
    long n;

    if(memo_fact == NULL || memo_pot == NULL)
    {
        printf("Memoria llena");
        return ZERO;
    }
    else
    {
        //inicializa los arreglos
        memo_fact[ONE] = memo_fact[ZERO] = ONE;
        memo_pot[ZERO] = ONE;

        printf("Ingrese el valor de x a evaluar\n");
        scanf("%lf", &x);

        real = exp(-pow(x, 2)); // calcula el valor "real"
        printf("Ingrese el numero de iteraciones a realizar\n");
        scanf("%ld", &n);
        printf("\n\n");
        result = serie(memo_fact, memo_pot, x, n);
        printf("El resultado real es: %.7f\n", real);
        printf("El resultado de la serie es: %.7f\n", result);
        printf("El error relativo es: %.13f\n" , E_R(real, result));
    }

    free(memo_fact);
    free(memo_pot);

    return ZERO;
}
