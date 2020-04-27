#include <stdio.h>
#include <stdlib.h>


void imprimir(int A[], int ulPos);
int soma(int A[], int ultPos);



int main(int argc, char const *argv[])
{

  int a[] = {10,5,6,7}, *pta;
  imprimir(a,3);
  printf("\nSoma consecutivo = %d\n", soma(a, 3));
  return 0;
}


void imprimir(int A[], int ulPos)
{
  int *pta = A;
  for(int i=0; i <= ulPos; i++) printf("%d\n", *(pta+i));
}


int soma(int A[], int ultPos)
{
  int *pta = A, soma = 0;
  for(int i=0; i <= ultPos; i++) soma+= *(pta+i);
  return soma;
}
