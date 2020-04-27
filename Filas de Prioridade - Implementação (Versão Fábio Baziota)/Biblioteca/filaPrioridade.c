/*
    Autor: BaziotaBeans
    Data: 11/11/2018
    Hora: 01:00
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : filaPrioridade.c
Objectivo: Disponibilizar as operações comuns sobe uma fila de prioridade
--------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "filaPrioridade.h"
#include <stdlib.h>
/*----------------------------------------------------------------------------------------------------------
                                            ESTRUTURA DE DADOS
-----------------------------------------------------------------------------------------------------------*/
typedef enum boolean {true = 1, false = 0} Boolean;

typedef struct 
{
    int chave;
    int valor;
    int prioridade;
}TItem;

typedef struct
{
    TItem *item;
    int nElementos;
}THeap;

/*----------------------------------------------------------------------------------------------------------
                                            
-----------------------------------------------------------------------------------------------------------*/
void inicializar(THeap *h)
{
    h->nElementos = 0;
}

Boolean isEmpty(THeap *h)
{
    return (h->nElementos == 0);
}

Boolean isFull(THeap *h)
{
    return (h->nElementos == H_PROFUNDIDADE);
}

/*---------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento no fim do Max-Heap e reconstituir a árvore
Parâmetro Entrada: Heap e o elemento a inserir
Parâmetro de Saída: Heap actualizado
---------------------------------------------------------------------------------------------------*/
void inserirHeap (THeap *h, Titem x, int x)
{
    int pai, filho;
    Boolean sobe;
    h->nElementos++;
    filho = h->nElementos;
    h->item[filho].chave = x;
    pai = filho/2;
    sobe = TRUE;
    
    while((pai > 0) && (sobe))
    {
        if (h->item[pai].prioridade < x.prioridade)
        {
            trocar(&h[pai], &h[filho]);
            filho = pai;
            pai = pai/2;
        }
        else sobe = false;
    }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Remover o elemento da raiz do Heap e reconstituir a árvore
Parâmetro Entrada: Heap e o número elementos inseridos
Parâmetro saída: Heap actualizado e o elemento removido
--------------------------------------------------------------------------------------------------------*/
void removerHeap (THeap *H, Titem *x)
{
    *x = H->item[1];
    H[1] = H->item[H.nElementos];
    H->nElementos--;
    restaurarHeap(1, &H);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Restaurar o Max-Heap
Parâmetro Entrada: Posição restauro e Estrutura do Heap
Parâmetro de Saída: Estrutura de max-Heap restaurada
--------------------------------------------------------------------------------------------------------*/
void restaurarHeap (int i, THeap *H )
{
    while ( i < H->nElementos/2 )
    {
        int filhoEsq = 2*i, filhoDir = 2*i + 1, maiorFilho;
        if ( filhoDir <= H->nElementos ) // se tem filho direito 
        {
            if ( H->item[filhoesq].prioridade < H->item[filhodir].prioridade ) maiorFilho = filhoDir;
            else maiorFilho = filhoesq;
        }
        else maiorFilho = filhoEsq;

        if ( H->item[i].prioridade >= H->item[maiorFilho].prioridade ) break;
        troca (&H[i], &H[maiorFilho]);
        i = maiorFilho; // desce
    }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Ordenar os elementos do Max-Heap
Parâmetro Entrada: Estrutura de um Max-Heap
Parâmetro de saída: Vector ordenado em ordem crescente
-------------------------------------------------------------------------------------------------------*/
void heapSort (THeap *H)
{
    TItem x;
    for ( int i = H->nElementos; i >= 2; i--)
    {
        troca (&H[1], &H[i]);
        T->nElementos--;
        restaurarHeap (1, &H);
    }
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir os elementos no vector de forma a constituir um Max-heap
Parâmetro Entrada: Vector
Parâmetro de Saída: Estrutura de max-heap
Valor de Retorno: Número de elementos inseridos
--------------------------------------------------------------------------------------------------------*/
int ControiHeap (THeap *H )
{
    inicializarHeap (&H);
    THeap dado = LerDados();
    while (dado.chave != SENTINELA )
    {
        if ( cheioHeap(H) )
        {
            printf(“\N Erro: Vector está cheio”);
            return 0;
        }
        inserirHeap (&H dado);
        dado = LerDados();
    }
    return H->nElementos;
}


/*--------------------------------------------------------------------------------------------------------
Objectivo: Restaura os elementos de forma a construir um max-heap
Parâmetro Entrada: vector
Parâmetro de Saída: Estrutura de max-heap
--------------------------------------------------------------------------------------------------------*/
int carregarHeap (THeap *H)
{
    for (int i = H->nElementos/2 ; i >= 1; i--) restaurarHeap (i,&T);
    return H->nElementos;
}




