#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
  char ensinoMedio[4], enceja, tipoEscola[4];
  int notaEnceja;
  float renda;

  
  scanf (" %s",ensinoMedio);
  
  scanf (" %c",&enceja);
  scanf ("%i",&notaEnceja);

  scanf (" %s",tipoEscola);

  scanf ("%f",&renda);

  if ( (strcmp (ensinoMedio,"CLD") ==0) || (strcmp (ensinoMedio,"CVC")==0) || (strcmp (ensinoMedio,"CSC")==0) || (strcmp (ensinoMedio,"NCC")==0) ) {

    if ( ((strcmp (ensinoMedio,"CVC")==0) && (strcmp (tipoEscola,"PUB")==0)) || ( ((strcmp (tipoEscola,"PUB")==0) || (strcmp (tipoEscola,"PCB")==0)) && (renda <= 1431.00)) )  {

      printf ("Voce terah direito a isencao");
    }
    else {
      printf ("Infelizmente voce nao tem direito a isencao");
    }
  }

  else {
     printf ("Informacao sobre ensino medio invalida");
  } 

	return 0;
}
