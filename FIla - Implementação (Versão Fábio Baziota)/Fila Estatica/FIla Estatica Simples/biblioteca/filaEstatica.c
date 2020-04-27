/*
  Autor: BaziotaBeans
  Data: 17/09/2018
  Hora: 22:15
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : filaEstatica.c
Objectivo: Implementação da TDA fila estatica e disponibilizas as suas operacoes basicas
--------------------------------------------------------------------------------------------------------*/
#include "filaEstatica.h"
#include <stdio.h>


/*--------------------------------------------------------------------------------------------------------
Objectivo: Criar uma estrutura de dados do tipo fila
Parâmetro Entrada: Um vector
Parámetro de Saída: Fila
--------------------------------------------------------------------------------------------------------*/
void inicializarFila (TFila *fila)
{
  fila->frente = -1;
  file->fundo = -1;
}

Boolean vaziaFila(TFIla *fila)
{
  return (fila->fundo == -1);
}

Boolean cheiaFIla(TFila *fila)
{
  return (fila->fundo == MAX-1);
}


/*-------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento no fundo da fila
Parâmetro Entrada: Um elemento qualquer e uma fila
Parâmetro de Saída: Fila actualizada
Valor de Retorno: Código de erro ( QUEUE_FULL ou OK)
-------------------------------------------------------------------------------------------------------*/
int inserirFila (int x, TFila *fila)
{
  if (cheiaFila(fila)) return QUEUE_FULL;
  fila->fundo++;
  fila->item[fila->fundo] = x;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover um elemento na frente da fila
Parâmetro Entrada: Fila
Parâmetro de saída: Fila actualizada, o conteúdo do elemento removido
Valor de Retorno: Código erro ( QUEUE_EMPTY ou OK)
-------------------------------------------------------------------------------------------------------*/
int removerFila (TFila *fila, int *x)
{
  if (vaziaFila(fila)) return QUEUE_EMPTY;
  fila->frente++;
  *x= fila->item[fila->frente];
  if (fila->frente == fila-> fundo) inicializar(fila);
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
