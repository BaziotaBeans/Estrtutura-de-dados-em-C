#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int ordenada;
  int absissa;
}TPlano;

int main(int argc, char const *argv[])
{
  TPlano *p, quadrante = {1,3};
  p = &quadrante;
  printf("{ %d, %d }\n", (*p).ordenada, (*p).absissa );
  printf("{ %d, %d }\n", p->ordenada, p->absissa );
  return 0;
}

TPlano adicionarPontos (TPlano p1, TPlano p2)
{
  TPlano res;
  res.x = p1.x + p2.x;
  res.y = p1.y + p2.y;
  return res;
}
