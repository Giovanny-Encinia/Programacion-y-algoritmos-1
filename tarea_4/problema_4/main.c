#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define ALCANCE 5000
#define TAMANIO 12
#define SIZE(a) (sizeof(array) / sizeof(*array))

void find_three_largest(const int *a, int len_a, int *largest, \
  int *index_largest, int *second_largest, int *second_index_largest,\
  int *third_largest, int *third_index_largest);
int in(int move, int *memo);

int in(int move, int *memo)
{
    /*verifica que el
    movimiento no se haya hecho antes
    si se hizo regresa ONE
    de lo contrario ZERO*/
    int i = ZERO;

    while(i < THREE)
    {
        if(*(memo + i) == move)
        {
            return ONE;
        }

        i++;
    }

    return ZERO;
}

void find_three_largest(const int *a, int len_a, int *largest, \
  int *index_largest, int *second_largest, int *second_index_largest,\
  int *third_largest, int *third_index_largest)
{
  int i = ZERO, j = ZERO, k = ZERO;
  int maxi, index;
  int *temp = (int *)malloc(THREE * sizeof(int));

  for(i = ZERO; i < THREE; i++)
  {
    *(temp + i) = -1;
  }

  i = ZERO;

  while (i < len_a)
  {
    j = i;


    if(in(i, temp))/*asegura que no sea repetido*/
    {
      i++;
      continue;
    }

    maxi = *(a + i);

    while(j < len_a)
    {
      if(in(j, temp))/*asegura que no sea repetido*/
      {
        j++;
        continue;
      }

      if(*(a + j) >= maxi)
      {
        index = j;
        maxi = *(a + j);
      }

      j++;
    }

    if(in(index, temp))/*asegura que no sea repetido*/
    {
      i++;
      continue;
    }

    *(temp + k) = index;

    switch (k)
    {
      case ZERO:
        *largest = *(a + index);
        *index_largest = index;
        break;
      case ONE:
        *second_largest = *(a + index);
        *second_index_largest = index;
        break;
      case TWO:
        *third_largest = *(a + index);
        *third_index_largest =  index;
        break;
    }/*end switch*/

    k++;

    if(k == THREE)/*variable control*/
      break;

    i++;

    }

    free(temp);
}


void llenar_arreglo(int *array, int tamanio)
{
  /*llena el arreglo con numeros aleatorios*/
  int i;

  srand(time(NULL));

  for(i = ZERO; i < tamanio; i++)
  {
    array[i] = rand() % ALCANCE;
  }

}

void imprimir_arreglo(int *array, int tamanio)
{
  int i;

  printf("==============================================================\n");
  printf("%s\n", "El arreglo es:\n");

  for(i = ZERO; i < tamanio;  i++)
  {
    printf("%d ", array[i]);
  }

}

void imprimir_resultado(int m_1, int i_1, int m_2, int i_2, int m_3, int i_3)
{
  printf("\n==============================================================\n");
  printf("Estos son los numeros mas altos y sus correspondientes indices\n");
  printf("indice %d, numero %d\n", i_1, m_1);
  printf("indice %d, numero %d\n", i_2, m_2);
  printf("indice %d, numero %d\n", i_3, m_3);
}

int main(void)
{
  int m_1, m_2, m_3, i_1, i_2, i_3, tamanio;
  int array[TAMANIO];

  tamanio = SIZE(array);
  llenar_arreglo(array, tamanio);
  find_three_largest(array, tamanio, &m_1, &i_1, &m_2, &i_2, &m_3, &i_3);
  imprimir_arreglo(array, tamanio);
  imprimir_resultado(m_1, i_1, m_2, i_2, m_3, i_3);

  return ZERO;
}
