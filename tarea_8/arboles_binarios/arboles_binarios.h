#ifndef ARBOLESBINARIOS_H
#define ARBOLESBINARIOS_H
typedef struct NODO
{
    struct NODO *der;
    struct NODO *izq;
    int dato;

} NODO;

typedef struct ARBOL
{
    struct NODO *tronco;
    int profundidad;
    int tamanio;

} ARBOL;

NODO *crear_nodo(int);
ARBOL *crear_arbol(void);
#endif /*ARBOLESBINARIOS_H*/