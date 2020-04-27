/*
  Objectivo: Desenvolva uma função iterativa que recebe uma lista ligada
  simples e o endereço de um ponteiro. Remover o átomo que antecede esse
  ponteiro.
  Data: 28/08/2018
  Hora: 01:35
  Autor: @baziotaBeans A.K.A Insonia
*/
int removerAntecede(TLista *lista, int chave, TInfo *x)
{
  TAtomo *ant = NULL, *perc = lista->primeiro;
  while((perc != NULL) && (perc->info.chave != chave))
  {
    ant = perc;
    perc = perc->prox;
  }
  if (perc == NULL) return NOT_FOUND;
  *x = lista->info;
  if (ant == NULL) return INVALID_ACESS;
  else
  {
    ant = perc;
    ant->prox = perc->prox;
  }
  free(perc);
  return OK;
}
