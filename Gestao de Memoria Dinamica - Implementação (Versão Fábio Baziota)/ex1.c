#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
  void *ptr;
  int *pnumero;
  int *pnum;
  ptr = malloc(1000);
  pnum = (int *)malloc(1000);
  pnumero = (int *)ptr;
  *pnumero = 10;
  printf("%d\n", *pnumero);

  //void free (void *ptr);  libertacao
  free(ptr);
  printf("%d\n", *pnumero);

  return 0;
}
