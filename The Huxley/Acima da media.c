#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  float valor1 = 0, valor2 =0 , valor3 = 0, media;
  int contador = 0; 

  scanf("%f",&valor1);
  scanf("%f",&valor2);
  scanf("%f",&valor3);

  media = (valor1 + valor2 + valor3) / 3;

  if (valor1 > media) {
    contador = contador + 1;
   }
  if (valor2 > media) {
    contador = contador + 1;
   }
  if (valor3 > media) {
    contador = contador + 1;
   }

  printf ("%d", contador);
  
  return 0;
 } 