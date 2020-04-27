#include "listaSequencial.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
  TLista lista;
  TItem x;
  inicializarLista(&lista);
  int i = 0;
  while(i < 4)
  {
    x.chave = lerNumChave();
    x.valor = lerNumValor();
    if(inserirElementoFim(&lista, x) == OK) i++;
    else i = 10;
  }
  if (imprimirElementos(&lista) != OK) printf("\nA lista esta vazia\n");
  else printf("\nImpressao feita com sucesso\n");
  return 0;
}
