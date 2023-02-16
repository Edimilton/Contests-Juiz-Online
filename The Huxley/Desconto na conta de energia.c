#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  char bairro;
  int renda, consumo;

  scanf (" %c",&bairro);
  scanf ("%i",&renda);
  scanf ("%i",&consumo);  

  if ('S' == bairro || 'I' == bairro || 'T' == bairro) {
    if (renda < 0 || consumo < 0) {
      printf ("Renda e consumo nao podem ser negativos.");
    }
    else {

     if (bairro == 'S') {
      if (50 <= renda && renda <= 500) {
       consumo = consumo - 50;
      }
      if (500 < renda && renda <= 1000) {
      consumo = consumo - 25;
      }
      printf ("%i",consumo);
     }
     else {
      if (bairro == 'I') {
      if (240 <= renda && renda <= 1000) {
      consumo = consumo - 240;
      }
      if (1000 < renda && renda <= 5000) {
      consumo = consumo - 120;
      }
      printf ("%i",consumo);
     }
     else {
      if (5000 < renda && renda <= 10000) {
      consumo = consumo - 720;
      }
      if (10000 < renda && renda <= 20000) {
      consumo = consumo - 360;
      }
      printf ("%i",consumo);
     }
    }
   }

  }
  else {
    printf ("Bairro invalido.");
  }
  
	return 0;
}
