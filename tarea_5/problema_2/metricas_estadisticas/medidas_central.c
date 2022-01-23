#define ZERO 0
#define ONE 1
#define TWO 2

void selection_sort(double *ordenado, int size)
{
    /*Elige a las primeros 10 probabilidades
    mayores*/
    int i= ZERO, j = ZERO, index = ZERO;
    double min, temp;

    /*ordena hasta la mitad*/
    while(i <= (size - ONE)/ TWO)
    {

        j = i;
        min = *(ordenado + i);

        while(j < size)
        {
            if(*(ordenado + j) <= min)
            {
                index = j;
                min = *(ordenado + j);
            }

            j++;
        }

        temp = *(ordenado + i);
        *(ordenado + i) = min;

        *(ordenado + index) = temp;
        i++;
    }

}

double mediana(double *array, int size)
{
    selection_sort(array, size);

    return *(array + (size - ONE) / TWO);
}

double promedio(double *array, int size)
{
    double sum = ZERO;
    int i;

    for(i=ZERO; i < size; i++)
    {
        sum += *(array + i);
    }

    return sum / (double)size;
}
