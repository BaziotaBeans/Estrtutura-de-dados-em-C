/*
  Objectivo: 4.11.33- Desenvolva um função iterativa e uma função recursiva que recebe
  como parâmetro de entrada uma lista ligada simples ordenada e uma
  determinada chave. Verificar se essa chave encontra-se na lista.
  Data: 28/08/2018
  Hora: 11:04
  Autor: @baziotaBeans A.K.A
*/

Boolean verificarExiste(TLista *lista, int chave)
{
  TAtomo *ant = NULL, *perc = lista->primeiro;
  while((perc != NULL) && (perc->info.chave < chave))
  {
    ant = perc;
    perc = perc->prox;
  }
  if (perc->info.chave == chave) return TRUE;
  return FALSE;
}

Boolean verificarExiste(TLista *lista, int chave)
{
  TAtomo *perc = lista->primeiro;
  while((perc != NULL) && (perc->info.chave < chave)) perc = perc->prox;
  if (perc->info.chave == chave) return TRUE;
  return FALSE;
}

//Recursao Nao Caudal
Boolean verificarExisteRecursivoNoC(TLista *lista, int chave, TAtomo *perc)
{
  if (perc->info.chave == chave) return TRUE;
  if((perc != NULL) && (perc->info.chave < chave))
    return verificarExisteRecursivo(lista, chave, perc->prox);
  return FALSE;
}

//Recursao Caudal
Boolean verificarExisteRecursivoC(TLista *lista, int chave, TAtomo *perc)
{
  if (perc->info.chave == chave) return TRUE;
  if ((perc->info.chave > chave) || (perc == NULL)) return FALSE;
  if((perc != NULL) && (perc->info.chave < chave))
    return verificarExisteRecursivo(lista, chave, perc->prox);
}
