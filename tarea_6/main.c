#include <stdio.h>
#include <stdlib.h>
#include "estudiantes_escuelas/escuela_estudiante.h"
#include "estudiantes_escuelas/funciones_estudiantes.h"

int main()
{
    estudiante *data_base;
    int *totalp_grupo, *totalp_turno, i;
    int (*f_n)(estudiante, estudiante);
    int (*f_p)(estudiante, estudiante);
    int (*f_e)(estudiante, estudiante);

    f_n = &compara_nombre;
    f_p = &compara_promedio;
    f_e = &compara_edad;
    /*A, B, C, D, E, F*/
    totalp_grupo = (int*)calloc(6, sizeof(int));
    /*M, V*/
    totalp_turno = (int*)calloc(2, sizeof(int));

    data_base = leer_archivo("file.txt", totalp_grupo, totalp_turno, &i);

    Imprimirarchivo(data_base);

    /*ordena por nombre*/
    merge_sort(data_base, 0, i-1, f_n);
    printf("\n");
    Imprimirarchivo(data_base);

    /*ordena por calificacion promedio*/
    merge_sort(data_base, 0, i-1, f_p);
    printf("\n");
    Imprimirarchivo(data_base);

    /*ordena por edad*/
    merge_sort(data_base, 0, i-1, f_e);
    printf("\n");
    Imprimirarchivo(data_base);

    free_data_base(data_base, i);

    /*muestra el numero de estudiantes por grupo*/
    NumeroEstudiantesGrupo(totalp_grupo);

    /*muestra el numero de estudiantes por turno*/
    NumeroEstudiantesTurno(totalp_turno);


    free(totalp_grupo);
    free(totalp_turno);

    return(0);

}
