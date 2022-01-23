#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "estudiantes_escuelas/escuela_estudiante.h"
#include "estudiantes_escuelas/funciones_estudiantes.h"
#define ZERO 0
#define ONE 1

int main(int argc, char *argv[])
{
    estudiante *data_base;
    estudiante nuevo, baja;
    int *totalp_grupo, *totalp_turno, i, libera = ZERO, condition = ONE;
    char eleccion;
    int (*f_n)(estudiante, estudiante);
    int (*f_p)(estudiante, estudiante);
    int (*f_e)(estudiante, estudiante);
    char option;

    data_base = NULL;
    f_n = &compara_nombre;
    f_p = &compara_promedio;
    f_e = &compara_edad;

    while(condition)
    {
        printf("\t+------------------------------------");
        printf("---------------------------------------+\n");
        printf("\t|                  Elige una de las siguientes opciones%22s\n", "|");
        printf("\t+------------------------------------");
        printf("---------------------------------------+\n");
        printf("\t%-40s%37s\n", "|1) Imprimir archivo", "|");
        printf("\t%-40s%37s\n", "|2) Ordenar por nombre", "|");
        printf("\t%-40s%37s\n", "|3) Ordenar por Edad", "|");
        printf("\t%-40s%37s\n", "|4) Ordenar por Promedio", "|");
        printf("\t%-40s%37s\n", "|5) Numero de estudiantes por grupo", "|");
        printf("\t%-40s%37s\n", "|6) Numero de estudiantes por turno", "|");
        printf("\t%-40s%37s\n", "|7) Baja estudiante", "|");
        printf("\t%-40s%37s\n", "|8) Alta estudiante", "|");
        printf("\t%-40s%37s\n", "|9) Invertir archivo", "|");
        printf("\t+------------------------------------");
        printf("---------------------------------------+\n");
        printf("\t");
        scanf(" %c", &option);

        /*Se hara null cuando, se manipule el archivo
        por lo que sera necesario de nuevo leer todo el archivo,
        teniendo ya leido se crea data_base la cual es usada en
        las opciones de ordenamiento y conteo de alumnos por
         grupo y turno*/
        if(data_base == NULL)
        {
            /*A, B, C, D, E, F*/
            totalp_grupo = (int*)calloc(6, sizeof(int));
            /*M, V*/
            totalp_turno = (int*)calloc(2, sizeof(int));

            if(totalp_grupo == NULL || totalp_turno == NULL)
            {
                printf("No se asigna memoria: %d", (errno));
                break;
            }

            data_base = leer_archivo(argv[1], totalp_grupo, totalp_turno, &i, 0);
            libera = ONE;
        }

        switch(option)
        {
            /*Imprime el archivo*/
        case '1':
            Imprimirarchivo(data_base);
            break;
        /*ordena por nombre*/
        case '2':
            merge_sort(data_base, 0, i-1, f_n);
            printf("\n");
            Imprimirarchivo(data_base);
            break;
        /*ordena por edad*/
        case '3':
            merge_sort(data_base, 0, i-1, f_e);
            printf("\n");
            Imprimirarchivo(data_base);
            break;
        /*ordena por promedio*/
        case '4':
            merge_sort(data_base, 0, i-1, f_p);
            printf("\n");
            Imprimirarchivo(data_base);
            break;
        /*Numero de estudiantes por grupo*/
        case '5':
            NumeroEstudiantesGrupo(totalp_grupo);
            break;
        /*Numero de estudiantes por turno*/
        case '6':
            NumeroEstudiantesTurno(totalp_turno);
            break;
        /*Baja estudiante*/
        case '7':
            printf("\tDaremos de baja al estudiante\n");
            printf("\tAgregue el nombre: ");
            baja.nombre = (char *)malloc(40 * sizeof(char));
            scanf(" %[^\n]", baja.nombre);
            printf("\tAgregue el promedio: ");
            baja.calif_promedio = (char *)malloc(4 * sizeof(char));
            scanf(" %[^\n]", baja.calif_promedio);
            printf("\tAgregue el edad: ");
            scanf("%d", &baja.edad);
            baja.E = (escuela *)malloc(sizeof(escuela));
            printf("\tAgregue el grupo: ");
            scanf(" %c", &baja.E->grupo);
            printf("\tAgregue el turno: ");
            scanf(" %c", &baja.E->turno);
            BajaEstudiante(argv[1], baja);
            /*se le suma para saber que hay un elemento mas*/
            free(baja.E);
            free(baja.nombre);
            free(baja.calif_promedio);
            free_data_base(data_base, i - ONE);
            data_base = NULL;
            libera = ZERO;
            free(totalp_grupo);
            free(totalp_turno);
            break;
        /*Alta estudiante*/
        case '8':
            /*Dar de alta a un estudiante*/
            printf("\tDaremos de alta al estudiante\n");
            printf("\tAgregue el nombre: ");
            nuevo.nombre = (char *)malloc(40 * sizeof(char));
            scanf(" %[^\n]", nuevo.nombre);
            printf("\tAgregue el promedio: ");
            nuevo.calif_promedio = (char *)malloc(4 * sizeof(char));
            scanf(" %[^\n]", nuevo.calif_promedio);
            printf("\tAgregue el edad: ");
            scanf("%d", &nuevo.edad);
            nuevo.E = (escuela *)malloc(sizeof(escuela));
            printf("\tAgregue el grupo: ");
            scanf(" %c", &nuevo.E->grupo);
            printf("\tAgregue el turno: ");
            scanf(" %c", &nuevo.E->turno);
            AltaEstudiante(argv[1], nuevo, &i);
            /*se le suma para saber que hay un elemento mas*/
            free(nuevo.E);
            free(nuevo.nombre);
            free(nuevo.calif_promedio);
            free_data_base(data_base, i - ONE);
            data_base = NULL;
            libera = ZERO;
            free(totalp_grupo);
            free(totalp_turno);
        break;
        /*Invertir archivo*/
        case '9':
            volteaArchivo(argv[1]);
            free_data_base(data_base, i - ONE);
            data_base = NULL;
            libera = ZERO;
            free(totalp_grupo);
            free(totalp_turno);
            break;
        default:
            printf("\tElige una opcion valida\n");
        }

        printf("\tDesea realizar otra accion?(1: si, 0: No): ");
        scanf(" %c", &eleccion);
        printf("\n");

        if(eleccion != '1')
            condition = ZERO;


    }/*end while*/

    /*Se asegura de liberar la memoria*/
    if(libera)
    {
        free_data_base(data_base, i - ONE);
        free(totalp_grupo);
        free(totalp_turno);
    }

    return ZERO;
}
