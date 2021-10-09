#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#ifndef ZERO
#define ZERO 0
#endif
#ifndef ONE
#define ONE 1
#endif
#ifndef TRANSFORMER
#define TRANSFORMER 0xff
#endif
#define KEY1 456372
#define KEY2 4372
#define KEY3 56
#define B 787
#define M 5
#define EPSILON 65395
#define INICIO 44

int tamanio_archivo_bits(char *name)
{
    /*funcion que retorna el tamanio en
    bits de un archivo, en bits.
    Parametros
    ===========
    char *name: es el nombre del archivo que
    se lee*/

    int size;
    FILE *file = fopen(name, "rb");

    if (file == NULL)
    {
        printf("No se puede abrir el archivo:\n %s\n", strerror(errno));
        return ZERO;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fclose(file);

    return size;
}

unsigned int *leer_audio(char *name, int *tamanio)
{
    /*Funcion que lee los datos en bits de un
    archivo de audio

    Parametros
    ===========
    char *name: es el nombre del archivo de audio
    int *tamanio: sera el tamanio del archivo, esta variable
    la podemos ver como un variable de retorno
    
    Retorna
    =======
    int *data: es un vector con la informacion del archivo*/

    FILE *file;
    int i, t;
    unsigned int *data;

    *tamanio = tamanio_archivo_bits(name);

    if (*tamanio == ZERO)
    {
        return NULL;
    }

    data = (unsigned int * )malloc(*tamanio * sizeof(unsigned int));

    if (data == NULL)
    {
        printf("No hay suficiente memoria Error: \n", errno);
    }

    file = fopen(name, "rb");

    if (file == NULL)
    {
        printf("No se puede abrir el archivo: \n%s\n", strerror(errno));
        return NULL;
    }

    fread(data, 2, *tamanio / 2, file);

    fclose(file);

    return data;
}

void guardar_audio(unsigned int *data, int tamanio, char *name)
{
    /*funcion que guarda un archivo de audio
    
    Parametros
    ===========
    int *data: es la informacion del archivo que se guardara
    int tamanio: es la cantidad de bits que contiene
    char *name: es el nombre del archivo donde se guarda data*/

    FILE *file;

    file = fopen(name, "wb");

    if (file == NULL)
        printf("No se puede guardar el audio: \n%s\n", strerror(errno));
    else
        fwrite(data, ONE, tamanio, file);

    fclose(file);
}

unsigned int *split_bits(unsigned int number)
{
    /*Funcion que separa los bits de un numero, puede entregar un
    array de 4 o de 8 casillas segun el compilador

    Ejemplo 
    
    Parametros
    ===========
    unsigned int number: el numero al cual se le realizara el split*/

    int bytes, i;
    unsigned int *b, trans = TRANSFORMER;

    /*se comprueba el tamanio que asigna el compilador a los enteros
    sin signo*/
    bytes = sizeof(unsigned int);
    b = (unsigned int *)malloc(bytes * sizeof(unsigned int));

    if (b == NULL)
    {
        printf("No hay memoria suficiente\nError: %s\n", strerror(errno));
        return NULL;
    }

    for (i = ZERO; i < bytes - ONE; i++)
    {
        /*TRANSFORMER = 0xff esto para obtener cada bloque*/
        *(b + i) = number & trans;
        number >>= 8;
    }

    return b;
}

void caos(unsigned int *data, int tamanio)
{
    /*funcion que encripta un archivo de audio
    utilizando mapas caoticos
    
    Parametros
    ==========
    int * data: es la informacion que se obtiene
    al leer el archivo de audio
    int tamanio: es el tamanio en bits del archivo
    de audio*/

    int i, j;
    unsigned int x, y, z, k1 = KEY1, k2 = KEY2;
    unsigned int acopla, e = EPSILON;
    unsigned int *b1, *b2, *b3, b = B, m = M, k3 = KEY3;

    i = INICIO / 2;

    /*recorre todo el archivo*/
    while (i < tamanio / 2)
    {
        /*son las llaves de inicio*/
        if (i == INICIO / 2)
        {
            x = k1;
            y = k2;
            z = k3;
        }
        else
        {
            acopla = e & (x ^ y ^ z);
            x = b * x + (unsigned int)(x >> m) + acopla;
            y = b * y + (unsigned int)(y >> m) + acopla;
            z = b * z + (unsigned int)(z >> m) + acopla;
        }

        /*funcion que separa por bloques el numero
        encontrado*/
        b1 = split_bits(x);
        b2 = split_bits(y);
        b3 = split_bits(z);

        /*aplica la transformacion a cada bit del archivo*/
        for (j = ZERO; j < sizeof(unsigned int); j++)
            *(data + j + i) ^= *(b1 + j);

        /*los aumentos en i dependen del tamanio
        de los enteros, pueden ser 4 u 8*/
        i += j;

        for (j = ZERO; j < sizeof(unsigned int); j++)
            *(data + j + i) ^= *(b2 + j);

        i += j;

        for (j = ZERO; j < sizeof(unsigned int); j++)
            *(data + j + i) ^= *(b3 + j);

        i += j;

        free(b1);
        free(b2);
        free(b3);
        /*aqui ya ha terminado de aplicar el mapeo*/
    }

}

void encriptar(char *name, char *name_save)
{
    /*funcion que ordena leer un archivo de audio y despues
    aplica un mapeo caotico para encriptarlo, despues esto
    se guarda en un nuevo archivo
    
    Parametros
    ===========
    char *name: es el nombre del archivo que se leera*/

    int tamanio, i;
    unsigned int *data;

    data = leer_audio(name, &tamanio);
    /*Se aplica el mapeo caotico el cual encripta el audio*/
    caos(data, tamanio);
    /*se guarda en un archivo .wav el archivo encriptado*/
    guardar_audio(data, tamanio, name_save);

    free(data);
}