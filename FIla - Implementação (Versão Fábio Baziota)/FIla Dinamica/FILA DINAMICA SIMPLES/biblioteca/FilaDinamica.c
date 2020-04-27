/*
  Autor: BaziotaBeans
  Data: 17/09/2018
  Hora: 23:40
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : filaDinamica.c
Objectivo: Implementação da TDA fila dinamica e disponibilizas as suas operacoes basicas
--------------------------------------------------------------------------------------------------------*/
#include "FilaDinamica.h"
#include <stdio.h>
 


typedef struct info
{
    int chave;
    int valor;
}TInfo;

typedef struct atomo
{
    TInfo info;
    apontador *prox;
}TAtomo;

typedef struct fila
{
    TAtomo * frente;
    TAtomo *fundo;
} TFilaDinamic;



    

/*--------------------------------------------------------------------------------------------------------
Objectivo: Inicializar uma fila em organização dinâmica
Parâmetro Entrada Uma fila
Parâmetro de saída: fila dinâmica com ponteiros actualizados.
------------------------------------------------------------------------------------------------------ */
void iniciaFilaDinamica (TFilaDinamic *fila)
{
    fila->frente = NULL;
    fila->fundo = NULL;
}

/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a fila está vazia
Parâmetro Entrada: Uma fila
Valor de Retorno: True ou False
------------------------------------------------------------------------------------------------------- */
Boolean vaziaFilaDinamica (TFilaDinamic *fila)
{
    return (fila->frente == NULL && fila->fundo == NULL);
}



/*-----------------------------------------------------------------------------------------------------
Objectivo: Inserir um átomo com uma determinada informação no fim da fila
Parâmetro Entrada: Uma fila e uma determinada informação
Parâmetro de Saída: Fila actualizada
Valor de Retorno: Código de erro ( NO_SPACE ou OK)
---------------------------------------------------------------------------------------------------- */
int inserirFilaDinamica (TFilaDinamic *fila, TInfo x)
{
    TAtomo *pnovo = (TAtomo *) malloc( sizeof(TAtomo));
    if (pnovo == NULL) return NO_SPACE;
    pnovo->info = x;
    pnovo->prox = NULL;
    if ( vaziaFilaDinamica(fila))
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
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover o átomo que está no ínicio da fila
Parâmetro Entrada: Uma fila
Parâmetro de Saída: Fila actualizada e a informação removida
Valor de Retorno: Código de erro (QUEUE_EMPTY ou OK)
-------------------------------------------------------------------------------------------------------*/
int removerFilaDinamica (TFilaDinamic *fila, TInfo *x)
{
    if ( vaziaFilaDinamica(fila)) return QUEUE_EMPTY;
    TAtomo *pdel = fila->frente;
    *x = fila->frente->info;
    if (filaUnitaria(fila)) InicializaFilaDinamica(fila);
    else
    fila->frente = fila->frente->prox;
    free(pdel);
}


