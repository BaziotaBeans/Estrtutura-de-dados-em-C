/* -------------------------------------------------------------------------------------------------------
Especificação das Operações: racional.c
Objectivo: Implementação das funções que manipulam um número racional
-------------------------------------------------------------------------------------------------------*/

#include "racional.h"
#include <stdio.h>

struct racional
{
  float numerador;
  float denomidador;
};

int lerNumero()
{
  int x;
  printf ("\n Entre com um numero inteiro:"); scanf("%d",&x);
  return x;
}


TRacional criar( int num, int den)
{
  TRacional rac;
  rac.numerador = num;
  rac.denomidador = den;
  return rac;
}


TRacional adicao(TRacional v1, TRacional v2)
{
  TRacional res;
  res.numerador = (v1.numerador * v2.denomidador) + (v2.numerador * v1.denomidador);
  res.denomidador = v1.denomidador * v2.denomidador;
  return res;
}

TRacional subtrair(TRacional v1, TRacional v2)
{
  TRacional res;
  res.numerador = (v1.numerador * v2.denomidador) - (v2.numerador * v1.denomidador);
  res.denomidador = v1.denomidador * v2.denomidador;
  return res;
}


TRacional multiplicacao(TRacional v1, TRacional v2)
{
  TRacional res;
  res.numerador = v1.numerador * v2.numerador;
  res.denomidador = v1.denomidador * v2.denomidador;
  return res;
}
