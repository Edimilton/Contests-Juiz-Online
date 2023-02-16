#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {

  int pot2 (int k);
  int ehprimo (int p); 

  int partidas, tabuleiro, turnos, fabio, ayalla,avanco1 = 0,avanco2 = 0,passagem1 = 0, passagem2 = 0, bonificado1 = 0, bonificado2 = 0, penalizado1 = 0, penalizado2 = 0;

  scanf ("%i",&partidas);
  scanf ("%i",&tabuleiro);

  for (int n = 1; n <= partidas; ++n) {

    scanf ("%i",&turnos);

    for (int x = turnos; x > 0; x = x - 1) {

      scanf ("%i %i",&fabio,&ayalla);

      avanco1 = avanco1 + fabio;
      avanco2 = avanco2 + ayalla;


    if (avanco1 > tabuleiro) {
      ++passagem1;
      avanco1 = 0;
    }
    else {
      if (bonificado1 < 1){

        if (pot2 (avanco1)) {
          avanco1 += 2;
          ++bonificado1;
          ++penalizado1;

        }
      }

      if (penalizado1 < 1) {

        if (ehprimo (avanco1)) {
          avanco1 = avanco1 - 2;
          ++bonificado1;
          ++penalizado1;
        }
      }

      if (avanco1 > tabuleiro) {
        ++passagem1;
        avanco1 = 0;
      }
    }

    if (avanco2 > tabuleiro) {
      ++passagem2;
      avanco2 = 0;
    }
    else {
      if (bonificado2 < 1) {

        if (pot2 (avanco2)) {
          avanco2 += 2;
          ++bonificado2;
          ++penalizado2;
        }
      }

      if (penalizado2 < 1) {

        if (ehprimo (avanco2)) {
          avanco2 = avanco2 - 2;
          ++bonificado2;
          ++penalizado2;          
        }
      }

      if (avanco2 > tabuleiro) {
        ++passagem2;
        avanco2 = 0;
      }
    }

    penalizado1 = 0;
    penalizado2 = 0;
    bonificado1 = 0;
    bonificado2 = 0;

    }


    if (passagem1 > passagem2) {
      printf ("Partida %i : Fabio venceu na posicao %i passando %i vezes pelo final do tabuleiro\n", n, avanco1, passagem1);
    }
    else {
      if (passagem1 < passagem2) {
        printf ("Partida %i : Ayalla venceu na posicao %i passando %i vezes pelo final do tabuleiro\n", n, avanco2, passagem2);
      }
      else {
        if (avanco1 > avanco2) {
          printf ("Partida %i : Fabio venceu na posicao %i passando %i vezes pelo final do tabuleiro\n", n, avanco1, passagem1);
        }
        else {
          if (avanco1 < avanco2) {
            printf ("Partida %i : Ayalla venceu na posicao %i passando %i vezes pelo final do tabuleiro\n", n, avanco2, passagem2);
          }
          else {
            printf ("Partida %i : Houve um empate nas posicoes %i e %i\n", n, avanco1, avanco2);
          }
        }
      }
        
    }

    avanco1 = 0;
    avanco2 = 0;
    passagem1 = 0;
    passagem2 = 0;


  }


  return 0;
}



int pot2 (int k) {

  int verdade = 1, falsidade = 0;
  
  if (k == 1 || k == 2 || k == 4 || k == 8 || k == 16 || k == 32 || k == 64 || k == 128 || k == 256 || k == 512 || k == 1024 || k == 2048 || k == 4096) {
   return verdade;
  }
  else {
    return falsidade;
  }
}


int ehprimo (int num) {

   int k, primo = 0, verdade = 1, falsidade = 0;

   if (num == 2) {
     return falsidade;
   }


   for(k = 1; k <= num; ++k) {
      if((num % k)==0) { 
      primo++;
      }
   }   

   if(primo>2) {
     return falsidade;
   }

   else {
     return verdade;
      }
          
   }
