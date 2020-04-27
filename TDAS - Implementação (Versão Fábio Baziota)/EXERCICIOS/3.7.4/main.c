#include "complexo.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  TComplexo r1, r2, r3, r4, r5, r6;

  r1 = criar(lerNumero(), lerNumero());
  r2 = criar(lerNumero(), lerNumero());
  r3 = adicao(r1,r2);
  r4 = subtrair(r1, r2);
  r5 = multiplicacao(r1, r2);
  r6 = dividir(r1, r2);

  printf ("Adicao : %.0f + %.0fi", r3.real, r3.imaginario);
  printf ("Subtracção : %.0f - %.0fi", r4.real, r4.imaginario);
  printf ("Multiplicação: %.0f + %.0fi", r5.real, r5.imaginario);
  printf("Divisao de Numeros Complexos\n");
  printf ("%.0f     %.0f\n", r6.real, r6.imaginario);
  printf("------ + ------- i\n");
  printf("%.0f     %.0f\n", r6.denominador, r6.denominador);


  return 0;
}
