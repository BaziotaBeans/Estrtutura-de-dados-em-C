typedef struct
{
  int chave;
  int valor;
}TItem;

typedef struct
{
  TItem pilha[MAX];
  int topo;
}TPilha;

int empilhar (TPilha *pilha, TItem x)
{
    if (isFULL(pilha)) return STACK_FULL;
    pilha->topo++;
    pilha->item[pilha->topo] = x;
    return OK;
}

int desempilhar (TPilha *pilha, TItem *x)
{
  if (isEMPTY(pilha)) return STACK_EMPTY;
  *x = pilha->item[pilha->topo];
  pilha->topo--;
  return OK;
}
/*-------------------------------------------PILHA DUPLA-------------------------------------------------*/
typedef struct
{
  TItem pilha[MAX];
  int topo1;
  int topo2;
}TPDilha;


void inicializarPilhaDupla(TPDupla *pilha)
{
  pilha->topo1 = -1;
  pilha->topo2 = MAX;
}


int tamanhoPilhaDupla(TPDupla pilha, int np)
{
  if (np == 1) return (pilha->topo1 + 1);
  if (np == 2) return (MAX - pilha->topo2);
  return INVALID_NUMBER_OF_STACK;
}

Boolean pilhaDuplaVazia(TPilha *pilha)
{
  if (np == 1) return (pilha->topo1 == -1);
  return (pilha->topo2 == MAX);
}

Boolean pilhaDuplaCheia (TPDupla *pilha)
{
  return ((pilha->topo1) == (pilha->topo2 - 1));
}

int empilhar (TPDupla *pilha, TItem x, int np)
{
  if (pilhaDuplaCheia(pilha)) return DOUBLE_STACK_FULL;
  if (np == 1)
  {
    pilha->topo1++;
    pilha->item[pilha->topo1] = x;
  }
  else
  {
    pilha->topo2--;
    pilha->item[pilha->topo2] = x;
  }
  return OK;
}

int desempilhar(TPDupla *pilha, TItem *x, int np)
{
  if (pilhaDuplaVazia(pilha)) return STACK_EMPTY;
  if (np == 1)
  {
    *x = pilha->item[pilha->topo1];
    pilha->topo1--;
  }
  else
  {
    *x = pilha->item[pilha->topo2];
    pilha->topo2--;
  }
  return OK;
}
/*-------------------------------------------PILHA MULTIPLA-------------------------------------------------*/
typedef struct
{
    int valor;
    int chave;
}TItem;

typedef struct
{
    int base[NP + 1];
    int topo[NP + 1];
    int item[MAX];
}TPM;


void inicializarPilhaDupla(TPM *pilha, int k)
{
    for (int i=0; i <= NP; i++)
    {
        pilha->base[i] = (i*(MAX/NP)) - 1;
        pilha->topo[i] = pilha->base[i];
    }
}


Boolean isEMPTY (TPM *pilha, int k)
{
    return (pilha->topo[k] == pilha->base);
}

Boolean isFULL (TPM *pilha, int k)
{
    return (pilha->topo[k] == pilha->base[k] - 1);
}

int remover(TPM *pilha, int k, TItem *x)
{
    if (isEMPTY(pilha)) return MULTIPLE_STACK_EMPTY;
    *x = pilha->item[pilha->topo[k]];
    pilha->topo[k] = pilha->topo[k] - 1;
    return OK;
}


Boolean paraDireira (TPM *pilha, int k)
{
    if ( (k < 1) || (k > NP - 1) ) return FALSE;
    if (pilha->topo[k] < pilha->base[k + 1])
    {
        for ( int i = pilha->topo[k] + 1; i > pilha->base[k]; i-- ) pilha->topo[i] = pilha->topo[i - 1];
        pilha->topo[k]++;
        pilha->base[k]++;
        return OK;
    }
    return FALSE;
}


int inserir (TPM *pilha, int k, TItem x)
{
    if ( (isFULL(pilha)) && (k < NP - 1) )
        // desloca p/direita todas as pilhas de [k+1..NP-1] em ordem reversa
        for ( int j = NP - 1; j > K; j-- ) paraDireita(pilha, j);
    if ( (isFULL(pilha)) && (k > 0) )
        // desloca p/esquerda todas as pilhas de [1..k] (mas não a pilha 0)
        for ( int j = 1; j <= k; j++ ) paraEsquerda(p, j);
    if (isFULL(pilha)) return MULTIPLE_STACK_EMPTY;
    pilha->topo[k]++;
    pilha->pilha[p->topo[k]] = x;
    return OK;
}
/*-------------------------------------------PILHA Dinamica-------------------------------------------------*/
typedef struct
{
  int valor;
  int chave;
}TInfo;

typedef struct apontador
{
  TInfo info;
  struct apontador *prox;
}TAtomo;



typedef struct
{
  TAtomo *topo;
}TPilhaDinamica;




void inicializarPilhaMultipla (TPilhaDinamica *pilha)
{
  pilha->topo == NULL;
}


Boolean isEMTY (TPilhaDinamica *pilha)
{
  return (pilha->topo == NULL);
}

int empilhar (TPilhaDinamica *pilha, TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = pilha->topo;
  pilha->topo = pnovo;
  return OK;
}


int remover (TPilhaDinamica *pilha, TInfo *x)
{
  if ( isEMPTY(pilha) ) return STACK_EMPTY;
  TAtomo *pdel = pilha->topo;
  *X = pilha->topo->info;
  pilha->topo = pilha->topo->prox;
  free(pdel);
  return OK;
}



/*-------------------------------------------------------------------------------------*/
int trocarPercurso (TLista *lista)
{
  if (listaVazia(lista)) return LIST_EMPTY;
  TAtomo *pant = NULL, *perc = lista->primeiro, *pposterior = lista->primeiro;
  while (perc != NULL)
  {
    pposterior = pposterior->prox;
    perc->prox = pant;
    pant = perc;
    perc = pposterior;
  }
  TAtomo *paux = lista->primeiro;
  lista->primeiro = lista->ultimo;
  lista->ultimo = paux;
  return OK;
}
/*-------------------------------------------------------------------------------------*/
Boolean isEqual (TAtomo *p1, TAtomo *p2)
{
  if ( (p1 == NULL) && (lista2 == p2) ) return TRUE;
  if ( (p1 == NULL) || (p2 == NULL) ) return FALSE;
  return ((p1->info == p2->) && isEqual(p1->prox, p2->prox));
}
/*-------------------------------------------------------------------------------------*/
int inserirEsquerda (TListaCircular *lista, TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if  (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  if (vaziaListaLigadaCircular(lista))
  {
    lista->primeiro = pnovo;
    lista->primeiro->prox = lista->primeiro;
  }
  else
  {
    TAtomo *pbusca = lista->primeiro;
    while (pbusca->prox != lista->primeiro) pbusca = pbusca->prox;
    pnovo->prox = lista->primeiro;
    pbusca->prox = pnovo;
    lista->primeiro = pnovo;
  }
  return OK;
}
/*-------------------------------------------------------------------------------------*/
TAtomo *BuscaRecursiva (TListaCircularCabeca *lista, int chave, TAtomo *pbusca)
{
  if (lista->cabeca == pbusca) return NULL;
  if (pbusca->info.chave == chave) return pbusca;
  return BuscaRecursiva (lista, chave, pbusca->prox);
}
/*-------------------------------------------------------------------------------------*/
void inicializarPilhaMultipla (TPM *pilha)
{
  for (int i = 0; i < NP; i++)
  {
    pilha->base[i] = (i*(MAX/NP)) - 1;
    pilha->topo[i] = pilha->base[i];
  }
}
/*-------------------------------------------------------------------------------------*/
void intercalarVector(TVet *A, TVet *B, TVet *C, int i, int j)
{
  if ((i == 0) && (j == 0))
  {
    A->item[A->ultPos++] = INT_MAX;
    B->item[B->ultPos++] = INT_MAX;
  }
  if ((A->item[i] < INT_MAX) || (A->item[i] < INT_MAX))
  {
    if (A->item[i].chave < B->item[j].chave)
    {
      C->item[C->ultPos++] = A->item[i];
      intercalarVector(A,B,C, i+1, j);
    }
    else if (A->item[i] > B->item[j].chave)
    {
      C->item[C->ultPos++] = B->item[j];
      intercalarVector(A,B,C,i,j+1);
    }
    else
    {
      C->item[C->ultPos++] = B->item[j];
      intercalarVector(A,B,C,i+1,j+1);
    }
  }
}

/*-----------------------------------------------------------------------------------*/
Boolean isEqual(TPilha *p1, TPilha *p2)
{
    if ( (isEmpty(p1) == TRUE) && (isEmpty(p2) == TRUE) ) return TRUE;
    TPilha *paux1;
    inicializarPilha(paux1);
    while ( (p1->topo != NULL) && (p2->topo != NULL))
    {
        if ( p1->topo.info != p1->topo.info ) return FALSE;
        TInfo x1, TInfo x2;
        desempilhar(p1, &x1);
        desempilhar(p2, &x2);
        empilhar(paux, x1);
        empilhar(paux, x2);
    }
    if ( (p1->topo == NULL) && (p2->topo == NULL) )
    {
        while ( (paux1->topo != NULL) && (paux2->topo != NULL))
        {
            TInfo x1, TInfo x2;
            desempilhar(paux, &x1);
            desempilhar(paux, &x2);
            empilhar(p1, x1);
            empilhar(p2, x2);
        }
        return TRUE;
    }
    return FALSE;
}
/*-------------------------------------------------------------------------------------*/
int isWCM (char st[])
{
  TPilha *pilha;
  int cont = 0;
  inicializarPilha(pilha);
  for (int i = 0; st[i] != 'c'; i++)
  {
    TInfo x.valor = st[i];
    if( empilhar(pilha, x) == NO_SPACE ) return NO_SPACE;
    cont++;
  }
  for (int i = cont+2; (st[i] != '\0') && (pilha->topo != NULL); i++)
  {
    TInfo x;
    desempilhar(pilha, &x);
    if ( x.valor != st[i] ) return IS_NOT_WCM;
  }
  if ( (st[i] == '\0') && (pilha->topo == NULL) ) return IS_WCM;
  return IS_NOT_WCM;
}
/*-------------------------------------------------------------------------------------*/
int isXY(char st[])
{
  TPilha *pilha;
  int tam = tamanho(st)/2, cont = 0;
  inicializarPilha(pilha);
  for (int i = 0; i <= tam; i++)
  {
    TInfo x.valor = st[i];
    if( empilhar(pilha, x) == NO_SPACE ) return NO_SPACE;
    cont++;
  }
  for (int i = cont+1; (st[i] != '\0') && (pilha->topo != NULL); i++)
  {
    TInfo x;
    desempilhar(pilha, &x);
    if ( x.valor != st[i] ) return XY;
  }
  if ( (st[i] == '\0') && (pilha->topo == NULL) ) return IS_XY;
  return IS_NOT_XY;
}

int tamanho (char st[])
{
  int i = 0,;
  while (st[i] != '\0') i++;
  return i;
}
/*-------------------------------------------------------------------------------------*/
int MaxMin (TPilhaDinamica *pilha, int *max, int *min)
{
  if (pilhaVazia(pilha)) return STACK_EMPTY;
  TPilha *paux;
  inicializarPilha(paux);
  *min = pilha->topo->info.valor; //Caso existir uma pilha unitaria
  while (pilha->topo != NULL)
  {
    TInfo x1;
    desempilhar(pilha, *x1);
    if (x1.valor > *max) *max = x.valor;
    if (x1.valor < *min) *menor = x1.valor;
    if (empilhar(paux, x) == NO_SPACE ) return NO_SPACE;
  }
  while (paux->topo != NULL)
  {
    TInfo x1;
    desempilhar(paux, *x1);
    if (empilhar(pilha, x) == NO_SPACE ) return NO_SPACE;
  }
  return OK;
}
/*-------------------------------------------------------------------------------------*/
int capicuaPar (char st[])
{
  TPilha *pilha;
  inicializarPilha(pilha);
  int tam = tamanho(st)/2, cont = 0;
  for (int i = 0; i <= tam; i++)
  {
    TInfo x.valor = st[i];
    if ( empilhar(pilha, x) == NO_SPACE) return NO_SPACE;
    cont++;
  }
  for (int i = cont+1; (st[i] != '\0') && (pilha->topo != NULL); i++)
  {
    TInfo x;
    desempilhar(pilha, &x);
    if ( x.valor != st[i] ) return IS_NOT_CAPICUA_PAR;
  }
  if ( (st[i] == '\0') && (pilha->topo == NULL) ) return IS_CAPICUA_PAR;
  return IS_NOT_CAPICUA_PAR;
}

int tamanho (char st[])
{
  int i = 0;
  while (st[i] != '\0') i++;
  return OK;
}
/*-------------------------------------------------------------------------------------*/
int inverterPalavraTexto (TPIlha *pilha)
{
  if (pilhaVazia(pilha)) return STACK_EMPTY;
  TPilhaDinamica *paux1, *paux2;
  inicializarPilha(paux1);
  inicializarPilha(paux2);
  while (pilha->topo != NULL)
  {
    TInfo x;
    desempilhar(pilha, &x);
    if (empilhar(paux1, x) == NO_SPACE) return NO_SPACE;
  }
  while (paux1->topo != NULL)
  {
    TInfo x;
    desempilhar(paux1, &x);
    if ( empilhar(paux2, x) == NO_SPACE) return NO_SPACE;
    if (paux1->topo->info.valor == ' ')
    {
      while (paux2->topo != NULL)
      {
        TInfo x;
        desempilhar(paux2, &x);
        if ( empilhar(pilha, x) == NO_SPACE ) return NO_SPACE;
      }
      TInfo x;
      desempilhar(paux1, &x);
      if ( empilhar(pilha, x) == NO_SPACE ) return NO_SPACE;
    }
  }
  return OK;
}
/*-------------------------------------------FILA--------------------------------------------------------------------------------*/
typedef struct
{
  int valor;
  int chave;
}TItem;

typedef struct
{
  TItem item[MAX];
  int frente;
  int fundo;
}TFilaSequencial;

void inicializarFila (TFilaSequencial *fila)
{
  fila->frente = -1;
  fila->fundo = -1;
}

Boolean vazia(TFilaSequencial *fila)
{
  return (fila->fundo == -1);
}

Boolean cheia(TFilaSequencial *fila)
{
  return (fila->fundo == MAX - 1);
}

int inserir (TFilaSequencial *fila, TItem x)
{
  if (cheia(fila)) return QUEUE_FULL;
  fila->fundo++;
  fila->item[fila->fundo] = x;
  return OK;
}

int remover (TFilaSequencial *fila, TItem *x)
{
  if (vazia(fila)) return QUEUE_EMPTY;
  fila->frente++;
  *x = fila->item[fila->frente];
  if (fila->frente == fila->fundo) inicializarFila(fila);
  return OK;
}

int tamanhoFila (TFilaSequencial *fila)
{
  return (fila->fundo - fila->frente);
}
/*-------------------------------------------FILA CIRCULAR---------------------------------------------------------------------------*/
typedef struct
{
  int valor;
  int chave;
}TItem;



typedef struct
{
  TItem item[MAX];
  int tamanho = 0;
  int frente;
  int fundo;
}TFilaCircular;


void inicializarFilaCircular (TFilaCircular *fila)
{
  fila->frente = TAMANHO/2;
  fila->fundo = TAMANHO/2;
}

Boolean vazia(TFilaCircular; *fila)
{
  return (fila->fundo == fila->frente);
}

Boolean cheia(TFilaCircular *fila)
{
  return (fila->tamanho == TAMANHO);
}

int inserir (TFilaCircular *fila, TItem x)
{
  if (cheia(fila)) return QUEUE_FULL;
  fila->fundo = (fila->fundo + 1)%TAMANHO;
  fila->tamanho++;
  fila->item[fila->fundo] = x;
  return OK;
}


int remover (TFilaCircular *fila, TItem *x)
{
  if (vazia(fila)) return QUEUE_EMPTY;
  fila->frente = (fila->frente + 1)%TAMANHO;
  fila->tamanho--;
  *x = fila->item[fila->frente];
  return OK;
}

/*-------------------------------------------FILA Dinamica---------------------------------------------------------------------------*/
typedef struct
{
  int valor;
  int chave;
}TInfo;

typedef struct apontador
{
  TInfo info;
  struct apontador *prox;
}TAtomo;

typedef struct
{
  TAtomo *frente;
  TAtomo *fundo;
}TFilaDinamica;



int inserirFila (TFilaDinamica *fila, TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = NULL;
  if (vazia(fila))
  {
    fila->fundo = pnovo;
    fila->frente = pnovo;
  }
  else
  {
    fila->fundo->prox = pnovo;
    fila->fundo = pnovo;
  }
  return OK;
}

int remover (TFilaDinamica *fila, TItem *x)
{
  if (vazia(fila)) return QUEUE_EMPTY;
  TAtomo *pdel = fila->frente;
  *x = fila->frente->info;
  if (unitaria(fila)) inicializarFila(fila);
  else fila->frente = fila->frente->prox;
  free(pdel);
  return OK;
}

/*-------------------------------------------FILA DUPLA---------------------------------------------------------------------------*/
typedef struct
{
  int valor;
  int chave;
}TInfo;

typedef struct apontador
{
  TInfo info;
  struct apontador *eprox;
  struct apontador *dprox;
}TAtomo;

typedef struct
{
  TAtomo *frente;
  TAtomo *fundo;
}TFilaDupla;



int inserir(TFilaDupla *fila, TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->dprox = NULL;
  pnovo->eprox = fila->fundo;
  if (fila->fundo == NULL)
  {
    fila->fundo = pnovo;
    fila->frente = pnovo;
  }
  else
  {
    fila->fundo->dprox = pnovo;
    fila->fundo = pnovo;
  }
  return OK;
}
int removerDequeInicio (TFilaDupla *fila, TInfo *x)
{
  if (vaziaDeque(fila)) return FILA_EMPTY;
  TAtomo *pdel = fila->frente;
  *x = pdel->info;
  if (unitaria(fila)) inicializarDequeu(fila);
  else
  {
    fila->frente = fila->frente->dprox;
    fila->frente->eprox = NULL;
  }
  free(pdel);
  return OK;
}
/*-------------------------------------------ARVORE---------------------------------------------------------------------------*/
typedef struct
{
  int valor;
  int chave;
}TInfo;

typedef struct apontador
{
  TInfo info;
  struct apontador *fesq;
  struct apontador *fdir;
}TAtomo;

typedef struct
{
  TAtomo *raiz;
}TAB;


void iniciaArvoreBinaria(TAB *arvore)
{
  arvore->raiz = NULL;
}

int iniciaAtomoRaiz(TAB *arvore, TInfo x)
{
  arvore->raiz = (TAtomo *) malloc(sizeof(TAtomo));
  if ( arvore->raiz == NULL ) return NO_SPACE;
  arvore->raiz->info = x;
  arvore->raiz->fesq = NULL;
  arvore->raiz->fdir = NULL;
  return OK;
}



//Pre Ordem Iterative
int preOrdemIterativo (TAtomo *raiz)
{
  if (arvoreVazia(raiz)) return TREE_EMPTY;
  TPilhaDinamica *pilha;
  inicializarPilha(pilha);
  TAtomo *paux = raiz;
  do
  {
    while (paux != NULL)
    {
      visitaAtomo(paux->info.valor);
      int codret = empilhar(pilha, paux->info);
      if ( codret == NULL )
      {
        destruirPilha(pilha);
        return NO_SPACE;
      }
      paux = paux->fesq;
    }
    desempilhar(pilha, &paux->info);
    paux = paux->fdir;
  } while(paux != NULL || pilha->topo != NULL);
  return OK;
}

//In Ordem Iterative
int intOrdemIterativo (TAtomo *raiz)
{
  if ( raiz == NULL ) return TREE_EMPTY;
  TPilhaDinamica *pilha;
  inicializarPilha(pilha);
  TAtomo *paux = raiz;
  do
  {
    while (paux != NULL)
    {
      int codret = empilhar(pilha, paux->info);
      if ( codret == NULL )
      {
        destruirPilha(pilha);
        return NO_SPACE;
      }
      paux = paux->fesq;
    }
    desempilhar(pilha, &paux->info);
    visitaAtomo(paux->info.valor);
    paux = paux->fdir;
  } while(paux != NULL || pilha->topo != NULL);
  return OK;
}





//Pos-Ordem Iterative

int intPosIterativo (TAtomo *raiz)
{
  if ( raiz == NULL ) return TREE_EMPTY;
  TPilhaDinamica *pilha;
  inicializarPilha(pilha);
  TAtomo *paux = raiz;
  do
  {
    while (paux != NULL)
    {
      int codret = empilhar(pilha, paux->info);
      if ( codret == NULL )
      {
        destruirPilha(pilha);
        return NO_SPACE;
      }
      paux = paux->fesq;
    }
    desempilhar(pilha, &paux->info);
    visitaAtomo(paux->info.valor);
    paux = paux->fdir;
  } while(paux != NULL || pilha->topo != NULL);
  return OK;
}


//                      ARVORE DE BUSCA BINARIA

TAtomo *criarFIlho(TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  pnovo->
}


int inserirABB (TAB *arvore, TInfo x)
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->fesq = NULL;
  pnovo->fdir = NULL;
  if ( arvore->raiz == NULL )
  {
    pnovo->pai = NULL;
    arvore->raiz = pnovo;
  }
  else
  {
    TAtomo *ppai = NULL, *paux = arvore->raiz;
    while ( paux != NULL )
    {
      ppai = paux;
      if (paux->info.chave < pnovo->info.chave) paux = paux->fdir;
      else paux = paux->fdir;
    }
    pnovo->pai = ppai;
    if (ppai->info.chave < pnovo->info.chave) ppai->fdir = pnovo;
    else ppai->fesq = pnovo;
  }
  return OK;
}


///remover a estudar
