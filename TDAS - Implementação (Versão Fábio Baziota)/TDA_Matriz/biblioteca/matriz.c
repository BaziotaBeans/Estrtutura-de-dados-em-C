/* -------------------------------------------------------------------------------------------------------
Especificação das Operações: matriz.c
Objectivo: Implementação da TDA (Matriz) e Disponibilizar operações adição e multiplicação de números reais
-------------------------------------------------------------------------------------------------------*/
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "matriz.h"
#include "libError.h"

/* Solucacao Antiga
struct matriz 
{
  int lin;
  int col;
  float* v;
};
*/

//Solucao nova
typedef struct matriz 
{
  int lin;
  int col;
  float* v;
}TMatriz;

void libera (Matriz* mat)
{
  free(mat->v);
  free(mat);
}

TMatriz* cria (int m, int n)
{
  Matriz *mat = (TMatriz *) malloc(sizeof(TMatriz));
  if (mat == NULL)
  {
    printf ("Memória insuficiente!\n"); //Má escolha!
    exit(1);
  }
  mat->lin = m;
  mat->col = n;
  mat->v = ( float *) malloc( m*n* sizeof(float ));
  return mat;
}


/*Outra Alternativa do Criar + melhor*/
TMatriz* cria (int m, int n, int *flagErro)
{
    TMatriz mat = (TMatriz *) malloc(sizeof(TMatriz));
    if (mat == NULL)
    {
        *flagERRO = ERRO_MEMORIA_INSUFICIENTE;
        exit(1);
    }
    
    mat->lin = m;
    mat->col = n;
    
    mat->v = (float*) malloc(m*n*sizeof(float));
    
    f(mat->v == NULL)
    {
        /*Se não há memória suficiente para a matriz, desalocar a memória anteriormente alocada*/
        free(mat);
        *flagErro = ERRO_MEMORIA_INSUFICIENTE;
        exit(1);
    }
    *flagErro = ERRO_SUCESSO;
    return mat;
}


float acessa (TMatriz* mat, int i, int j)
{
  int k; /* índice do elemento no vetor */
  if (i<0 || i>=mat->lin || j<0 || j>=mat->col)
  {
    printf ("Acesso inválido!\n");
    exit (1);
  }
  k = (i – 1)*mat->col + j;
  return mat->v[k];
}


int linhas (Matriz* mat)
{
  return mat->lin;
}

void atribui (Matriz* mat, int i, int j, float v)
{
  int k; /* índice do elemento no vetor */
  if (i<0 || i>=mat->lin || j<0 || j>=mat->col)
  {
    printf ("Atribuição inválida!\n"); //MSG: Má escolha!
    exit (1);
  }
  k = (i – 1)*mat->col + j;
  mat->v[k] = v;
}


int colunas (Matriz* mat)
{
  return mat->col;
}
