/*
    Autor: BaziotaBeans
    Data: 07/08/2018
    Objectivo:1.7.2- Desenvolva uma função que recebe como parâmetro um vector de
    números inteiros e um inteiro n maior ou igual a zeros. Carregar nesse vector
    as n notas das provas dos estudantes.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void carregarNota(float v[], int n);
float lerNota();
int lerN();
void imprimir(float A[], int ulPos);

int main(int argc, char const *argv[])
{
  float notas[MAX];
  int num = lerN();
  carregarNota(notas,num);
  imprimir(notas, num);
  return 0;
}


void carregarNota(float v[], int n)
{
  float *pta = v;
  for(int i=0; i < n; i++) *(pta + i) = lerNota();
}


void imprimir(float A[], int ulPos)
{
  float *pta = A;
  for(int i=0; i < ulPos; i++) printf("%f\n", *(pta+i));
}

int lerN()
{
  int n;
  while(1)
  {
    printf("Digite um numero natural: "); scanf("%d", &n);
    if((n > 0) && (n <= MAX)) return n;
  }
}


float lerNota()
{
  float nota;
  while(1)
  {
    printf("Digite a nota: "); scanf("%f", &nota);
    if((nota >= 0) && (nota <= 20.0)) return nota;
  }
}
