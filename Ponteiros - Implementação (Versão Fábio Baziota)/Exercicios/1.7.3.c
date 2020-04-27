/*
    Autor: BaziotaBeans
    Data: 07/08/2018
    Objectivo:1.7.3- Para além da adição de ponteiros, uma outra operação possível é a
    subtração entre ponteiros do mesmo tipo. Quando um ponteiro é subtraído de
    um outro, o resultado é o número de elementos existentes no espaço de
    memória compreendido entre os endereços apontados por eles. Utilizando
    essa ideia, desenvolva a função strlen(s), que devolve o número de
*/

#include <stdio.h>
#include <stdlib.h>


int tamanho(char *s);

int main(int argc, char const *argv[])
{
  char s[] = "FABIO";
  printf("Tamnho da string: %d\n",tamanho(s));
  return 0;
}

int tamanho(char *s)
{
  char *pta;
  int count = 0;
  while((*s++ != '\0')) count += *s - *pta;
  return count;
}
