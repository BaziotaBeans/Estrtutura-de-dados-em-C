/*
  Autor: BaziotaBeans
  Data: 09/09/2018
  Hora: 17:27
*/

#include "pilhaSequencialDupla.h"
#include <stdio.h>

typedef struct
{
  int chave;
  int valor;
}TItem;

typedef struct
{
  TItem item[MAX];
  int topo1;
  int topo2;
}TPDupla;

/*--------------------------------------------------------------------------------------------------------
Objectivo: Criar uma estrutura de dados do tipo pilha dupla
Parâmetro Entrada: Vector com lixo residual
Parâmetro de Saída: Pilha dupla inicializada
--------------------------------------------------------------------------------------------------------*/
void inicializarPilhaDupla ( TPDupla *pilha )
{
  pilha->topo1 = -1;
  //pilha->topo2 = MAX + 1;
  pilha->topo2 = MAX;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Determinar o número de elementos inseridos numa pilha
Parâmetro Entrada: Vector com as pilhas, número da pilha
Retorno da Função: Número de elementos dessa pilha
--------------------------------------------------------------------------------------------------------*/
int tamanhoPilhaDupla ( TPDupla pilha, int np )
{
  if( np == 1 ) return(pilha.topo1 + 1);
  //return(MAX + 1 - pilha.topo2);
  return(MAX - pilha.topo2);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se uma pilha está vazia
Parâmetro Entrada: Vector com as pilhas e o número da pilha
Retorno da Função: Verdadeiro ou falso
--------------------------------------------------------------------------------------------------------*/
Boolean pilhaDuplaVazia ( TPDupla pilha, int np )
{
  if ( np == 1) return (pilha.topo1 == -1);
  return (pilha.topo2 == MAX);
  //return ( pilha.topo2 == MAX+1 );
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a pilha está cheia
Parâmetro Entrada: Vector com as pilhas
Retorno da Função: Verdadeiro ou falso
--------------------------------------------------------------------------------------------------------*/
Boolean pilhaDuplaCheia ( TPDupla pilha )
{
  return (pilha.topo1 == pilha.topo2 - 1);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento numa pilha
Parâmetro Entrada: Vector com as pilhas, elemento a inserir, número da pilha
Parâmetro de saída : Pilha actualizada
Retorno da Função: Código de erro (STACK_EMPTY ou OK)
--------------------------------------------------------------------------------------------------------*/
int empilhar ( TPDupla *pilha, TItem x, int np )
{
  if (pilhaDuplaCheia(pilha)) return STACK_FULL;
  if (np == 1)
  {
    pilha->topo1++;
    pilha->item[pilha->topo1] = x;
  }
  else
  {
    pilha->topo2++;
    pilha->item[pilha->topo2] = x;
  }
  return OK;
}

int desempilhar (TDUpla *pilha, TItem *x, int np)
{
  if (pilhaDuplaVazia(pilha)) return STACK_EMPTY;
  if (np == 1)
  {
    *x = pilha->item[pilha->topo1];
    pilha->topo1--;
  }
  else
  {
    *x = pilha->item[pilha->topo2];
    pilha->topo2++;
  }
  return OK;
}
