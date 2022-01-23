//Giovanny Encinia
//30/08/2021
#include <stdio.h>
#define ZERO 0
#define ONE 1
#define SIZE 10
#define LEN(a) (sizeof(a) / sizeof(a[ZERO]))

void push(int);
int pop(void);
void imprime(void);
int is_full(void);
int is_empty(void);

int a[SIZE];
int n = ZERO; // servira para controlar el stack

int is_full(void)
{
    /*Comprueba que el stack esta vacio,
     esto con ayuda de la
    variable global n*/

    if(n == SIZE)
    {
        return ONE;//verdadero
    }
    else
    {
        return ZERO;//falso
    }
}

int is_empty(void)
{
    /*Comprueba que el stack este lleno,
     esto con ayuda de la
    variable global n*/

    if(n == ZERO)
    {
        return ONE;
    }
    else
    {
        return ZERO;
    }
}

void push(int number)
{
    if(!is_full())
    {
        a[n] = number;
        n++; // actualiza el estado del stack
    }
    else
    {
        printf("\t\tEl arreglo ya esta\
lleno, imposible hacer push\n");
    }

}

int pop(void)
{
    int number;
    if(!is_empty())
    {
        number = a[n - ONE];
        n -= ONE; // actualiza el estado del stack
    }
    else
    {
        printf("\t\tEl arreglo ya esta\
vacio imposible hacer pop, regresara 0\n");
        return ZERO;
    }

    return number;
}

void imprime(void)
{
    int i = ZERO;

    printf("\t\tEl stack tiene %d \
elementos:\n\t\t", n);

    while(i < n)
    {
        printf("%d ", a[i]);
        i++;
    }

    printf("\n\n");
}

int main(void)
{
    int i = ZERO;

    while(i < SIZE + ONE)
    {
        printf("\t\tpush al valor %d\n", i*3);
        push(i*3);
        imprime();
        i++;
    }

    printf("\t\tpop al valor %d\n", pop());
    imprime();
    printf("\t\tpop al valor %d\n", pop());
    printf("\t\tpop al valor %d\n", pop());
    printf("\t\tpop al valor %d\n", pop());
    push(i++);
    imprime();

    return ZERO;

}
