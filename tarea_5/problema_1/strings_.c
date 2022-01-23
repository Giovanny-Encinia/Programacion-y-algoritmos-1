#define ZERO 0
#define ONE 1

void quitar_salto(char *str)
{
    /*esta funcion se crea con el fin de quitar los espacios
    los saltos de lineas leidos por terminal*/

    int i = ZERO;

    while(*(str + i) != '\0' && *(str + i) != 10)
        i++;

    *(str + i) = '\0';

}

int size(char *str)
{
    /*regresa el tamnio del str
    str: es el char[] que contiene la palabra, str, etc

    regreda el tamanio del str*/
    int i = ZERO;

    while(*(str + i) != '\0')
        i++;

    return i;
}

void minusculas(char *str)
{
    /*convierte letras a minusculas,
    se trata que el programa no sea sensible
    a mayusculas o minusculas*/
    int i = ZERO;


    while(*(str + i) != '\0')
    {
        if(*(str + i) <= 90 && *(str + i) >= 65)
            *(str + i) += 32;

        i++;
    }

}

int cuenta_chars(char* palabra, char c)
{
    /*cuenta las coincidencias de un caracter
    dentro de un string

    parametros
    ==========
    char * palabra: el string en donde se realizara la
    busqueda

    char c: el caracter que se buscara

    return
    ======
    itn count: es el numero de coincidencias*/

    int i, count;

    i = count = ZERO;

    minusculas(palabra);

    if(c <= 90 && c >= 65)
            c += 32;

    while(*(palabra + i) != '\0')
    {
        if(*(palabra + i) == c)
            count++;

        i++;
    }

    return count;
}

char *str_to_dynamic(char *str)
{
    int tamanio, i;
    char *r;

    quitar_salto(str);
    tamanio = size(str);
    r = (char *)malloc((tamanio + ONE) * sizeof(char));

    for(i = ZERO; i < tamanio + ONE; i++)
        *(r + i) = *(str + i);

    return r;
}
