#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "escuela_estudiante.h"
#include <errno.h>
/*Giovanny Encinia*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 60/*numero de latras por nombre en promedio*/
#define N 100/*numero de nombres en total*/
#define ZERO 0
#define ONE 1
#define TWO 2
#define SIZE_DB 30

void free_data_base(estudiante *data_base, int i)
{
    int j;

    for(j = ZERO; j < i; j++)
    {
        free((*(data_base + j)).nombre);

        free((*(data_base + j)).E);
    }

    free(data_base);
}

int compara_edad(estudiante a, estudiante b)
{
    /*Funcion que compara la edad de los alumnos,
    esta pensado para que se ordene de manera ascendente,
    siendo el primer elemento el mayor*/

    if(a.edad > b.edad)
        return ONE;

    return ZERO;

}

int compara_promedio(estudiante a, estudiante b)
{
    /*funcion para comparar el promedio*/
    char *cal1 = a.calif_promedio;
    char *cal2 = b.calif_promedio;

    /*La calificacion es mayor en la letra*/
    if(*cal1 < *cal2)
        return ONE;

    /*si son la misma letra se fija en el signo +*/
    if(*(cal1 + ONE) == '+' && *cal1 <= *cal2)
        return ONE;

    /*si son iguales y no es signo mas, compara el sin signo que es mayor al negativo*/
    if(*(cal1 + ONE) == '\0' && *(cal2 + ONE) == '-' && *cal1 <= *cal2)
        return ONE;

    return ZERO;
}

int compara_nombre(estudiante a, estudiante b)
{
  /*Compara caracter por caracter
  se basa en el codigo ASCII, el simbolo espacio es
  menor a simbolos del abecedario*/

  int i = ZERO, j = ZERO, r = ONE;
  char *primero = a.nombre;
  char *segundo = b.nombre;

  while (*(primero + i) != '\0')
  {
    if(*(primero + i) < *(segundo + j))
    {
      r = ONE;
      break;
    }
    else
    {
      if(*(primero + i) > *(segundo + j))
      {
        r = ZERO;
        break;
      }

    }

    i++;
    j++;
  }

  return  r;
}

void merge_(estudiante *a, int left, int mid, int right, int (*f)(estudiante, estudiante))
{
    /*Es el paso merge del algoritmo merge sort*/

    int l_1, r_1, k, i = ZERO, j = ZERO;
    char grupo_, turno_;
    estudiante *L, *R;


    l_1 = mid - left + ONE;
    r_1 = right - mid;
    /*Arreglos que nos ayudan a almacenar
    divisiones del original*/
    L = (estudiante *)malloc(l_1 * sizeof(estudiante));
    R = (estudiante *)malloc(r_1 * sizeof(estudiante));

    if(L == NULL && R == NULL)
        printf("No se puede asignar memoria para ordenar: %s\n", strerror(errno));

    while(i < l_1)
    {
        /*nuestro punto de referencia
        siempre es left, este cambia
        conforme avanza la recursividad*/
        (*(L + i)).nombre = (*(a + left + i)).nombre;
        (*(L + i)).calif_promedio = (*(a + left + i)).calif_promedio;
        (*(L + i)).edad = (*(a + left + i)).edad;
        (*(L + i)).E = (escuela *)malloc(sizeof(escuela));
        (*(L + i)).E->grupo = (*(a + left + i)).E->grupo;
        (*(L + i)).E->turno = (*(a + left + i)).E->turno;
        i++;
    }


    while(j < r_1)
    {
        (*(R + j)).nombre = (*(a + mid + j + ONE)).nombre;
        (*(R + j)).calif_promedio = (*(a + mid + j + ONE)).calif_promedio;
        (*(R + j)).edad = (*(a + mid + j + ONE)).edad;
        (*(R + j)).E = (escuela *)malloc(sizeof(escuela));
        (*(R + j)).E->grupo = (*(a + mid + j + ONE)).E->grupo;
        (*(R + j)).E->turno = (*(a + mid + j + ONE)).E->turno;
        j++;
    }

    i = j = ZERO;
    k = left;

    /*esta es la parte que compara los tamanios
    esta cambia dependiendo de la funcion que se le de*/
    while(i < l_1 && j < r_1)
    {
        if(f((*(L + i)), (*(R + j))))
        {
            (*(a + k)).nombre = (*(L + i)).nombre;
            (*(a + k)).calif_promedio = (*(L + i)).calif_promedio;
            (*(a + k)).edad = (*(L + i)).edad;
            grupo_ = (*(L + i)).E->grupo;
            (*(a + k)).E->grupo = grupo_;
            turno_ = (*(L + i)).E->turno;
            (*(a + k)).E->turno = turno_;
            i++;
        }
        else
        {
            (*(a + k)).nombre = (*(R + j)).nombre;
            (*(a + k)).calif_promedio = (*(R + j)).calif_promedio;
            (*(a + k)).edad = (*(R + j)).edad;
            grupo_ = (*(R + j)).E->grupo;
            (*(a + k)).E->grupo = grupo_;
            turno_ = (*(R + j)).E->turno;
            (*(a + k)).E->turno = turno_;
            j++;
        }

        k++;
    }

    /*pueden haber sobrado datos
    sin ordenar, asi que se llena
    con el sobrente*/
    while(i < l_1)
    {
        (*(a + k)).nombre = (*(L + i)).nombre;
        (*(a + k)).calif_promedio = (*(L + i)).calif_promedio;
        (*(a + k)).edad = (*(L + i)).edad;
        (*(a + k)).E->grupo = (*(L + i)).E->grupo;
        (*(a + k)).E->turno = (*(L + i)).E->turno;
        i++;
        k++;
    }

    while(j < r_1)
    {
        (*(a + k)).nombre = (*(R + j)).nombre;
        (*(a + k)).calif_promedio = (*(R + j)).calif_promedio;
        (*(a + k)).edad = (*(R + j)).edad;
        (*(a + k)).E->grupo = (*(R + j)).E->grupo;
        (*(a + k)).E->turno = (*(R + j)).E->turno;
        j++;
        k++;
    }

    /*libera memoria asignada a la escuela temporal*/
    for(j = ZERO; j < r_1; j++)
        free((*(R + j)).E);

    for(j = ZERO; j < l_1; j++)
        free((*(L + j)).E);

    free(L);
    free(R);

}/*end merge*/

void merge_sort(estudiante *a, int left, int right, int (*f)(estudiante, estudiante))
{
    /*algoritmo merge sort*/

    int mid;

    if(left < right)
    {
        /*buscamos el punto medio*/
        mid = left + (right - left) / 2;

        /*recurividad a laprimera mitad*/
        merge_sort(a, left, mid, f);

        /*segunda mitad*/
        merge_sort(a, mid + ONE, right, f);

        /*realiza merge a las mitades*/
        merge_(a, left, mid, right, f);
    }

}

void Imprimirarchivo(estudiante *data_base)
{
    /*Funcion que imprime el estado del archivo
    Parametros
    ==========
    estudiante *data_base: es la estructura donde se guardan los datos del
    archivo
    */

    int i = ZERO;

    printf("\n\t+-----------------------------------+-------------+-------+--------+--------+\n");
    printf("\t|%-35s|%-13s|%-7s|%-8s|%-8s|\n", "Nombre", "Calificacion", "Edad", "Grupo", "Turno");
    printf("\t+-----------------------------------+-------------+-------+--------+--------+\n");

    while((*(data_base + i)).nombre != NULL && (*(data_base + i)).calif_promedio != NULL)
    {

        printf("\t|%-35s|%-13s|%-7d|%-8c|%-8c|\n",(*(data_base + i)).nombre,\
        (*(data_base + i)).calif_promedio, (*(data_base + i)).edad,\
        (*(data_base + i)).E->grupo, (*(data_base + i)).E->turno);
        i++;
    }

    printf("\t+-----------------------------------+-------------+-------+--------+--------+\n");

}

estudiante *leer_archivo(char *name, int *totalp_grupo, int *totalp_turno, int *size, int invertir)
{

    /*Esta funcion sirve para saber cuantos nombres
    hay, y la cantidad de letras que contiene cada uno

    count: se guardara el numero de nombres que hay en el archivo
    total_letras: guarda la cantidad total de c_letras

    Parametros
    ===========
    char *name:es el nombre del archivo
    int *totalp_grupo: es un arreglo de enteros que guarda la cantidad de alumnos
        por grupo
    int *totalp_turno: es un arreglo de enteros que guarda la cantidad de alumnos
        por turno
    int *size: es una variable donde se guarda la cantidad de alumnos, con ella
        sabemos el estado de la base de datos, es decir el numero de elementos
    int invertir: es un avariable de control, si toma el valor de 0, puede calcular el total
        de alumnos por grupos y turno, si es 1 entonces unicamente se usar la funcion para invertir
        el archivo y no calcula los alumnos por grupos especificos.

    Return
    =======
    estudiante *data_base: es la estructura que contiene la info del archivo
    */

    char name_temp[36], calif_temp[3], grupo_t, turno_t;
    char basura;
    int edad_t, i;
    estudiante *data_base;

    data_base = (estudiante *)malloc(SIZE_DB * sizeof(estudiante));
    FILE * fp;

    fp = fopen (name, "r");

    if(fp == NULL)
        printf("No se pudo abrir el archivo\nError: %s\n", strerror(errno));

    i = ZERO;

    while(fscanf(fp, " %[^,]", name_temp) != EOF)
    {
        (*(data_base + i)).nombre = (char *)malloc(36 * sizeof(char));

        if((*(data_base + i)).nombre == NULL)
            printf("No se puede asignar memoria a nombre: %s\n", strerror(errno));

        strcpy((*(data_base + i)).nombre, name_temp);

        fscanf(fp, " %c", &basura);

        fscanf(fp, " %[^,]", calif_temp);
        (*(data_base + i)).calif_promedio = (char *)malloc(3 * sizeof(char));

        if((*(data_base + i)).calif_promedio == NULL)
            printf("No se puede asignar memoria calificacion: %s\n", strerror(errno));

        strcpy((*(data_base + i)).calif_promedio, calif_temp);

        fscanf(fp, " %c", &basura);

        fscanf(fp, " %d", &edad_t);
        (*(data_base + i)).edad = edad_t;

        fscanf(fp, " %c", &basura);

        (*(data_base + i)).E = (escuela *)malloc(sizeof(escuela));

        if((*(data_base + i)).E == NULL)
            printf("No se puede asignar memoria a Escuela: %s\n", strerror(errno));

        fscanf(fp, "%c", &grupo_t);
        (*(data_base + i)).E->grupo = grupo_t;

        if(!invertir)
        {
            switch(grupo_t)
            {
            case 'A':
                *(totalp_grupo) += 1;
                break;
            case 'B':
                *(totalp_grupo + ONE) += 1;
                break;
            case 'C':
                *(totalp_grupo + 2) += 1;
                break;
            case 'D':
                *(totalp_grupo + 3) += 1;
                break;
            case 'E':
                *(totalp_grupo + 4) += 1;
                break;
            case 'F':
                *(totalp_grupo + 5) += 1;
                break;
            }

        }

        fscanf(fp, "%c", &basura);

        fscanf(fp, "%c", &turno_t);
        (*(data_base + i)).E->turno = turno_t;

        if(!invertir)
        {

            switch(turno_t)
            {
            case 'M':
                *(totalp_turno) += 1;
                break;
            case 'V':
                *(totalp_turno + ONE) += 1;
                break;
            }

        }

        i++;
    }

    /*el ultimo elemento apunta a NULL*/
    (*(data_base + i)).nombre = NULL;
    (*(data_base + i)).calif_promedio = NULL;

    *size = i;

    fclose(fp);

    return data_base;
}

void NumeroEstudiantesGrupo(int *vectorn)
{
    int i;

    printf("\tNumero de estudiantes por grupo\n");

    for(i = ZERO; i < 6; i++)
        printf("\t%c: %d\n", 'A' + i, *(vectorn + i));

}

void NumeroEstudiantesTurno(int *vectorn)
{
    printf("\tNumero de estudiantes por turno\n");
    printf("\tM: %d\n", *vectorn);
    printf("\tV: %d\n", *(vectorn + ONE));
}



void AltaEstudiante(char *filename, estudiante new_es, int *i)
{
    /*Funcion que agrega un nuevo estudiante al archivo, si no
    existe el archivo, entonces lo crea*/

    FILE *file = fopen(filename, "a");

    if(file == NULL)
        printf("\tNo se pudo abrir el archivo\nError: %s\n", strerror(errno));

    fprintf(file, "\n%s,%s,%d,%c,%c",\
    new_es.nombre, new_es.calif_promedio, new_es.edad,\
    new_es.E->grupo, new_es.E->turno);
    printf("\tSe ha dado de alta un nuevo estudiante\n");
    fclose(file);

    (*i)++;

}

void volteaArchivo(char *name)
{

    /*Funcion que invierte el contenido de un archivo, este lee linea por linea
    hasta llegar a la ultima, penultima... fila e imprime en un nuevo archivo,
    al final destruye el archivo original y crea uno nuevo modificado con el mismo
    nombre. Este algoritmo es eficiente en el uso de memoria, ya que solo necesita
    la cantidad necesaria para almacenar una estructura de estudiante y una estructura
    de escuela

    Parametros
    ==========
    char *name: es el nombre del archivo original*/

    char name_temp[36], calif_temp[3], grupo_t, turno_t;
    char basura, file_name_temp[] = "temporal_t.txt";
    int edad_t, i, j, k = ZERO, tamanio, l = ZERO;
    estudiante estudiante_i;
    FILE *f_temp;
    FILE *fp;

    fp = fopen (name, "r");
    f_temp = fopen(file_name_temp, "w");

    i = ZERO;

    /*la estructura dinammica son necesarias por motivos de la tarea*/
    estudiante_i.nombre = (char *)malloc(36 * sizeof(char));
    (estudiante_i).calif_promedio = (char *)malloc(3 * sizeof(char));
    (estudiante_i).E = (escuela *)malloc(sizeof(escuela));

    if(estudiante_i.nombre == NULL || (estudiante_i).E == NULL || (estudiante_i).calif_promedio == NULL)
        printf("\tNo se puede asignar memoria: %s\n", strerror(errno));


    /*cuenta el numero de lineas que hay en el archivo*/
    while(fscanf(fp, " %[^\n]", name_temp) != EOF)
    {
        i++;
    }

    /*iniciara con el numero de \n - uno, para que imprima de reversa*/
    for(j = i-ONE; j >= ZERO; j--)
    {
        /*cada vez que encuentre la fila ultima dara rewind() y contara de nuevo*/
        rewind(fp);

        while(fscanf(fp, " %[^\n]", name_temp) != EOF)
        {
            /*si el numero de \n corresponde con el siguiente entonces
            lee, crea la estructura e imprimme*/
            if(k == j)
            {
                tamanio = ZERO;
                l = ZERO;

                /*ya que leimos toda la linea es necesario contar la cantidad
                de caracteres que hay en la linea*/
                while(name_temp[l] != '\0')
                {
                    tamanio++;
                    l++;
                }

                /*regresa al inicio del renglon*/
                fseek(fp, -tamanio, SEEK_CUR);


                /*lee e imprime el nombre*/
                fscanf(fp, " %[^\,]", name_temp);
                strcpy(estudiante_i.nombre, name_temp);
                fprintf(f_temp, "%s,", estudiante_i.nombre);
                /*salta la coma*/
                fscanf(fp, " %c", &basura);
                /*lee e imprime la calificacion*/
                fscanf(fp, " %[^,]", calif_temp);
                strcpy(estudiante_i.calif_promedio, calif_temp);
                fprintf(f_temp, "%s,", estudiante_i.calif_promedio);
                /*salta la coma*/
                fscanf(fp, " %c", &basura);

                fscanf(fp, " %d", &edad_t);
                estudiante_i.edad = edad_t;
                fprintf(f_temp, "%d,", estudiante_i.edad);
                /*salta la coma*/
                fscanf(fp, " %c", &basura);

                fscanf(fp, "%c", &grupo_t);
                estudiante_i.E->grupo = grupo_t;
                fprintf(f_temp, "%c,", estudiante_i.E->grupo);
                /*salta la coma*/
                fscanf(fp, "%c", &basura);

                fscanf(fp, "%c", &turno_t);
                estudiante_i.E->turno = turno_t;
                fprintf(f_temp, "%c\n", estudiante_i.E->turno);
                k = ZERO;

                break;
            }

            k++;
        }

    }

    free( estudiante_i.nombre);
    free( estudiante_i.calif_promedio);
    free(estudiante_i.E);

    fclose(f_temp);
    fclose(fp);
    remove(name);

    if(rename(file_name_temp, name))
        printf("\tArchivo no se pudo invertir\nError: %s\n", strerror(errno));
    else
        printf("\tEl archivo se ha invertido\n");

}

void BajaEstudiante(char *file_name, estudiante baja_es, int *tamanio)
{
    /*Algoritmo que da de baja un estudiante, busca linea por linea a el estudiente mediante
    su nombre, e imprime de nuevo en un nuevo archivo*/

    char name_temp[36], calif_temp[3], grupo_t, turno_t, salto[80];
    char basura, file_name_temp[] = "temporal_baja.txt";
    int edad_t;
    estudiante estudiante_i;
    FILE *f_temp;
    FILE *file;

    file = fopen (file_name, "r");
    f_temp = fopen(file_name_temp, "w");

    if(file == NULL || f_temp == NULL)
        printf("\tNo se puede leer el archivo\nError: %s\n", strerror(errno));

    /*la estructura dinammica son necesarias por motivos de la tarea*/
    estudiante_i.nombre = (char *)malloc(36 * sizeof(char));
    (estudiante_i).calif_promedio = (char *)malloc(3 * sizeof(char));
    (estudiante_i).E = (escuela *)malloc(sizeof(escuela));

    if(estudiante_i.nombre == NULL || (estudiante_i).E == NULL || (estudiante_i).calif_promedio == NULL)
        printf("\tNo se puede asignar memoria: %s\n", strerror(errno));

        while(fscanf(file, " %[^\,]", name_temp) != EOF)
        {
            /*busqueda a traves del nombre*/
            if(strcmp(name_temp, baja_es.nombre))
            {

                strcpy(estudiante_i.nombre, name_temp);
                fprintf(f_temp, "%s,", estudiante_i.nombre);
                /*salta la coma*/
                fscanf(file, " %c", &basura);
                /*lee e imprime la calificacion*/
                fscanf(file, " %[^,]", calif_temp);
                strcpy(estudiante_i.calif_promedio, calif_temp);
                fprintf(f_temp, "%s,", estudiante_i.calif_promedio);
                /*salta la coma*/
                fscanf(file, " %c", &basura);

                fscanf(file, " %d", &edad_t);
                estudiante_i.edad = edad_t;
                fprintf(f_temp, "%d,", estudiante_i.edad);
                /*salta la coma*/
                fscanf(file, " %c", &basura);

                fscanf(file, " %c", &grupo_t);
                estudiante_i.E->grupo = grupo_t;
                fprintf(f_temp, "%c,", estudiante_i.E->grupo);
                /*salta la coma*/
                fscanf(file, " %c", &basura);

                fscanf(file, " %c", &turno_t);
                estudiante_i.E->turno = turno_t;
                fprintf(f_temp, "%c\n", estudiante_i.E->turno);
            }
            /*Se salta el estudiante que se da de baja*/
            else
                fscanf(file, " %[^\n]", salto);

        }

    free( estudiante_i.nombre);
    free( estudiante_i.calif_promedio);
    free(estudiante_i.E);

    fclose(file);
    fclose(f_temp);

    remove(file_name);

    if(rename(file_name_temp, file_name))
        printf("\tEl estudiante no se pudo dar de baja %s\n", strerror(errno));
    else
    {
        printf("\tEstudiante dado de baja\n");
    tamanio--;
    }



}
