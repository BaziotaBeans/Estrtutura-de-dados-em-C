/*
  Autor: BaziotaBeans
  Data: 03/09/2018
  Hora: 03:13
*/

#include "pilha.h"
#include <stdio.h>


typedef struct
{
  int chave;
  int valor;
}TItem;


typedef struct
{
  TItem pilha[MAX];
  int topo;
}TPilha;

typedef struct
{
  TItem item[MAX];
  int topo1;
  int topo2;
}TPupla;


/*--------------------------------------------------------------------------------------------------------
Objectivo: Criar uma estrutura de dados do tipo pilha
Parâmetro Entrada: pilha com lixo residual
Parâmetro de Saída: Pilha inicializada
--------------------------------------------------------------------------------------------------------*/
void inicializarPilha ( TPilha *pilha )
{
  pilha->topo = -1;
}


/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a pilha está vazia
Parâmetro Entrada: Pilha
Retorno da Função: Verdadeiro ou Falso
--------------------------------------------------------------------------------------------------------*/
Boolean vaziaPilha ( TPilha pilha )
{
  return ( pilha.topo == -1 );
}


/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a pilha está cheia
Parâmetro Entrada: Pilha
Retorno da Função: Verdadeiro ou Falso
--------------------------------------------------------------------------------------------------------*/
Boolean cheiaPilha ( TPilha pilha )
{
  return ( pilha.topo == TAMANHO-1 );
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento no topo da pilha
Parâmetro Entrada: Um elemento qualquer e uma pilha
Parâmetro de Saída: Pilha actualizada
Retorno da Função: Código de erro (QUEUE_FULL ou OK )
-------------------------------------------------------------------------------------------------------*/
int empilhar ( int x, TPilha *pilha )
{
  if (CheiaPilha(pilha)) return STACK_FULL;
  pilha->topo++;
  pilha->item[pilha->topo] = x;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover um elemento que está no topo da pilha
Parâmero Entrada: Pilha
Parâmetro de Saída: Pilha actualizada e a informação removida
Retorno da Função: Código de erro ( STACK_EMPTY ou OK).
--------------------------------------------------------------------------------------------------------*/
int desempilhar ( TPilha *pilha, int *x )
{
  if ( VaziaPilha(pilha)) return STACK_EMPTY;
  *x = pilha->item[pilha->topo];
  pilha->topo--;
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Consultar um elemento da pilha
Parâmetro Entrada: Pilha
Parâmetro de Saída: Conteudo da Pilha
Retorno da Função: Código de erro (STACK_EMPTY ou OK)
-------------------------------------------------------------------------------------------------------*/
int acessoPilha ( TPilha pilha, int *x )
{
  if ( vaziaPilha (pilha) ) return STACK_EMPTY;
  *x = pilha->item[pilha->topo];
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Determinar o número de elementos inseridos numa pilha
Parâmetro Entrada: Pilha
Retorno da Função: Número de elementos
--------------------------------------------------------------------------------------------------------*/
int tamanhoPilha(TPilha pilha)
{
  return ( pilha.topo + 1 );
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar Pilha WCM
Parâmetro Entrada: Pilha
Retorno da Função: Número de elementos
--------------------------------------------------------------------------------------------------------*/
int wcm(TPilha *p)
{
	if (vazia(p)) return vazia;
	TPilha *p2;
	inicializar(p2);
	while(p->item[p->topo].valor != 'c') p->item[++p->topo] = p->item[p->topo--];
	TItem c = p->item[p->topo--];
	if (tamanho(p) == tamanho(p2))
	{
		while(p->topo != -1 && p2->topo != -1) if (p->item[p->topo--] != p2->item[p2->topo--]) return 0;
		return 1;
	}
	return 0;
}	



Boolean inverter(char *string)
{
	TPilha aux;
	inicializar(&aux);
	int meio = (strlen(string) - 1)/2;
	for (int posicao = 0; posicao <= meio; posicao++) aux->item[++aux->topo] = string[posicao];
	while (aux->topo != -1)
		if (aux->item[aux->topo--] != string[meio++]) return false;
	return true;
}


int ordenarPilha(TPilha *pilha)
{
	if (vazia(pilha)) return STACK_EMPTY;
	TPilha aux, ordenado;
	int menor = pilha->item[pilha->topo], tamanho1 = tamanho(pilha), taux = tamanho*3;
	for (int posicao =0; posica <= taux; posicao++)
	{
		aux.item[++aux.topo] = pilha->item[pilha->topo--];
		if (aux.item[aux.topo.chave < menor) menor = aux.item[aux.topo].chave;
		if (aux.topo == tamanho) ordenada->item[++ordenada.topo] = menor;
		{
			for(int y = 0; y < tamanho; y++)
			{
				if(menor == aux.item[aux.topo.chave]) aux.topo--;
				else pilha->item[++pilha->topo] = aux.item[aux.topo--];
			}
			tamanho--;
			menor = pilha->item[pilha->topo];
		}
	}
	
}




















