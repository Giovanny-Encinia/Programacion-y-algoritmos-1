//Giovanny Encinia
//23-08-2021
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_dif(char type)
{
   int number;

   printf(\
          "Escribe un numero para el formato %c\n"\
          , type);
   if(type == 'i')
   {
       scanf("%i", &number);
   }
   else
   {
       scanf("%d", &number);
   }

   printf(\
          "El numero con formato d  es:  %d\n"\
          , number);
   printf(\
          "El numero con  formato i  es:  %i\n\n"\
          , number);
}

int main()
{
   char i='i', d='d';
   _Bool verdad = 2, falso = 0;

   print_dif(i);
   print_dif(d);

   printf("_Bool 0 es %s\n"\
          , falso?"verdad":"falso");
   printf("_Bool != 0 es %s\n"\
          , verdad?"verdad":"falso");

   return 0;
}
