#include <stdio.h>
#define SIZE 50
#define ZERO 0
#define ONE 1

int read_array(int []);
void print_array(int [], int);
int producto(int [], int, int);
void products(int [], int [],\
               int);

int read_array(int a[])
{
    int i = 0, number;

    printf("\t\tIngrese el numero \
de elementos maximo 50\n\t\t");
    scanf(" %d", &number);

    while(i < number)
    {
        printf("\t\tI\
ngrese el elemento %d\n\t\t", i);
        scanf(" %d", &a[i++]);
    }


    return number;
}

void print_array(int a[], int length)
{

    int i = 0;

    printf("\t\t");
    while(i < length)
    {
        printf("%d ", a[i++]);
    }
    printf("\n\n");
}

int producto(int a[], int index, int length)
{
    /*Realiza el producto de cada uno de los
    elementos del arreglo*/

    int i = ZERO, pro = ONE;

    while(i < length)
    {
        if(i == index)
        {
            i++;
            continue;
        }

        pro *=  a[i++];
    }

    return pro;
}

void products(int a[], int product[],\
               int length)
{
    /*Asigna el producto del areglo
    a un elemento del nuevo arreglo
    evitando el elemento i del
    arreglo original*/

    int i = ZERO, prod = ONE;
    int count = ZERO, index;
    int activate_index;

    //cuantsa cuantos ceros
    // hay en el arreglo
    while(i < length)
    {
        if(a[i] == ZERO)
        {
            count++;
            index = i;
        }

        i++;
    }

    switch(count)
    {
    case ZERO:// no hay ceros
        activate_index = ZERO;
        //menos uno es para poder
        //multiplicar todos los elementos
        prod = producto(a, -ONE, length);
        break;
    case ONE://hay un cero
        // producto que tendra el elemento
        //con cero
        //ademas que se activa en el if
        //si hay valor
        activate_index = \
        producto(a, index, length);
        prod = ZERO;
        break;
    default:
        activate_index = ZERO;
        prod = ZERO;
    }

    i = ZERO;

    while(i < length)
    {
        //existe solo un 0
        if(activate_index)
        {

            if(i == index)
            {
                product[i] = activate_index;
            }
            else
            {
                product[i] = ZERO;
            }

        }
        else
        {
            //existe mas de un 0
            if(prod == ZERO)
            {
                product[i] = ZERO;
            }
            //no existe ningun 0
            else
            {
                product[i] = prod/a[i];
            }

        }

        i++;
    }

}


int main()
{
    int a[SIZE], b[SIZE], l_1;

    //lee y obtiene #elementos
    l_1 = read_array(a);
    //obtiene arreglo productos
    products(a, b, l_1);
    printf("\n\t\tEl arreglo \
original es:\n");
    print_array(a, l_1);
    printf("\t\tEl arreglo con \
oroductos es:\n");
    print_array(b, l_1);

    return ZERO;
}
