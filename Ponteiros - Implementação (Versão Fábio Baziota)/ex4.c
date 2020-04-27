#include <stdio.h>
#include <stdlib.h>

int (*pts)(int,int);
int soma(int x, int y);

int main(int argc, char const *argv[])
{

    pts = soma;
    printf("%d\n", pts(4,5));
    return 0;
}


int soma(int x, int y)
{
  return (x+y);
}
