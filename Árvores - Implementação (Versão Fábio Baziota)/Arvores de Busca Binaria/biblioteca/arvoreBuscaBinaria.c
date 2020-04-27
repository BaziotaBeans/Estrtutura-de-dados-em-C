/*
    Autor: BaziotaBeans
    Data: 14/10/2018
    Hora: 18:33
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : arvoreBuscaBinaria.c
Objectivo: Disponibilizar as operações comuns sobe uma árvore busca binária dinâmica                          
--------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "arvoreBuscaBinaria.h"
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
    struct Atomo *pai;
}TAtomo;

typedef struct arvore
{
    TAtomo *raiz;
}TAB;


typedef enum {true = 1, false = 0} Boolean;


/*----------------------------------------------------------------------------------------------------------
                                            Implementação das Operações
-----------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------
Recebe: Arvore de busca binária, conteudo da chave de busca
Objectivo: Encontrar um átomo que possui essa chave
Devolve: NULL se o elemento não existe ou o endereço do átomo
------------------------------------------------------------------------------------------------------ */
TAtomo *busca(TAB *arvore, int x)
{
    TAtomo *pbusca = arvore->raiz;
    while (pbusca != NULL)
    {
        if (pbusca->info.chave == x) return pbusca;
        else if (pbusca->info.chave > x) pbusca = pbusca->fesq;
        else pbusca = pbusca->fdir;
    }
    return NULL;
}

TAtomo *buscaRecursiva(TAB *arvore, int x, TAtomo *pbusca)
{
    if (pbusca == NULL) return NULL;
    if (pbusca->info.chave == x) return pbusca;
    if (pbusca->info.chave > x) return buscaRecursiva(arvore, x, pbusca->fesq);
    return buscaRecursiva(arvore, x, pbusca->fdir);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Criar uma folha
Parâmetro Entrada: Informação a inserir
Parâmetro de Saída: árvore binaria 
------------------------------------------------------------------------------------------------------ */
TAtomo *criarFolha(TInfo x)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    pnovo->info = x;
    pnovo->fdir = NULL;
    pnovo->fesq = NULL;
    return pnovo;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento
Parâmetro Entrada: árvore de busca binária, Informação a inserir
Parâmetro de Saída: árvore binaria actualizada
Valor de Retorno: Código de Erro (NO_SPACE ou OK)
------------------------------------------------------------------------------------------------------ */
int inserirABB (TAB *arvore, Tinfo x, )
{
    TAtomo *pnovo = criarFolha(x);
    if (pnovo == NULL) return NO_SPACE;
    if (arvore->raiz == NULL) // Árvore Vazia
    {
        pnovo->pai = NULL;
        arvore->raiz = pnovo;
    }
    else
    {
        TAtomo *ppai = NULL, *paux = arvore->raiz; //Procura Lugar
        while (paux != NULL)
        {
            ppai = paux;
            if (pnovo->info.chave > paux->info.chave) paux = paux->fdir;
            else paux = paux->fesq;
        }
        pnovo->pai = ppai;
        if (ppai->info.chave > pnovo->info.chave) ppai->fesq = pnovo;
        else ppai->fdir = pnovo;
    }
    return OK;
}

TAtomo *miniAB(TAB *arvore)
{
    if (arvore == NULL) return NULL;
    if (arvore->fesq == NULL) return arvore;
    return miniAB(arvore->fesq);
}


void moverAtomo ( TAB *arvore, TAtomo * destino, TAtomo * origem )
{
    if ( destino != NULL )
    {
        if ( destino-> pai == NULL ) // destino é a raiz da ABB
        arvore = origem ;
        else
        {
            if ( destino == destino->pai->esq )
                destino->pai->esq = origem ;
            else
            destino->pai->dir = origem ;
            if ( origem != NULL )
            origem->pai = destino->pai ;
        }
    }
}


/*-------------------------------------------------------------------------------------------------------
Objectivo: Remover um átomo dado uma chave.
Parâmetro Entrada: Arvore e a chave
Parâmetro Saída: árvore binaria actualizada.
Valor de Retorno: Código de erro (NOT_FOUND ou OK)
------------------------------------------------------------------------------------------------------- */
int removerABB (TAB *arvore, int x)
{
    TAtomo * paux1 = buscaABB(&arvore,x );
    if ( paux1 == NULL ) return NOT_FOUND;
    if (paux1->fesq == NULL) /* Caso 1 ou 2 */
        moverAtomo(&arvore, paux1 ,paux1->fdir);
    else
    {
        if (paux1->fdir == NULL) /* Caso 2 */
        moverAtomo(&arvore, paux1,paux1->fesq );
        else 
        {
            TAtmo * paux2 = miniABB(paux1->fdir ); /* Caso 3 */
            if (paux2->pai != paux1 )
            {
                moverAtomo (&arvore,paux2, paux2->fdir);
                paux2->fdir = paux1->fdir;
                paux2->fdir->pai = paux1;
            }
            moverAtomo(&arvore , paux1 , paux2);
            paux2->fesq = paux1->fesq ;
            paux2->fesq->pai = paux1 ;
        }
    }
    free ( paux1);
    return OK;
}










