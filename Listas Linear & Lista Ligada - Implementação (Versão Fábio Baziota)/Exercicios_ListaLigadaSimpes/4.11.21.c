/*
  Objectivo: 4.11.21- Desenvolva uma função iterativa que recebe como parâmetro de
  entrada uma lista ligada simples e uma determinada informação. Inserir um
  novo átomo com essa informação no início da lista.
  Data: 28/08/2018
  Hora: 01:09
  Autor: @baziotaBeans A.K.A Insonia
*/
int inserirInicioListaLigada(TLista *lista, TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_ESPACE;
  pnovo->info = x;
  pnovo->prox = NULL;

  pnovo->prox = lista->primeiro;
  lista = pnovo;

  return OK;
}
