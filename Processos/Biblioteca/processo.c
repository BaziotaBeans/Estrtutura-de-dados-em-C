/*
  Autor: 
  Data: 04/11/2018
  Hora: 23:40
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : filaDinamica.c
Objectivo: Implementação da TDA fila dinamica e disponibilizas as suas operacoes basicas
--------------------------------------------------------------------------------------------------------*/
#include "processo.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum boolean { FALSE= 0, TRUE= 1 } Boolean;


typedef struct info
{
  int id;
  int tempoDuracao;
}TInfo;

typedef struct apontador
{
  TInfo info;
  struct apontador *prox;
}TAtomo;

typedef struct fila
{
  TAtomo *frente;
  TAtomo *fundo;
} TFilaDinamic;
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de saída:
------------------------------------------------------------------------------------------------------ */
TFilaDinamic* criar()
{
    TFilaDinamic *fila = (TFilaDinamic *) malloc(sizeof(TFilaDinamic));
    iniciaFilaDinamica(fila);
    return fila;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inicializar uma fila em organização dinâmica
Parâmetro Entrada Uma fila
Parâmetro de saída: fila dinâmica com ponteiros actualizados.
------------------------------------------------------------------------------------------------------ */
void iniciaFilaDinamica (TFilaDinamic *fila)
{
    fila->frente = NULL;
    fila->fundo = NULL;
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a fila está vazia
Parâmetro Entrada: Uma fila
Valor de Retorno: True ou False
------------------------------------------------------------------------------------------------------- */
Boolean vaziaFilaDinamica (TFilaDinamic *fila)
{
    return (fila->frente == NULL && fila->fundo == NULL);
}

/*-----------------------------------------------------------------------------------------------------
Objectivo: Inserir um átomo com uma determinada informação no fim da fila
Parâmetro Entrada: Uma fila e uma determinada informação
Parâmetro de Saída: Fila actualizada
Valor de Retorno: Código de erro ( NO_SPACE ou OK)
---------------------------------------------------------------------------------------------------- */
int inserirFilaDinamica (TFilaDinamic *fila, TInfo *x)
{
    TAtomo *pnovo = (TAtomo *) malloc( sizeof(TAtomo));
    if (pnovo == NULL) return NO_SPACE;
    pnovo->info = *x;
    pnovo->prox = NULL;
    if ( vaziaFilaDinamica(fila))
    {
        fila->fundo = pnovo;
        fila->frente = pnovo;
    }
    else
    {
        fila->fundo->prox = pnovo;
        fila->fundo = pnovo;
    }
    return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover o átomo que está no ínicio da fila
Parâmetro Entrada: Uma fila
Parâmetro de Saída: Fila actualizada e a informação removida
Valor de Retorno: Código de erro (QUEUE_EMPTY ou OK)
-------------------------------------------------------------------------------------------------------*/
int removerFilaDinamica (TFilaDinamic *fila, TInfo *x)
{
    if ( vaziaFilaDinamica(fila)) return QUEUE_EMPTY;
    TAtomo *pdel = fila->frente;
    *x = fila->frente->info;
    if (filaUnitaria(fila)) iniciaFilaDinamica(fila);
    else
    fila->frente = fila->frente->prox;
    free(pdel);
}

Boolean existe(TFilaDinamic *fila, int tempoDuracao)
{
  for (TAtomo *pbusca = fila->frente; pbusca != NULL; pbusca = pbusca->prox)
    if(pbusca->info.tempoDuracao == tempoDuracao) return TRUE;
  return FALSE;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
int removerId(TFilaDinamic *fila, int tempoDuracao)
{
  if ( vaziaFilaDinamica(fila)) return QUEUE_EMPTY;
  if (existe(fila, tempoDuracao))
  {
      TAtomo *pdel = fila->frente, *pant = NULL;
      while (pdel != NULL)
      {
        if (pdel->info.tempoDuracao == tempoDuracao && pdel == fila->frente)
        {
          fila->frente = fila->frente->prox;
          free(pdel);
          return OK;
        }
        else if (pdel->info.tempoDuracao == tempoDuracao)
        {
          pant->prox = pdel->prox;
          pdel->prox = NULL;
          free(pdel);
          return OK;
        }
        pant = pdel;
        pdel = pdel->prox;
      }
  }
  return NOT_FOUND;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Verficar se uma fila e unitaria
Parâmetro Entrada: Uma fila
Valor de Retorno: TRUE OR FALSE
-------------------------------------------------------------------------------------------------------*/
Boolean filaUnitaria(TFilaDinamic *fila)
{
  return (fila->frente == fila->fundo);
}

void imprimir(TFilaDinamic *fila)
{
  for(TAtomo *perc = fila->frente; perc != NULL; perc = perc->prox) printf("\n|ID: %d e Tempo de execucao: %d|\n", perc->info.id, perc->info.tempoDuracao);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
int lerTempo()
{
  int exec;
  printf("\nDigite o Tempo de execucao do processo: "); scanf("%d", &exec);
  while (1)
  {
    if (exec >= 0) return exec;
    printf("\nERRO: (ID invalido) Digite o Tempo de execucao do processo: "); scanf("%d", &exec);
  }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
int lerID()
{
  int id;
  printf("\nDigite o ID do processo: "); scanf("%d", &id);
  while (1)
  {
    if (id >= 1) return id;
    printf("\nERRO: (ID invalido) Digite o ID do processo: "); scanf("%d", &id);
  }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
TInfo* lerInfo()
{
  TInfo *info = (TInfo *) malloc(sizeof(TInfo));
  info->id = lerID();
  info->tempoDuracao = lerTempo();
  return info;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
void inserirProcesso(TFilaDinamic *fila)
{
  int n = lerQuantidadeProcesso();
  for (int i = 1; i <= n; i++) inserirFilaDinamica(fila, lerInfo());
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
int lerQuantidadeProcesso()
{
  int n;
  printf("\nDigite a quantidade de processo que deseja inserir: "); scanf("%d", &n);
  while (1)
  {
    if (n > 0) return n;
    printf("\nERRO: (ID invalido) Digite a quantidade de processo que deseja inserir: "); scanf("%d", &n);
  }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
int removerMaior(TFilaDinamic *fila)
{
  int maior = 0, id;
  TAtomo *faux = fila->frente;
  while (faux != NULL)
  {
    if (maior < faux->info.tempoDuracao)
    {
      maior = faux->info.tempoDuracao;
      id = faux->info.tempoDuracao;
    }
    faux = faux->prox;
  }
  return id;
}
/*
int removerMaior(TFilaDinamic *fila)
{
  int maior = 0, tempoDuracao;
  TAtomo *faux = fila->frente;
  while (faux != NULL)
  {
    if (maior < faux->info.id)
    {
      maior = faux->info.id;
      id = faux->info.tempoDuracao;
    }
    faux = faux->prox;
  }
  return tempoDuracao;
}
*/
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Valor de Retorno:
-------------------------------------------------------------------------------------------------------*/
void liberar(TFilaDinamic *fila)
{
  free(fila);
}
