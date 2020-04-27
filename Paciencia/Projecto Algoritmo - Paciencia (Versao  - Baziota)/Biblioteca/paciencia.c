/*

      AUTOR: BAZIOTABEANS A.K.A 007
      HORA: 03:00
      Data: 10/11/2018
      Descricao: Projecto III de Algoritmo e Complexidade (ESTRUTURA DE DADOS) - Paciencia

*/
/* -------------------------------------------------------------------------------------------------------
Especificação de operacoes : paciencia.c
Objectivo: Disponibilizar as operações comuns sobre a paciencia
--------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------
                                    Importacao das Bibliotecas
--------------------------------------------------------------------------------------------------------*/
#include "paciencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
/*--------------------------------------------------------------------------------------------------------
			                               Estruturas de Dados   Definidos
--------------------------------------------------------------------------------------------------------*/
typedef enum boolean {true = 1, false = 0}Boolean;

typedef struct carta
{
  int peso;
  char valor;
  char cor;
  char naipe;
  Boolean aberto;
}TCarta;


typedef struct baralho
{
  TCarta *carta;
  int ultPos;
}TBaralho;

typedef struct pointer
{
  TCarta info;
  struct pointer *prox;
}TAtomo;

typedef struct pilha
{
  TAtomo *topo;
  char reference;
  int unidade;
}TPilhaDinamic;
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */
TBaralho* criarBaralho ()
{
    TBaralho *baralho = (TBaralho *) malloc(sizeof(TBaralho));
    baralho->carta  = (TCarta *) malloc(52 * sizeof(TCarta));
    baralho->ultPos = -1;
    return baralho;
}
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */
TPilhaDinamic* criarPilha ()
{
    TPilhaDinamic *pilha = (TPilhaDinamic *) malloc(sizeof(TPilhaDinamic));
    if(pilha != NULL) iniciaPilhaDinamica(pilha);
    return pilha;
}
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */

/*--------------------------------------------------------------------------------------------------------
Recebe: Uma pilha
Objectivo: Inicializar uma pilha em alocação dinâmica
Devolve: pilha dinâmica com ponteiros de controlo actualizados.
------------------------------------------------------------------------------------------------------- */
void iniciaPilhaDinamica ( TPilhaDinamic *pilha )
{
  pilha->topo = NULL;
}
/*--------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
------------------------------------------------------------------------------------------------------- */
Boolean vaziaPilhaDinamica(TPilhaDinamic *pilha)
{
    return (pilha->topo == NULL);
}

/*-------------------------------------------------------------------------------------------------------
Recebe: Uma pilha e um determinado registro
Objectivo: Inserir um átomo com essa informação no topo da pilha
Devolve: Pilha actualizada e código de erro
------------------------------------------------------------------------------------------------------ */
int empilhar ( TPilhaDinamic *pilha , TCarta x )
{
  TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
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
-------------------------------------------------------------------------------------------------------*/
int desempilhar (TPilhaDinamic *pilha, TCarta *x)
{
  if (vaziaPilhaDinamica(pilha)) return STACK_EMPTY;
  TAtomo *pdel = pilha->topo;
  *x = pilha->topo->info;
  pilha->topo = pdel ->prox;
  free (pdel);
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
/*int imprimirPilha (TPilhaDinamic *pilha)
{
  TPilhaDinamic *paux1 = criarPilha(), *paux2 = criarPilha();
  while (pilha->topo != NULL)
  {
    printf("| %d \n", pilha->topo->info.peso);
    TCarta x;
    desempilhar(pilha, &x);
    empilhar(paux1, x);
  }
  while (paux1 != NULL)
  {
    TCarta x;
    desempilhar(paux1, &x);
    empilhar(paux2, x);
  }
  while (paux2 != NULL)
  {
    TCarta x;
    desempilhar(paux2, &x);
    empilhar(pilha, x);
  }
  free(paux1);
  free(paux2);
  return OK;

}*/
void imprimirPilha (TPilhaDinamic *pillha)
{
  for (TAtomo *aux = pillha->topo; aux != NULL; aux = aux->prox)
  {
      if (aux->info.aberto == true) printf("%d%c|", aux->info.peso, aux->info.naipe);
      //else printf("#|");
  }
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
int autoInserting(TBaralho *baralho)
{
  int codNaipe = 0;
  for (int i = 0, j = 1; i < 52; i++, j++)
  {
    if (j == 14) j = 1;
    if ((i >= 0)  && (i <= 12)) carregar(baralho, i, j, 'v', 'C');
    if ((i >= 13) && (i <= 25)) carregar(baralho, i, j, 'p', 'E');
    if ((i >= 26) && (i <= 38)) carregar(baralho, i, j, 'v', 'O');
    if ((i >= 39) && (i <= 51)) carregar(baralho, i, j, 'p', 'P');
    baralho->ultPos++;
  }
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
int carregar(TBaralho *baralho, int i, int peso, char cor, char naipe)
{
  baralho->carta[i].peso = peso;
  baralho->carta[i].cor = cor;
  baralho->carta[i].naipe = naipe;
  baralho->carta[i].aberto = false;
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
void imprimirBaralho(TBaralho *baralho)
{
  printf("\tCOPA  \tESPADA \tOURO  \tPAUS\n");
  for (int i = 0; i < 13; i++) printf("\t|%d%c  \t|%d%c  \t|%d%c  \t|%d%c \n", baralho->carta[i].peso,baralho->carta[i].naipe, baralho->carta[i + 13].peso,baralho->carta[i + 13].naipe, baralho->carta[i + 26].peso,
  baralho->carta[i + 26].naipe,baralho->carta[i + 39].peso,baralho->carta[i + 39].naipe);
}
/*-------------------------------------------------------------------------------------------------------
Recebe:
Objectivo:
Devolve:
-------------------------------------------------------------------------------------------------------*/
TBaralho* embaralharCarta(TBaralho *baralho)
{
  TBaralho *novoBaralho = criarBaralho ();  int pos;
  TCarta *x = criarCarta();
  for (int i = 0; i < MAX_BARALHO && baralho->ultPos != 0; i++)
  {
    srand(time(NULL)); /* Inicializa o gerador de numeros aleatorios */
    pos = 0 + (rand() % baralho->ultPos);
    x = criarCarta();
    removerElemento(baralho, pos, x);
    novoBaralho->carta[i] = *x;
    novoBaralho->ultPos++;
  }
  novoBaralho->ultPos++;
  removerElemento(baralho, baralho->ultPos, x);
  novoBaralho->carta[novoBaralho->ultPos] = *x;
  free(x);
  return novoBaralho;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
TCarta *criarCarta()
{
  TCarta *carta = (TCarta *) malloc(sizeof(TCarta));
  return carta;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
Boolean isEmpty(TBaralho *baralho)
{
  return (baralho->ultPos == -1);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int removerElemento (TBaralho *baralho, int pos, TCarta *x)
{
  if (isEmpty(baralho)) return BARALHO_IS_EMPTY;
  if ( pos < 0 || pos > baralho->ultPos ) return INVALID_INDEX;
  *x = baralho->carta[pos];
  for ( int aux = pos; aux <= baralho->ultPos - 1; aux++ ) baralho->carta[aux] = baralho->carta[aux + 1];
  baralho->ultPos--;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
void simulation1()
{
  TBaralho *baralho = criarBaralho(), *novoBaralho;
  autoInserting(baralho);
  printf("\nANTES DE EMBARALHAR AS CARTAS\n");
  imprimirBaralho(baralho);
  novoBaralho = embaralharCarta(baralho);
  printf("\nDEPOIS DE EMBARALHAR AS CARTAS\n");
  imprimirBaralho(novoBaralho);
  simulation2(novoBaralho);
  free(baralho);
  free(novoBaralho);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
void simulation2(TBaralho *baralho)
{
  TPilhaDinamic *p1 = criarPilha(), *p2 = criarPilha(), *p3 = criarPilha(), *p4 = criarPilha(), *p5 = criarPilha(), *p6 = criarPilha(), *p7 = criarPilha();
  TPilhaDinamic *ps1 = criarPilha(), *ps2 = criarPilha(), *ps3 = criarPilha(), *ps4 = criarPilha(), *pE = criarPilha(), *pD = criarPilha();
  Boolean flag1 = false, flag2 = false, flag3 = false, flag4 = false;
  for ( int i = 0, j = 1; j <= 7;  j++)
  {
    if (j <= 1) empilhar(p1, baralho->carta[i++]);
    if (j <= 2) empilhar(p2, baralho->carta[i++]);
    if (j <= 3) empilhar(p3, baralho->carta[i++]);
    if (j <= 4) empilhar(p4, baralho->carta[i++]);
    if (j <= 5) empilhar(p5, baralho->carta[i++]);
    if (j <= 6) empilhar(p6, baralho->carta[i++]);
    if (j <= 7) empilhar(p7, baralho->carta[i++]);
  }
  distribuirParaPilhaEstoque(pE, baralho);
  movimentar(pE, pD);
  abrir(p1);
  abrir(p2);
  abrir(p3);
  abrir(p4);
  abrir(p5);
  abrir(p6);
  abrir(p7);
  abrir(pD);
  printf("\n");
  printf("E   D  %d%c\n",pD->topo->info.peso,pD->topo->info.naipe);
  printf("J1  J1 %d%c\n",p1->topo->info.peso,p1->topo->info.naipe);
  printf("J2  J2 %d%c\n",p2->topo->info.peso,p2->topo->info.naipe);
  printf("J3  J3 %d%c\n",p3->topo->info.peso,p3->topo->info.naipe);
  printf("J4  J4 %d%c\n",p4->topo->info.peso,p4->topo->info.naipe);
  printf("J5  J5 %d%c\n",p5->topo->info.peso,p5->topo->info.naipe);
  printf("J6  J6 %d%c\n",p6->topo->info.peso,p6->topo->info.naipe);
  printf("J7  J7 %d%c\n",p7->topo->info.peso,p7->topo->info.naipe);
  /*printf("\nPilha de Jogo 1:");imprimirPilha(p1);
  printf("\nPilha de Jogo 2:");imprimirPilha(p2);
  printf("\nPilha de Jogo 3:");imprimirPilha(p3);
  printf("\nPilha de Jogo 4:");imprimirPilha(p4);
  printf("\nPilha de Jogo 5:");imprimirPilha(p5);
  printf("\nPilha de Jogo 6:");imprimirPilha(p6);
  printf("\nPilha de Jogo 7:");imprimirPilha(p7);
  printf("\n");
  printf("\nPilha de estoque: ");imprimirPilha(pE); printf("\n");
  printf("\nNumero de Cartas na Pilha de Estoque %d\n", contar(pE));
  printf("\nNumero de Cartas na Pilha de Jogo 1 %d\n", contar(p7));*/
  for (int i = 1; (i <= MAX_MOVIMENTACAO) && (validSaidaStack(ps1, ps2, ps3, ps4) != true); i++)
  {
    // Para Caso inicial
    if(vaziaPilhaDinamica(ps1))
    {
      compararA(pD,&flag1,ps1);
      compararA(p1,&flag1,ps1);
      compararA(p2,&flag1,ps1);
      compararA(p3,&flag1,ps1);
      compararA(p4,&flag1,ps1);
      compararA(p5,&flag1,ps1);
      compararA(p6,&flag1,ps1);
      compararA(p7,&flag1,ps1);
    }
    if (vaziaPilhaDinamica(ps2))
    {
      compararA(pD,&flag2,ps2);
      compararA(p1,&flag2,ps2);
      compararA(p2,&flag2,ps2);
      compararA(p3,&flag2,ps2);
      compararA(p4,&flag2,ps2);
      compararA(p5,&flag2,ps2);
      compararA(p6,&flag2,ps2);
      compararA(p7,&flag2,ps2);
    }
    if (vaziaPilhaDinamica(ps3))
    {
      compararA(pD,&flag3,ps3);
      compararA(p1,&flag3,ps3);
      compararA(p2,&flag3,ps3);
      compararA(p3,&flag3,ps3);
      compararA(p4,&flag3,ps3);
      compararA(p5,&flag3,ps3);
      compararA(p6,&flag3,ps3);
      compararA(p7,&flag3,ps3);
    }

    if (vaziaPilhaDinamica(ps4))
    {
      compararA(pD,&flag3,ps4);
      compararA(p1,&flag3,ps4);
      compararA(p2,&flag3,ps4);
      compararA(p3,&flag3,ps4);
      compararA(p4,&flag3,ps4);
      compararA(p5,&flag3,ps4);
      compararA(p6,&flag3,ps4);
      compararA(p7,&flag3,ps4);
    }

  }
  if (!vaziaPilhaDinamica(ps1)) printf("\n%d%d\n", ps1->topo->info.peso, ps1->topo->info.naipe);

}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int distribuirParaPilhaEstoque(TPilhaDinamic *pilha,TBaralho *baralho)
{
  for (int i = 28; i <= baralho->ultPos; i++) empilhar(pilha, baralho->carta[i]);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
Boolean isOrder(TPilhaDinamic *pilha)
{
  TPilhaDinamic *paux1 = criarPilha();
  TAtomo *aux;
  TCarta carta;
  for (int i=1; i < 13; i++)
  {
    desempilhar(pilha, &carta);
    if ( carta.peso > pilha->topo->info.peso )
    {
      empilharAux(paux1, pilha, i);
      return false;
    }
    empilhar(paux1, carta);
  }
    /*for (int j = i + 1; j <= 13 - i; j++)
    {
      if ( (carta.peso > pilha->topo->info.peso ) return false;
      //desempilhar(pilha, &carta);
      empilhar(paux1, carta);
    }*/
    //empilhar(paux2, carta);
    //empilharAux(paux1, pilha, i);
  empilharAux(paux1, pilha, 0);
  free(paux1); //free(paux2);
  return true;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int empilharAux(TPilhaDinamic *pOrigem, TPilhaDinamic *pDestino, int i)
{
  TCarta carta;
  for (int j=0; j < 13 - i; j++)
  {
    desempilhar(pOrigem, &carta);
    empilhar(pDestino, carta);
  }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
void insert(TPilhaDinamic *pilha, TBaralho *baralho)
{
  for (int i = 0; i < 13; i++) empilhar(pilha, baralho->carta[i]);
}


void simulation3 ()
{
  TPilhaDinamic *pilha = criarPilha();
  TBaralho *baralho = criarBaralho();
  autoInserting(baralho);
  insert (pilha, baralho);
  //imprimirPilha(pilha);
  if (isOrder(pilha)) imprimirPilha(pilha);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
void simulation4 ()
{

}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
Boolean validSaidaStack(TPilhaDinamic *p1, TPilhaDinamic *p2, TPilhaDinamic *p3, TPilhaDinamic *p4)
{
  int cont1 = contar(p1),cont2 = contar(p2),cont3 = contar(p3),cont4 = contar(p4);
  if ((cont1 == 13) && (cont2 == 13))
    if ((cont3 == 13) && (cont4 == 13)) return true;
  return false;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int contar (TPilhaDinamic *pilha)
{
  if (vaziaPilhaDinamica(pilha)) return STACK_EMPTY;
  int count = 0;
  TPilhaDinamic *paux = criarPilha();
  iniciaPilhaDinamica(paux);
  while (pilha->topo != NULL)
  {
    TCarta carta;
    desempilhar(pilha, &carta);
    empilhar(paux, carta);
    count++;
  }
  while (paux->topo != NULL)
  {
    TCarta carta;
    desempilhar(paux, &carta);
    empilhar(pilha, carta);
  }
  free(paux);
  return count;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int movimentar(TPilhaDinamic *pilhaOrigem, TPilhaDinamic *pilhaDestino)
{
  TCarta x;
  if (vaziaPilhaDinamica(pilhaOrigem)) return STACK_EMPTY;
  desempilhar(pilhaOrigem, &x);
  empilhar(pilhaDestino, x);
  imprimirPilha(pilhaDestino);
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int compararA(TPilhaDinamic *stack1, Boolean *estado, TPilhaDinamic *stack2)
{
  if ((stack1->topo->info.peso == 1) && (*estado != true) )
  {
    movimentar(stack1, stack2);
    *estado = true;
  }
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
void abrir(TPilhaDinamic *pilha)
{
  pilha->topo->info.aberto = true;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int comparar(TPilhaDinamic *stack1, Boolean *estado, TPilhaDinamic *stack2)
{
  int count = contar(stack1);
  if (vaziaPilhaDinamica(stack1) || vaziaPilhaDinamica(stack2)) return STACK_EMPTY;
  for (int i = 1; i <= count; i++)
  {
    if ((stack1->topo->info.peso - 1 == stack2->topo->info.peso) && (stack1->topo->info.cor != stack2->topo->info.cor) ) movimentar(stack1, stack2);
  }
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
--------------------------------------------------------------------------------------------------------*/
int compararK(TPilhaDinamic *stack1, Boolean *estado, TPilhaDinamic *stack2)
{
  if ((stack1->topo->info.peso == 13) && (*estado != true))
  {
    movimentar(stack1, stack2);
    *estado = true;
  }
  return OK;
}
