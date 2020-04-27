/*
    Autor: BaziotaBeans
    Data: 07/08/2018
    Objectivo:1.7.2- Desenvolva a função strchr(s,c) que devolve o endereço da primeira
    ocorrência do caracter c na string s ou o valor NULL caso esse caracter não
    seja encontrado.
*/

#include <stdio.h>
#include <stdlib.h>


int strchr(char *s, char c);
void strcpy(char *s, char *t);

int main(int argc, char const *argv[])
{

  return 0;
}

int strchr(char *s, char c)
{
  for(int i=0; *s != '\0'; i++)
    if(*s == c) return i;
  return NULL;
}

int strchr(char *s, char c, int i)
{
  if(*s == '\0') return NULL;
  if(*s == c) return i;
  return strchr(*s, c, i+1);
}

void strcpy(char *s, char *t)
{
  while((*s++ = *t++) != '\0');
}
