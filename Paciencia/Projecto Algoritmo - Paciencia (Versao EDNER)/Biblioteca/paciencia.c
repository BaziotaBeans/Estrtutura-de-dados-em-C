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
void imprimirPilha (TPilhaDinamic *pilha)
{
  //for (TAtomo *aux = pillha->topo; aux != NULL; aux = aux->prox) printf("%d%c|", aux->info.peso, aux->info.naipe);
  if(pilha->topo != NULL)
  {
	for (TAtomo *aux = pilha->topo; aux != NULL; aux = aux->prox)
	{
		if(aux->info.aberto == true)
		{
			if(aux->info.peso == 1) printf("A");
			else if(aux->info.peso == 11) printf("J");
			else if(aux->info.peso == 12) printf("Q");
			else if(aux->info.peso == 13) printf("K");
			else printf("%d", aux->info.peso);
			printf("%c", aux->info.naipe);
		}
		else printf("--"); //printf("::");
		printf("|");
	}
  }
  else printf("Vazia");
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
  int cont, margem;
  printf("\tCOPA  \tESPADA \tOURO  \tPAUS\n");
  for (int i = 0; i < 13; i++)
  {
  	margem = 0;
  	cont = 0;
  	while(cont<4)
  	{
  		printf("\t|");
  		if(baralho->carta[i+margem].peso == 1) printf("A");
  		else if(baralho->carta[i+margem].peso == 11) printf("J");
  		else if(baralho->carta[i+margem].peso == 12) printf("Q");
  		else if(baralho->carta[i+margem].peso == 13) printf("K");
  		else printf("%d", baralho->carta[i+margem].peso);
  		printf("%c  ", baralho->carta[i+margem].naipe);
  		cont++;
  		margem+=13;
  	}
  	printf("\n");

  	//	printf("\t|%d%c  \t|%d%c  \t|%d%c  \t|%d%c \n", baralho->carta[i].peso,baralho->carta[i].naipe, baralho->carta[i + 13].peso,baralho->carta[i + 13].naipe, baralho->carta[i + 26].peso,
  	//	baralho->carta[i + 26].naipe,baralho->carta[i + 39].peso,baralho->carta[i + 39].naipe);
  }
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

void abrirTopo(TPilhaDinamic *pilha)
{
	//para o caso de pilha vazias
	if( !vaziaPilhaDinamica(pilha) ) pilha->topo->info.aberto = true;
}

void fecharTopo(TPilhaDinamic *pilha)
{
	//para o caso de pilha vazias
	if( !vaziaPilhaDinamica(pilha) ) pilha->topo->info.aberto = false;
}

int empilharAs(TPilhaDinamic *pilha, TPilhaDinamic *pS1, TPilhaDinamic *pS2, TPilhaDinamic *pS3, TPilhaDinamic *pS4) //empilharAces(pJ1, pS1, pS2, pS3, pS4)
{
  TCarta x;
  if(pilha->topo != NULL)
  {
	if(pilha->topo->info.peso == 1)
	{
		desempilhar(pilha, &x);
		if(pS1->topo == NULL) empilhar(pS1, x);
		else if(pS2->topo == NULL) empilhar(pS2, x);
		else if(pS3->topo == NULL) empilhar(pS3, x);
		else if(pS4->topo == NULL) empilhar(pS4, x);
		abrirTopo(pilha);
		return OK;
	}
  }
  return -1;
}

int empilharPSaida(TPilhaDinamic *pilha, TPilhaDinamic *pS1, TPilhaDinamic *pS2, TPilhaDinamic *pS3, TPilhaDinamic *pS4) //empilharAs(pJ1, pS1, pS2, pS3, pS4)
{
  if( pS1->topo != NULL || pS2->topo != NULL || pS3->topo != NULL || pS4->topo != NULL )
  {
	if(pilha->topo != NULL)
	{
		TCarta x;
		if( pS1->topo != NULL && pilha->topo->info.naipe == pS1->topo->info.naipe
		&& pilha->topo->info.peso - pS1->topo->info.peso == 1 )
		{
			desempilhar(pilha, &x);
			empilhar(pS1, x);
			abrirTopo(pilha);
			return OK;
		}
		else if( pS2->topo != NULL && pilha->topo->info.naipe == pS2->topo->info.naipe
		&& pilha->topo->info.peso - pS2->topo->info.peso == 1 )
		{
			desempilhar(pilha, &x);
			empilhar(pS2, x);
			abrirTopo(pilha);
			return OK;
		}
		else if( pS3->topo != NULL && pilha->topo->info.naipe == pS3->topo->info.naipe
		&& pilha->topo->info.peso - pS3->topo->info.peso == 1 )
		{
			desempilhar(pilha, &x);
			empilhar(pS3, x);
			abrirTopo(pilha);
			return OK;
		}
		else if( pS4->topo != NULL && pilha->topo->info.naipe == pS4->topo->info.naipe
		&& pilha->topo->info.peso - pS4->topo->info.peso == 1 )
		{
			desempilhar(pilha, &x);
			empilhar(pS4, x);
			abrirTopo(pilha);
			return OK;
		}
	}
  }
  return -1;
}

void imprimirTodasPilhas(TPilhaDinamic *pJ1, TPilhaDinamic *pJ2, TPilhaDinamic *pJ3, TPilhaDinamic *pJ4, TPilhaDinamic *pJ5, TPilhaDinamic *pJ6, TPilhaDinamic *pJ7, TPilhaDinamic *pS1, TPilhaDinamic *pS2, TPilhaDinamic *pS3, TPilhaDinamic *pS4, TPilhaDinamic *pD, TPilhaDinamic *pE)
{
	printf("\nPilha de Jogo 1: "); imprimirPilha(pJ1);
	printf("\nPilha de Jogo 2: "); imprimirPilha(pJ2);
	printf("\nPilha de Jogo 3: "); imprimirPilha(pJ3);
	printf("\nPilha de Jogo 4: "); imprimirPilha(pJ4);
	printf("\nPilha de Jogo 5: "); imprimirPilha(pJ5);
	printf("\nPilha de Jogo 6: "); imprimirPilha(pJ6);
	printf("\nPilha de Jogo 7: "); imprimirPilha(pJ7);
	printf("\n");
	printf("\nPilha de Estoque: "); imprimirPilha(pE);
	printf("\nPilha de Descarte: "); imprimirPilha(pD);
	printf("\n");

	printf("\nPilha de Saída 1: "); imprimirPilha(pS1);
	printf("\nPilha de Saída 2: "); imprimirPilha(pS2);
	printf("\nPilha de Saída 3: "); imprimirPilha(pS3);
	printf("\nPilha de Saída 4: "); imprimirPilha(pS4);
	printf("\n");
}

int qtdPSaidaNulas(TPilhaDinamic *pS1, TPilhaDinamic *pS2, TPilhaDinamic *pS3, TPilhaDinamic *pS4)
{
	int cont = 0;
	if(pS1->topo == NULL) cont++;
	if(pS2->topo == NULL) cont++;
	if(pS3->topo == NULL) cont++;
	if(pS4->topo == NULL) cont++;
	return cont;
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
  TPilhaDinamic *pJ1 = criarPilha(), *pJ2 = criarPilha(), *pJ3 = criarPilha(), *pJ4 = criarPilha(), *pJ5 = criarPilha(), *pJ6 = criarPilha(), *pJ7 = criarPilha();
  TPilhaDinamic *pS1 = criarPilha(), *pS2 = criarPilha(), *pS3 = criarPilha(), *pS4 = criarPilha(), *pE = criarPilha(), *pD = criarPilha();
  int qtdNull, cont, cont2 = 0;
  
  for ( int i = 0, j = 1; j <= 7;  j++)
  {
    if (j <= 1) empilhar(pJ1, baralho->carta[i++]);
    if (j <= 2) empilhar(pJ2, baralho->carta[i++]);
    if (j <= 3) empilhar(pJ3, baralho->carta[i++]);
    if (j <= 4) empilhar(pJ4, baralho->carta[i++]);
    if (j <= 5) empilhar(pJ5, baralho->carta[i++]);
    if (j <= 6) empilhar(pJ6, baralho->carta[i++]);
    if (j <= 7) empilhar(pJ7, baralho->carta[i++]);
  }
  distribuirParaPilhaEstoque(pE, baralho);

  abrirTopo(pJ1);
  abrirTopo(pJ2);
  abrirTopo(pJ3);
  abrirTopo(pJ4);
  abrirTopo(pJ5);
  abrirTopo(pJ6);
  abrirTopo(pJ7);

  imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
  
  printf("\n Clique <ENTER> para continuar...\n");
  system("read x");
  system("clear");
//  printf("\n\n DEPOIS DE EMPILHAR ASES");

  imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
  system("sleep 2");
//  system("clear");

  //MANDAR ASES PARA AS PILHAS DE SAÍDA
  qtdNull = qtdPSaidaNulas(pS1, pS2, pS3, pS4);
  cont = 0;
  while(cont<qtdNull)
  {
	system("clear");
	empilharAs(pJ1, pS1, pS2, pS3, pS4);
	empilharAs(pJ2, pS1, pS2, pS3, pS4);
	empilharAs(pJ3, pS1, pS2, pS3, pS4);
	empilharAs(pJ4, pS1, pS2, pS3, pS4);
	empilharAs(pJ5, pS1, pS2, pS3, pS4);
	empilharAs(pJ6, pS1, pS2, pS3, pS4);
	empilharAs(pJ7, pS1, pS2, pS3, pS4);
	cont++;

	imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
	system("sleep 2");
//	system("clear");
  }
  cont = 0;
  while(cont<5)
  {
	if( empilharPSaida(pJ1, pS1, pS2, pS3, pS4) == OK )
	{
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 1");
	}
	if( empilharPSaida(pJ2, pS1, pS2, pS3, pS4) == OK )
	{
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 1");
	}
	if( empilharPSaida(pJ3, pS1, pS2, pS3, pS4) == OK )
	{
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 1");
	}
	if( empilharPSaida(pJ4, pS1, pS2, pS3, pS4) == OK )
	{
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 1");
	}
	if( empilharPSaida(pJ5, pS1, pS2, pS3, pS4) == OK )
	{
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 1");
	}
	if( empilharPSaida(pJ6, pS1, pS2, pS3, pS4) == OK )
	{
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 1");
	}
	empilharPSaida(pJ7, pS1, pS2, pS3, pS4);
	cont++;

	system("clear");
	imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
	system("sleep 1");
//	system("clear");
  }
  TCarta x;
  while(pE->topo != NULL)
  {
	desempilhar(pE, &x);
	empilhar(pD, x);
	abrirTopo(pD);
	system("clear");
	imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
	system("sleep 2");
	while ( empilharPSaida(pD, pS1, pS2, pS3, pS4) == OK || empilharAs(pD, pS1, pS2, pS3, pS4) == OK )
	{
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 2");

		empilharPSaida(pJ1, pS1, pS2, pS3, pS4);
		empilharPSaida(pJ2, pS1, pS2, pS3, pS4);
		empilharPSaida(pJ3, pS1, pS2, pS3, pS4);
		empilharPSaida(pJ4, pS1, pS2, pS3, pS4);
		empilharPSaida(pJ5, pS1, pS2, pS3, pS4);
		empilharPSaida(pJ6, pS1, pS2, pS3, pS4);
		empilharPSaida(pJ7, pS1, pS2, pS3, pS4);
		
		system("clear");
		imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
		system("sleep 1");

/*		if(  )
		{
			system("clear");
			imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
			system("sleep 2");
		}
		if(  )
		{
			system("clear");
			imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
			system("sleep 2");
		}
*/
	}

	fecharTopo(pD);
  }
  while(pD->topo != NULL)
  {
	desempilhar(pD, &x);
	empilhar(pE, x);
	fecharTopo(pE);
  }
  //PÔR O empilharAs E O empilharPSaida NUMA SÓ FUNÇÃO, COMO FIZ COMO O imprimirPilha
  system("clear");
  printf("\nULTIMA IMPRESSÃO\n");
  imprimirTodasPilhas(pJ1, pJ2, pJ3, pJ4, pJ5, pJ6, pJ7, pS1, pS2, pS3, pS4, pD, pE);
  system("sleep 1");
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
