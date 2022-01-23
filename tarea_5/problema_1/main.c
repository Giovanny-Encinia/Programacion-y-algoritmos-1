#include <stdio.h>
#include <stdlib.h>
#include "funciones_a_b_c.h"
#include "strings_.h"
#define SIZE 100

void imprime_a(void)
{
    char palabra[SIZE];
    char str[SIZE];
    int valor;

    printf("Busqueda de palabras en una frase\n");
    printf("========================================\n");
    printf("Ingresa la frase donde se buscara\n");
    fgets(palabra, SIZE, stdin);
    printf("\n");
    printf("Ingresa la palabra o caracter que\
 se buscara en tu frase\n");
    fgets(str, SIZE, stdin);
    printf("\n");
    valor = count_word(palabra, str);
    printf("El numero de apariciones es %d\n", valor);
    printf("========================================\n\n");

}

void imprime_b(void)
{
    int i=ZERO;
    char a[SIZE];
    char c[SIZE];
    char **token;

    printf("\nSeparador de palabras\n");
    printf("========================================\n");
    printf("Ingresa la frase\n");
    fgets(a, SIZE, stdin);
    printf("\n");
    printf("Ingresa el separador que se utilizara\n");
    fgets(c, SIZE, stdin);
    token = tokens(a, *(c));

    printf("Los token separados por '%c' son\n", *c);
    while(*(token + i) != NULL)
        printf("%s\n", *(token + i++));
    printf("========================================\n\n");
}

void imprime_c(void)
{
    char palabra[SIZE];
    char str[SIZE];
    char *first, *second;

    printf("\nConcatena palabras\n");
    printf("========================================\n");
    printf("Ingresa la primera palabra\n");
    fgets(palabra, SIZE, stdin);
    printf("\n");
    printf("Ingresa la segunda palabra\n");
    fgets(str, SIZE, stdin);
    printf("\n");
    first = str_to_dynamic(palabra);
    second = str_to_dynamic(str);

    first = concatena(first, second);
    printf("La palabra concatenada es\n%s\n", first);
    printf("========================================\n\n");
    free(first);

}

int main(void)
{
    imprime_a();
    imprime_b();
    imprime_c();

    return ZERO;
}
