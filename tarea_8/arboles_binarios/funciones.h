#include "arboles_binarios.h"
#ifndef FUNCIONESH
#define FUNCIONESH
void eliminar_ramas(NODO *subarbol);
void eliminar_arbol(ARBOL *arbol);
void inserta_recursivo(NODO *tronco, int number);
void insertar_nodo(ARBOL *arbolito, int number);
void imprimir_arbol(NODO *subarbol);
int profundidad(NODO *tronco);
int calcula_profundidad(ARBOL *arbol);
#endif /*FUNCIONESH*/