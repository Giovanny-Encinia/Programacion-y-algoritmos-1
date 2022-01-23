//Giovanny Encinia
//31/08/2021
#include <stdio.h>
#define ZERO 0
#define ONE 1
#define SIZE 20

void merge(int a[], int l_1, int b[],\
            int l_2, int c[], int l_3)
{
    /*Junta dos arreglos en un nuevo arreglo*/

    int i = ZERO, j = ZERO, k = ZERO;

    while(i  < l_1)
    {
        c[k] = a[i++];
        k++;
    }

     while(j  < l_2)
    {
        c[k] = b[j++];
        k++;
    }

}

void merge_(int a[], int left, int mid, int right, int order)
{
    /*Es el pado merge del algoritmo merge sort*/

    int l_1, r_1, k, i = ZERO, j = ZERO;

    l_1 = mid - left + ONE;
    r_1 = right - mid;
    //Arreglos que nos ayudan a almacenar
    //divisiones del original
    int L[l_1], R[r_1];

    while(i < l_1)
    {
        //nuestro punto de referencia
        //siempre es left, este cambia
        //conforme avanza la recursividad
        L[i] = a[left + i];
        i++;
    }

    while(j < r_1)
    {
        R[j] = a[mid + j + ONE];
        j++;
    }

    i = j = ZERO;
    k = left;

    while(i < l_1 && j < r_1)
    {
        //oder 1 creciente
        // 0 decreciente
        if(order?(L[i] < R[j]): (L[i] > R[j]))
        {
            a[k] = L[i++];
        }
        else
        {
            a[k] = R[j++];
        }

        k++;
    }

    //pueden haber sobrado datos
    //sin ordenar, asi que se llena
    //con el sobrente
    while(i < l_1)
    {
        a[k] = L[i++];
        k++;
    }

    while(j < r_1)
    {
        a[k] = R[j++];
        k++;
    }

}

void merge_sort(int a[], int left, int right, int order)
{
    /*algoritmo merge sort*/

    int mid;

    if(left < right)
    {
        //buscamos el punto medio
        mid = left + (right - left) / 2;

        //recursdividad a laprimera mitad
        merge_sort(a, left, mid, order);
        //segunda mitad
        merge_sort(a, mid + ONE, right, order);
        //realiza merge a las mitades
        merge_(a, left, mid, right, order);
    }

}

void print_array(int a[], int size)
{
    int i = ZERO;

    printf("\t\t");
    while(i < size)
    {
        printf("%d ", a[i++]);
    }

    printf("\n");
}

int leer_arreglo(int array[])
{
    /*Lee cada uno de los elementos
    que tendra el arreglo
    el tamanio maximo es de 20 elementos*/

    int tamanio, i = ZERO;

    printf("\t\tCuantos elementos tendra \
el arreglo (maximo 20)?\n\t\t");
    scanf(" %d", &tamanio);

    while(i < tamanio)
    {
        printf("\t\tAgregue el elemento %d\n\t\t", i);
        scanf(" %d", &array[i++]);
    }

    printf("\n\n");

    return tamanio;
}

int compare(int a[], int b[], int tamanio)
{
    /*Compara cada elemento de los arreglos
    y regresa 1 si son inguales ambos arreglos
    0 si son distintos*/

    int i = ZERO;

    while(i < tamanio)
    {
        if(a[i] != b[i])
        {
            return ZERO;
        }

        i++;
    }

    return ONE;
}

void copy_array(int a[], int copy[], int size)
{
    /*Copia elementos a un nuevo arreglo*/

    int i = ZERO;

    while(i < size)
    {
        copy[i] = a[i];
        i++;
    }

}

int write_copia_comprueba(int a[], int a_c[])
{
    int tamanio;

    printf("\t\tAgregue los \
elementos del arreglo\n");
    tamanio = leer_arreglo(a);
    copy_array(a, a_c, tamanio);
    merge_sort(a_c, ZERO, tamanio - ONE, ZERO);

    // comprueba que no este en orden decreciente
    if(compare(a, a_c, tamanio))
    {
        printf("\t\tAgregue un arreglo \
que no este en orden decreciente\n");

        return ZERO;
    }

    return tamanio;
}
