#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
  float ph;

  scanf ("%f",&ph);
  
  if (ph == 7) {
    printf ("Neutra");
  }
  else {
    if (ph < 7) {
      printf ("Acida");
    }
    else {
      printf ("Basica");
    }
  }

	return 0;
}