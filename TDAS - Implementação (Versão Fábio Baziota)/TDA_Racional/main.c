#include "racional.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  TRacional r1, r2, r3, r4;

  r1 = criar(lerNumero(), lerNumero());
  r2 = criar(lerNumero(), lerNumero());
  r3 = adicao(r1,r2);
  r4 = multiplicacao(r1, r2);

  printf("adicao : %.0f/%.0f \n", r3.numerador, r3.denomidador);
  printf("multiplicacao :%.0f/%.0f \n", r4.numerador, r4.denomidador);

  return 0;
}
