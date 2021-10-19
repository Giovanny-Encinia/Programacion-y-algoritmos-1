#include <stdio.h>
#include <stdlib.h>
#include "hash/hash.h"
#include "arboles_binarios/arboles_binarios.h"
#include "arboles_binarios/funciones.h"
#define SIZE 11

int main(void)
{
    int a[] = {190, 146};
    int i;
    ARBOL *arbol;
    arbol = crear_arbol();

    for(i = 0; i < 2; i++)
    {
        insertar_nodo(arbol, a[i]);
    }

    imprimir_arbol(arbol->tronco);
    printf("\n");
    
    printf("profundidad %d\n", calcula_profundidad(arbol));
    eliminar_nodo(arbol, 190);
    
    

    imprimir_arbol(arbol->tronco);
    
    eliminar_arbol(arbol);

    /*
    HASH *tabla;
    char selection;
    int number, condition = 1;*/

    /*se crea la estructura general de la tabla*/
    /*tabla = crear_tabla("tarea8", SIZE);*/
    /*para fines de la tarea, de da un tabla que ya
    contiene 100 elementos*/
   /* llenar_tabla_random(tabla);

    while (condition)
    {
        printf("+--------------------------------------------+\n");
        printf("| %20s %23s\n", "MENU", "|");
        printf("+--------------------------------------------+\n");
        printf("|%-28s %10s\n", "\t1-Imprimir Tabla en orden", "|");
        printf("|%-28s %10s\n", "\t2-Arbol mas profundo", "|");
        printf("|%-28s %10s\n", "\t3-Eliminar nodo", "|");
        printf("|%-28s %10s\n", "\t4-Insertar nodo","|");
        printf("|%-28s %10s\n", "\tOtro-Salir", "|");
        printf("+--------------------------------------------+\n\n");

        printf("Elige una opcion: ");
        scanf(" %c", &selection);

        switch (selection)
        {
        case '1':
            imprimir_tabla(tabla);
            break;
        case '2':
            imprime_arbol_deeper(tabla);
            break;
        case '3':
            printf("Ingresa el numero que deseas eliminar: ");
            scanf(" %d", &number);
            eliminar_elemento_tabla(tabla, number);
            printf("\n");
            break;
        case '4':
            printf("Ingresa el numero que deseas agregar: ");
            scanf(" %d", &number);
            agregar_elemento_tabla(tabla, number);
            printf("\n");
            break;
        default:
            printf("\tAdios\n");
            condition = ZERO;
            break;
        }

    }

    eliminar_tabla(tabla);*/

    return 0;
}