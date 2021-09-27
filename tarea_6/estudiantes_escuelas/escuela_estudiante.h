#ifndef ESCUELA_ESTUDUANTEH
#define ESCUELA_ESTUDUANTEH
typedef struct escuela
{
    char grupo; // A, B, C, D, E, F
    char turno; // Matutino o Vespertino (M, V)
}

typedef struct estudiante
{
    char *nombre;
    char *calif_promedio; // Formato USA {A+ > A > A- > B+ > B > B- > C}
    int edad;
    struct escuela *E;
};
#endif /* ESCUELA_ESTUDUANTEH*/


