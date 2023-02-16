#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
  int maiorC (int num1, int num2);
  int numero1, numero2, ciclo;

  while (scanf ("%i %i",&numero1,&numero2) != EOF) {

    if ((numero1 < 0 || numero1 > 1000000) || (numero2 < 0 || numero2 > 1000000) ) {
      break;
    }

    if (numero1 <= numero2) {
      ciclo = maiorC (numero1,numero2);
    }
    else {
      ciclo = maiorC (numero2,numero1);
    }


    printf ("%i %i %i\n",numero1,numero2,ciclo);

  }

  return 0;
}

// auxiliar 2

int maiorC (int num1, int num2) {
  
  int maiorCiclo = 1, maiorCiclo2;
  int tamanhoCiclo (int x);

  if (num1 <= 0) {
    exit(0);
  }

  while (num1 <= num2) {

    maiorCiclo2 = tamanhoCiclo(num1);

    if (maiorCiclo < maiorCiclo2) {
      maiorCiclo = maiorCiclo2;
    }
    ++num1;
  }



  return maiorCiclo;
}

// auxiliar 1

int tamanhoCiclo (int x) {
  
  int contador = 1;
  
  while (x != 1) {
    
    if (x % 2 == 0){
      x /= 2;
    }
    else {
      x = (x * 3) + 1;
    }
    
    ++contador;
  }

  return contador;
}