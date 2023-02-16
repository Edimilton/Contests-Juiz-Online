#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 int main() {
   float cotacao, aliquota, produto, frete;
   double valorProd, valorFrete, valorTotal, imposto, valorFinalP, aliquotaPC, icms, totalImposto, totalPagar;

   scanf ("%f",&cotacao);
   scanf ("%f",&aliquota);
   scanf ("%f",&produto);
   scanf ("%f",&frete);
  
  if (produto < 2500) {
     valorProd = produto * cotacao;
     valorFrete = frete * cotacao;
     valorTotal = valorProd + valorFrete;
     imposto = valorTotal * 0.6;
     aliquotaPC = aliquota / 100;
     valorFinalP = (valorTotal + imposto)/(1 - aliquotaPC);
     icms = valorFinalP * aliquotaPC;
     totalImposto = imposto + icms;
     totalPagar = valorTotal + totalImposto;

     printf ("%.2f\n",cotacao);
     printf ("%.2lf\n",valorProd);
     printf ("%.2lf\n",valorFrete);
     printf ("%.2lf\n",valorTotal);
     printf ("%.2lf\n",imposto);
     printf ("%.2lf\n",icms);
     printf ("%.2lf\n",totalImposto);
     printf ("%.2lf\n",totalPagar);
     printf ("Impostos calculados com o frete");

  }
  else {
     valorProd = produto * cotacao;
     valorFrete = frete * cotacao;
     valorTotal = valorProd + valorFrete;
     imposto = valorProd * 0.6;
     aliquotaPC = aliquota / 100;
     valorFinalP = (valorProd + imposto)/(1 - aliquotaPC);
     icms = valorFinalP * aliquotaPC;
     totalImposto = imposto + icms;
     totalPagar = valorTotal + totalImposto;

     printf ("%.2f\n",cotacao);
     printf ("%.2lf\n",valorProd);
     printf ("%.2lf\n",valorFrete);
     printf ("%.2lf\n",valorTotal);
     printf ("%.2lf\n",imposto);
     printf ("%.2lf\n",icms);
     printf ("%.2lf\n",totalImposto);
     printf ("%.2lf\n",totalPagar);
     printf ("Impostos calculados sem o frete");
  }

	return 0;
}