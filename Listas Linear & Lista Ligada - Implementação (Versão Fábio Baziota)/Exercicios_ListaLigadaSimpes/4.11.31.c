/*
  Objectivo: 4.11.31- desenvolva uma função iterativa que recebe como parâmetro de
  entrada uma lista ligada simples. Devolve como parâmetro de saída a
  mesma lista com os mesmos átomos na ordem inversa. Não pode trocar o
  conteudo dos átomos, troca apenas os ponteiros.
  Data: 28/08/2018
  Hora: 01:53
  Autor: @baziotaBeans A.K.A Insonia
*/


void trocarPonteiros(TLista *ligada)
{
  TAtomo *ant = NULL, perc = lista->primeiro, actual = lista->primeiro;
  //TAtomo *aux;
  while(perc != NULL)
  {
    TAtomo *aux = ant;
    ant = perc;
    perc = perc->prox;
    actual = perc;
    ant->prox = aux;
    actual->prox = ant;
  }
  TAtomo *aux = lista->primeiro;
  lista->primeiro = lista->ultimo;
  lista->ultimo = aux;
}
/*
void trocarPonteiros(TLista *lista, TAtomo *ant, TAtomo *perc, TAtomo *actual)
{
    if(perc == NULL)
    {
        TAtomo *aux = lista->primeiro;
        lista->primeiro = lista->ultimo;
        lista->ultimo = aux;
    }
    if(perc != NULL)
    {
        TAtomo *aux = ant;
        ant = perc;
        ant->prox = aux;
        actual->prox = ant;
        trocarPonteiros(lista, ant, perc->prox, actual);
        trocarPonteiros(lista, ant, perc, perc);
    }
}
*/
