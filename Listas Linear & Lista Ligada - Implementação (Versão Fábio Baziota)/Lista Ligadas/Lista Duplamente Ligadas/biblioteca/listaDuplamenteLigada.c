/*
  Autor: BaziotaBeans
  Data: 31/08/2018
  Hora: 17:38
*/
#include "listaDuplamenteLigada.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int chave;
  int valor;
}TInfo;

typedef struct Atomo
{
  TInfo info;
  struct Atomo *dprox;
  struct Atomo *eprox;
}TAtomo;

typedef struct
{
  TAtomo *primeiro;
  TAtomo *ultimo;
}

int iniciarListaDuplamenteLigada(TLista *lista)
{
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}


Boolean vaziaListaDuplamenteLigada(TLista *lista)
{
  return (lista->primeiro == NULL);
}

int imprimirListaDuplamenteLigada(TLista *lista)
{
  if (!vaziaListaDuplamenteLigada(lista))
  {
    for(TAtomo *paux = lista->primeiro; paux != NULL; paux = paux->dprox)
      printf("%d",paux->info.chave);
    return OK;
  }
  return LIST_EMPTY;
}

// Recursao Caudal
int imprimirListaDuplamenteLigadaRecursivo(TLista *lista, TAtomo *paux)
{
  if (vaziaListaDuplamenteLigada(lista)) return LIST_EMPTY;
  if (paux == NULL) return OK;
  if (paux != NULL)
  {
    printf("%d",paux->info.chave);
    return imprimirListaDuplamenteLigadaRecursivo(lista, paux->dprox);
  }
}

TAtomo *BuscarAtomo ( TLista *lista, int chave )
{
    for (TAtomo *paux = lista->primeiro; paux != NULL; paux = paux->dprox)
      if(paux->info.chave == chave) return paux;
    return NULL;
}

TAtomo *BuscarAtomoRecursivo ( TLista *lista, int chave, TAtomo *paux)
{
  if (paux == NULL) return NULL;
  if (paux != NULL)
  {
    if(paux->info.chave == paux) return paux;
    return BuscarAtomoRecursivo(lista, chave, paux->dprox);
  }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um àtomo com essa informação dado uma chave da lista
Parâmetro Entrada: A informação a inserir, chave de busca e lista duplamente
Parâmetro de Saída: Lista actualizada
Retorno da Função: Código de erro
--------------------------------------------------------------------------------------------------------*/
int inserirChaveListaDupla ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = ( TAtomo *) malloc ( sizeof(TAtomo) );
  if ( pnovo == NULL ) return NO_SPACE;
  pnovo->info = x;
  TAtomo *paux = BuscarAtomo(lista, x.chave);
  if (paux == NULL)
  {
    free(pnovo);
    return INVALID_INDEX;
  }
  if (paux == lista->primeiro)
  {
    pnovo->dprox = lista->primeiro;
    lista->primeiro->eprox = pnovo;
    pnovo->eprox = NULL;
    lista->primeiro = pnovo;
  }
  else
  {
    pnovo->dprox = paux;
    pnovo->eprox = paux->eprox;
    paux->eprox->dprox = pnovo;
    paux->eprox = pnovo;
  }
  return OK;
}

int inserirAtomoFim ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (vaziaListaDuplamenteLigada(lista))
  {
    lista->primeiro = pnovo;
    lista->primeiro->dprox = NULL;
    lista->primeiro->eprox = NULL;
    lista->ultimo = lista->primeiro;
  }
  else
  {
    pnovo->eprox = lista->ultimo;
    lista->ultimo->dprox = pnovo;
    pnovo->dprox = NULL;
  }
  return OK;
}

int inserirAtomoDireita ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (vaziaListaDuplamenteLigada(lista))
  {
    lista->primeiro = pnovo;
    lista->primeiro->dprox = NULL;
    lista->primeiro->eprox = NULL;
    lista->ultimo = lista->primeiro;
  }
  else
  {
    pnovo->dprox = lista->primeiro;
    lista->primeiro->eprox = pnovo;
    lista->primeiro = pnovo;
    lista->primeiro->eprox = NULL;
  }
  return OK;
}


int inserirAtomoOrdenado ( TInfo x, TLista *lista, int chave )
{
  TAtomo *ant = NULL, *perc = lista->primeiro, *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  while ((perc != NULL) && (perc->info.chave < x))
  {
    ant = perc;
    perc = perc->prox;
  }
  if (ant == NULL)
  {
    pnovo->prox = lista->primeiro;
    lista->primeiro = pnovo;
    lista->primeiro->dprox = NULL;
    lista->primeiro->eprox = NULL;
    lista->ultimo = pnovo;
  }
  else
  {
    pnovo->prox = ant->prox;
    pnovo->eprox = ant;
    ant->dprox->eprox = pnovo;
    ant->dprox = pnovo;
  }
  return OK;
}

int removerAtomoChave (TLista *lista, TInfo *x, int chave)
{
  if (vaziaListaDuplamenteLigada(lista)) return LIST_EMPTY;
  TAtomo *premove = BuscarAtomo(lista, chave);
  if (premove == NULL) return INVALID_INDEX;
  x* = premove->info;
  if (premove == lista->primeiro)
  {
    lista->primeiro = premove->dprox;
    lista->primeiro->eprox = NULL;
  }
  else if (premove == lista->ultimo)
  {
    lista->ultimo = pnovo->eprox;
    lista->ultimo->dprox = NULL;
  }
  else
  {
    premove->eprox->dprox = premove->dprox;
    premove->dprox->eprox = premove->eprox;
  }
  free(pdel);
  return OK;
}
