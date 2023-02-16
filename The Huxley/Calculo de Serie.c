#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  double x = 1, y = 1, z = 0, soma = 0;
  int numero, contador = 2;

  scanf ("%i",&numero);

  if (numero == 0) {
    printf ("S: 0.00");
    return 0;
  }

  if (numero == 1) {
    printf ("S: 1.00");
    return 0;
  }

  while (contador <= numero) {

    x *= 2; 

    if (contador % 2 == 0) {
     z += 3; 

     soma = soma + (x / z);

    }
    else {
      y = y + 2;

      soma = soma + (y / x);
    }

    ++contador;
  }

  ++soma; 

  printf ("S: %.2lf",soma);


  return 0;
}

