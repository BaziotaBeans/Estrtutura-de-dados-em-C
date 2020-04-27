/*
  Autor: BaziotaBeans
  Data: 30/08/2018
  Hora: 16:08
*/
#include "listaLigadaCircular.h"
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
} TAtomo;


typedef struct
{
  TAtomo *primeiro;
}TLista;

typedef enum { FALSE = 0, TRUE= 1 } Boolean;


/*--------------------------------------------------------------------------------------------------------
Objectivo: Inicializar uma estrutura de dados do tipo lista ligada Circular
Parâmetro Entrada: Lista ligada circular
Parâmetro de Saída: Lista ligada circular com o ponteiro de controlo actualizado.
------------------------------------------------------------------------------------------------------- */
void iniciarListaLigadaCircular(TLista *lista)
{
  lista->primeiro = NULL;
}

/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a lista está vazia
Parâmetro Entrada: Lista ligada circular
Retorno da Função: Verdadeiro ou Falso
-------------------------------------------------------------------------------------------------------*/
Boolean vaziaListaLigadaCircular(TLista *lista)
{
  return (lista->primeiro == NULL);
}

int imprimirListaLigadaCircular (TLista *lista)
{
  TAtomo *paux = lista->primeiro;
  if(!(vaziaListaLigadaCircular(lista)))
  {
    do
    {
      printf("%d",paux->info);
      paux = paux->prox;
    } while(paux != lista->primeiro);
    return OK;
  }
  return LIST_EMPTY;
}

TAtomo *BuscarAtomo ( TLista *lista, int chave )
{
  TAtomo *paux = lista->primeiro;
  if (!vaziaListaLigadaCircular(lista))
  {
    do
    {
      if(paux->info.chave == chave) return paux;
      paux = paux->prox;
    } while(paux != lista->primeiro);
    return NOT_FOUND;
  }
  return LIST_EMPTY;
}

int inserirAtomoFim ( TInfo x, TLista *lista )
{
  TAtomo *perc = lista->primeiro, *ant = NULL, *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if(pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (!vaziaListaLigadaCircular(lista))
  {
    do
    {
      ant = perc;
      perc = perc->prox;
    } while(perc != lista->primeiro);
    pnovo->prox = lista->primeiro;
    ant->prox = pnovo;
  }
  else
  {
    lista->primeiro = pnovo;
    pnovo->primeiro->prox = pnovo;
  }
  return OK;
}

int inserirAtomoDireita ( TInfo x, TLista *lista )
{
  TAtomo *pnovo = ( TAtomo *) malloc(sizeof(TAtomo));
  if ( pnovo == NULL ) return NO_SPACE;
  pnovo->info = x;
  if (vaziaListaLigadaCircular(lista)) lista->primeiro = pnovo;
  else pnovo->prox = lista->primeiro->prox;
  lista->primeiro->prox = pnovo;
  return OK;
}


int inserirAtomoNoMeio ( TInfo x, TLista *lista, int chave )
{
  TAtomo *perc = lista->primeiro, *ant = NULL, *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (!vaziaListaLigadaCircular(lista))
  {
    do
    {
      ant = perc;
      perc = perc->prox;
    } while((perc != lista->primeiro) && (perc->info.chave < chave));
    pnovo->prox = ant->prox;
    ant->prox = pnovo;
  }
  else
  {
    lista->primeiro = pnovo;
    pnovo->primeiro->prox = pnovo;
  }
  return OK;
}

int removerAtomoChave (TLista *lista, TInfo *x)
{
  if (vaziaListaLigadaCircular(&lista)) return LIST_EMPTY;
  TAtomo *pdel = lista->primeiro->prox;
  *x = pdel->info;
  if (pdel == lista->primeiro) inicializarListaCircular(lista);
  lista->primeiro->prox = pdel->prox;
  free(pdel);
  return OK;
}
