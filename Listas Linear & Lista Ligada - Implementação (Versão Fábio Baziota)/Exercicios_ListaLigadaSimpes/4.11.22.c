/*
  Objectivo: 4.11.22- Desenvolva uma função iterativa e uma função recursiva que
  recebe como parâmetro de entrada uma lista ligada simples, uma
  determinada chave e uma determinada informação. Inserir um novo átomo
  com essa informação antes do átomo que contém essa chave.
  Data: 28/08/2018
  Hora: 01:14
  Autor: @baziotaBeans A.K.A Insonia
*/
int inserirAntesListaLigada(TLista *lista, TInfo x, int chave)
{
  TAtomo *ant = NULL, *perc = lista->primeiro;
  while((perc != NULL) && (perc->info.chave < chave))
  {
    ant = perc;
    perc = ant->prox;
  }

  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  pnovo->info = x;
  pnovo->prox = NULL;
  if(ant == NULL)
  {
    pnovo->prox = lista->primeiro;
    lista = pnovo;
  }
  else
  {
    pnovo->prox = ant->prox;
    ant->prox = pnovo;
  }
  return OK;
}

void inserirAntesListaLigadaRecursivo(TLista *lista, TInfo x, int chave, TAtomo *ant, TAtomo *perc)
{
  if((perc == NULL) || (perc->info.chave == chave))
  {
    if (ant == NULL)
    {
      pnovo->prox = lista->primeiro;
      lista = pnovo;
    }
    else
    {
      pnovo->prox = ant->prox;
      ant->prox = pnovo;
    }
  }
  if((perc != NULL) && (perc->info.chave < chave))
  {
    ant = perc;
    inserirAntesListaLigada(lista,x, chave, ant, perc->prox);
  }
}
