/*
    Autor: BaziotaBeans
    Data: 13/10/2018
    Hora: 22:23
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
