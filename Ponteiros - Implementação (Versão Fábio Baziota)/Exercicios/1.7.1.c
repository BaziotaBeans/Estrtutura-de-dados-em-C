/*
    Autor: BaziotaBeans
    Data: 07/08/2018
    Objectivo:1.7.1- Desenvolva uma função que recebe como parâmetro um vector v de
    números reais e a posição do último elemento inserido. Devolve como valor de
    retorno o elemento máximo e o elemento mínimo.
*/

#include <stdio.h>
#include <stdlib.h>

float menor(float a, float b);
float maior(float a, float b);
float minimoMaximo(float A[], int ultPos, float (*comp)(float, float));

int main(int argc, char const *argv[])
{
  float v[] = {1.2, 33.4, 0.5};
  printf ("Menor = %f ", minimoMaximo(v,2,menor) );
  printf ("\nMaior = %f \n", minimoMaximo(v,2,maior) );
  return 0;
}

float menor(float a, float b)
{
  return (a > b);
}
float maior(float a, float b)
{
  return (a < b);
}

float minimoMaximo(float A[], int ultPos, float (*comp)(float, float))
{
  float valor = A[0];
  for(int i=0; i <= ultPos; i++)
    if(comp(valor, A[i])) valor = A[i];
  return valor;
}
