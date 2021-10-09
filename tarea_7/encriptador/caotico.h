#ifndef CAOTICOH
#define CAOTICOH
void encriptar(char *, char *);
unsigned int *leer_audio(char *, int *);
int tamanio_archivo_bits(char *);
void guardar_audio(unsigned int *, int, char *);
unsigned int *split_bits(unsigned int number);
void caos(unsigned int *data, int tamanio);
#endif