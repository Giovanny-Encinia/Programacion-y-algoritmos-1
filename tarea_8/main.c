#include <stdio.h>
#include <stdlib.h>
#include "arboles_binarios/arboles_binarios.h"
#include "arboles_binarios/funciones.h"

int main(void)
{
    int a[] = {9, 10, -6, 11, 3, 4, 5, 1, 7, -90};
    int i;
    ARBOL *arbol;
    arbol = crear_arbol();

    for(i = 0; i < 10; i++)
    {
        insertar_nodo(arbol, a[i]);
    }

    imprimir_arbol(arbol->tronco);
    printf("\n");
    
    printf("prof %d\n", calcula_profundidad(arbol));
    eliminar_arbol(arbol);

    return 0;
}