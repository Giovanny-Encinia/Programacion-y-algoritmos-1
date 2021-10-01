#ifndef FUNCIONESESTUDIANTES_
#define FUNCIONESESTUDIANTES_
void AltaEstudiante(char *filename, estudiante new_es, int *i);
void NumeroEstudiantesGrupo(int *vectorn);
void NumeroEstudiantesTurno(int *vectorn);
estudiante *leer_archivo(char *name, int *totalp_grupo, int *totalp_turno, int *size, int invertir);
void Imprimirarchivo(estudiante *data_base);
int compara_nombre(estudiante, estudiante);
int compara_edad(estudiante, estudiante);
int compara_promedio(estudiante, estudiante);
void merge_(estudiante *, int, int, int, int (*f)(estudiante, estudiante));
void merge_sort(estudiante *, int, int, int (*f)(estudiante, estudiante));
void free_data_base(estudiante *, int i);
void volteaArchivo(char *name);
void BajaEstudiante(char *file_name, estudiante baja_es);
#endif /* FUNCIONESESTUDIANTES_*/
