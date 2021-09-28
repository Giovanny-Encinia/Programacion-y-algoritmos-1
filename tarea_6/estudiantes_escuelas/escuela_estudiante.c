#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "escuela_estudiante.h"
/*Giovanny Encinia*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 60/*numero de latras por nombre en promedio*/
#define N 100/*numero de nombres en total*/
#define ZERO 0
#define ONE 1
#define TWO 2
#define SIZE_DB 100


int compara_nombre(estudiante, estudiante);
void merge_(estudiante *, int, int, int, int (*f)(estudiante, estudiante));
void merge_sort(estudiante *, int, int, int (*f)(estudiante, estudiante));
void free_data_base(estudiante *, int i);

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

int compara_promedio(estudiante a, estudiante b)
{
    char *cal1 = a.calif_promedio;
    char *cal2 = b.calif_promedio;

    /*La calificacion es mayor en la letra*/
    if(*cal1 < *cal2)
        return ONE;

    /*si son la misma letra se fija en el signo +*/
    if(*(cal1 + ONE) == '+')
        return ONE;

    /*si son iguales y no es signo mas, compara el sin signo que es mayor al negativo*/
    if(*(cal1 + ONE) == '\0' && *(cal2 + ONE) == '-')
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

    while((*(data_base + i)).nombre != NULL && (*(data_base + i)).calif_promedio != NULL)
    {
        printf("%s %s %d %c %c\n",(*(data_base + i)).nombre,\
        (*(data_base + i)).calif_promedio, (*(data_base + i)).edad,\
        (*(data_base + i)).E->grupo, (*(data_base + i)).E->turno);
        i++;
    }

}

struct estudiante *leer_archivo(char *name)
{
  /*Esta funcion sirve para saber cuantos nombres
  hay, y la cantidad de letras que contiene cada uno

  count: se guardara el numero de nombres que hay en el archivo
  total_letras: guarda la cantidad total de c_letras
  */

    char name_temp[36], calif_temp[3], grupo_t, turno_t;
    char basura;
    int edad_t, i;
    estudiante *data_base;
    int (*f_n)(estudiante);
    int (*f_p)(estudiante);

    f_n = &compara_nombre;
    f_p = &compara_promedio;

    data_base = (estudiante *)malloc(SIZE_DB * sizeof(estudiante));
    FILE * fp;

    fp = fopen (name, "r");

    i = ZERO;
    while(fscanf(fp, " %[^,]", name_temp) != EOF)
    {

        fscanf(fp, " %[^,]", name_temp);
        (*(data_base + i)).nombre = (char *)malloc(36 * sizeof(char));
        strcpy((*(data_base + i)).nombre, name_temp);

        fscanf(fp, " %c", &basura);

        fscanf(fp, " %[^,]", calif_temp);
        (*(data_base + i)).calif_promedio = (char *)malloc(3 * sizeof(char));
        strcpy((*(data_base + i)).calif_promedio, calif_temp);

        fscanf(fp, " %c", &basura);

        fscanf(fp, " %d", &edad_t);
        (*(data_base + i)).edad = edad_t;

        fscanf(fp, " %c", &basura);

        (*(data_base + i)).E = (escuela *)malloc(sizeof(escuela));

        fscanf(fp, "%c", &grupo_t);
        (*(data_base + i)).E->grupo = grupo_t;

        fscanf(fp, "%c", &basura);

        fscanf(fp, "%c", &turno_t);
        (*(data_base + i)).E->turno = turno_t;

        /*printf("%s %s %d %c %c", name_temp, calif_temp, edad_t, grupo_t, turno_t);*/

        i++;
    }

    /*el ultimo elemento apunta a NULL*/
    (*(data_base + i)).nombre = NULL;
    (*(data_base + i)).calif_promedio = NULL;


    Imprimirarchivo(data_base);

    merge_sort(data_base, 0, i-1, f_n);
printf("\n");
    Imprimirarchivo(data_base);

    merge_sort(data_base, 0, i-1, f_p);
    printf("\n");
Imprimirarchivo(data_base);
    free_data_base(data_base, i);



    fclose(fp);

    return data_base;
}



/*
int main()
{
  int i;
  int *number_letra, count = ZERO, total_letras = ZERO;
  char **data_base;

  data_base = contar_letras_palabras(&count);
  printf("%s\n", "La lista original es:");
  printf("==========================================\n");

  for(i=ZERO; i < count; i++)
  {
    printf("%s\n", data_base[i]);
  }

  printf("\n\n");
  merge_sort(data_base, ZERO, count - ONE);
  printf("%s\n", "La lista ordenada por nombre es");
  printf("==========================================\n");

  for(i=ZERO; i < count; i++)
  {
    printf("%s\n", data_base[i]);
  }

  free_data_base(data_base);

  return ZERO;
}*/


int NumeroEstudiantesGrupo()
{

}
int NumeroEstudiantesTurno()
{

}

void BajaEstudiante()
{

}

void AltaEstudiante()
{

}

void InvertirArchivo()
{

}
