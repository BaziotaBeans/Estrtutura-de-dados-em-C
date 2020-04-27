#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  //void *ptr;
  int *pnumero;
  float *num;
  //ptr = malloc(1000);
  pnumero = (int *) malloc(1000);
  num = (float *) malloc(1000);
  *pnumero = 10;
  *num = 120;
  printf("%d\n", *pnumero);
  free(pnumero);
  printf("%d\n", *pnumero);
  /////////////////////////
  printf("%f\n", *num);
  free(num);
  printf("%f\n", *num);
  return 0;
}
