/*
  Objectivo: 4.11.36- Desenvolva uma função recursiva que recebe como parâmetro de
  entrada uma lista ligada simples e uma determinada chave. Remover o
  átomo que possui essa chave.
  Data: 28/08/2018
  Hora: 11:49
  Autor: @baziotaBeans A.K.A
*/

int removerAtomo(TLista *lista, Tinfo *x, int chave)
{
  if(vaziaListaLigada(lista)) return LIST_IS_EMPTY;
  TAtomo *ant = NULL, *perc = lista->primeiro;
  while((perc != NULL) && (perc->info.chave != x))
  {
    ant = perc;
    perc = perc->prox;
  }
  if (perc == NULL) return NOT_FOUND;
  *x = perc->info;

  if (perc == lista->ultimo) lista->ultimo = ant;
  if (perc == lista->primeiro) lista->primeiro = lista->primeiro->prox;
  else ant->prox = perc->prox;
  free(perc);
  return OK;
}
// Recursao Caudal
int removerAtomoRecursivo(TLista *lista, Tinfo *x, int chave, TAtomo *ant, TAtomo *perc)
{
  if(vaziaListaLigada(lista)) return LIST_IS_EMPTY;
  if(perc == NULL) return NOT_FOUND;
  if(perc->info.chave == x)
  {
    if (perc == lista->ultimo) lista->ultimo = ant;
    if (perc == lista->primeiro) lista->primeiro = lista->primeiro->prox;
    else ant->prox = perc->prox;
    free(perc);
    return OK;
  }
  if((perc != NULL) && (perc->info.chave != x))
  {
    ant = perc;
    return removerAtomoRecursivo(lista, x, chave, ant, perc->prox);
  }
}
