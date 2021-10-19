#ifndef HASHH
#define HASHH
#include "../arboles_binarios/arboles_binarios.h"
#ifndef ZERO
#define ZERO 0
#endif /*ZERO*/
typedef struct HASH
{
    char *name;
    int tamanio;
    ARBOL **datos;
}HASH;
void imprimir_tabla(HASH *tabla);
void imprime_arbol_deeper(HASH *tabla);
HASH *crear_tabla(char *name, int tamanio);
void eliminar_tabla(HASH *tabla);
void agregar_elemento_tabla(HASH *tabla, int number);
void eliminar_elemento_tabla(HASH *tabla, int number);
#endif/*HASHH*/