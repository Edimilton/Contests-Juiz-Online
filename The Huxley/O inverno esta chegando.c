#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  char casa, sexo, habilidade, sexoEspadachim;
  int idade, idadeA = 999, total = 0, lanceiro = 0, arqueiro = 0;
  float altura, altura2 = 0, altura3 = 0;

  scanf ("%c", &casa);

  while (casa == 'S' || casa == 'P' || casa == 'C' || casa == 'O') {
     
     scanf (" %c",&sexo);
     scanf ("%i",&idade);
     scanf ("%f",&altura);
     scanf (" %c",&habilidade);

     total = total + 1;

     if (casa == 'C') {
       if (altura2 < altura) {
           altura2 = altura;
       }
     }

     if (casa == 'S' && habilidade == 'l') {
       ++lanceiro;
     }

     if (casa == 'O' && habilidade == 'a') {
       if (idadeA == 999) {
           idadeA = idade;
        }
       else {
         if (idadeA < idade) {
           idadeA = idade;
         }
       }
     }

     if (casa == 'P' && habilidade == 'e') {
       if (altura3 < altura) {
           altura3 = altura;
           sexoEspadachim = sexo;
        }
     }

     scanf (" %c", &casa);

  }

  if (altura3 > 0.00) {

    printf ("%i\n",total);
    printf ("%.2f\n",altura2);
    printf ("%i\n",lanceiro);
    printf ("%i\n",idadeA);
    printf ("%c",sexoEspadachim);
  }
  else {

    printf ("%i\n",total);
    printf ("%.2f\n",altura2);
    printf ("%i\n",lanceiro);
    printf ("%i\n",idadeA);
    printf ("X\n");

  }


  return 0;
}