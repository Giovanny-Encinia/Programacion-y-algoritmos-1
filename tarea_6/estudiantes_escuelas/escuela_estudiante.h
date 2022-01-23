#ifndef ESCUELA_ESTUDUANTEH
#define ESCUELA_ESTUDUANTEH
typedef struct escuela
{
    char grupo; // A, B, C, D, E, F
    char turno; // Matutino o Vespertino (M, V)
}escuela;

typedef struct estudiante
{
    char *nombre;
    char *calif_promedio; // Formato USA {A+ > A > A- > B+ > B > B- > C}
    int edad;
    struct escuela *E;
}estudiante;
#endif /* ESCUELA_ESTUDUANTEH*/


