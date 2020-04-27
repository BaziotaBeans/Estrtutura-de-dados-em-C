#include <stdio.h>
#include <stdlib.h>

int (*pts)(int, int);
int soma(int a, int b);

int main(int argc, char const *argv[])
{
  pts = soma;
  printf("Soma = %d\n",pts(4,5));
  return 0;
}


int soma(int a, int b)
{
  return (a+b);
}
