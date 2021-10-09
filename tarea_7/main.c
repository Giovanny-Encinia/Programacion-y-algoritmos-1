#include <stdio.h>
#include "encriptador/caotico.h"

int main(void)
{
    char female[] = "files/ftea_10k.wav";
    char male[] = "files/mtea_10k.wav";
    int option;

    /*encripta directamente con los mapeos*/
    encriptar(male, "resultados/directo/m_encriptado.wav", 0);
    encriptar(female, "resultados/directo/f_encriptado.wav", 0);

    /*desencriptar, se aplica la misma funcion
    pero ahora con el archivo encriptado*/
    encriptar("resultados/directo/m_encriptado.wav", "resultados/directo/m_desencriptado.wav", 0);
    encriptar("resultados/directo/f_encriptado.wav", "resultados/directo/f_desencriptado.wav", 0);

    /*encripta con split en los mapeos*/
    encriptar(male, "resultados/split/m_encriptado.wav", 1);
    encriptar(female, "resultados/split/f_encriptado.wav", 1);

    /*desencriptar, se aplica la misma funcion
    pero ahora con el archivo encriptado*/
    encriptar("resultados/split/m_encriptado.wav", "resultados/split/m_desencriptado.wav", 1);
    encriptar("resultados/split/f_encriptado.wav", "resultados/split/f_desencriptado.wav", 1);
}