/*--------------------------------------------------------------------------------------------------------
Recebe: Uma pilha
Objectivo: Inicializar uma pilha em alocação dinâmica
Devolve: pilha dinâmica com ponteiros de controlo actualizados.
------------------------------------------------------------------------------------------------------- */
void iniciaPilhaDinamica ( TPilhaDinamic *pilha )
{
  pilha-> topo = NULL;
}

/*-------------------------------------------------------------------------------------------------------
Recebe: Uma pilha e um determinado registro
Objectivo: Inserir um átomo com essa informação no topo da pilha
Devolve: Pilha actualizada e código de erro
------------------------------------------------------------------------------------------------------ */
int Empilhar ( TPilhaDinamic *pilha , TInfo x )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtmo));
  if (pnovo == NULL) return NO_SPACE;
  pnovo->info = x;
  pnovo->prox = pilha->topo;
  pilha->topo = pnovo;
  return OK;
}

/*-------------------------------------------------------------------------------------------------------
Recebe: Uma pilha
Objectivo: Remover o átomo que está no topo da pilha
Devolve: Pilha actualizada, informação removida e código de erro
------------------------------------------------------------------------------------------------------ */
int desempilhar ( TPilhaDinamica *pilha, TInfo *x )
{
if ( vaziaPilhaDinamica(pilha) ) return STACK_EMPTY;
 TAtomo *pdel = pilha->topo;
 *x = pilha->info;
 pilha->topo = pdel ->prox;
 free (pdel);
 return OK;
}
