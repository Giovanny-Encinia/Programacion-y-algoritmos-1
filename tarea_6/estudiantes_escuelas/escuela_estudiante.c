#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/*Giovanny Encinia*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 60/*numero de latras por nombre en promedio*/
#define N 100/*numero de nombres en total*/
#define ZERO 0
#define ONE 1
#define TWO 2

int inicio_nombre(char *);
int compara_nombre(char *, char *);
void merge_(char **, int, int, int);
void merge_sort(char **, int, int);
char **contar_letras_palabras(int *);
void free_data_base(char **);

int inicio_nombre(char *nombre)
{
  int count = ZERO, i =ZERO;

  while (*(nombre+i) != '\0')
  {
    if(*(nombre +  i) == 44)
      count++;

    if(count == TWO)
      break;

    i++;
  }

  return i;
}

int compara_nombre(char *primero, char *segundo)
{
  /*Compara caracter por caracter
  se basa en el codigo ASCII, el simbolo espacio es
  menor a simbolos del abecedario*/

  int i, j, r = ONE;

  /*busca donde iniccia el nombre*/
  i =  inicio_nombre(primero);
  j = inicio_nombre(segundo);

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

void merge_(char **a, int left, int mid, int right)
{
    /*Es el paso merge del algoritmo merge sort*/

    int l_1, r_1, k, i = ZERO, j = ZERO;

    l_1 = mid - left + ONE;
    r_1 = right - mid;
    /*Arreglos que nos ayudan a almacenar
    divisiones del original*/
    char **L = (char **)malloc(l_1 * sizeof(char*));
    char **R = (char **)malloc(r_1 * sizeof(char*));

    while(i < l_1)
    {
        /*nuestro punto de referencia
        siempre es left, este cambia
        conforme avanza la recursividad*/
        *(L + i) = *(a + left + i);
        i++;
    }

    while(j < r_1)
    {
        *(R + j) = *(a + mid + j + ONE);
        j++;
    }

    i = j = ZERO;
    k = left;

    while(i < l_1 && j < r_1)
    {
        if(compara_nombre(*(L + i), *(R + j)))
        {
            *(a + k) = *(L + i++);
        }
        else
        {
            *(a + k) = *(R + j++);
        }

        k++;
    }

    /*pueden haber sobrado datos
    sin ordenar, asi que se llena
    con el sobrente*/
    while(i < l_1)
    {
        *(a + k) = *(L + i++);
        k++;
    }

    while(j < r_1)
    {
        *(a + k) = *(R + j++);
        k++;
    }

    free(L);
    free(R);

}/*end merge*/

void merge_sort(char **a, int left, int right)
{
    /*algoritmo merge sort*/

    int mid;

    if(left < right)
    {
        /*buscamos el punto medio*/
        mid = left + (right - left) / 2;

        /*recurividad a laprimera mitad*/
        merge_sort(a, left, mid);
        /*segunda mitad*/
        merge_sort(a, mid + ONE, right);
        /*realiza merge a las mitades*/
        merge_(a, left, mid, right);
    }

}

char **contar_letras_palabras(int *count)
{
  /*Esta funcion sirve para saber cuantos nombres
  hay, y la cantidad de letras que contiene cada uno

  count: se guardara el numero de nombres que hay en el archivo
  total_letras: guarda la cantidad total de c_letras
  */

  char letra;
  int i, j;
  /*en data_base se guardaran todos los nombres*/
  char **data_base = (char **)malloc(N * sizeof(char*));

  /*Crea las particiones de la base de datos, en donde se
  almacenaran los nombres*/
  for(i = ZERO; i < N; i++)
  {
    *(data_base + i) = (char *)malloc(TAMANIO * sizeof(char));
  }

  j = i = ZERO;

  while(scanf("%c", &letra) != EOF)
  {
    *(*(data_base + i) + j) = letra;
    j++;

    /*El 10 corresponde al salto de linea en codigo ASCII*/
    if(letra == 10)
    {
      /*el ultimo caracter es un salto de linea
      y lo transformamos en caracter especial para que
      ahora sea un string*/
      *(*(data_base + i) + j - ONE) = '\0';
      (*count)++;
      j = ZERO;
      i++;
    }

  }

  return data_base;
}

void free_data_base(char **data_base)
{
  free(*(data_base));
  free(data_base);
}

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
}

void Imprimirarchivo()
{

}
void OrdenarNombre()
{

}
void OrdenarEdad()
{

}

void OrdenarPromedio()
{

}
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
