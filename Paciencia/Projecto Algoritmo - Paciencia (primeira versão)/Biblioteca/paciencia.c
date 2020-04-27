/*

      AUTOR: BAZIOTABEANS A.K.A 007
      HORA: 03:00
      Data: 10/11/2018
      Descricao: Projecto III de Algoritmo e Complexidade (ESTRUTURA DE DADOS) - Paciencia

*/
/* -------------------------------------------------------------------------------------------------------
Especificação de operacoes : paciencia.c
Objectivo: Disponibilizar as operações comuns sobre a paciencia
--------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------
                                    Importacao das Bibliotecas
--------------------------------------------------------------------------------------------------------*/
#include "paciencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
/*--------------------------------------------------------------------------------------------------------
			                               Estruturas de Dados   Definidos
--------------------------------------------------------------------------------------------------------*/
typedef enum boolean {true = 1, false = 0}Boolean;

typedef struct carta
{
  int peso;
  char valor;
  char cor;
  char naipe;
  Boolean aberto;
}TCarta;


typedef struct baralho
{
  TCarta *carta;
  int ultPos;
}TBaralho;

typedef struct pointer
{
  TCarta info;
  struct pointer *prox;
}TAtomo;

typedef struct pilha
{
  TAtomo * topo;
  char reference;
  int unidade;
}TPilhaDinamic;
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */
TBaralho* criarBaralho ()
{
    TBaralho *baralho = (TBaralho *) malloc(sizeof(TBaralho));
    baralho->carta  = (TCarta *) malloc(52 * sizeof(TCarta));
    baralho->ultPos = -1;
    return baralho;
}
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */
TPilhaDinamic* criarPilha ()
{
    TPilhaDinamic *pilha = (TPilhaDinamic *) malloc(sizeof(TPilhaDinamic));
    if(pilha != NULL) iniciaPilhaDinamica(pilha);
    return pilha;
}
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */

/*--------------------------------------------------------------------------------------------------------
Recebe: Uma pilha
Objectivo: Inicializar uma pilha em alocação dinâmica
Devolve: pilha dinâmica com ponteiros de controlo actualizados.
------------------------------------------------------------------------------------------------------- */
void iniciaPilhaDinamica ( TPilhaDinamic *pilha )
{
  pilha-> topo = NULL;
}
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */
Boolean vaziaPilhaDinamica(TPilhaDinamic *pilha)
{
    return (pilha->topo == NULL);
}

/*-------------------------------------------------------------------------------------------------------
Recebe: Uma pilha e um determinado registro
Objectivo: Inserir um átomo com essa informação no topo da pilha
Devolve: Pilha actualizada e código de erro
------------------------------------------------------------------------------------------------------ */
int empilhar ( TPilhaDinamic *pilha , TCarta x )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = pilha->topo;
  pilha->topo = pnovo;
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Recebe: Uma pilha
Objectivo: Remover o átomo que está no topo da pilha
Devolve: Pilha actualizada, informação removida e código de erro
-------------------------------------------------------------------------------------------------------*/
int desempilhar (TPilhaDinamic *pilha, TCarta *x)
{
  if (vaziaPilhaDinamica(pilha)) return STACK_EMPTY;
  TAtomo *pdel = pilha->topo;
  *x = pilha->topo->info;
  pilha->topo = pdel ->prox;
  free (pdel);
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
/*int imprimirPilha (TPilhaDinamic *pilha)
{
  TPilhaDinamic *paux1 = criarPilha(), *paux2 = criarPilha();
  while (pilha->topo != NULL)
  {
    printf("| %d \n", pilha->topo->info.peso);
    TCarta x;
    desempilhar(pilha, &x);
    empilhar(paux1, x);
  }
  while (paux1 != NULL)
  {
    TCarta x;
    desempilhar(paux1, &x);
    empilhar(paux2, x);
  }
  while (paux2 != NULL)
  {
    TCarta x;
    desempilhar(paux2, &x);
    empilhar(pilha, x);
  }
  free(paux1);
  free(paux2);
  return OK;

}*/
void imprimirPilha (TPilhaDinamic *pillha)
{
  for (TAtomo *aux = pillha->topo; aux != NULL; aux = aux->prox) printf("%d%c|", aux->info.peso, aux->info.naipe);
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
int autoInserting(TBaralho *baralho)
{
  int codNaipe = 0;
  for (int i = 0, j = 1; i < 52; i++, j++)
  {
    if (j == 14) j = 1;
    if ((i >= 0)  && (i <= 12)) carregar(baralho, i, j, 'v', 'C');
    if ((i >= 13) && (i <= 25)) carregar(baralho, i, j, 'p', 'E');
    if ((i >= 26) && (i <= 38)) carregar(baralho, i, j, 'v', 'O');
    if ((i >= 39) && (i <= 51)) carregar(baralho, i, j, 'p', 'P');
    baralho->ultPos++;
  }
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
int carregar(TBaralho *baralho, int i, int peso, char cor, char naipe)
{
  baralho->carta[i].peso = peso;
  baralho->carta[i].cor = cor;
  baralho->carta[i].naipe = naipe;
  baralho->carta[i].aberto = false;
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
void imprimirBaralho(TBaralho *baralho)
{
  printf("\tCOPA  \tESPADA \tOURO  \tPAUS\n");
  for (int i = 0; i < 13; i++) printf("\t|%d%c  \t|%d%c  \t|%d%c  \t|%d%c \n", baralho->carta[i].peso,baralho->carta[i].naipe, baralho->carta[i + 13].peso,baralho->carta[i + 13].naipe, baralho->carta[i + 26].peso,
  baralho->carta[i + 26].naipe,baralho->carta[i + 39].peso,baralho->carta[i + 39].naipe);
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
TBaralho* embaralharCarta(TBaralho *baralho)
{
  TBaralho *novoBaralho = criarBaralho ();  int pos;
  TCarta *x = criarCarta();
  for (int i = 0; i < MAX_BARALHO && baralho->ultPos != 0; i++)
  {
    srand(time(NULL)); /* Inicializa o gerador de numeros aleatorios */
    pos = 0 + (rand() % baralho->ultPos);
    x = criarCarta();
    removerElemento(baralho, pos, x);
    novoBaralho->carta[i] = *x;
    novoBaralho->ultPos++;
  }
  novoBaralho->ultPos++;
  removerElemento(baralho, baralho->ultPos, x);
  novoBaralho->carta[novoBaralho->ultPos] = *x;
  free(x);
  return novoBaralho;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
TCarta *criarCarta()
{
  TCarta *carta = (TCarta *) malloc(sizeof(TCarta));
  return carta;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
Boolean isEmpty(TBaralho *baralho)
{
  return (baralho->ultPos == -1);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int removerElemento (TBaralho *baralho, int pos, TCarta *x)
{
  if (isEmpty(baralho)) return BARALHO_IS_EMPTY;
  if ( pos < 0 || pos > baralho->ultPos ) return INVALID_INDEX;
  *x = baralho->carta[pos];
  for ( int aux = pos; aux <= baralho->ultPos - 1; aux++ ) baralho->carta[aux] = baralho->carta[aux + 1];
  baralho->ultPos--;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
void simulation1()
{
  TBaralho *baralho = criarBaralho(), *novoBaralho;
  autoInserting(baralho);
  printf("\nANTES DE EMBARALHAR AS CARTAS\n");
  imprimirBaralho(baralho);
  novoBaralho = embaralharCarta(baralho);
  printf("\nDEPOIS DE EMBARALHAR AS CARTAS\n");
  imprimirBaralho(novoBaralho);
  simulation2(novoBaralho);
  free(baralho);
  free(novoBaralho);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
void simulation2(TBaralho *baralho)
{
  TPilhaDinamic *p1 = criarPilha(), *p2 = criarPilha(), *p3 = criarPilha(), *p4 = criarPilha(), *p5 = criarPilha(), *p6 = criarPilha(), *p7 = criarPilha();
  TPilhaDinamic *pS1 = criarPilha(), *ps2 = criarPilha(), *ps3 = criarPilha(), *ps4 = criarPilha(), *pE = criarPilha(), *pD;
  for ( int i = 0, j = 1; j <= 7;  j++)
  {
    if (j <= 1) empilhar(p1, baralho->carta[i++]);
    if (j <= 2) empilhar(p2, baralho->carta[i++]);
    if (j <= 3) empilhar(p3, baralho->carta[i++]);
    if (j <= 4) empilhar(p4, baralho->carta[i++]);
    if (j <= 5) empilhar(p5, baralho->carta[i++]);
    if (j <= 6) empilhar(p6, baralho->carta[i++]);
    if (j <= 7) empilhar(p7, baralho->carta[i++]);
  }
  distribuirParaPilhaEstoque(pE, baralho);
  printf("\nPilha de Jogo 1:");imprimirPilha(p1);
  printf("\nPilha de Jogo 2:");imprimirPilha(p2);
  printf("\nPilha de Jogo 3:");imprimirPilha(p3);
  printf("\nPilha de Jogo 4:");imprimirPilha(p4);
  printf("\nPilha de Jogo 5:");imprimirPilha(p5);
  printf("\nPilha de Jogo 6:");imprimirPilha(p6);
  printf("\nPilha de Jogo 7:");imprimirPilha(p7);
  printf("\n");
  printf("\nPilha de estoque: ");imprimirPilha(pE); printf("\n");

}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int distribuirParaPilhaEstoque(TPilhaDinamic *pilha,TBaralho *baralho)
{
  for (int i = 28; i <= baralho->ultPos; i++) empilhar(pilha, baralho->carta[i]);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
Boolean isOrder(TPilhaDinamic *pilha)
{
  TPilhaDinamic *paux1 = criarPilha();
  TAtomo *aux;
  TCarta carta;
  for (int i=1; i < 13; i++)
  {
    desempilhar(pilha, &carta);
    if ( carta.peso > pilha->topo->info.peso )
    {
      empilharAux(paux1, pilha, i);
      return false;
    }
    empilhar(paux1, carta);
  }
    /*for (int j = i + 1; j <= 13 - i; j++)
    {
      if ( (carta.peso > pilha->topo->info.peso ) return false;
      //desempilhar(pilha, &carta);
      empilhar(paux1, carta);
    }*/
    //empilhar(paux2, carta);
    //empilharAux(paux1, pilha, i);
  empilharAux(paux1, pilha, 0);
  free(paux1); //free(paux2);
  return true;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int empilharAux(TPilhaDinamic *pOrigem, TPilhaDinamic *pDestino, int i)
{
  TCarta carta;
  for (int j=0; j < 13 - i; j++)
  {
    desempilhar(pOrigem, &carta);
    empilhar(pDestino, carta);
  }
}

void insert(TPilhaDinamic *pilha, TBaralho *baralho)
{
  for (int i = 0; i < 13; i++) empilhar(pilha, baralho->carta[i]);
}


void simulation3 ()
{
  TPilhaDinamic *pilha = criarPilha();
  TBaralho *baralho = criarBaralho();
  autoInserting(baralho);
  insert (pilha, baralho);
  //imprimirPilha(pilha);
  if (isOrder(pilha)) imprimirPilha(pilha);
}


/*int distribuirParaPilhaJogada(TPilhaDinamic *pilha,TBaralho *baralho)
{
  for ( int i = 0, j = 1; j <= 7;  j++)
  {
    if (j <= 1) empilhar(p1, baralho->carta[i++]);
    if (j <= 2) empilhar(p2, baralho->carta[i++]);
    if (j <= 3) empilhar(p3, baralho->carta[i++]);
    if (j <= 4) empilhar(p4, baralho->carta[i++]);
    if (j <= 5) empilhar(p5, baralho->carta[i++]);
    if (j <= 6) empilhar(p6, baralho->carta[i++]);
    if (j <= 7) empilhar(p7, baralho->carta[i++]);
  }
}*/
/*int distribuirJogada(TBaralho *baralho)
{

}*/
/*
if (peso == 1) baralho->carta[i].valor = 'A';
if (peso == 2) baralho->carta[i].valor = '2';
if (peso == 3) baralho->carta[i].valor = '3';
if (peso == 4) baralho->carta[i].valor = '4';
if (peso == 5) baralho->carta[i].valor = '5';
if (peso == 6) baralho->carta[i].valor = '6';
if (peso == 7) baralho->carta[i].valor = '7';
if (peso == 8) baralho->carta[i].valor = '8';
if (peso == 9) baralho->carta[i].valor = '9';
if (peso == 10)baralho->carta[i].valor = '1';
if (peso == 11)baralho->carta[i].valor = 'J';
if (peso == 12)baralho->carta[i].valor = 'Q';
if (peso == 13)baralho->carta[i].valor = 'K';
*/
