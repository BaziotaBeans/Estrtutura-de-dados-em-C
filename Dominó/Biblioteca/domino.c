/*

      AUTOR: BAZIOTABEANS A.K.A 007
      Hora de Criacao: 02:30
      Data de criacao: 16/10/2018
      Hora de Modificacao: 06:20
      Data de Modificacao: 04/11/2018
      Descricao: Projecto II de Algoritmo e Complexidade (ESTRUTURA DE DADOS) - DOMINO

*/
/* -------------------------------------------------------------------------------------------------------
Especificação de operacoes : domino.c
Objectivo: Disponibilizar as operações comuns sobre um domino
--------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------
                                    Importacao das Bibliotecas
--------------------------------------------------------------------------------------------------------*/
#include "domino.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*--------------------------------------------------------------------------------------------------------
			                               Estruturas de Dados   Definidos
--------------------------------------------------------------------------------------------------------*/
typedef enum boolean {true = 1, false = 0}Boolean;

typedef struct peca
{
  int x;
  int y;
}TPeca;

typedef struct atomo
{
    TPeca peca;
    struct atomo *dprox;
    struct atomo *eprox;
}TAtomo;

typedef struct lista
{
  TAtomo *primeiro;
  TAtomo *ultimo;
  Boolean campo;
}TLista;


typedef struct jogada
{
    TLista *jogada;
    int ultJogada;
}TJogada;


/*--------------------------------------------------------------------------------------------------------------------------------------------
			                                                                    Fim de Estruturas de Dados
--------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------------
			                                                                   Impletação das Funções da LISTA
--------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------
Objectivo: Criar o ponteiro jogada alocando um espaco para o vector de ponteiro das listas
Parâmetro Entrada: nada
Parâmetro de Saída: o espaco necessario alocado
Parâmetro de retorno: o ponteiro com o espaco alocado
------------------------------------------------------------------------------------------------------- */
TJogada* criar()
{
  TJogada *jogada = (TJogada *) malloc(sizeof(TJogada));
  jogada->jogada = (TLista *) malloc(sizeof(TLista));
  jogada->jogada->primeiro = NULL;
  jogada->jogada->ultimo = NULL;
  jogada->ultJogada = -1;
  return jogada;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: realocar espaco necessario para o vector de ponteiro das listas
Parâmetro Entrada: o ponteiro jogada e o numero de jogada (iteracao)
Parâmetro de Saída: o espaco necessario realocada
Parâmetro de retorno: o ponteiro com o espaco realocado
------------------------------------------------------------------------------------------------------- */
TJogada* recriar(TJogada *jogada, int nJogada)
{
  jogada->jogada = (TLista *) realloc(jogada->jogada, sizeof(TLista) * nJogada);
  jogada->ultJogada = jogada->ultJogada + 1;
  return jogada;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inicializar uma estrutura de dados do tipo lista duplamente ligada
Parâmetro Entrada: Lista duplamente ligada
Parâmetro de Saída: Lista duplamente ligada com os ponteiros de controlo actualizados.
------------------------------------------------------------------------------------------------------- */
void iniciarLiista(TLista *lista)
{
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se uma lista esta vazia
Parâmetro Entrada: Lista duplamente ligada
Parâmetro de Saída: Verdade ou Falso
------------------------------------------------------------------------------------------------------- */
Boolean isEmpty(TJogada *jogada, int i)
{
  return (jogada->jogada[i].primeiro == NULL);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um àtomo na lista
Parâmetro Entrada: A informacao a inserir, o ponteiro jogada e o indice que referencia a posicao no vector
Parâmetro de Saída: vector jogada e a Lista actualizada
Retorno da Função: Código de erro
--------------------------------------------------------------------------------------------------------*/
int inserirDireita (TJogada *jogada, TPeca *x, int i)
{
  TAtomo *pnovo = ( TAtomo *) malloc (sizeof(TAtomo));
  if ( pnovo == NULL ) return NO_SPACE;
  pnovo->peca = *x; pnovo->dprox = NULL;  pnovo->eprox = NULL;
  if (jogada->jogada[i].primeiro == NULL) jogada->jogada[i].primeiro = pnovo;
  //if (isEmpty(jogada, i)) jogada->jogada[i].primeiro = pnovo;
  else
  {
    pnovo->eprox = jogada->jogada[i].ultimo;
    jogada->jogada[i].ultimo->dprox = pnovo;
  }
  jogada->jogada[i].ultimo = pnovo;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Imprimir as pecas
Parâmetro  Entrada: Ponteiro jogadas e o indice que representa a posicao no vector
Retorno da Função: Código de erro
------------------------------------------------------------------------------------------------------- */
int imprimirLista(TJogada *jogada, int i)
{
  if (jogada->jogada[i].campo != true) {printf("\n\n Teste %d\n\n", i+1); printf("\n NAO\n");}
  else
  {
    if (jogada->jogada[i].primeiro == NULL) return LIST_EMPTY;
    printf("\n\n Teste %d\n\n", i+1);
    printf("\n\n SIM \n\n");
    for(TAtomo *paux = jogada->jogada[i].primeiro; paux != NULL; paux = paux->dprox) printf(" |%d %d|",paux->peca.x, paux->peca.y);
  }
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Imprimir na sequecia vectorial as listas armazenadas em cada indice do ponteiro jogada
Parâmetro  Entrada: ponteioro jogada
------------------------------------------------------------------------------------------------------- */
int imprimirGeral(TJogada *jogada)
{
  for (int i = 0; i <= jogada->ultJogada; i++)
  {
    imprimirLista(jogada, i);
  }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Ler as pecas (X E Y), validar, armazenar no ponteiro do tipo TPeca e retornar o ponteiro
Parâmetro Entrada: Nada
Parâmetro de retorno: ponteiro criado
------------------------------------------------------------------------------------------------------- */
TPeca* lerPecas()
{
  TPeca *p = (TPeca *) malloc(sizeof(TPeca));
  int x, y;
  Boolean flag = true;
  printf("\n Digite o valor da peça X e Y: "); scanf("%d %d", &x, &y);
  while(flag)
  {
      if (((x >= 0) && (x <= 6)) && ((y >= 0) && (y <= 6))) flag = false;
      else
      {
        printf("\n(ERRO: Valor Invalido)\n Digite o valor da peça X e Y: "); scanf("%d %d", &x, &y);
      }
  }
  p->x = x;
  p->y = y;
  return p;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: ler um numero inteiro (quantidade de pecas)  e validar
Parâmetro Entrada: Nada
Parâmetro de retorno: a respectiva quantidade de peca
------------------------------------------------------------------------------------------------------- */
int lerQuantidadePecas()
{
  int n;
  printf("\n Digite a quantidade de pecas: "); scanf("%d", &n);
  while(1)
  {
      if ((n >= 0) && (n <= 28)) return n;
      printf("\nERRO: quantidade invalido, Por favor Digite o quantidade da peça: "); scanf("%d", &n);
  }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Ordenar as pecas do domino
Parâmetro Entrada: o ponteiro jogada
Parametro de saída: o ponteiro jogada actualizada
Retorno da Função: Código de erro
-------------------------------------------------------------------------------------------------------*/
int ordenarDomino (TJogada *jogada, int i)
{
  TAtomo *percorrer = jogada->jogada[i].primeiro;
	while (percorrer != NULL)
	{
		TAtomo *auxiliar = percorrer->dprox;
		while (auxiliar != NULL)
		{
			if (percorrer->peca.y != auxiliar->peca.x)
			{
				if (percorrer->peca.y == auxiliar->peca.y)
				{
					trocarDados (&auxiliar->peca);
					if (percorrer->dprox != auxiliar) ligarLinksDireita (&jogada->jogada[i], percorrer, auxiliar);
					percorrer = percorrer->dprox;
					auxiliar = percorrer->dprox;
				}
				else auxiliar = auxiliar->dprox;
			}
			else
			{
				if (percorrer->dprox != auxiliar) ligarLinksDireita (&jogada->jogada[i], percorrer, auxiliar);
				percorrer = percorrer->dprox;
				auxiliar = percorrer->dprox;
			}
		}
		percorrer = percorrer->dprox;
	}
  if(!verificarDomino(jogada->jogada[i])) ligarLinksEsquerda (&jogada->jogada[i], jogada->jogada[i].ultimo);
  if(!verificarDomino(jogada->jogada[i])) numeroDesordenado(&jogada->jogada[i],jogada,i);
  jogada->jogada[i].campo = verificarDomino(jogada->jogada[i]);
	return OK;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Trocar os valor das pecas nesse caso (X e Y)
Parâmetro Entrada: a peca
Parametro de saída: as pecas actualizadas
-------------------------------------------------------------------------------------------------------*/
void trocarDados (TPeca *peca)
{
	int auxiliar = peca->x;
	peca->x = peca->y;
	peca->y = auxiliar;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: ligar um atomo com outro da direita para esquerda
Parâmetro Entrada: a listas duplamente ligada, e dois atomos
Parametro de saída: a lista actualizada com os atomos linkados
-------------------------------------------------------------------------------------------------------*/
void ligarLinksDireita (TLista *lista, TAtomo *peca, TAtomo *proximaPeca)
{
	proximaPeca->eprox->dprox = proximaPeca->dprox;
	if (proximaPeca->dprox == NULL) lista->ultimo = proximaPeca->eprox;
	else proximaPeca->dprox->eprox = proximaPeca->eprox;
	proximaPeca->dprox = peca->dprox;
	peca->dprox->eprox = proximaPeca;
	peca->dprox = proximaPeca;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: ligar um atomo com outro da esquerda para direita
Parâmetro Entrada: a listas duplamente ligada, e um atomos
Parametro de saída: a lista actualizada com os atomos linkados
-------------------------------------------------------------------------------------------------------*/
void ligarLinksEsquerda (TLista *lista, TAtomo *peca)
{
	for (TAtomo *percorrer = lista->primeiro; percorrer != NULL; percorrer = percorrer->dprox)
	{
    if (percorrer == peca) continue;
    if (peca->peca.y == percorrer->peca.x)
		{
			if (percorrer != lista->primeiro && peca->peca.x == percorrer->eprox->peca.y)
			{	trocarAntes (lista, percorrer, peca); break; }
			else if (percorrer == lista->primeiro)
			{	trocarAntes (lista, percorrer, peca); break; }
		}
		if (peca->peca.x == percorrer->peca.x)
		{
			if (percorrer != lista->primeiro && peca->peca.y == percorrer->eprox->peca.y)
			{	trocarDados (&peca->peca); trocarAntes (lista, percorrer, peca); break; }
			else if (percorrer == lista->primeiro)
			{	trocarDados (&peca->peca); trocarAntes (lista, percorrer, peca); break; }
		}
		if (peca->peca.x == percorrer->peca.y)
		{
			if (peca->peca.y == percorrer->dprox->peca.x)
			{	trocarDepois (lista, percorrer, peca); break; }
		}
		if (peca->peca.y == percorrer->peca.y)
		{
			if (peca->peca.x == percorrer->dprox->peca.x)
			{	trocarDados (&peca->peca); trocarDepois (lista, percorrer, peca); break; }
		}
	}
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: trocar as posicoes doas atomos antes
Parâmetro Entrada: a listas duplamente ligada, e dois atomos
Parametro de saída: a lista actualizada com os atomos linkados
-------------------------------------------------------------------------------------------------------*/
void trocarAntes (TLista *lista, TAtomo *proximaPeca, TAtomo *peca)
{
	peca->eprox->dprox = peca->dprox;
	if (peca->dprox == NULL) lista->ultimo = peca->eprox;
	else
		peca->dprox->eprox = peca->eprox;
	if (proximaPeca == lista->primeiro)
	{
		lista->primeiro = peca;
		peca->eprox = NULL;
	}
	else
		proximaPeca->eprox->dprox = peca;
	proximaPeca->eprox = peca;
	peca->dprox = proximaPeca;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: trocar as posicoes doas atomos depois
Parâmetro Entrada: a listas duplamente ligada, e dois atomos
Parametro de saída: a lista actualizada com os atomos linkados
-------------------------------------------------------------------------------------------------------*/
void trocarDepois (TLista *lista, TAtomo *peca, TAtomo *proximaPeca)
{
	proximaPeca->eprox->dprox = proximaPeca->dprox;
	if (proximaPeca->dprox == NULL) lista->ultimo = proximaPeca->eprox;
	else proximaPeca->dprox->eprox = proximaPeca->eprox;
	proximaPeca->dprox = peca->dprox;
	peca->dprox->eprox = proximaPeca;
	peca->dprox = proximaPeca;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verficar se as pecas do domino esta ordenadas
Parâmetro Entrada: a Lista duplamente ligada
Paramentro de retorno: TRUE or FALSE
-------------------------------------------------------------------------------------------------------*/
Boolean verificarDomino (TLista lista)
{
	for (TAtomo *percorrer = lista.primeiro; percorrer->dprox != NULL; percorrer = percorrer->dprox)
		if (percorrer->peca.y != percorrer->dprox->peca.x) return false;
	return true;
}

/*-------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
int numeroPecasDesordenado (TLista *lista)
{
  int contador = 0;
  for (TAtomo *percorrer = lista->primeiro; percorrer->dprox != NULL; percorrer = percorrer->dprox)
		if (percorrer->peca.y != percorrer->dprox->peca.x) contador++;
	return contador;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: liberar o espaco da jogada
Parâmetro Entrada: ponteiro jogada
Parametro de saída: espaco do ponteiro jogada liberado
-------------------------------------------------------------------------------------------------------*/
void liberar(TJogada *jogada)
{
  free(jogada);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Ordenar as pecas que estao ainda desordenadas
Parâmetro Entrada: A lista, o ponteiro jogada(vector de lista) e o indice que referencia a posicao no vector
Parametro de saída: A lista actualizada
-------------------------------------------------------------------------------------------------------*/
void numeroDesordenado(TLista *lista, TJogada *jogada, int i)
{
  int cont = 1, contadorDesord = numeroPecasDesordenado(lista);
  while (cont++ <= contadorDesord)
  {
    for (TAtomo *percorrer = lista->primeiro; percorrer->dprox != NULL; percorrer = percorrer->dprox)
    {
        if (percorrer->peca.y != percorrer->dprox->peca.x)
        {
          TAtomo *aux1 = percorrer->dprox, *aux2 = aux1->dprox;
          while(aux1 != NULL)
          {
              ligarLinksEsquerda (&jogada->jogada[i], aux1);
              aux1 = aux2;
              if (aux2 != NULL && aux2->dprox != NULL) aux2 = aux2->dprox;
              else
              {
                if (aux1 != NULL) ligarLinksEsquerda (&jogada->jogada[i], aux1);
                aux1 = NULL;
              }
          }
          break;
        }
      }
  }
}
