/*
  Autor: BaziotaBeans
  Data: 30/08/2018
  Hora: 16:08
*/
#include "listaLigadaCircularComCabeca.h"
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
  struct Atomo *prox;
}TAtomo;

typedef struct
{
  TAtomo *cabeca;
}

int iniciarListaLigadaCircularCabeca(TLista *lista)
{
  TAtomo *paux = (TAtomo *) malloc(sizeof(TAtomo));
  if (paux == NULL) return NO_SPACE;
  lista->cabeca = paux;
  lista->cabeca->prox = paux;
  return OK;
}

Boolean vaziaListaLigadaCircularCabeca(TLista *lista)
{
  return (lista->cabeca->prox = lista->cabeca);
}

int imprimirListaLigadaCircularCabeca(TLista *lista)
{
  TAtomo *paux = lista->cabeca;
  if (!vaziaListaLigadaCircularCabeca(lista))
  {
    do
    {
      printf("%d", paux->info.chave);
      paux = paux->prox;
    } while(paux != lista->cabeca);
    return OK;
  }
  else return LIST_EMPTY;
}

TAtomo *BuscarAtomo ( TLista *lista, int chave )
{
  lista->cabeca->info.chave = chave;
  TAtomo *pbusca = lista->cabeca->prox;
  while(pbusca->info.chave != chave) pbusca = pbusca->prox;
  if (!(pbusca != lista->Cabeca)) return pbusca;
  return NULL;
}


TAtomo *BuscarAtomo (TLista *lista, int chave)
{
  lista->cabeca->info.chave = chave;
  TAtomo *pbusca = lista->cabeca->prox;
  if (!vaziaListaLigadaCircularCabeca(lista))
  {
    do
    {
      if (!(pbusca->info.chave == chave)) return pbusca;
      pbusca = pbusca->prox;
    } while(pbusca != lista->cabeca);
    return INVALID_INDEX;
  }
  return LIST_EMPTY;
}

int inserirAtomoFim ( TInfo x, TLista *lista )
{
  TAtomo *ant = NULL, *perc = lista->cabeca;
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if(pnovo == NULL) return NO_SPACE;
  if (!vaziaListaLigadaCircularCabeca(lista))
  {
    do
    {
        ant = perc;
        perc = perc->prox;
    } while(perc != lista->cabeca);
    pnovo->prox = ant->prox;
    ant->prox = pnovo;
  }
  else
  {
    lista->cabeca->prox = pnovo;
    pnovo->prox = lista->cabeca;
  }
  return OK;
}



int inserirAtomoDireita ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (vaziaListaLigadaCircularCabeca(lista))
  {
    lista->cabeca->prox = pnovo;
    pnovo->prox = lista->cabeca;
  }
  else
  {
    pnovo->prox = lista->cabeca-prox;
    lista->cabeca->prox = pnovo;
  }
  return OK;
}


int inserirAtomoNoMeio ( TInfo x, TLista *lista, int chave )
{
  TAtomo *ant = NULL, *perc = lista->cabeca;
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  if (!vaziaListaLigadaCircularCabeca(lista))
  {
    do
    {
      ant = perc;
      perc = perc->prox;
    } while((perc != lista->cabeca) && (perc->info.chave < chave));
    pnovo->prox = ant->prox;
  }
  else
  {
    pnovo->prox = lista->cabeca-prox;
    lista->cabeca->prox = pnovo;
  }
  return OK;
}

int removerAtomoChave (TLista *lista, TInfo *x, int chave)
{
  TAtomo *ant = NULL, *perc = lista->cabeca;
  if (!vaziaListaLigadaCircularCabeca(lista))
  {
    do
    {
      ant = perc;
      perc = perc->prox;
    } while((perc != lista->cabeca) && (perc->info.chave != chave));
    ant->prox = perc->prox;
    perc->ant;
    free(perc);
    return OK;
  }
  return LIST_EMPTY;
}
