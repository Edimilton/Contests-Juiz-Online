#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main () {

  int idadeP, idadeC;
  char irmao, conjunta, casados, desconhecidos, consentimentoP, consentimentoC;
  
  scanf ("%i",&idadeP);

  if (idadeP < 18) {
    printf ("N�o pode adotar");
    exit(0);
  } 

  scanf (" %c",&irmao);
  scanf (" %c",&conjunta);
  scanf (" %c",&casados);
  scanf (" %i",&idadeC);
  scanf (" %c",&desconhecidos);
  scanf (" %c",&consentimentoP);
  scanf (" %c",&consentimentoC);


    if ( (irmao == 'N') && ((conjunta == 'N') || (casados == 'S')) && ((idadeP - idadeC) >= 16) && ((desconhecidos == 'S') || (consentimentoP == 'S')) && ((consentimentoC == 'S') || (idadeC < 12)) ) {
      printf ("Pode adotar");
    }
    else {
      printf ("N�o pode adotar");
    }
  

  return 0;
}
 
