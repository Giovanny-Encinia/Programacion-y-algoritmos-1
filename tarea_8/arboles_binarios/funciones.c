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

    arbolito->tamanio += 1;
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

    if(arbol->tronco == NULL)
        printf("Arbol vacio\n");
    else
    {
        eliminar_ramas(arbol->tronco);
        free(arbol);
        printf("El arbol ha sido eliminado\n");
    }
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

NODO *buscar_nodo(NODO *tronco, int number)
{
    /*Funcion que busca nodos de manera recursiva
    Parametros
    ==========
    NODO *tronco: inicia con el tronco de la estrictura arbol
    al ser un NODO, despues cumple la misma funcion pero para
    subarboles
    int number: es el dato que se agragara
    
    Return
    ======
    regresa un subarbol NODO, que tiene como raiz el elemento padre del nodo que se busca*/

    NODO *temp = NULL;
    
    if (number > tronco->dato)
    {

        if (tronco->der->dato == number)
            temp =  tronco;
        else
            temp = buscar_nodo(tronco->der, number);
    }
    else
    {

        if (tronco->izq->dato == number)
            temp =  tronco;
        else
           temp = buscar_nodo(tronco->izq, number);
    }

    return temp;
}

NODO *encontrar_minimo(NODO *tronco)
{
    /*Funcion que encuentra el nodo con el dato
    con valor minimo
    Parametros
    ==========
    NODO *tronco: es la raiz del arbol, o subarbol
    
    Return
    =======
    NODO *nodo: el nodo padre que tiene a su izquierda el
    nodo con valor minimo*/

    /*El nodo mas a la izquierda es el que tiene menor valor*/

    NODO *temp = tronco;

    while (tronco->izq != NULL)
    {
        temp = tronco;
        tronco = tronco->izq;   
    }

    return temp;
    
}

void eliminar_nodo(ARBOL *arbol, int number)
{
    /*Funcion que elimina un nodo del arbol,
    toma en cuenta los tres casos para eliminar el
    nodo
    Parametros
    ===========
    ARBOL *arbol: es el arbol binario de donde
    se eliminara el nodo
    int number: es la informacion que contiene el nodo
    que sera eliminado*/

    NODO *subarbol, *nodo_temp, *abuelo;
    NODO *nodo_obj, *padre_minimo, *minimo;
    int dir;
    
    if(arbol->tamanio == ONE)
        arbol->tronco = NULL;
    else
    {
        /*subarbol contiene un subarbol, cuya raiz es el padre
        del nodo que se quiere eliminar, a menos que el tronco
        sea el nodo que se debe de eliminar*/
        if(arbol->tronco->dato == number)
        {
            subarbol = arbol->tronco;
            nodo_obj = subarbol;

        }
        else
        {
            subarbol = buscar_nodo(arbol->tronco, number);
            /*es necesario de nuevo buscar entre los dos nodos
            hijos que valor es el que buscamos, si es nulo entonces
            no hay nada que eliminar, pero se omprime en terminal*/
            if(subarbol == NULL)
            {
                printf("No se encuentra el nodo que se desea eliminar\n");
            }
            else
            {
                if(subarbol->der->dato == number)
                {
                    nodo_obj = subarbol->der;
                    /*la direccion del elemento con respecto
                    al nodo padre*/
                    dir = ONE;
                }
                else
                {
                    nodo_obj = subarbol->izq;
                    /*direccion*/
                    dir = ZERO;
                }
            }
        }
        
        /*Caso en el que el nodo a elimimar es una hoja 
        dos NULL*/
        if(nodo_obj->der == NULL && nodo_obj->izq == NULL)
        {
            
            if(dir == ONE)
                subarbol->der = NULL;
            else
                subarbol->izq = NULL;

            /*se libera el espacio dinamico*/
            free(nodo_obj);
            nodo_obj = NULL;

        }
        else
        {
            /*cuando se tiene solo un hijo diferente de NULL*/
            if (nodo_obj->der == NULL || nodo_obj->izq == NULL)
            {
                /*revisamos donde esta la direccion*/
                /*derecha*/
                if(dir == ONE)
                {
                    /*revisamos que hijo no es NULL
                    y lo guardamos*/
                    if(nodo_obj->der != NULL)
                        nodo_temp = nodo_obj->der;
                    else
                        nodo_temp = nodo_obj->izq;

                    subarbol->der = nodo_temp;
                }
                /*izquierda*/
                else
                {
                    if (nodo_obj->izq != NULL)
                        nodo_temp = nodo_obj->der;
                    else
                        nodo_temp = nodo_obj->izq;

                    subarbol->izq = nodo_temp;
                }

                /*se libera la memoria del nodo que se elimina*/
                free(nodo_obj);
                nodo_obj = NULL;

            }
            /*cuando los dos hijos son distintos de NULL*/
            else
            {
                /*se encuentra el subarbol a la derecha del nodo a eliminar*/
                padre_minimo = encontrar_minimo(nodo_obj->der);

                /*no existe un nodo menor mas que el padre*/
                if(padre_minimo->izq == NULL)
                    minimo = padre_minimo;
                else
                    /*el nodo a la izquierda es menor que el nodo padre*/
                    minimo = padre_minimo->izq;

                /*el nodo minimo en el subarbol se elimina*/
                eliminar_nodo(arbol, minimo->dato);
                nodo_obj->dato = minimo->dato;
                
            }

        }
    }
    printf("Se ha eliminado el nodo con exito\n");
}