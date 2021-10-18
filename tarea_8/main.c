#include <stdio.h>
#include <stdlib.h>
#include "arboles_binarios/arboles_binarios.h"
#include "arboles_binarios/funciones.h"

int main(void)
{
    int a[] = {9, 10, 11, 12, 13};
    int i;
    ARBOL *arbol;
    arbol = crear_arbol();

    for(i = 0; i < 5; i++)
    {
        insertar_nodo(arbol, a[i]);
    }

    imprimir_arbol(arbol->tronco);
    printf("\n");
    
    printf("profundidad %d\n", calcula_profundidad(arbol));
    eliminar_nodo(arbol, -9);
    

    imprimir_arbol(arbol->tronco);

    
    eliminar_arbol(arbol);

    return 0;
}