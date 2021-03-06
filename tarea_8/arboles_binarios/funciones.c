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
    /*printf("Se ha creado un nuevo nodo\n");*/
    
}

void imprimir_arbol(NODO *subarbol)
{
    /*Funcion que utiliza recursion para poder imprimir un nodo
    Parametros
    ===========
    NODO *subarbol: se inicia entregando el tronco de 
    la estructura ARBOL*/

    if(subarbol == NULL)
    {
        printf("Vacio ");
    }
    /*arbol no esta vacio*/
    else
    {

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

    }/*end else el arbol no esta vacio*/

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

    if(arbol->tronco != NULL)
        eliminar_ramas(arbol->tronco);

    free(arbol);
    /*printf("El arbol ha sido eliminado\n");*/

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
        if(tronco->der == NULL)
            temp = NULL;
        else
        {
            if (tronco->der->dato == number)
                temp =  tronco;
            else
                temp = buscar_nodo(tronco->der, number);
        }
    }
    else
    {
        if(tronco->izq == NULL)
            temp = NULL;
        else
        {
            if (tronco->izq->dato == number)
                temp =  tronco;
            else
            temp = buscar_nodo(tronco->izq, number);
        }
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

    NODO *subarbol, *nodo_temp, *abuelo, *nodo_salvado;
    NODO *nodo_obj, *padre_minimo, *minimo;
    int dir;
    
    /*la raiz no debe de ser nula*/
    if(arbol->tronco != NULL)
    {      
        /*if de cuando el arbol es solo un nodo y se quiere eliminar ese
        nodo*/
        if(arbol->tamanio == ONE && number == arbol->tronco->dato)
        {
            free(arbol->tronco);
            arbol->tronco = NULL;
            arbol->tamanio -= ONE;
            printf("Se ha eliminado el nodo con exito\n");
        }
        else
        {
            /*subarbol contiene un subarbol, cuya raiz es el padre
            del nodo que se quiere eliminar, a menos que el tronco
            sea el nodo que se debe de eliminar*/
            if(arbol->tronco->dato == number)
            {
                subarbol = arbol->tronco;
                nodo_obj = subarbol;

                /*las direcciones se usan para los dos 
                primeros casos*/
                if(arbol->tronco->der != NULL)
                    dir = ONE;
                else
                    dir = ZERO;
            }
            else
            {
                subarbol = buscar_nodo(arbol->tronco, number);
                /*es necesario de nuevo buscar entre los dos nodos
                hijos que valor es el que buscamos, si es nulo entonces
                no hay nada que eliminar, pero se imprime en terminal, que
                no se encuentra, y mas adelante en un condicional termina la funcion*/
                if(subarbol == NULL)
                {
                    printf("No se encuentra el nodo que se desea eliminar\n");
                }
                else
                {
                    /*existe un nulo en alguno de los hijos*/
                    if(subarbol->der != NULL && subarbol->izq == NULL)
                    {
                        nodo_obj = subarbol->der;
                        dir = ONE;
                    }
                    else
                    {
                        
                        /*existe un nulo en alguno de los hijos*/
                        if(subarbol->der == NULL && subarbol->izq != NULL)
                        {   
                            nodo_obj = subarbol->izq;
                            dir = ZERO;
                        }
                        else
                        {

                            /*los hijos no son nulos*/
                            /*revisa la direccion en la que se encuentra 
                            el valor a eliminar*/
                            if (subarbol->der->dato == number)
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

                    }/*end else dar direccion hacia donde esta el elemento a eliminar*/

                }/*end else cinicializa elementos de busqueda cuando existe el elemnto a 
                eliminar*/

            }/*end else el elemnto no se encuentra en la raiz del arbol*/

            /*solo se activa si existe el valor a eliminar*/
            if(subarbol != NULL)
            {
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
                    arbol->tamanio -= ONE;
                    printf("Se ha eliminado el nodo con exito\n");
                }/*end if caso 1*/
                else
                {
                    /*Caso 2*/
                    /*cuando se tiene solo un hijo diferente de NULL*/
                    if (nodo_obj->der == NULL || nodo_obj->izq == NULL)
                    {
                        
                        /*el caso en que el nodo que se elimina, es el nodo raiz*/
                        if(subarbol->dato == number)
                        {
                            
                            if(dir == ONE)
                            {
                                /*primero se guarda el nodo raiz, que es
                                el que se eliminara*/
                                nodo_salvado = nodo_obj;
                                free(nodo_obj);
                                nodo_obj = NULL;
                                arbol->tronco = nodo_salvado->der;
                                
                            }
                            else
                            {
                                /*se guarda el nodo raiz que se eliminara despues*/
                                nodo_salvado = nodo_obj;
                                free(nodo_obj);
                                nodo_obj = NULL;
                                arbol->tronco = nodo_salvado->izq;
                            }

                            /*se debe de reducir el tamanio*/
                            arbol->tamanio -= ONE;                            
                        }/*end if elimina raiz que contiene un hijo distinto de NULL*/
                        else
                        {
                            /*revisamos donde esta la direccion con no nulo
                            respecto al nodo a eliminar*/
                            /*derecha*/
                            if(nodo_obj->der != NULL)
                                nodo_temp = nodo_obj->der;
                            /*izquierda*/
                            else
                                nodo_temp = nodo_obj->izq;

                            /*hace la nueva conexion con respecto 
                            al padre del nodo que se elimino*/
                            if(dir == ONE)
                                subarbol->der = nodo_temp;
                            else
                                subarbol->izq = nodo_temp;

                            /*se libera la memoria del nodo que se elimina*/
                            free(nodo_obj);
                            nodo_obj = NULL;
                            arbol->tamanio -= ONE;
                            printf("Se ha eliminado el nodo con exito\n");
                        }/*end else cuando existe un hijo distinto de NULL y el elemento a 
                        eliminar no es la raiz*/

                    }/*end if caso 2*/
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
                        
                    }/*end if caso 3*/

                }/*end else de caso 2 y 3*/

            }/*end if cuando existe elemento a eliminar*/

        }/*end else cuando se elimina un elemento de un arbol no vacio*/

    }/*end if la raiz no es nula*/

}/*end function eliminar_nodo()*/