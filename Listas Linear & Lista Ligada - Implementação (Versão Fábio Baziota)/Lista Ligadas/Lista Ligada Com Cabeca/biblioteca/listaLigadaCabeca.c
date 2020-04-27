#include "listaLigada.h"
#include <stdio.h>


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
  TAtomo *ultimo;
}TLista;


int iniciarListaCabeca(TLista *lista)
{
  TAtomo paux = (TAtomo *)malloc(sizeof(TAtomo));
  if(paux == NULL) return NO_SPACE;
  lista->cabeca = paux;
  lista->ultimo = paux;
  lista->cabeca->prox = NULL;
  return 0K;
}

Boolean vaziaListaLigadaCabeca(TLista *lista)
{
  return (lista->cabeca->prox == NULL);
}


TAtomo* BuscarAtomo(TLista *lista, int chave)
{
  for (TAtomo *paux = lista->cabeca->prox; paux != NULL; paux = paux->prox)
    if(paux->info.chave == chave) return paux;
  return NULL;
}

int inserirDireira(TLista *lista, TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = NULL;

  if (vaziaListaLigadaCabeca(lista))
  {
    lista->cabeca->prox = pnovo;
    lista->ultimo = pnovo;
  }
  else
  {
    pnovo->prox = lista->cabeca->prox;
    lista->cabeca->prox = pnovo;
  }
  return OK;
}

int inserirFim(TLista *lista, Tinfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = NULL;
  if (vaziaListaLigadaCabeca(lista)) lista->cabeca->prox = pnovo;
  else lista->ultimo->prox = pnovo;
  lista->ultimo = pnovo;
  return OK;
}

int inserirOrdenandoMeio(TLista *lista, TInfo x, int chave)
{
  TAtomo *ant = NULL, *perc = lista->cabeca->prox;
  while((perc != NULL) && (perc->info.chave < chave))
  {
    ant = perc;
    perc = perc->prox;
  }
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = NULL;
  if (ant == NULL)
  {
    lista->cabeca->prox = pnovo;
    lista->ultimo = pnovo;
  }
  else
  {
    pnovo->prox = ant->prox;
    ant->prox = pnovo;
  }
  return OK;
}

int remocaoListaCabeca(TLista *lista, TInfo *x, int chave)
{
  if(vaziaListaLigadaCabeca(lista)) return LISTA_IS_EMPTY;
  TAtomo *perc = lista->cabeca, *ant  = NULL;
  while((perc != NULL) && (perc->info.chave != chave))
  {
    ant = perc;
    perc = perc->prox;
  }
  if ((perc == NULL)) return INVALID_INDEX;
  *x = perc->info;
  if (perc = lista->ultimo) lista->ultimo = ant;
  else ant->prox = perc->prox;
  free(perc);
  return OK;
}
