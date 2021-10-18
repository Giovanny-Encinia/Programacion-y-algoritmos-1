#include <stdio.h>
#include <stdlib.h>
#include "arboles_binarios/arboles_binarios.h"
#include "arboles_binarios/funciones.h"

int main(void)
{
    int a[] = {9, 10, -6, 11, 3, 4, 5, 1, 7, -90, 6, 8, 0};
    int i;
    ARBOL *arbol;
    arbol = crear_arbol();

    for(i = 0; i < 13; i++)
    {
        insertar_nodo(arbol, a[i]);
    }
printf("funcioina\n");
printf("tr %d \n", arbol->tronco->dato);
    imprimir_arbol(arbol->tronco);
    
    printf("arbolsss %d \n", arbol->tronco->der->dato);

    return 0;
}