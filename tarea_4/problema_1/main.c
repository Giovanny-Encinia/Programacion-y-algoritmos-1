#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 10
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define TIMESLEEP 350000

#ifdef _WIN32
  #include<windows.h>
#endif

void clean()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif

}

int in(int, int *);
void print_tablero(char **);
int *caminata_aleatoria(char **, int *);
void free_tablero(char **);
char **crear_tablero(void);

int in(int move, int *memo)
{
    /*verifica que el
    movimiento no se haya hecho antes
    si se hizo regresa ONE
    de lo contrario ZERO*/
    int i = ZERO;

    while(i < FOUR)
    {
        if(*(memo+i) == move)
        {
            return ONE;
        }

        i++;
    }

    return ZERO;
}

void print_tablero(char **tablero)
{
    int i = ZERO, j = ZERO;

    while(i < SIZE)
    {
        j = ZERO;

        while(j < SIZE)
        {
            printf("  %c ", *(*(tablero + i) + j++));
        }

        printf("\n\n");
        i++;
    }

    printf("\n\n");
}

int *caminata_aleatoria(char **tablero, int *verification)
{
    int i = ZERO, j= ZERO;
    int x, y, k = ZERO, move, l;
    char letra = 'A';
    int *memo = (int*)malloc(FOUR*sizeof(int));

    if(memo == NULL)
        return NULL;

    srand (time(NULL));

    i = rand()%SIZE;
    j = rand()%SIZE;

    *(*(tablero + i) + j) = letra;
    x = i;
    y = j;

    while(ONE)
    {
        k = ZERO;

        for(l = 0; l < FOUR; l++)
        {
            *(memo + l) = -1;
        }

        while(k < FOUR)
        {

            move = rand() % FOUR;

            /*intenta movimientos
            validos  que no ha intentado
            antes*/
            while(in(move, memo))
            {
                move = rand() % FOUR;
            }

            memo[k] = move;

            switch(move)
            {
            /*arriba*/
            case ZERO:
                x--;
                break;
            /*abajo*/
            case ONE:
                x++;
                break;
            /*izquierda*/
            case TWO:
                y--;
                break;
            /*derecha*/
            case THREE:
                y++;
                break;
            }

            /*condicion para imprimir*/
            if((x < SIZE  && x >= ZERO) && (y < SIZE && y >= ZERO) && *(*(tablero + x) + y) == '.')
            {
                i = x;
                j = y;
                letra += ONE;

                if(letra == '[')
                    letra = 'a';

                if(letra == '{')
                {
                    letra = 'A';
                }


                *(*(tablero + i) + j) = letra;
                print_tablero(tablero);
                usleep(TIMESLEEP);
                clean();
                break;
            }
            else
            {
                /*deshace ell movimiento anterior*/
                 switch(move)
                {
                /*arriba*/
                case ZERO:
                    x++;
                    break;
                /*abajo*/
                case ONE:
                    x--;
                    break;
                /*izquierda*/
                case TWO:
                    y++;
                    break;
                /*derecha*/
                case THREE:
                    y--;
                    break;
                }

            }

            k++;
        }

        if(k == 4)
        {
            printf("\tNo puedo avanzar mas\n\n");
            break;
        }
    }

    free(memo);

    return verification;

}

void free_tablero(char **tablero)
{
    free(*(tablero));
    free(tablero);
}

char **crear_tablero(void)
{
    /*Crea un puntero con la info
    del tablero*/
    int i = ONE, j = ZERO;
    char **tablero = (char**)malloc(SIZE* sizeof(char*));

    *(tablero) = (char*)malloc(SIZE * SIZE * sizeof(char));

    if(tablero == NULL || *(tablero) == NULL)
        return NULL;

    while(i < SIZE)
    {
        *(tablero + i) = *(tablero + i - ONE) + SIZE;
        i++;
    }

    i = ZERO;

    while(i < SIZE)
    {
        j = ZERO;

        while(j < SIZE)
        {
            *(*(tablero+i)+j) = '.';
            j++;
        }

        i++;
    }

    return tablero;

}

int main()
{
    char **tablero;
    int *play, *verification;
    int i = ZERO;

    verification = &i;
    tablero = crear_tablero();
    play = caminata_aleatoria(tablero, verification);

    if(play == NULL)
    {
        printf("Se necesita espacio en memoria\n");
    }
    else
    {
        print_tablero(tablero);
        free_tablero(tablero);
    }


    return ZERO;
}
