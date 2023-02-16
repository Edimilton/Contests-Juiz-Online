#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  int pregos, sobra, total = 0, caixa = 12;
  float valor = 7.89;

  scanf ("%i",&pregos);

  if ((pregos % 2) != 0)
    exit(0);

  while ( (pregos % 2) == 0) {
   
   total = total + pregos;

   scanf ("%i",&pregos);
  }

  while (total >= caixa) {
    valor += 7.89;
    caixa += 12;

  }

  sobra = caixa - total;
    
  printf ("%.2f\n%i\n",valor,sobra);
  return 0;
}