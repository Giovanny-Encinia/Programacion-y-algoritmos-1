#ifndef MOVING33
#define MOVING33

#ifndef ZERO
#define ZERO 0
#endif /*ZERO*/

#ifndef ONE
#define ONE 1
#endif /*ONE*/
double mediana(double *array, int size);
void selection_sort(float *ordenado, int size);
double promedio(double *array, int size);
double **moving_3_3(double **matrix, int m, int n, double (*f)(double *array, int size));
#endif /*MOVING33*/
