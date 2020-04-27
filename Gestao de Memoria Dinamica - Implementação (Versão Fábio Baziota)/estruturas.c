/*
    Autor: Manuel Meneses Jr.
    Data:
    Objectivo:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int ordenada;
  int absissa;
} TPlano;

/*TPlano *pCoordenda = (TPlano*)malloc ( sizeof (TPlano) )
if ( pCoordenada == NULL )
{
  printf (" Erro: Nao ha memória suficiente \n ");
  return;
}*/

int main(int argc, char const *argv[])
{
  int i, j, n;
  printf("Digite o numero de elementos: \n"); scanf("%d", &n); // lê o número de elementos

  TPlano *tabPonto = (TPlano *) malloc( sizeof(TPlano) *n );
  if ( tabPonto == NULL)
  {
    printf (" Erro: Nao ha memória suficiente \n ");
    return 1;
  }

  for ( i = 0; i < n; i++ ) // Zera os elementos do vector
  {
    (tabPonto+i)->ordenada = 0;
    (tabPonto+i)->absissa = 0;
  }

  for ( i = 0; i < n; i++ ) // impprimir os elementos do vector
  {
    printf("Ordenada: %d\n", (tabPonto+i)->ordenada);
    printf("absissa: %d\n", (tabPonto+i)->absissa);
  }

  free (tabPonto);
  return 0;
}
