#include "strings_.h"
#include <stdlib.h>
#include <stdio.h>
int count_word(char *palabra, char *str)
{
    /*Funcion que encuentra el numero de repeticiones de
    una palabra/ str/ char en una cadena de caracteres

    Parametros
    ===========
    char * palabra: es la cadena de caracteres donde
    se hara la busqueda

    char *str: es lo que se buscara dentro de palabra

    return
    =======
    regresa el numero de coincidencias encontradas*/

    int count, tamanio, j, i, same_c, tamanio_p;

    i = j = count = same_c = ZERO;

    /*quita saltos de linea si es que existen*/
    quitar_salto(palabra);
    quitar_salto(str);


    minusculas(palabra);
    minusculas(str);

    /*tamanio de la palabra que se buscara*/
    tamanio = size(str);
    tamanio_p = size(palabra);

    /*si lo que se busca es mayor no
    se encontrara nunca*/
    if(tamanio > tamanio_p)
        return ZERO;

    /*revisa todo el string, o palabra donde se busca*/
    while(*(palabra + i) != '\0')
    {
        j = ZERO;
        same_c = ZERO;

        /*busca las coincidencias con la palabra a busccar*/
        while(*(str + j) != '\0')
        {

            if(*(str + j) == *(palabra + i + j))
                same_c += ONE;

            j++;
        }

        /*si el numero de coincidencias es
        el tamanio de la palabra a buscar entonces
        encontreo una palabra*/

        if(same_c == tamanio)
            count += ONE;

        i++;
    }

    return count;
}

void free_char(char **str)
{
    /*funcion que libera memoria
    char** */
    int i = ZERO;

    while(*(str + i) != NULL)
    {
        free(*(str + i));
        i++;
    }

    free(*(str + i));
    free(str);

}

char **tokens(char *str, char ch)
{
    /*funcion que hace split a un string
    el split se realiza a partir de un caracter dado

    parametros
    ==========
    char *str: es en donde se aplicara la funcion de split
    char ch: es el caracter que servira como separedor

    return
    ======
    **datos: apuntador a string separados, el ultimo elemmento es un NULL*/

    int sum, i, tamanio, count, k, j, l;
    char **datos;
    int *number_split, diff_zero;

    sum = k = i = count = ZERO;
    /*asegura que no se lean saltos de linea*/
    quitar_salto(str);
    tamanio = size(str);
    number_split = (int *)calloc(tamanio, sizeof(int));

    /*cuenta el numero de caracteres distintos a
    ch*/
    while(*(str + i) != '\0')
    {

        if(*(str + i) != ch)
        {
            *(number_split + k) += ONE;
            count++;
        }
        else
        {
            k++;
        }

        i++;
    }

    /*no existe el separador*/
    if(count == tamanio)
        return NULL;

    /*un marcador*/
    *(number_split + k) = -ONE;

    i = ZERO;

    while(*(number_split + i) != -ONE)
    {
        sum += *(number_split + i);
        i++;
    }

    /*si quedan remanentes los agrega*/
    *(number_split + k++) = count - sum;
    *(number_split + k) = -ONE;

    diff_zero = i = ZERO;

    while(*(number_split + i) != -ONE)
    {

        if(*(number_split + i) != ZERO)
        {
            diff_zero++;
        }

        i++;
    }


    datos = (char **)malloc((diff_zero + ONE) * sizeof(char *));
    i = ZERO;
    l = ZERO;

    /*pide memoria para cada string que se almacenara
    se toma encuenta que habra un '\0' al final de cada
    string*/
    while(*(number_split + i) != -ONE)
    {

        if(*(number_split + i) != ZERO)
        {
            *(datos + l)  = (char *)malloc(((*(number_split + i)) + ONE) * sizeof(char));
            l++;
        }


        i++;
    }

    *(datos + l) = NULL;

    i = ZERO;
    j = ZERO;
    l = k = ZERO;

    while(*(str + i) != '\0')
    {

        if(*(str + i) != ch)
        {
            if(*(number_split + k) != ZERO)
            {

                j = ZERO;

                while(j < *(number_split + k))
                {
                    *(*(datos + l) + j) = *(str + i + j);
                    j++;
                }

                *(*(datos + l) + j) = '\0';
                l++;
                i += *(number_split + k);

            }

                k++;
        }
        else
        {
            i++;
        }

    }

    free(number_split);

    return datos;

}

char *concatena(char *str1, char *str2)
{
    /*funcion que recibe dos cadenas de caracteres creadas con
    memoria dinamica y las concatena*/
    int tamanio, t, i;

    tamanio = size(str1);
    t = tamanio;
    tamanio += size(str2);

    str1 = (char *)realloc(str1, (tamanio + ONE)*sizeof(char));

    for(i=ZERO; i< tamanio; i++)
        *(str1 + i + t) = *(str2 + i);

    *(str1 + i + t) = '\0';

    free(str2);
    return str1;
}
