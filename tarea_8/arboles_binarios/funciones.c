#include <stdlib.h>
#include "arboles_binarios.h"
#include <stdio.h>
#ifndef ONE
#define ONE 1
#endif
#ifndef ZERO
#define ZERO 0
#endif

void inserta_recursivo(NODO *tronco, int number)
{
    /*Funcion que inserta los nodos de manera recursiva
    Parametros
    ==========
    NODO *tronco: inicia con el tronco de la estrictura arbol
    al ser un NODO, despues cumple la misma funcion pero para
    subarboles
    int number: es el dato que se agragara*/
    
    if(number > tronco->dato)
    {

        if(tronco->der == NULL)
            tronco->der = crear_nodo(number);
        else
            inserta_recursivo(tronco->der, number);

    }
    else
    {

        if (tronco->izq == NULL)
            tronco->izq = crear_nodo(number);
        else
            inserta_recursivo(tronco->izq, number);

    }

}

void insertar_nodo(ARBOL *arbolito, int number)
{
    /*Funcion que inserta un nodo en un arbol arbol
    Parametros
    ==========
    Nodo *node: es el nodo que se insertara en el arbol
    ARBOL *arbolito: es el arbol donde se inserta*/
    
    if(arbolito->tronco == NULL)
        arbolito->tronco = crear_nodo(number);
    else
        inserta_recursivo(arbolito->tronco, number);

    printf("Se ha creado un nuevo nodo\n");
    
}

void imprimir_arbol(NODO *subarbol)
{
    /*Funcion que utiliza recursion para poder imprimir un nodo
    Parametros
    ===========
    NODO *subarbol: se inicia entregando el tronco de 
    la estructura ARBOL*/

    /*primero imprime lo que esta mas a la
    izquierda*/
    
    if(subarbol->izq == NULL)
    {
        printf("%d ", subarbol->dato);

        /*revisa que este vacio a la derecha*/
        /*si no esta vacio entonces aplica la recursion*/
        if(subarbol->der != NULL)
            imprimir_arbol(subarbol->der);

    }
    else
    {
        /*navega por el arbol, primero a la izquierda*/
        imprimir_arbol(subarbol->izq);
        /*terminaste de imprimir a la izquierda
        ahora imprime el nodo que es raiz en el subarbol*/
        printf("%d ", subarbol->dato);

        /*ahora navega por el subarbol asociado
        por el nodo de la derecha*/
        if (subarbol->der != NULL)
            imprimir_arbol(subarbol->der);
    }

}

void eliminar_ramas(NODO *subarbol)
{
    /*Funcion que utiliza recursion para eliminar ramas de 
    arbol
    Parametros
    ===========
    NODO *subarbol: se inicia entregando el tronco de 
    la estructura ARBOL*/

    /*primero que se elimina lo que esta mas a la
    izquierda*/

    if (subarbol->izq == NULL)
    {

        /*revisa que este vacio a la derecha*/
        /*si no esta vacio entonces aplica la recursion*/
        if (subarbol->der != NULL)
            eliminar_ramas(subarbol->der);

        /*printf("%d ", subarbol->dato);*/
        free(subarbol);
    }
    else
    {
        /*navega por el arbol, primero a la izquierda*/
        eliminar_ramas(subarbol->izq);
        /*terminaste de imprimir a la izquierda
        ahora elimina el nodo que es raiz en el subarbol*/

        /*ahora navega por el subarbol asociado
        por el nodo de la derecha*/
        if (subarbol->der != NULL)
            eliminar_ramas(subarbol->der);

        /*printf("%d ", subarbol->dato);*/
        free(subarbol);
    }
}

void eliminar_arbol(ARBOL *arbol)
{
    /*Funcion que elimina toda la estructura de
    arbol*/

    eliminar_ramas(arbol->tronco);
    free(arbol);
    printf("El arbol ha sido eliminado\n");
}

int profundidad(NODO *tronco)
{
    /*Funcion que calcula la profundidad de un arbol
    de manera recursiva
    Parametros
    ===========
    NODO *tronco: es el tronco de la structura arbol al inicio,
    este pasa a ser la raiz de los subarboles*/

    int a = ZERO, b = ZERO;

    if(tronco == NULL)
        return ZERO;

    a = profundidad(tronco->izq);
    b = profundidad(tronco->der);

    if (a > b)
        return a + ONE;
    else
        return b + ONE;

}

int calcula_profundidad(ARBOL *arbol)
{
    /*Funcion que engloba a la que busca la profudidad
    solo se usa como mediadora para dar directamente
    la estructura como arbol*/
    return profundidad(arbol->tronco);
}

void eliminar_nodo(NODO *tronco, int dato)
{

}