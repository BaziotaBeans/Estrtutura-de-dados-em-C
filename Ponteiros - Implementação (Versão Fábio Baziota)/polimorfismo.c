#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maior(int x, int y);
int menor(int x, int y);
int minimax(int v[], int ultPos, int (*cmp)(int, int));

int main(int argc, char const *argv[])
{
  int w[5] = {78,34,12,45,51};
  printf ( "%d ", minimax(w,5,menor) );
  printf ("%d ", minimax(w,5,maior) );
  return 0;
}

int maior(int x, int y)
{
   return x > y;
}


int menor(int x, int y)
{
   return x < y;
}

int minimax(int v[], int ultPos, int (*cmp)(int, int))
{
  int x = v[0];
  for(int i=1; i < ultPos; i++)
    if(cmp(x, v[i])) x = v[i];
  return x;
}
