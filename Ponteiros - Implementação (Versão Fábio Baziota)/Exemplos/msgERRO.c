#include <stdio.h>
#include <stdlib.h>


void msgErro(int codigo);


int main(int argc, char const *argv[])
{
  msgErro(1);
  return 0;
}

void msgErro(int codigo)
{
  static char *erro[] = {"Posicao Inicial Inválida","Posicao Final Nao Encontrada","Posicao Final Encontrada"};
  printf ( "\n %s", erro[codigo]);
}
