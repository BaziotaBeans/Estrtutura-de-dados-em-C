/*
  Objectivo: 4.11.32*- Desenvolva uma função iterativa que recebe como parâmetro de
  entrada uma lista ligada simples. Devolva como parâmetro de saída essa
  lista ordenada em ordem crescente de chave. ( Como no exercício anterior
  pode trocar o conteúdo dos átomos).
  Data: 28/08/2018
  Hora: 09:58
  Autor: @baziotaBeans A.K.A
*/

void ordenarCrescente(TLista *lista)
{
  TAtomo *ant = NULL, *perc = lista->primeiro, *actual = lista->primeiro;

  while(perc != NULL)
  {
    ant = perc;
    perc = perc->prox;
    actual = lista->primeiro;
    while(actual != NULL)
    {
      if(ant->info.chave > actual->info.chave)
      {
        TAtomo *aux = ant;
        ant = actual;
        actual = aux;
        actual->prox = ant->prox;
        ant->prox = actual;
      }
      ant = actual;
      actual = actual->prox;
    }
  }
}
