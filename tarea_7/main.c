#include <stdio.h>
#include "encriptador/caotico.h"

int main(void)
{
    char female[] = "files/ftea_10k.wav";
    char male[] = "files/mtea_10k.wav";

    /*encripta*/
    encriptar(male, "resultados/m_encriptado.wav");
    encriptar(female, "resultados/f_encriptado.wav");

    /*desencriptar, se aplica la misma funcion
    pero ahora con el archivo encriptado*/
    encriptar("resultados/m_encriptado.wav", "resultados/m_desencriptado.wav");
    encriptar("resultados/f_encriptado.wav", "resultados/f_desencriptado.wav");
}