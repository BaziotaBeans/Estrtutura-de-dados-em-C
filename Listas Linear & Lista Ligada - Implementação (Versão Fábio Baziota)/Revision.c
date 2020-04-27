void imprimirLista(TLista *lista)
{
    for(TAtomo *aux = lista->primeiro; *aux != NULL; aux = aux->prox)
        printf("\n%d\n", aux->info.chave);
}

void imprimirListaRecursiva(TAtomo *paux)
{
    if(paux != NULL)
    {
        printf("\n%d\n", aux->info->chave);
        imprimirListaRecursiva(paux->prox);
    }
}


TAtomo *buscarAtomo(TLista *lista, int chave)
{
    for(TAtomo *paux = lista->primeira; paux != NULL; paux = paux->prox)
        if(paux->info.chave == chave) return paux;
    return NULL;
}


int inserirAtomoFim(TLista *lista, TInfo x)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if (pnovo == NULL) return NO_SPACE;
    pnovo->info = x;
    pnovo->prox = NULL;

    if (vaziaListaLigada(lista)) lista->primeiro = pnovo;
    else lista->ultimo->prox = pnovo;
    lista->ultimo = pnovo;
    return OK;
}


int inserirAtomoInicio(TLista *lista, TInfo x)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if (pnovo == NULL) return NO_SPACE;
    pnovo->info = x;
    pnovo->prox = NULL;

    pnovo->prox = lista->primeiro;
    pnovo = lista->primeiro;
    return OK;
}


int inserirOrdenando(TLista *lista, int x)
{
    TAtomo *ant = NULL, *perc = lista
}



int removerAtomoChave(TLista *lista, TInfo *x, int chave)
{
    if (vaziaListaLigada(lista)) return LISTA_IS_EMPTY;
    TAtomo *ant = NULL, *perc = lista->primeiro;

    while((perc != NULL) && (perc->info.chave != chave))
    {
        ant = perc;
        perc = perc->prox;
    }

    if (perc == list->ultimo) lista->ultimo = ant;
    if (perc == list->primeiro) lista->primeiro = lista->primeiro->prox;
    else ant->prox = perc->prox;
    free(perc);
    return OK;
}


void liberarLista_recursivo(TLista *lista)
{
    if (!vaziaListaLigada(lista))
    {
        liberarLista_recursivo(lista->prox);
        free(lista);
    }
}



Boolean isEqual(TLista *l1, TLista *l2)
{
    TLista *p1, *p2;
    for(p1 = l1, p2 = l2; (p1 != NULL) && (p2 != NULL); p1 = p1->prox, p2 = p2->prox)
        if (p1->info != p2->info) return FALSE;
    return (p1 == p2);
    return TRUE;
}


Boolean isEqualRecursive(TLista *l1, TLista *l2)
{
    if ((l1 == NULL) && (l2 == NULL)) return TRUE;
    else if ((l1 == NULL) || (l2 == NULL)) return FALSE;
    else return ( (l1->info == l2->info) && (isEqualRecursive(l1->prox, l2->prox)) );
}



void inicializarListaCircular(TLista *lista)
{
  lista->primeiro = NULL;
}

int inserirAtomoDireita(TLista *lista, TINfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (vaziaListaLigadaCircular(lista)) lista->primeiro = pnovo;
  else pnovo->prox = lista->primeiro->prox;
  lista->primeiro->prox = pnovo;
  return OK;
}
