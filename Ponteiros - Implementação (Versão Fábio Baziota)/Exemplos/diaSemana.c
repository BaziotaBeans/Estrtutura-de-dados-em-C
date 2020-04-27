#include <stdio.h>
#include <stdlib.h>


char *diaSemana(int n);


int main(int argc, char const *argv[]) {
  /* code */
  int dia;
  printf("\nDigite o dia de semana: "); scanf("%d", &dia);
  printf("\nDia de semana %s\n",diaSemana(dia));
  return 0;
}


char *diaSemana(int n)
{
  static char *d[] = {"erro", "domingo", "segunda-feira", "terça-feira","quarta-feira", "quinta-feira", "sexta-feira", "sábado"};
  return d[1<=n && n<=7 ? n : 0];
}
