/*------------------------------------------------------------------------------
Nome do arquivo interface: operacoesLista.c
Objectivo: disponibilizar a estrutura e os m�todos para manipular listas
------------------------------------------------------------------------------*/

#include "operacoesLista.c"
#ifdef OPERACOES_LISTA_H
#define OPERACOES_LISTA_H

//Objectivo: Verificar se a lista Sequencial est� vazia
boolean VaziaLista(TLista lista);

//Objectivo: Verificar se a Lista Sequencial est� cheia
boolean CheiaLista(TLista lista);

//Objectivo: Criar uma estrutura de dados do tipo Lista Sequencial
void InicializarLista(TLista *lista);

//Objectivo: Imprimir o conteudo de todos os elementos dessa estrutura
void ImprimirLista(TLista lista);

//Objectivo:Consultar a informa��ode um determinado elemento
int ConsultarLista(TLista lista, TItem *x, int pos);

//Objectivo: Inserer um elemento nessa posi��o
int InserirNumaPosicao(TItem item, int pos, TLista *lista);

//Objectivo: Inserer um elemento nessa posi��o
int Inserir(TItem item, TLista *lista);

//Objectivo: Remover o elemento que est� nessa posi��o
int RemoverElemento (int pos, TLista *lista, TItem *item);

//Objectivo: Procurar o elemento na lista
int buscaSequencial( int x, TLista lista);

//Objectivo: Calcular o n�mero de elementos de uma lista sequencial
int TotalElementos( int i, int f, TLista lista);

//Objectivo: Calcular o n�mero de zeros de uma lista sequencial
int TotalZeros( int i, int f, TLista lista);

//Objectivo: Calcular o n�mero de zeros de uma lista sequencial
int zeros (int i, int f, TLista lista);

#endif

