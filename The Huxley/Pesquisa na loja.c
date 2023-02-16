#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {

  int idade, idade2, quantMulheres = 0, quantHomens = 0, maisJovem;
  char sexo, sexo2, estilo, estilo2;
  float media, contador = 1.0, total, total2;
  
  scanf ("%i",&idade);

  if (idade <= 0) {
    printf ("0");
    exit(0);
  }

  scanf (" %c",&sexo);
  scanf ("%f",&total);
  scanf (" %c",&estilo);
  
  
  if ( (total <= 100) && (sexo == 'f') )  {
      quantMulheres = quantMulheres + 1; 
    }

  if ( (sexo == 'm') && ((estilo == 'f') || (estilo == 't')) ) {
      quantHomens = quantHomens + 1;
  }

  maisJovem = idade;

  scanf ("%i",&idade2);

  while (idade2 > 0) {

    scanf (" %c",&sexo2);
    scanf ("%f",&total2);
    scanf (" %c",&estilo2);

    if ( (total2 <= 100) && (sexo2 == 'f') )  {
      quantMulheres = quantMulheres + 1; 
    }
    contador = contador + 1;
    total = total + total2;
    
    if ( (sexo2 == 'm') && ((estilo2 == 'f') || (estilo2 == 't')) ) {
      quantHomens = quantHomens + 1;
    }

    if (maisJovem > idade2) {
      maisJovem = idade2;
    }
    
    scanf ("%i",&idade2);
  }
  
  media = total / contador;

  printf ("%i\n",quantMulheres);
  printf ("%i\n", maisJovem);
  printf ("%.2f\n",media);
  printf ("%i\n",quantHomens);


	return 0;
}