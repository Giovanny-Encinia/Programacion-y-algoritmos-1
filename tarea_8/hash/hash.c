#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include "hash.h"
#include "../arboles_binarios/funciones.h"
#define FUNCTION(a, b) ((a)%(b))

HASH *crear_tabla(char *name, int tamanio)
{
    /*Funcion que crea la estrictura general de una tabla
    tipo HASH
    Parametros
    ===========
    char *name: el nombre que recibe la tabla
    int tamanio: el numero de elementos que tiene la tabla*/
    int i;
    HASH *tabla = (HASH *)malloc(sizeof(HASH));

    if(tabla == NULL)
    {
        printf("No se puede crear la tabla\nError: %d\n", errno);
        return NULL;
    }

    tabla->name = name;
    tabla->tamanio = tamanio;
    tabla->datos = (ARBOL **)malloc(tamanio * sizeof(ARBOL *));

    /*a cada elemento de la tabla se le agrega la estructura
    general de un arbol*/
    for(i = ZERO; i < tamanio; i++)
    {
        tabla->datos[i] = crear_arbol();
    }

    return tabla;
}

void eliminar_tabla(HASH *tabla)
{
    /*Funcion que libera memoria de toda la tabla HASH
    Parametros
    ==========
    HASH *tabla: la tabla hash que se eliminara*/

    int i;

    /*se debe eliminar cada arbol asociado a cada
    elemento de la tabla*/
    for(i = ZERO; i < tabla->tamanio; i++)
    {
        eliminar_arbol(tabla->datos[i]);
    }

    free(tabla);
}

void agregar_elemento_tabla(HASH *tabla, int number)
{
    /*Funcion que agrega un elemento a la tabla hash
    se utiliza el modulo para hacer la asignacion
    Parametros
    ===========
    HASH *tabla: es la tabla hash donde se aplica la funcion
    int number: es el numero que se agregara a la tabla*/

    insertar_nodo(tabla->datos[FUNCTION(number, tabla->tamanio)], number);
}

void eliminar_elemento_tabla(HASH *tabla, int number)
{
    /*Funcion que elimina un elemento de algun arbol
    contenido en la tabla HASH
    Parametros
    ===========
    HASH *tabla: es la tabla hash en donde se aplica la funcion
    int number: es el numero que se eliminara*/

    eliminar_nodo(tabla->datos[FUNCTION(number, tabla->tamanio)], number);
}

void imprimir_tabla(HASH *tabla)
{
    /*Funcion que imprime la yabla hash, con sus
    respectivos arboles
    Parametros
    ===========
    HASH *tabla: es la tabla hash que se va a imprimir*/

    int i;
    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n");
    printf("|%50s%57s\n", tabla->name, "|");
    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n");
    printf("|%8s|%10s|%37s%50s\n", "INDEX", "TAMANIO", "ELEMENTOS", "|");
    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n");

    for(i = ZERO; i < tabla->tamanio; i++)
    {
        printf("|%8d|%10d|\t", i, tabla->datos[i]->tamanio);
        imprimir_arbol(tabla->datos[i]->tronco);
        printf("\n");
    }

    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n\n");

}

void imprime_arbol_deeper(HASH *tabla)
{
    /*Funcion que imprime el arbol mas profundo, dentro de la
    tabla hash
    Parametros
    ===========
    HASH *tabla: es la tabla de donde se buscara el arbol*/

    int i, maxi, index;

    /*Calcula la profundidad de cada arbol*/
    for(i = ZERO; i < tabla->tamanio; i++)
        tabla->datos[i]->profundidad = profundidad(tabla->datos[i]->tronco);

    maxi = tabla->datos[ZERO]->profundidad;

    /*busca el arbol que tenga mayor profundidad*/
    for (i = ZERO; i < tabla->tamanio; i++)
    {

        if (tabla->datos[i]->profundidad >= maxi)
        {
            maxi = tabla->datos[i]->profundidad;
            index = i;
        }

    }

    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n");
    printf("|%50s%57s\n", "Arbol mas profundo", "|");
    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n");
    printf("|%8s|%8s|%12s|%19s%57s\n", "INDEX", "TAMANIO","PROFUNDIDAD", "ELEMENTOS", "|");
    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n");
    printf("|%8d|%8d|%12d| ", index, tabla->tamanio,tabla->datos[index]->profundidad);
    imprimir_arbol(tabla->datos[index]->tronco);
    printf("\n");
    printf("+-----------------------------------------------------");
    printf("-----------------------------------------------------+\n\n");
}

void llenar_tabla_random(HASH *tabla)
{
    /*Funcion que genera numeros aleatoriamente y 
    los agrega a la tabla hash*/
    int number, i;
    srand(time(NULL));

    for(i = ZERO; i < 30; i++)
    {
        /*se llena con numeros del 0 al 199*/
        number = rand()%200;
        agregar_elemento_tabla(tabla, number);
    }

}