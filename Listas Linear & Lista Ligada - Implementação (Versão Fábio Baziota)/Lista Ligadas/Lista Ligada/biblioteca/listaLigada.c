/*
  Autor: BaziotaBeans
  Data: 09/08/2018
  Hora: 03:19
*/

/* -------------------------------------------------------------------------------------------------------
Especificação de operacoes : listaLigada.c
Objectivo: Disponibilizar as operações comuns sobre uma lista Ligadas
--------------------------------------------------------------------------------------------------------*/

#include "listaLigada.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct
{
  int chave;
  int valor;
}TInfo;

typedef struct Atomo
{
  TInfo info;
  struct Atomo *prox;
}TAtomo;

typedef struct
{
  TAtomo *primeiro;
  TAtomo *ultimo;
}TLista;
*/


/*--------------------------------------------------------------------------------------------------------
Objectivo: Inicializar uma estrutura de dados do tipo lista ligada
Parâmetro Entrada: Lista ligada
Parâmetro de Saída: Lista ligada com os ponteiros de controlo actualizados.
------------------------------------------------------------------------------------------------------- */
void iniciarListaLigada ( TLista *lista )
{
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a lista está vazia
Parâmetro Entrada: Lista ligada
Retorno da Função: Verdadeiro ou Falso
-------------------------------------------------------------------------------------------------------*/
Boolean vaziaListaLigada(TLista *lista)
{
  return (lista->primeiro == NULL);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Imprimir o conteudo de todos os átomo da lista
Parâmetro Entrada: A lista ligada
Parâmetro de Saída: nada
--------------------------------------------------------------------------------------------------------*/
void imprimirListaLigada(TLista *lista)
{
  for(TAtomo *paux = lista->primeiro; paux != NULL; paux = paux->prox) printf("%d", paux->info.chave);//imprimirAtomo(paux->info);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Imprimir o conteudo de cada átomo
Parâmetro Entrada: A lista ligada
Parâmetro de Saída: Nada
--------------------------------------------------------------------------------------------------------*/
/*void imprimirListaLigadaRecursiva (TAtomo *paux )
{
  if ( paux != NULL )
  {
    imprimirAtomo (paux->info );
    imprimirListaLigadaRecursiva ( paux->prox );
  }
}*/
/*--------------------------------------------------------------------------------------------------------
Objectivo: Encontrar um átomo dado uma chave
Parâmetro Entrada: lista ligada, valor da chave
Retorno da Função: Endereço do átomo ou um endereço inválido (NULL)
--------------------------------------------------------------------------------------------------------*/
TAtomo *BuscarAtomo ( TLista *lista, int chave )
{
  for(TAtomo *paux = lista->primeiro; paux != NULL; paux = paux->prox)
    if(paux->info.chave == chave) return paux;
  return NULL;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um átomo como essa informação no fim de uma lista ligada
Parâmetro Entrada: A informação a inserir e a lista ligada
Parâmetro de Saída: Lista actualizada
Retorno da Função: Código de erro.
--------------------------------------------------------------------------------------------------------*/
int inserirAtomoFim ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = ( TAtomo *) malloc(sizeof(TAtomo));
  if ( pnovo == NULL ) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = NULL;
  if ( vaziaListaLigada (lista) ) lista->primeiro = pnovo;
  else lista->ultimo->prox = pnovo;
  lista->ultimo = pnovo;
  return 0;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um átomo com essa informação de forma ordenada
Parâmetro Entrada: A informação a inserir, chave e a lista ligada
Parâmetro de Saída: Lista actualizada
Retorno da Função: Código de erro.
--------------------------------------------------------------------------------------------------------*/
int inserirOrdenando (TLista *lista, Tinfo x, int chave)
{
    TAtomo *pant = NULL, *perc = lista->primeiro, *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if (pnovo == NULL) return NO_SPACE;
    while((perc != NULL) && (perc->info.chave < chave))
    {
        pant = perc;
        perc = perc->prox;
    }
    if (pant == NULL)
    {
        perc->prox = lista;
        lista = perc;
    }
    else
    {
        perc->prox = pant->prox;
        pant->prox = perc;
    }
    return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um átomo com uma informação antes da chave dada
Parâmetro Entrada: A informação a inserir, chave e a lista ligada
Parâmetro de Saída: Lista actualizada
Retorno da Função: Código de erro.
--------------------------------------------------------------------------------------------------------*/
int inserirAntesDaChave(TLista *lista, Tinfo x, int chave)
{
    if (vaziaListaLigada(&lista)) return LIST_EMPTY;
    TAtomo *pant = NULL, *perc = lista->primeiro;
    while((perc != NULL) && (perc->info.chave != chave))
    {
        pant = perc;
        perc = perc->prox;
    }
    if (perc == NULL) return NOT_FOUND;
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if (pnovo == NULL) return NO_SPACE;
    pnovo->info = x;
    pnovo->prox = NULL;
    if (pant == NULL)
    {
        pnovo->prox = lista->primeiro;
        lista->primeiro = pnovo;
    }
    else
    {
        pnovo->prox = pant->prox;
        pant->prox = pnovo;
    }
    return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um átomo com uma informação depois da chave dada
Parâmetro Entrada: A informação a inserir, chave e a lista ligada
Parâmetro de Saída: Lista actualizada
Retorno da Função: Código de erro.
--------------------------------------------------------------------------------------------------------*/
int inserirDepoisDaChave(TLista *lista, Tinfo x, int chave)
{
    if (vaziaListaLigada(&lista)) return LIST_EMPTY;
    TAtomo *pant = NULL, *perc = lista->primeiro;
    while((perc != NULL) && (perc->info.chave != chave))
    {
        pant = perc;
        perc = perc->prox;
    }
    if (perc == NULL) return NOT_FOUND;
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    pnovo->info = x;
    pnovo->prox = NULL;
    if (pant == NULL)
    {
       lista->primeiro->prox = pnovo;
       lista->ultimo = pnovo;
    }
    else if (perc == lista->ultimo)
    {
        lista->ultimo->prox = pnovo;
        lista->ultimo = pnovo;
    }
    else
    {
        pnovo->prox = perc->prox;
        perc->prox = pnovo;
    }
    return OK;
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um átomo com uma informação depois no inicio da lista
Parâmetro Entrada: A informação a inserir, chave e a lista ligada
Parâmetro de Saída: Lista actualizada
Retorno da Função: Código de erro.
--------------------------------------------------------------------------------------------------------*/
int inserirAtomoInicio ( TInfo x, TLista *lista )
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if (pnovo ==  NULL) return NO_SPACE;
    pnovo->info = x;
    pnovo->prox = NULL;
    if (vaziaListaLigada(&lista))
    {
        lista->primeiro = pnovo;
        lista->ultimo = pnovo;
    }
    else
    {
        pnovo->prox = lista->primeiro;
        lista->primeiro = pnovo;
    }
    return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover um átomo dado uma chave
Parâmetro Entrada: Lista Ligada, valor da chave
Parâmetro de Saída: Lista actualizada, informação removida
Retorno da Função: Código de erro
--------------------------------------------------------------------------------------------------------*/
int removerAtomoChave (TLista *lista, int *x, int chave)
{
  if ( vaziaListaLigada (lista) ) return LIST_EMPTY;
  TAtomo *pant = NULL, *pdel = lista->primeiro; // Procurar a chave
  while ( (pdel != NULL) && (pdel->info.chave != chave))
  {
      pant = pdel;
      pdel = pdel->prox;
  }
  if(pdel == NULL) return NOT_FOUND; // Se a chave não foi encontrada
  *x = pdel->info.chave;//lista->info.chave;
  if ( pdel == lista->ultimo ) lista->ultimo = pant; // Se chave está no ultimo átomo
  if ( pdel == lista->primeiro ) lista->primeiro = lista->primeiro->prox; // Se chave está no primeiro átomo
  else pant->prox = pdel->prox;
  free(pdel);
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Imprimir um Atomo
Parâmetro Entrada: O respectivo Atomo
Parâmetro de Saída:
Retorno da Função: Nada
--------------------------------------------------------------------------------------------------------*/
/*void imprimirAtomo(TAtomo *paux)
{
  printf("%d", paux->info);
}*/


int ordenarLista(TListaLigada *lista)
{
	if (vazia(lista)) return LIST_EMPTY;
	for (TAtomo *percorrer = lista->primeiro, anterior NULL; percorrer != NULL; anterior = percorrer, percorrer = percorrer->prox)
	{
		for(TAtomo *aux = percorrer->prox; aux != NULL; aux = aux->prox)
			if (percorrer->info.chave > aux->info.chave)
			{
				anterior->prox = aux;
				percorrer->prox = aux->prox;
				aux->prox = percorrer;
				if (percorrer == lista->primeiro) lista->primeiro = aux;
			}
		if(percorrer->proximo == NULL) lista->ultimo = percorrer;
	}
	return OK;	
}


int remover(TLista *lista, TInfo *x, int chave)
{
	if (vazia(lista)) return LIST_EMPTY;
	TAtomo paux = lista->primeiro, pant = NULL, pdel = NULL;
	
	if (paux->info.chave == chave && paux->prox = lista->primeiro) free(paux);
	else 
	{
		pant = paux;
		while (pant->prox != paux) pant = pant->prox;
		while (paux->prox != lista->primeiro)
		{
			if (paux->info.chave == chave)
			{
				pdel = paux;
				paux = paux->prox;
				pant->prox = paux;
				free(pdel);
			}
			else
			{
				pant = paux;
				paux = paux->prox;
			}
		}
	}
	return OK;
}








