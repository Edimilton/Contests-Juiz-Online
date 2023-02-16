#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   int dia1, dia2;
   double comida1, comida2, refri1, refri2, cerveja, decoracao1, decoracao2, natal, anoNovo, total;

   scanf ("%i",&dia1);
   scanf ("%lf %lf %lf",&comida1,&refri1,&decoracao1);
   scanf ("%i",&dia2);
   scanf ("%lf %lf %lf %lf",&comida2,&refri2,&cerveja,&decoracao2);
   
   if (dia1 < 20) {
     natal = comida1 + (refri1 * 0.9) + (decoracao1 * 0.85);
   }
   if (dia1 == 20) {
     natal = (comida1 * 0.88) + (refri1 * 0.85) + (decoracao1 * 0.8);
   }
   if (dia1 == 21) {
     natal = (comida1 * 0.83) + (refri1 * 0.78) + (decoracao1 * 0.73);
   }
   if (dia1 == 22) {
     natal = (comida1 * 0.8) + (refri1 * 0.78) + (decoracao1 * 0.7);
   }
   if (dia1 == 23) {
     natal = (comida1 * 0.75) + (refri1 * 0.71) + (decoracao1 * 0.65);
   }
   if (dia1 == 24) {
     natal = (comida1 * 0.65) + (refri1 * 0.65) + (decoracao1 * 0.5);
   }



   if (dia2 == 25) {
     anoNovo = (comida2 * 0.85) + (refri2 * 0.87) + cerveja + (decoracao2 * 0.9);
   }
   if (dia2 == 26) {
     anoNovo = (comida2 * 0.81) + (refri2 * 0.75) + (cerveja * 0.95) + (decoracao2 * 0.77);
   }
   if (dia2 == 27) {
     anoNovo = (comida2 * 0.76) + (refri2 * 0.7) + (cerveja * 0.88) + (decoracao2 * 0.67);
   }
   if (dia2 == 28) {
     anoNovo = (comida2 * 0.7) + (refri2 * 0.68) + (cerveja * 0.8) + (decoracao2 * 0.65);
   }
   if (dia2 == 29 || dia2 == 30) {
     anoNovo = (comida2 * 0.65) + (refri2 * 0.6) + (cerveja * 0.67) + (decoracao2 * 0.58);
   }
   if (dia2 == 31) {
     anoNovo = (comida2 * 0.6) + (refri2 * 0.53) + (cerveja * 0.55) + (decoracao2 * 0.34);
   }
   

   total = natal + anoNovo;

   printf ("Compras de natal: R$ %.2lf.\n",natal);
   printf ("Compras de ano novo: R$ %.2lf.\n",anoNovo);
   printf ("Total das compras: R$ %.2lf.\n",total);





	return 0;
}