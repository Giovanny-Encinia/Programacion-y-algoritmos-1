#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#ifndef ZERO
#define ZERO 0
#endif
#ifndef ONE
#define ONE 1
#endif
#ifndef TRANSFORMER
#define TRANSFORMER 0xff
#endif

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

    data = (unsigned int *)malloc(*tamanio * sizeof(unsigned int));

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

    fread(data, sizeof(unsigned int), *tamanio, file);

    fclose(file);

    return data;
}

void caos(int *data)
{
    /*funcion que encripta un archivo de audio
    utilizando mapas caoticos
    
    Parametros
    ==========
    int * data: es la informacion que se obtiene
    al leer el archivo de audio*/
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
    unsigned int *b;

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
        *(b + i) = number & TRANSFORMER;
        number >>= 8;
    }

    return b;
}

void encriptar(char *name)
{
    /*funcion que ordena leer un archivo de audio y despues
    aplica un mapeo caotico para encriptarlo, despues esto
    se guarda en un nuevo archivo
    
    Parametros
    ===========
    char *name: es el nombre del archivo que se leera*/

    int tamanio, i;
    unsigned int *data, *b;

    data = leer_audio(name, &tamanio);
    printf("El tamanio es: %d\n", tamanio);
    printf("tamanio %lu\n", sizeof(int));

    guardar_audio(data, tamanio, "resultados/test.wav");

    b = split_bits(10448643);

    for (i = ZERO; i < sizeof(unsigned int); i++)
        printf("%u ", *(b + i));

    free(data);
    free(b);
}