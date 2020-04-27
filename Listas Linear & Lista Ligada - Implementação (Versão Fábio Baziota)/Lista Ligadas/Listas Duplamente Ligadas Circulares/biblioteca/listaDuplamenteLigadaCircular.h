/*
  Autor: BaziotaBeans
  Data: 31/08/2018
  Hora: 23:33
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : listaDuplamenteLigadaCircular.h
Objectivo: Disponibilizar as operações comuns sobre uma lista Duplamente Ligada Circular
--------------------------------------------------------------------------------------------------------*/
#ifndef LISTALIGDUPLIGCIR_H_INCLUDED
#define LISTALIGDUPLIGCIR_H_INCLUDED

//---------------------------------------------------------- Definição dos códigos de erro

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define LIST_EMPTY 2 // Lista vazia
#define NO_SPACE 5 // Não há espaço de memória

// Estrutura de Dados
typedef struct lista Tlista;

//------------------------------------------------------------- Protótipos das Funções

// Funções exportadas
int iniciarListaDuplamenteLigada(TLista *lista);
// inicializa uma lista ligada Circular
Boolean vaziaListaDuplamenteLigada(TLista *lista);
// verifica se a lista Sequencial está vazia
void imprimirAtomo(TInfo x);

int imprimirListaDuplamenteLigada(TLista *lista);
// mostrar no ecran o conteudo de todos os seus elemntos
int imprimirListaDuplamenteLigadaRecursivo(TLista *lista, TAtomo *paux);
// mostrar no ecran o conteudo de todos os seus elemntos recursivo
TAtomo *BuscarAtomo ( TLista *lista, int chave );
// Encontrar um átomo dado uma chave
TAtomo *BuscarAtomoRecursivo ( TLista *lista, int chave, TAtomo *paux);
// Encontrar um átomo dado uma chave recursivamente
int inserirChaveListaDupla ( TInfo x, TLista *lista );
int inserirAtomoFim ( TInfo x, TLista *lista );
// Inserir um átomo como essa informação no fim de uma lista ligada Circular Com Cabeca
int inserirAtomoDireita ( TInfo x, TLista *lista );
// Inserir um átomo como essa informação na direita de uma lista ligada Circular
int inserirAtomoOrdenado ( TInfo x, TLista *lista, int chave );
// Inserir um átomo como essa informação no meio de uma lista ligada Circular
int removerAtomoChave (TLista *lista, TInfo *x, int chave);
// Remover um átomo dado uma chave

#endif
