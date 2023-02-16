#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  int senhas, convidados = 0;
  float valor = 0;
  
  scanf ("%i",&senhas);

  if (senhas < 0) {
    printf ("0.00\n0");
  }


  while (senhas >=0 ) {

  if (senhas > 25) {
    senhas = 25;
  } 

  if (senhas > 15) {
    valor = valor + ((senhas - 15) * 42);
  }

  convidados = convidados + senhas + 1;

  scanf ("%i",&senhas);

  if (senhas < 0) {
    break;
  }

  }

  printf ("%.2f\n",valor);
  printf ("%i\n",convidados);



  return 0;
}