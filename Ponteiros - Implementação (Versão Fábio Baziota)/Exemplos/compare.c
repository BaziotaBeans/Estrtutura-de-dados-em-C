#include <stdio.h>
#include <stdlib.h>

void copiar(char *s, char *t);


int main(int argc, char const *argv[])
{
  /* code */
  char st1[] = {"BEANS++"}, st2[7];
  copiar(st2, st1);
  printf("Meu nome e: %s\n",st2);
  return 0;
}

void copiar(char *s, char *t)
{
  while((*s++ = *t++));
}
