/*
  Objectivo: 4.11.35- Desenvolva uma função iterativa e uma função recursiva que
  recebe como parâmetro de entrada duas listas ligadas simples. Verificar se
  elas são iguais.
  Data: 28/08/2018
  Hora: 11:33
  Autor: @baziotaBeans A.K.A
*/

Boolean isEqual(TLista *l1, TLista *l2)
{
  TAtomo *perc1 = l1->primeiro, *perc2 = l2->primeiro;
  while((perc1 != NULL) && (perc2 != NULL))
  {
    if(perc1->info != perc2->info) return FALSE;
    perc1 = perc1->prox;
    perc2 = perc2->prox;
  }
  return TRUE;
}

Boolean isEqualRecursive(TLista *l1, TLista *l2)
{
  if ((l1 == NULL) && (l2 == NULL)) return TRUE;
  if ((l1 == NULL) || (l2 == NULL)) return FALSE;
  return ((l1 == l2) && isEqualRecursive(l1->prox,l2->prox));
}

Boolean isEqualRecursive(TLista *l1, TLista *l2, TAtomo *perc1, TAtomo *perc2)
{
  if ((perc1 == NULL) && (perc2 == NULL)) return TRUE;
  if ((perc1 == NULL) || (perc2 == NULL)) return FALSE;
  return ((perc1 == perc2) && isEqualRecursive(perc1->prox, perc2->prox));
}
