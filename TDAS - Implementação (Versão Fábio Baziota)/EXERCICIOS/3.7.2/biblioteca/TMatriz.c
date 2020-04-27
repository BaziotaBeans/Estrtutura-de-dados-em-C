/* -------------------------------------------------------------------------------------------------------
Especificação das Operações: TMatriz.c
Objectivo: Implementação das funções que manipulam as operações basicas da matriz
-------------------------------------------------------------------------------------------------------*/

#include "TMatriz.h"
#include <stdio.h>


float lerNumero()
{
  float n;
  printf("\nDigite um numero real: "); scanf("%f",&n);
  return n;
}

void carregar(float A[][MAXCOL])
{
  for(int i=0; i<MAXLIN; i++)
    for(int j=0; j < MAXCOL; j++) A[i][j] = lerNumero();
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Aceder a informação de um elemento numa matriz
Recebe: Matriz, numero da linha, número da coluna
Valor de Retorno: conteudo do elemento acedido
-------------------------------------------------------------------------------------------------------*/
float aceder(float A[][MAXCOL],int i, int j)
{
  return (A[i][j]);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Atribuir um elemento numa matriz
Recebe: Matriz, numero da linha, número da coluna
Valor de Retorno: Nada
-------------------------------------------------------------------------------------------------------*/
void atribuir(float A[][MAXCOL],int i, int j)
{
  A[i][j] = lerNumero();
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Adicionar duas matrizes
Recebe: Matriz A, B e C
Devolve:
Valor de Retorno: Nada
-------------------------------------------------------------------------------------------------------*/
void adicionar(float A[][MAXCOL], float B[][MAXCOL], float C[][MAXCOL])
{
  for(int i=0; i<MAXLIN; i++)
    for(int j=0; j < MAXCOL; j++) C[i][j] = A[i][j] + B[i][j];
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Subtrair duas matrizes
Recebe: Matriz A, B e C
Devolve:
Valor de Retorno: Nada
-------------------------------------------------------------------------------------------------------*/
void subtrair(float A[][MAXCOL], float B[][MAXCOL], float C[][MAXCOL])
{
  for(int i=0; i<MAXLIN; i++)
    for(int j=0; j < MAXCOL; j++) C[i][j] = A[i][j] - B[i][j];
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Multiplicação de matrizes
Recebe: Matrizes A e B
Devolver: Matriz C = A*B
--------------------------------------------------------------------------------------------------------*/
void multiplicar(float A[][MAXCOL], float B[][MAXCOL], float C[][MAXCOL])
{
  for(int i=0; i<MAXLIN; i++)
    for(int j=0; j < MAXCOL; j++)
      {
        C[i][j] = 0.0;
        for(int k=0; k < MAXCOL; k++) C[i][j] += A[i][k] * B[k][j];
      }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Calcular a matriz transposta
Recebe: Matriz
Devolver: Matriz Transposta
--------------------------------------------------------------------------------------------------------*/
void transpor(float A[][MAXCOL], float B[][MAXCOL])
{
  for(int i=0; i<MAXLIN; i++)
    for(int j=0; j<MAXCOL; j++) B[j][i] = A[i][j];
}
