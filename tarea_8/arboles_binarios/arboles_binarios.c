#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "arboles_binarios.h"

NODO *crear_nodo(int number)
{
    /*Funcion que crea un nodo
    Parametros
    ============
    int number: es el numero que se guardara*/

    NODO *node = (NODO *)malloc(sizeof(NODO));

    if(node == NULL)
        printf("Error al crear nodo\nError: %d\n", errno);

    node->der = NULL;
    node->izq = NULL;
    node->dato = number;

    return node;

}

ARBOL *crear_arbol(void)
{
    /*Funcion que crea un estructura general arbol
    inicializada en cero y NULL's*/

    ARBOL *arbolito = (ARBOL *)malloc(sizeof(ARBOL));

    if (arbolito == NULL)
        printf("Error al crear arbol\nError: %d\n", errno);

    arbolito->profundidad = 0;
    arbolito->tamanio = 0;
    arbolito->tronco = NULL;

    return arbolito;
}