/*Giovanny Encinia*/

#include <stdio.h>
#include <stdlib.h>

#define ZERO 0
#define ONE 1
#define THREE 3
#define ELEVEN 11
#define TWELVE 12
#define SIZE 27
#define DESFASE 65

float leer_contar(float **);
void free_matrix(float **);
float **crear_matrix();
int *search_indices(float **, float *, int,  int);
int in(int, int *);
float *copiar_columnas(float **, int);
float *copiar_totales(float **, int);
void selection_sort(float *);
int special_chars(int);
void calcula_probabilidades(float **, int);
void probabilidad_condicional(float **, int);

int in(int move, int *memo)
{
    /*verifica que el
    movimiento no se haya hecho antes
    si se hizo regresa ONE
    de lo contrario ZERO*/
    int i = ZERO;

    while(i < TWELVE)
    {
        if(*(memo+i) == move)
        {
            return ONE;
        }

        i++;
    }

    return ZERO;
}

int *search_indices(float **matrix, float *ordenado, int n,  int type)
{
    int *ind = (int *)calloc(ELEVEN, sizeof(int));
    int j = ZERO, i;
    int *move = (int *)calloc(ELEVEN, sizeof(int));

    if(type)
    {/*de una fila busca a traves de las columnas*/

        while(j < TWELVE)
        {
            i = ZERO;

            while(i < SIZE)
            {

                if(*(ordenado + j) == *(*(matrix + n) + i))
                {
                    if(in(i, move))
                    {
                        i++;
                        continue;
                    }


                    *(ind +  j) = i;
                    *(move + j) = i;
                    break;
                }

                i++;
            }

            j++;
        }

    }

    else
    {
        /*de una columna busca a traves de las filas*/
        while(j < TWELVE)
        {
            i = ZERO;

            while(i < SIZE)
            {
                if(*(ordenado + j) == *(*(matrix + i) + n))
                {
                    if(in(i, move))
                    {
                        i++;
                        continue;
                    }

                    *(ind +  j) = i;
                    *(move + j) = i;
                    break;
                }

                i++;
            }

            j++;
        }
    }

    free(move);

    return ind;

}

float *copiar_columnas(float **matrix, int col)
{
    /*un arreglo que copia la ultima fila de la matriz original*/
    int i;
    float *mc = (float *)calloc(SIZE, sizeof(float));

    for(i = ZERO; i < SIZE; i++)
    {
        *(mc + i) = *(*(matrix + i) + col);
    }

    return mc;
}

float *copiar_totales(float **matrix, int row)
{
    /*un arreglo que copia la ultima fila de la matriz original*/
    int i;
    float *mc = (float *)calloc(SIZE, sizeof(float));

    for(i = ZERO; i < SIZE; i++)
    {
        *(mc + i) = *(*(matrix + row) + i);
    }

    return mc;
}

void selection_sort(float *ordenado)
{
    /*Elige a las primeros 10 probabilidades
    mayores*/
    int i= ZERO, j = ZERO, index = ZERO;
    float max, temp;

    while(i < TWELVE)
    {

        j = i;
        max = *(ordenado + i);

        while(j < SIZE)
        {
            if(*(ordenado + j)  > max)
            {
                index = j;
                max = *(ordenado + j);
            }

            j++;
        }

        temp = *(ordenado + i);
        *(ordenado + i) = max;

        *(ordenado + index) = temp;
        i++;
    }

}

void free_matrix(float **matrix)
{
    free(*(matrix));
    free(matrix);
}

float **crear_matrix()
{
    float **matrix = (float**)calloc((SIZE + ONE), sizeof(float*));
    int i;

    /*la ultima fila contiene las sumas*/
    *(matrix) = (float*)calloc((SIZE + ONE) * SIZE, sizeof(float));

    for(i = ONE; i < SIZE + ONE; i++)
    {
        *(matrix + i) = *(matrix + i - ONE) + SIZE;
    }

    return matrix;
}

int special_chars(int letra)
{
    /*Mueve a posicion equivalente
        de vocales, A corresponde a 0
        para nuestros fines de almacenamiento,
        ordenados primero mas probables*/
        switch(letra)
        {
        case -77:/*o'*/
            letra = 14; /*O*/
            break;
        case -83:/*i'*/
            letra = 8; /*I*/
            break;
        case -87:/*e'*/
            letra = 4; /*E*/
            break;
        case -95:/*a'*/
            letra = 0; /*A*/
            break;
        case -79:
            letra = 13; /*N~*/
            break;
        case -70:/*u'*/
            letra = 20; /*U*/
            break;
        case -109: /*O'*/
            letra = 14; /*O*/
            break;
        case -115: /*I'*/
            letra = 8; /*I*/
            break;
        case -119: /*E'*/
            letra = 4; /*E*/
            break;
        case -127: /*A'*/
            letra = 0; /*A*/
            break;
        case -102: /*U'*/
            letra = 20; /*U*/
            break;
        case -111:
            letra = 13; /*N~*/
            break;
        case -68:/*u:*/
            letra = 20; /*U*/
            break;
        case -100:/*U:*/
            letra = 20; /*U*/
            break;
        }

        return letra;
}

float leer_contar(float **matrix)
{
    /*Lee el archivo y almacena los datos que se van repitiendo
    en una matriz de 27 x 26*/

    char letra;
    int before = SIZE - ONE; /*Inicio*/
    int omega = -ONE;


    while(scanf("%c", &letra) != EOF)
    {
        letra = (int)letra;

        if(letra == -61)/*aparece en char special*/
            continue;

        if(letra < DESFASE && letra > ZERO)
            letra = SIZE - ONE; /* ] arbitrario*/


        if(letra < 0)
            letra = special_chars(letra);

        /*La A, a, son inicializadas en 0*/
        /*Mayusculas*/
        if(letra >= DESFASE && letra <= 90)
            letra -= DESFASE;

        /*Minusculas*/
        if(letra >= 97 && letra <= 122 )
            letra -= 97;
        else
        {
            if(letra > 25)
                letra = SIZE - ONE; /*]*/
        }

        /*contador de interseccion*/
        *(*(matrix + before) + letra) += ONE;
        /*contador total letra especifica*/
        *(*(matrix + SIZE) + letra) += ONE;
        before = letra;
        omega++;/*caracteres totales*/

    }

    return omega;
}

void calcula_probabilidades(float **matrix, int omega)
{
    int i;

    for(i = ZERO; i < SIZE; i++)
    {
        printf("P(%c) = %f,  ", i + DESFASE, *(*(matrix + SIZE) + i)/omega);

        if((i + ONE) % THREE == ZERO)
            printf("\n\n");
    }

}
void probabilidad_condicional(float **matrix, int i)
{
    float *fila_letra;
    int j = ZERO;
    int *indices;

    fila_letra = copiar_columnas(matrix, i);
    /*contiene los indices de los elementos con mayor incidencia
    de la letra*/
    selection_sort(fila_letra);
    indices = search_indices(matrix, fila_letra, i, 0);

    while(j < TWELVE)
    {
        if(*(fila_letra+j) == 26)
        {
            j++;
            continue;
        }

        printf("P(%c|%c) = %f, ", i + DESFASE, *(indices+j) + DESFASE, *(*(matrix + *(indices+j)) + i) / *(*(matrix + SIZE) + *(indices+j)));


        if(j%5 == 4)
            printf("\n");

        j++;
    }

    free(indices);
    free(fila_letra);
}

int main()
{
    float **matrix, omega, *ordenado;
    int *indices;
    int i = ZERO, *temporal;

    matrix = crear_matrix();
    omega = leer_contar(matrix);
    printf("===============================================================");
    printf("===============================================================\n");
    printf("\t\tLas probabilidades de cada letra:\n");
    printf("===============================================================");
    printf("===============================================================\n");
    calcula_probabilidades(matrix, omega);
    printf("===============================================================");
    printf("===============================================================\n");
    ordenado = copiar_totales(matrix, SIZE);
    selection_sort(ordenado);/*Encuentra las letras que mas se repiten*/
    indices = search_indices(matrix, ordenado, SIZE, ONE);
    printf("\t\tProbabilidades condicionales\n");
    printf("===============================================================");
    printf("===============================================================\n");

    for(i = ZERO; i<  TWELVE; i++)
    {
        if(*(indices + i) != 26)
            probabilidad_condicional(matrix, *(indices+i));
            printf("\n\n");
    }

    free(ordenado);
    free_matrix(matrix);
    free(indices);

    return ZERO;
}
