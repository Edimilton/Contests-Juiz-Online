#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  float valor1, valor2, valor3, valor4, valor5;
  int contador = 0;
  
  printf ("Digite um valor:\n");
  scanf ("%f",&valor1);
  printf ("Digite um valor:\n");
  scanf ("%f",&valor2);
  printf ("Digite um valor:\n");
  scanf ("%f",&valor3);
  printf ("Digite um valor:\n");
  scanf ("%f",&valor4);
  printf ("Digite um valor:\n");
  scanf ("%f",&valor5);

  if (valor1 < 0) {
    contador = contador + 1;
       }
  if (valor2 < 0) {
    contador = contador + 1;
       }
  if (valor3 < 0) {
    contador = contador + 1;
       }
  if (valor4 < 0) {
    contador = contador + 1;
       }
  if (valor5 < 0) {
    contador = contador + 1;
       }

  printf ("Foram digitados %d numeros negativos", contador);

	return 0;
}