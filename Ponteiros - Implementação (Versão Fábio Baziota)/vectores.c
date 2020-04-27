#include <stdio.h>
#include <stdlib.h>

void imprimir(int A[], int ultPos);


int main(int argc, char const *argv[])
{
  int A[] = {3,4,5,6};
  imprimir(A, 4);
  return 0;
}

void imprimir(int A[], int ultPos)
{
  int *pta = A;
  for(int i=0; i<ultPos; i++) printf("%d\n", (*pta + i));
}
