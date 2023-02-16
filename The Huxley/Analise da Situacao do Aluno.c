#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    float media;
    int aulas, faltas;

    scanf ("%f %i %i",&media,&aulas,&faltas);
    
    float frequencia;
    
    frequencia = (100 - ((faltas * 100) / aulas));
  
    if ((frequencia >= 75) && (media >= 5) ) {
      printf ("APROVADO");
    }
    else {
      if ((frequencia >= 50) && (media >= 7)) {
        printf ("APROVADO");
      }
      else {
        printf ("REPROVADO");
      }
    }
    
    return 0;
}