/*
  Autor: BaziotaBeans
  Data: 31/08/2018
  Hora: 23:34
*/
#include "listaDuplamenteLigadaCircular.h"
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
}

int iniciarListaDuplamenteLigadaCircular(TLista *lista)
{
  lista->primeiro = NULL;
}


Boolean vaziaListaDuplamenteLigadaCircular(TLista *lista)
{
  return (lista->primeiro == NULL);
}

void imprimirAtomo(TInfo x)
{
  printf("%d", x.chave);
}

int imprimirListaDuplamenteLigada(TLista *lista)
{
  TAtomo *paux = lista->primeiro;
  if(!vaziaListaDuplamenteLigadaCircular(lista))
  {
    do
    {
      imprimirAtomo(paux->info);
      paux = paux->dprox;
    } while(paux != lista->primeiro);
    return OK;
  }
  return LIST_EMPTY;
}

TAtomo *BuscarAtomo ( TLista *lista, int chave )
{
  TAtomo *paux = lista->primeiro;
  do
  {
    if (paux->info.chave == chave) return paux;
    paux = paux->dprox;
  } while(paux != lista->primeiro);
  return NULL;
}


int inserirChaveListaDupla ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo)), *paux = BuscarAtomo(lista, x.chave);
  if (pnovo == NULL) return NO_SPACE;
  if (paux == NULL)
  {
    free(pnovo);
    return INVALID_INDEX;
  }
  if (paux = lista->primeiro)
  {
    pnovo->dprox = lista->primeiro;
    pnovo->eprox = lista->primeiro->eprox;
    lista->primeiro->eprox = pnovo;
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
/*
int inserirAtomoFim ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (vaziaListaDuplamenteLigadaCircular(lista))
  {

  }
}*/



int removerAtomoChave ( TInfo *x, int chave, TLista *lista )
{
  if (vaziaListaDuplamenteLigadaCircular(lista)) return LIST_EMPTY;
  TAtomo *premove = BuscarAtomo(lista, chave);
  if (premove->info.chave == chave)
  {
    *x = premove->info;
    if (premove == lista->primeiro) lista->primeiro = lista->primeiro->dprox;
    premove->eprox->dprox = premove->dprox;
    premove->dprox->eprox = premove->eprox;
    free(premove);
    return OK;
  }
  return INVALID_INDEX;
}
