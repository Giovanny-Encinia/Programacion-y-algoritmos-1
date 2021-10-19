#include <stdio.h>
#include <stdlib.h>
#include "../hash/hash.h"
#include "../arboles_binarios/arboles_binarios.h"
#include "../arboles_binarios/funciones.h"
#define SIZE 11

void debugear(void)
{
    /*Funcion que se puede utilizar para debugear los 
    arboles binarios, en su momento se utilizo para saber
    donde habia errores al eliminar los nodos*/
    
    int a[] = {14, 80};
    int i;
    ARBOL *arbol;
    arbol = crear_arbol();

    for (i = 0; i < 2; i++)
    {
        insertar_nodo(arbol, a[i]);
    }

    imprimir_arbol(arbol->tronco);
    printf("\n");

    printf("profundidad %d\n", calcula_profundidad(arbol));
    eliminar_nodo(arbol, 14);
    printf("tamanio : %d\n", arbol->tamanio);
    printf("tronco: %d\n", arbol->tronco->dato);
    eliminar_nodo(arbol, 80);

    imprimir_arbol(arbol->tronco);
    eliminar_arbol(arbol);
}
