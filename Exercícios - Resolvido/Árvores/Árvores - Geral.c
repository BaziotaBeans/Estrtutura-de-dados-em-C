/*
    Autor: Emanuel Moura, Fábio Baziota
    Data: 13/10/2018
    Hora: 
    Descricao: Coletanea de Exercicos de Arvores Binarias e de Arvores de Busca Binarias.
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : arvoreBinaria.c
Objectivo: Disponibilizar as operações comuns sobe uma árvore binária dinâmica
--------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "arvoreBinaria.h"
#include <stdlib.h>
/*----------------------------------------------------------------------------------------------------------
                                            ESTRUTURA DE DADOS
-----------------------------------------------------------------------------------------------------------*/

typedef struct x
{
    int chave;
    int valor;
}TInfo;

typedef struct Atomo
{
    struct Atomo *fesq;
    TInfo info;
    struct Atomo *fdir;
}TAtomo;

typedef struct arvore
{
    TAtomo *raiz;
}TAB;


typedef enum {true = 1, false = 0} Boolean;


/*----------------------------------------------------------------------------------------------------------
                                            Implementação das Operações
-----------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------
Objectivo: Inicializar uma estrutura de dados do tipo árvore binária
Parâmetro Entrada: Árvore binária
Parâmetro de Saída: Árvore binaria com o ponteiro raiz actualizado.
------------------------------------------------------------------------------------------------------ */
void iniciaArvoreBinaria (TAB *arvore)
{
    arvore->raiz = NULL;
}

/*-------------------------------------------------------------------------------------------------------
Objectivo: Inicializar uma estrutura de dados do tipo árvore binária
Parâmetro Entrada: Árvore binária
Parâmetro de Saída: Árvore binaria Actualizada
Valor de Retorno: Correspondente código de erro ( NO_SPACE ou OK)
----------------------------------------------------------------------------------------------------- */
int iniciaAtomoRaiz (TAB *arvore, TInfo x)
{
    arvore->raiz = (TAtomo *) malloc(sizeof(TAtomo));
    if (arvore->raiz == NULL) return NO_SPACE;
    arvore->raiz->info = x;
    arvore->raiz->fesq = NULL;
    arvore->raiz->fdir = NULL;
    return OK;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar se uma arvore é vazia
Parâmetro Entrada: Árvore binária
Valor de Retorno: Correspondente código de erro ( SIM || NÃO )
----------------------------------------------------------------------------------------------------- */
Boolean VaziaArvoreBinaria (TAB *arvore)
{
    return (arvore->raiz == NULL);
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um novo átomo como descendente de uma chave
Parâmetro Entrada: Árvore binária, informação inserir e chave do átomo pai
Parâmetro de Saída: Árvore binaria actualizada
Valor de Retorno: Correspondente código de erro.
------------------------------------------------------------------------------------------------------- */
int inserirFilhoEsquerdo (TAB *arvore, TInfo x, int chavepai)
{
    if (VaziaArvoreBinaria(&arvore)) return iniciaAtomoRaiz(arvore, x);
    else
    {
        TAtomo *pai = localizar (&arvore, chavepai);
        if (pai == NULL) return NOT_FOUND;
        if (pai->fesq != NULL) return DESCENDING_FOUND;
        TAtomo *pfilho = (TAtomo *) malloc(sizeof(TAtomo));
        if (pfilho == NULL) return NO_SPACE;
        pfilho->fesq = NULL;
        pfilho->fdir = NULL;
        pfilho->info = x;
        pai->fesq = pfilho;
        return OK;
    }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover uma folha dada a chave do átomo-pai
Parâmetro Entrada: Árvore binária, chave a remover, chave do átomo pai
Parâmetro de Saída: Árvore binária actualizada, conteudo da informação
Valor de Retorno: Código de erro.
------------------------------------------------------------------------------------------------------ */
int removerFolha (TAB *arvore, TInfo * x, int chavepai, int chave)
{
    if (VaziaArvoreBinaria(&arvore)) return TREE_EMPTY;
    TAtomo *pai = localizar(&arvore, chavepai);
    if (pai == NULL) return NOT_FOUND_FATHER;
    if ((pai->fesq == NULL) && (pai->fdir == NULL)) return NOT_DESCENDING;
    if ((pai->fesq != NULL) && (pai->fesq->info.chave == chave))
    {
        TAtomo *pdel = pai->fesq;
        if (pdel->fesq = NULL && pdel->fdir = NULL)
        {
            *x = pdel->info;
            pai->fesq = NULL;
            free(pdel);
            return OK;
        }
        return NOT_TERMINAL;
    }
    if ((pai->fdir != NULL) && (paix->fdir == chave))
    {
        TAtomo *pdel = pai->fdir;
        if (pdel->fesq = NULL && pdel->fdir = NULL)
        {
            *x = pdel->info;
            pai->fdir = NULL;
            free(pdel);
            return OK;
        }
        return NOT_TERMINAL;
    }
    return NOT_FOUND_TERMINAL;
}

/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
Valor de Retorno:
------------------------------------------------------------------------------------------------------ */

void visitaAtomo (int x)
{
    printf("%c", x);
}

/*-----------------------------------------------------------------------------------------------------
Objectivo: Percorrer a árvore em pre-ordem
Parâmetro de Entrada: O endereço da raiz de uma árvore binária
----------------------------------------------------------------------------------------------------- */
void preOrdemRecursivo (TAtomo *raiz)
{
    if (raiz != nulo)
    {
        visitaAtomo(raiz->info.valor);
        preOrdemRecursivo(raiz->fesq);
        preOrdemRecursivo(raiz->fdir);
    }
}
/*-----------------------------------------------------------------------------------------------------
Objectivo: Percorrer a árvore em pre-ordem
Parâmetro de Entrada: Endereço da raiz da árvore binária
----------------------------------------------------------------------------------------------------- */
int preOrdemIterativo (TAtomo *raiz)
{
    if (raiz == NULL) return TREE_EMPTY;
    TAtomo *paux = raiz;
    TPilhaDinamic *pilha;
    iniciaPilhaDinamica(&pilha);
    do{
        while(paux != NULL)
        {
            visitaAtomo(paux->info);
            int codret = empilhar(pilha, paux->info);
            if (codret == NO_SPACE)
            {
                destruirPilha(&pilha);
                return NO_SPACE;
            }
            paux = paux->fesq;
        }
        desempilhar(&pilha, paux->info);
        paux = paux->fdir;
    }
    while (pilha->topo != NULL || paux != NULL)
    return OK;
}


/*-------------------------------------------------------------------------------------------------------
Objectivo: Percorrer a árvore em In-ordem
Parâmetro de Entrada: Endereço da raiz da árvore binária
------------------------------------------------------------------------------------------------------- */
void inOrdemRecursivo (TAtomo *raiz)
{
    if (raiz != NULL)
    {
        iniOrdemRecursivo(raiz->fesq);
        visitaAtomo(raiz->info.valor);
        iniOrdemRecursivo(raiz->fdir);
    }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Percorrer a árvore em In-ordem
Parâmetro de Entrada: Endereço da raiz da árvore binária
------------------------------------------------------------------------------------------------------- */
int inOrdemIterativo (TAtomo *raiz)
{
    if (raiz == NULL) return TREE_EMPTY;
    TAtomo *paux = raiz;
    TPilhaDinamic *pilha;
    iniciaPilhaDinamica(pilha);
    do{
        while(paux != NULL)
        {
            int codret = empilhar(&pilha, paux->info);
            if (codret == NO_SPACE)
            {
                destruirPilha(&pilha);
                return NO_SPACE;
            }
            paux = paux->fesq;
        }
        desempilhar(&pilha, paux->info);
        visitaAtomo(paux->info.chave);
        paux = paux->fdir;
    }
    while (pilha->topo != NULL || paux != NULL)
    return OK;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Percorrer a árvore em pos-ordem
Parâmetro de Entrada: Endereço da raiz da árvore binária
------------------------------------------------------------------------------------------------------- */
void posOrdemRecursivo(TAtomo *raiz)
{
    if (raiz != NULL)
    {
        posOrdemRecursivo(raiz->fesq);
        posOrdemRecursivo(raiz->fdir);
    }
}

int posOrdemIterativo(TAtomo *raiz);
/*--------------------------------------------------------------------------------------------------------
Objectivo: Contar o número de átomos de uma árvore binária.
Parâmetro Entrada: Endereço da raiz da árvore binária
Valor de retorno: o correspondente número de átomos de uma árvore
------------------------------------------------------------------------------------------------------ */
int contaAtomos (TAtomo *raiz)
{
    if (raiz == NULL) return 0;
    return 1 + contaAtomos(raiz->fesq) + contaAtomos(raiz->fdir);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: produzir uma cópia de uma árvore binária.
Parâmetro Entrada: Endereço da raiz da árvore binária
Valor de retorno: a correspondente cópia de uma árvore binária.
------------------------------------------------------------------------------------------------------ */
TAtomo *copiaArvore (TAtomo *raiz )
{
    TAtomo *paux = (TAtomo *) malloc(sizeof(TAtomo));
    if (paux != NULL)
        if (raiz != NULL)
        {
            paux->info = raiz->info;
            paux->fesq = copiaArvore(raiz->fesq);
            paux->fdir = copiaArvore(raiz->fdir);
        }
    return paux;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se duas arvores binarias são iguais
Parâmetro Entrada: Endereço da raiz das duas árvore binária
Valor de retorno: Sim || Não
------------------------------------------------------------------------------------------------------ */
Boolean iguais (TAtomo *raiz1, TAtomo *raiz2)
{
    if ((raiz1 == NULL) && (raiz2 == NULL)) return true;
    if ((raiz1 != NULL) && (raiz2 != NULL))
        if ((raiz1->info == raiz2->info)) return iguais(raiz1->fesq, raiz2->fesq) && iguais(raiz1->fdir, raiz->fdir);
        else return false;
    else return false;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Aceder a todos os átomos de um determinado nível
Parâmetro Entrada: Endereço da raiz de uma árvore binária e um nível
------------------------------------------------------------------------------------------------------ */
void visitaNivel (TAtomo *raiz, int nivel)
{
    if (raiz != NULL)
        if(nivel == 0) visitaAtomo(raiz->info.valor);
        else
        {
            visitaNivel(raiz->fesq, nivel - 1);
            visitaNivel(raiz->fdir, nivel - 1);
        }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Para calcular o elemento máximo, suponho que todos os átomos possuem conteúdo positivo
Parâmetro Entrada: Endereço da raiz de uma árvore binária e um nível
------------------------------------------------------------------------------------------------------ */
int maximo (TAtomo *raiz)
{
    if (raiz == NULL) return 0;
    else
    {
        int maxe = compara(raiz->info.valor, maximo(raiz->fesq));
        int maxd = compara(raiz->info.valor, maximo(raiz->fdir));
        return compara(maxe, maxd);
    }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: A profundidade ou altura de uma árvore, é determinada pelo número máximo de seus níveis.
Parâmetro Entrada: Endereço da raiz de uma árvore binária e um nível
------------------------------------------------------------------------------------------------------ */
int altura (TAtomo *raiz)
{
    int alte, altd;
    if ( raiz == NULL ) return 0;
    else
    {
        alte = 1+ altura(raiz->fesq);
        altd = 1+ altura(raiz->fdir);
        if (alte > altd) return alte + 1
        else return altd+1
    }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: operação para construir uma árvore binária
Parâmetro Entrada: Endereço da raiz de uma árvore binária e um nível
------------------------------------------------------------------------------------------------------ */
Boolean constroiRaiz (TAtomo *raiz )
{
    if ( vaziaArvoreBinaria(&raiz) )
        if ( iniciaAtomoRaiz(&raiz,lerValor())== OK ) return TRUE;
        else return FALSE;
    else return FALSE;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: operação para construir sub árvore binária
Parâmetro Entrada: Endereço da raiz de uma árvore binária e um nível
------------------------------------------------------------------------------------------------------ */
TAtomo *constroiSubArvore (TAtomo *raiz )
{
    int x = LerValor();
    if ( x == 0 ) return raiz;
    TAtomo *paux = (TAtomo *) malloc(sizeof(TAtomo));
    if (paux != NULL)
    {
        paux->info = x;
        paux->fesq = NULL;
        paux->fdir = NULL;
        raiz->fesq = constroiSubArvore(paux);
        raiz->fdir = ConstroiSubArvore(paux);
    }
    return paux;
}



/*
    Desenvolva uma função que recebe como parâmetro de entrada 3
    ponteiros para a raiz de uma árvore binária a1 a2 a3 na qual a soma de a1 e a2 resulta numa arvore a3
*/
  void somar(TAtomo *a1, TAtomo *a2, TAtomo *a3)
  {
    TAtomo *paux = (TAtomo *) malloc(sizeof(TAtomo));
    if (paux != NULL)
    {
        if (a1 != NULL || a2 != NULL)
       {
          if ((a1 != NULL) && (a2 != NULL)) paux->info.valor = a1->info.valor + a2->info.valor;
          if ((a1 != NULL) && (a2 == NULL)) paux->info.valor = a1->info.valor;
          if ((a1 == NULL) && (a2 != NULL)) paux->info.valor = a2->info.valor;
          a3 = paux;
          a3->fesq = NULL;
          a3->fdir = NULL;
          somar(a1->fesq, a2->fesq, a3->fesq); //BUG 
          somar(a1->fdir, a2->fdir, a3->fdir); //BUG
        } 
    }
  }
/*
    Ver altura de uma AB
*/
int alturaAB (TAtomo *raiz)
{
    int altE altD;
    if (raiz == NULL) return 0;
    else
    {
        altE = 1 + alturaAB (raiz->fesq);
        altD = 1 + alturaAB (raiz->fdir);
        if (altE > altD) return altE + 1;
        else return altD + 1;
    }
}


/*
    Visistar Nivel
*/


void visitarNivel (TAtomo *raiz, int nivel)
{
    if (raiz != NULL)
    {
        if (nivel == 0) visitaAtomo(raiz->info.valor);
        visitaNivel (raiz->fesq, nivel - 1);
        visitaNivel (raiz->fdir, nivel - 1);
    }
}


/*7.9.1- Desenvolva uma função que recebe como parâmetro de entrada um
ponteiro para a raiz de uma árvore binária e uma determinada informação.
Inserir essa informação como filho esquerdo.
7.9.2- Generalize o exercício anterior de tal á inserir um átomo.*/

typedef struct
{
  int valor;
  int chave;
}TInfo;

typedef struct atomo
{
  TInfo info;
  struct atomo *fesq;
  struct atomo *fdir;
}TAtomo;

typedef struct
{
  TAtomo *raiz;
}TAB;


int inserirFilhoCompleto (TAB *arvore, TInfo x, int chavePai)
{
  if (arvoreVazia(arvore)) return TREE_EMPTY;
  TAtomo *pai = localizar(arvore,chavePai);
  if ( pai == NULL ) return FATHER_NOT_FOUND;
  if ( (pai->fesq != NULL) && (pai->fdir != NULL) ) return DESCEDING_FOUND;
  TAtomo *pfilho = (TAtomo *) malloc(sizeof(TAtomo));
  if (pfilho == NULL) return NO_SPACE;
  pfilho->info = x;
  pfilho->fesq = NULL;
  pfilho->fdir = NULL;
  if ( (pai->fesq == NULL) && (pai->fdir != NULL) )
    if (pai->fdir->info != pfilho->info) pai->fesq = pfilho;
    else
    {
      free(pfilho);
      return NOT_TERMINAL;
    }
  else if ( (pai->fesq != NULL) && (pai->fdir == NULL) )
    if (pai->fesq->info != pfilho->info) pai->fdir - pfilho;
    else
    {
      free(pfilho);
      return NOT_TERMINAL;
    }
  else pai->fesq = pfilho;
  return OK;
}
/*
7.9.3- Desenvolva um procedimento recursivo que recebe como parâmetro
de entrada um ponteiro para a raiz de uma árvore binária. Percorrer esse
árvore nível por nível da esquerda para direita e de cima para baixo*/

/*
7.9.4- Desenvolva uma função recursiva que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore binária. Contar o número de
    átomos que são folhas.*/
int contarFIlhos (TAtomo *raiz)
{
  if (raiz == NULL) return 0;
  if ( (raiz->fesq == NULL) && (raiz->fdir == NULL) ) return 1 + contaAtomos(raiz->fesq) + contaAtomos(raiz->fdir);
  return contaAtomos(raiz->fesq) + contaAtomos(raiz->fdir);
}
/*7.9.5- Desenvolva uma função recursiva que recebe como parâmetro de
entrada dois ponteiros para as raízes de duas árvores binárias. Verificar se
essas árvores são opostas, ou seja, se a subárvore à esquerda de uma é
igual à subárvore a direita de outra e vice-versa.*/
Boolean isOpposed (TAtomo *raiz1, TAtomo *raiz2)
{
  if ((raiz1 == NULL) && (raiz2 == NULL) ) return TRUE;
  if ((raiz1 != NULL) && (raiz2 != NULL) )
    if (raiz1->info == raiz2->info) return isOpposed(raiz1->fesq, raiz->fdir) && isOpposed(raiz1->dir, raiz->fesq);
    else return false;
  else return false;
}
/*
7.9.6- Desenvolva uma função recursiva que recebe como parâmetro de
entrada um ponteiro para a raiz de um árvore binária. Devolver como valor
de retorno o conteúdo do átomo com o valor mínimo*/
int minimo (TAtomo *raiz)
{
  if (raiz == NULL) return 0;
  else
  {
    int minE = comparar(raiz, minimo(razi->fesq));
    int minD = comparar(raiz, minimo(razi->fdir));
    return comparar(minE, minD);
  }
}
int comparar(int x, int y)
{
  if (x < y) return x;
  else return y;
}
/*
7.9.7- Desenvolva uma função recursiva que recebe entre outros
parâmetros de entrada, um ponteiro para a raiz de uma árvore binária.
Devolver como valor de retorno o número de átomos de descendentes que
não são folhas.*/
int descedingNotSun(TAtomo *raiz)
{
  if (raiz == NULL ) return 0;
  if ( (raiz->fesq != NULL) || (raiz->fesq != NULL) ) return 1 + descedingNotSun(raiz->fesq) + descedingNotSun(raiz->fdir);
  return descedingNotSun(raiz->fesq) + descedingNotSun(raiz->fdir);
}
/*7.9.8- Desenvolva uma função iterativa que recebe como parâmetro de
entrada um ponteiro para a raíz de uma árvore binária. Verificar se essa
árvore e estritamente binária, ou seja, todos os átomos têm dois filhos com
a excepsão das folhas.*/
//Recursive
Boolean isStricltyBinary(TAtomo *raiz)
{
  if (raiz == NULL) return TRUE;
  if ((raiz->fesq != NULL) && (raiz->fdir == NULL)) return FALSE;
  if ((raiz->fesq == NULL) && (raiz->fdir != NULL)) return FALSE;
  return isStricltyBinary(raiz->fesq) && isStricltyBinary(raiz->fdir);
}


//Iterative
int isStricltyBinary(TAtomo *raiz)
{
  if (raiz == NULL) return TREE_EMPTY;
  TAtomo *paux = raiz;
  TPilhaDinamica *pilha;
  inicializarPilha(pilha);
  do
  {
    while (paux != NULL)
    {
      if ((paux->fesq != NULL) && (paux->fdir != NULL))
      {
        int codret = empilhar(pilha, paux->info);
        if ( codret == NO_SPACE )
        {
          destruirPilha(pilha);
          return NO_SPACE;
        }
        paux = paux->fesq;
      }
      else return IS_NOT_STRICTLY_BINARY;
    }
    desempilhar(pilha, &paux->info);
    paux = paux->fdir;
  } while(paux != NULL || pilha->topo != NULL);
  return IS_STRICTLY_BINARY;
}

/*
7.9.9- Desenvolva uma função iterativa que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore binária, uma determinada
chave e uma informação. Inserir essa informação como descendente de um
átomo identificado pela sua chave.*/
int inserirFilhoCompleto (TAB *arvore, TInfo x, int chavePai)
{
  if (arvoreVazia(arvore)) return TREE_EMPTY;
  TAtomo *pai = localizar(arvore,chavePai);
  if ( pai == NULL ) return FATHER_NOT_FOUND;
  if ( (pai->fesq != NULL) && (pai->fdir != NULL) ) return DESCEDING_FOUND;
  TAtomo *pfilho = (TAtomo *) malloc(sizeof(TAtomo));
  if (pfilho == NULL) return NO_SPACE;
  pfilho->info = x;
  pfilho->fesq = NULL;
  pfilho->fdir = NULL;
  if ( (pai->fesq == NULL) && (pai->fdir != NULL) )
    if (pai->fdir->info != pfilho->info) pai->fesq = pfilho;
    else
    {
      free(pfilho);
      return NOT_TERMINAL;
    }
  else if ( (pai->fesq != NULL) && (pai->fdir == NULL) )
    if (pai->fesq->info != pfilho->info) pai->fdir - pfilho;
    else
    {
      free(pfilho);
      return NOT_TERMINAL;
    }
  else pai->fesq = pfilho;
  return OK;
}
/*
7.9.10- Desenvolva uma função iterativa que recebe como parâmetro de
entrada um ponteiro para a raiz de uma arvore binária e uma determinada
informação. Inserir essa informação como a folha mais a esquerda dessa
árvore.*/

int inserirMaisEsquerda (TAB *arvore, TInfo x)
{
  if (arvoreVazia(arvore)) return TREE_EMPTY;
  TAtomo *paux = arvore->raiz;
  while (paux->fesq != NULL ) paux = paux->fesq;
  TAtomo *pfilho = (TAtomo *) malloc(sizeof(TAtomo));
  if (pfilho == NULL) return NO_SPACE;
  pfilho->info = x;
  pfilho->fesq = NULL;
  pfilho->dir = NULL;
  paux->fesq = pfilho;
  return OK;
}
/*
7.9.11- Desenvolva uma função iterativa que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore binária não vazia. Devolva o
endereço do primeiro átomo da árvore percorrida em ordem simétrica (in-
ordem).*/


/*
7.9.12- Desenvolva uma função que recebe como parâmetro de entrada um
ponteiro para uma árvore binária. Devolver como parâmetro de saída a
correspondente àrvore binária com o campo pai preenchido. Suponha que
esse caso foi inicializado com o valor NULL.*/

/*
7.9.13- Reconstrua a árvore binária a partir dos percursos em pré-ordem e
in-ordem:
Pré-ordem: N J I H G A K F B M L E C D
In-ordem: H I A G J F B K N L C E D M*/


/*
7.9.14- Desenvolva uma função iterativa que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore binária. Devolver como valor
de retorno o número de átomos que são folhas.*/

/*
7.9.15- Desenvolva uma função recursiva que recebe entre outros
parâmetros de entrada um ponteiro para a raiz de uma árvore binária a1 e
um ponteiro para a raiz de uma árvore binária a2. Verificar se uma árvore
binária está contida numa outra árvore binária. Dizemos que uma árvore
binária a1 está contida na árvore binária a2 quando a1 é equivalente a a2
ou quando existe pelo menos uma subárvore de a2 que seja equivalente a
a1.*/
Boolean ehContido (TAtomo *a1, TAtomo *a2)
{
    if (a2 == NULL) return TRUE;
    if (a1 == NULL) return FALSE;
    if (a1->info.chave == a2->info.chave) ehContido(a1->fesq, a2->fesq) || ehContido(a1->fesq, a2->fesq);
    ehContido(a1->fesq, a2->fesq) || ehContido(a1->fesq, a2->fesq);
}
/*
7.9.16- Desenvolva uma função recursiva que recebe entre outros
parâmetros de entrada um ponteiro para a raiz de uma árvore binária.
Verificar se uma árvore possui chaves repetidas.*/
Boolean chavesRepetidas(TAtomo *raiz, int key)
{
   // IDEIA   
}
/*
7.9.17- Desenvolva uma função recursiva que recebe entre outros
parâmetros um ponteiro para a raiz de uma árvore binária. Devolver como
valor de retorno o número de átomos de um determinado nível.
*/
int numeroAtomoNivel (TAtomo *raiz, int nivel)
{
    if (raiz == NULL) return 0;
    if (nivel == 0) return 1;
    return numeroAtomoNivel(raiz->esq, nivel - 1) + numeroAtomoNivel(raiz->fdir, nivel - 1);
}

/*
7.9.18- Com base nas sequências que a seguir descrevemos, reconstitua a
correspondente árvore binária: pré-ordem: A,B,C,D,E,F,G,H,I,J,K,L
in-Ordem : C,E,H,G,I,J,F,K,D,L,B,A*/

/*
7.9.20*- Desenvolva uma função que recebe como parâmetro de entrada
um ponteiro para a raiz de uma árvore binária e uma determinada
informação. Inserir esse átomo na árvore de tal forma que o nível das
subárvore não seja superior a um. Este tipo de árvore dá-se o nome de
árvore binária balanceada.*/



    // FALTA DE IDEIA


/*
7.9.21*- Desenvolva uma função iterativa que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore binária, a chave do átomo
que pretendemos remover e do seu pai. Remover esse átomo da árvore.*/

    // Basico

/*
7.9.22- Desenvolva uma função recursiva que recebe como parâmetros de
entrada um ponteiro para a raiz de uma árvore binária e uma determinada
chave. Devolver como valor de retorno o nível do átomo que contêm essa
chave.*/
int nivelAtomo (TAtomo *raiz, int chave)
{
  if (raiz == NULL) return 0;
  if (raiz->info.chave == chave) return 1 + nivelAtomo(raiz->fesq, chave) + nivelAtomo(raiz->fesq, chave);
  return nivelAtomo(raiz->fesq, chave) + nivelAtomo(raiz->fesq, chave);
}
/*
7.9.23- Desenvolva uma função que recebe como parâmetro de entrada uma
string com uma expressão aritmética com os operadores −, ∗ e / e os
operandos identificados por apenas uma letra. Devolva por parâmetro de saída
a correspondente arvore binária.*/
typedef struct
{
  char operadores;
  int operandos;
}TInfo;

typedef struct atomo
{
  TInfo info;
  struct atomo *fesq;
  struct atomo *fdir;
}TAtomo;

typedef struct
{
  TAtomo *raiz;
}TAB;

void Imprimir (TAtomo *raiz)
{
    if (raiz != NULL)
    {
      if ((raiz->fesq == NULL) && (raiz->fdir == NULL)) visitaAtomoOperador(raiz->info.operadores);
      if (raiz->info.operandos) visitaAtomoOperandos(raiz->info.operandos);
      Imprimir(raiz->fesq);
      Imprimir(raiz->fdir);

    }
}
/*
7.9.24- Desenvolva uma função que recebe como parâmetro de entrada a
arvore binária montada no exercício anterior e calcula o valor da expressão que
ela guarda. Suponha que existe uma rotina que dado uma letra, devolve o
correspondente valor.*/
int calcular (TAtomo *raiz)
{
  //if (raiz == NULL) return 0;
  if ((raiz->fesq == NULL) && (raiz->fdir == NULL)) return raiz->info.operandos;
  if (raiz->info.operadores == '+') return calcular(raiz->fesq) + calcular(raiz->fdir);
  if (raiz->info.operadores == '-') return calcular(raiz->fesq) - calcular(raiz->fdir);
  if (raiz->info.operadores == '*') return calcular(raiz->fesq) * calcular(raiz->fdir);
  if (raiz->info.operadores == '/') return calcular(raiz->fesq) / calcular(raiz->fdir);
}
/*
7.9.26- O espelho T' de uma árvore binária T é definido por:
Se T é vazia, então o seu espelho é vazio; Senão T ́ tem a seguinte forma: a
raiz de T′é a igual á raiz de T, a subárvore esquerda de T' é o espelho da
subárvore direita de T e a subárvore direita de T′ ́ ́e o espelho da subárvore
esquerda de T .
Desenvolva uma função recursiva que recebe um ponteiro para raiz de uma
árvore binária T e a transforma no seu espelho. Devemos salientar que
nenhum átomo deve ser criado e a função deve alterar apenas os ponteiros
filho esquerdo e filho direito.*/
TAtomo *criarEspelho (TAtomo *raiz)
{
  if (raiz == NULL) return raiz;
  raiz->fesq = criarEspelho(raiz->fdir);
  raiz->fdir = criarEspelho(raiz->fesq);
}

// 

TAtomo* buscaABB (TAB *arvore, int chave)
{

  TAtomo *pbusca = arvore->raiz;
  while (pbusca != NULL)
  {
    if (pbusca->info.chave == chave) return pbusca;
    if (pbusca->info.chave < chave) pbusca = pbusca->fdir;
    else pbusca = pbusca->fesq;
  }
  return pbusca;
}
TAtomo *buscaABBRecursiva (TAtomo *raiz, int chave)
{
  if (raiz == NULL) return NULL;
  if (raiz->info.chave == chave) return raiz;
  if (raiz->info.chave < chave) retunr buscaABBRecursiva(raiz->fdir);
  retunr buscaABBRecursiva(raiz->fesq);
}
/*
8.5.2- Desenvolva uma função recursiva que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore binária. Verificar se ele é ou não
uma árvore de busca binária.*/
Boolean isSearchBinaryTree(TAtomo *raiz)
{
    if (raiz == NULL) return TRUE;
    if ((raiz->fesq != NULL) || (raiz->fdir != NULL))
      if ((raiz->fesq->info.chave > raiz->info.chave) || (raiz->fdir->info.chave < raiz->info.chave)) return FALSE;
    return isSearchBinaryTree(raiz->fesq) && isSearchBinaryTree(raiz->fdir);
}
8.5.3- Desenvolva uma função recursiva que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore de busca binária. Devolver
como valor de retorno o elemento que contêm o maior conteúdo na subárvore a
esquerda.
TAtomo *buscaMaiorSubEsquerda(TAtomo *raiz)
{
  if (raiz == NULL) return NULL;
  if ((raiz->pai != NULL) && (raiz->fdir == NULL)) return raiz;
  if ((raiz->pai != NULL) && (raiz->fdir != NULL)) return buscaMaiorSubEsquerda(raiz->fdir);
  return buscaMaiorSubEsquerda(raiz->fesq);
}
/*
8.5.4- Desenvolva uma função iterativa que recebe como parâmetro de entrada
uma lista ligada e devolve como parâmetro de saída a correspondente árvore
de busca binária.*/
void *construirArvore(TLista *lista, TAB *arvore)
{
  inciaABB(arvore);
  for (TAtomo *paux = lista->primeiro; paux != NULL; paux = paux->prox) inserir(arvore, paux->info);
}
/*
8.5.5- Desenvolva uma função iterativa que recebe como parâmetro de entrada
um ponteiro para a raiz de uma árvore de busca binária e o endereço de um
determinado átomo. Devolver o endereço do átomo antecessor.*/
TAtomo *enderecoAntecessor (TABB *arvore, int chave)
{
    TAtomo *pbusca = arvore->raiz;
    while (raiz != NULL)
    {
        if (pbusca->info.chave == chave) return pbusca = pbusca->pai;
        if (pbusca->info.chave > chave) pbusca = pbusca->fesq;
        else pbusca = pbusca->fdir;
    }
    return NULL;
}
/*
8.5.6- Desenvolva uma função recursiva que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore de busca binária e uma
determinada chave. Devolver o nível do átomo que contêm essa chave.*/
int nivelAtomoABB(TAtomo *raiz, int chave)
{
  if (raiz == NULL) return 0;
  if (raiz->info.chave == chave) return 1;
  return 1 + nivelAtomoABB(raiz->fesq, chave) + nivelAtomoABB(raiz->fdir, chave);
}
/*
8.5.7- Desenvolva uma função iterativa que recebe como parâmetro de entrada
um ponteiro para a raiz de uma árvore de busca binária e dois valores.
Retornar o endereço do ancestral comum mais próximo desses valores. Caso
algum dos valores não esteja na árvore retornar o valor NULL.*/
TAtomo *buscaAncestralComum (TAB *arvore, int x, int y)
{
    // FALTA DE IDEIA
}
/////////////////////////////////////////////////////////////////////////////
/*
8.5.8- Desenvolva uma função que recebe como parâmetro de entrada um
ponteiro para a raiz de uma árvore de busca binária e um índice i entre 0 e n-1,
onde n é o número de elementos da árvore, e devolva o i-ésimo menor
elemento da árvore.*/
TAtomo *iEsimoMenorElemento (TAtomo *raiz, int i)
{
        // FALTA DE IDEIA
}
////////////////////////////////////////////////////////////////////////////////

/*
8.5.9- Desenvolva uma função que recebe como parâmetro de entrada um
ponteiro para a raiz de uma árvore de busca binária, construir uma árvore de
busca binária de com fios. Considere que a estrutura dos átomos dessa árvore
contêm os ponteiros sucessor e antecessor e que estão inicializados com
NULL.*/

    // FALTA DE IDEIA

/*
8.5.10- Desenvolva um procedimento recursivo que recebe como parâmetro de
entrada um ponteiro para uma árvore de busca binária . Imprimir o conteúdo
das chaves das folhas em ordem crescente.*/
void imprimirCrescente (TAtomo *raiz)
{
    if (raiz != NULL)
    {
        imprimirCrescente (raiz->fesq);
        if ((raiz->fesq == NULL) && (raiz->fdir == NULL)) visitaAtomo(raiz->info.chave);
        imprimirCrescente (raiz->fdir);
        
    }
}
/*
8.5.11- Desenvolva uma função que recebe como parâmetro de entrada um
ponteiro para a raiz de uma árvore e busca binária e uma determinada chave.
Remover o átomo que contêm essa chave se for uma folha.*/

    // FALTA DE IDEIA

/*
8.5.12- Desenvolva uma função recursiva que recebe como parâmetro de
entrada um ponteiro para a raiz de uma árvore de busca binária e uma
determinada informação. Inserir essa informação, mas suponha que nessa
árvore não podemos ter chaves repetidas.*/


    // FALTA DE IDEIA

/*
8.5.13- Desenvolva uma função que recebe como parâmetro de entrada um
ponteiro para a raiz de uma árvore e busca binária e uma determinada chave.
Remover o átomo que contêm essa chave se ele possuir um e apenas um filho.*/


    // FALTA DE IDEIA
