/*
  Autor: BaziotaBeans
  Data: 17/09/2018
  Hora: 22:15
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : filaEstatica.c
Objectivo: Implementação da TDA fila estatica e disponibilizas as suas operacoes basicas
--------------------------------------------------------------------------------------------------------*/
#include "filaEstaticaCircular.h"
#include <stdio.h>


/*--------------------------------------------------------------------------------------------------------
Objectivo: Criar uma estrutura de dados do tipo fila circular
Parâmetro de Entrada: vector fila
Parâmetro saída: Fila circular
--------------------------------------------------------------------------------------------------------*/
void inicializarFilaCircular(TFilaCirc *fila)
{
  fila->frente = TAMANHO/2;
  fila->fundo = TAMANHO/2;
  fila->tamanho = 0;
}

Boolean vaziaFila(TFIla *fila)
{
  return (fila->tamanho == 0);
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a fila circular está cheia
Parâmetro Entrada: Fila circular
Valor de Retorno: Verdadeiro ou falso
--------------------------------------------------------------------------------------------------------*/
Boolean cheiaFilaCircular (TFilaCirc fila)
{
  return (fila.tamanho == TAMANHO);
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento no fundo de uma fila circular
Parâmetro Entrada: Um elemento qualquer e uma fila circular
Parametro Saída : Fila circular actualizada
Valor Retorno: código de erro (QUEU_FULL ou OK)
--------------------------------------------------------------------------------------------------------*/
int inserirFilaCircular (int x, TFilaCirc *fila)
{
  if ( cheiaFilaCircular(fila) ) return QUEUE_FULL;
  fila->fundo = (fila->fundo + 1) % TAMANHO;
  fila->tamanho++;
  fila->item[fila->fundo] = x;
  return OK;
}

}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover o elemento da frente de uma fila circular
Parâmetro Entrada: Fila circular
Parâmetro de Saída:Fila circular actualizada, conteudo do elemento removido
Valor de Retorno: codigo de erro (QUEUE_EMPTY ou OK )
--------------------------------------------------------------------------------------------------------*/
int removerFilaCircular(TFilaCirc *fila, int *x);
{
  if ( vaziaFilaCircular(fila) ) return QUEUE_EMPTY;
  fila->frente = (fila->frente + 1) % TAMANHO;
  fila->tamanho--;
  *x = fila->item[fila->frente];
  return OK;
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Determinar o número de elementos da fila
Parâmetro Entrada: Fila
Valor de Retorno: Número inteiro maior ou igual a zero
--------------------------------------------------------------------------------------------------------*/
int TamanhoFila (Tfila fila);
{
  return (fila.fundo - fila.frente);
}
