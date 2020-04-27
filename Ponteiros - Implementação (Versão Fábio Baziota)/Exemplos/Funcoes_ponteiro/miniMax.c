#include <stdio.h>
#include <stdlib.h>

int menor (int x, int y);
int maior (int x, int y);
int minimax(int v[], int ultPos, int (*cmp)(int,int));


int main(int argc, char const *argv[])
{
  int w[5] = {78,34,12,45,51};
  printf ("Menor = %d ", minimax(w,5,menor) );
  printf ("\nMaior = %d \n", minimax(w,5,maior) );
  return 0;
}


int menor (int x, int y)
{
  return x > y;
}

int maior (int x, int y)
{
  return x < y;
}

int minimax(int v[], int ultPos, int (*cmp)(int,int))
{
  int x = v[0];
  for(int i=0; i<ultPos; i++)
    if(cmp(x,v[i])) x = v[i];
  return x;
}
