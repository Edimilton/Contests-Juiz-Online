#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   int dias, kmetros;
   float total;

   scanf ("%i\n%i",&dias,&kmetros);

   total = dias * 90;

   if (kmetros > (dias * 100)) {
     total = total + ((kmetros - (dias * 100)) * 12);
   }

   printf ("%.2f",total);




	return 0;
 }