/* -------------------------------------------------------------------------------------------------------
Especificação das Operações: complexo.c
Objectivo: Implementação das funções que manipulam um número complexo
-------------------------------------------------------------------------------------------------------*/

#include "complexo.h"
#include <stdio.h>


float lerNumero()
{
  float x;
  printf ("\n Entre com um numero inteiro:"); scanf("%f",&x);
  return x;
}

TComplexo criar (float real, float imag)
{
    TComplexo comp;
    comp.real = real;
    comp.imaginario = imag;
    return comp;
}


void remover(TComplexo *comp, float real, float imag)
{

}
//Remover os ados de um número complexo.
//Aceder
TComplexo adicao(TComplexo z1, TComplexo z2)
{
  TComplexo comp;
  comp.real = z1.real + z2.real;
  comp.imaginario = z1.imaginario + z2.imaginario;
  return comp;
}
// Recebe dois números complexos e retorna a sua adição
TComplexo subtrair(TComplexo z1, TComplexo z2)
{
  TComplexo comp;
  comp.real = z1.real - z2.real;
  comp.imaginario = z1.imaginario - z2.imaginario;
  return comp;
}
// Recebe dois números complexos e retorna a sua subtracao
TComplexo multiplicacao(TComplexo z1, TComplexo z2)
{
  TComplexo comp;
  comp.real = (z1.real * z2.real) + (z1.imaginario * z2.imaginario);
  comp.imaginario = (z2.imaginario*z1.real) + (z1.imaginario * z2.real);
  return comp;
}
// recebe dois números complexos e retorna a sua multiplicacão
TComplexo dividir(TComplexo z1, TComplexo z2)
{
  TComplexo comp;
  //float denomidador;

  comp.real = (z1.real * z2.real) + (z1.imaginario * z2.imaginario)
  comp.imaginario = (z1.imaginario * z2.real) - (z2.imaginario * z1.real);
  comp.denomidador = (z2.real*z2.real) + (z2.imaginario*z2.imaginario);

  return comp;
}
