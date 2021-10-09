#ifndef CAOTICOH
#define CAOTICOH
void encriptar(char *name);
unsigned int *leer_audio(char *name, int *tamanio);
int tamanio_archivo_bits(char *name);
void guardar_audio(unsigned int *data, int tamanio, char *name);
#endif