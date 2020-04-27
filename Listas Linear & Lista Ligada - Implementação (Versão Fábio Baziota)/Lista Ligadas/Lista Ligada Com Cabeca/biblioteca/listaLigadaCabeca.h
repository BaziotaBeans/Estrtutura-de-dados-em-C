/*
  Autor: BaziotaBeans
  Data: 13/08/2018
  Hora: 23:02
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : listaLigada.h
Objectivo: Disponibilizar as operações comuns sobre uma lista Ligadas
--------------------------------------------------------------------------------------------------------*/
#ifndef LISTALIGCAB_H_INCLUDED
#define LISTALIGCAB_H_INCLUDED

//---------------------------------------------------------- Definição dos códigos de erro

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define LIST_EMPTY 2 // Lista vazia
#define NO_SPACE 5 // Não há espaço de memória


//----------------------------------------------------------- Tipo de Dados a ser exportado
typedef struct lista Tlista;
// Estrutura de Dados


typedef enum { FALSE = 0, TRUE= 1 } Boolean;

// Funções exportadas
int iniciarListaCabeca(TLista *lista);
// inicializa uma lista cabeca
Boolean vaziaListaLigadaCabeca(TLista *lista);
// Verifica se uma lista esta vazia
TAtomo* BuscarAtomo(TLista *lista, int chave)
// Busca um atomo dado uma chave
int inserirDireira(TLista *lista, TInfo x);
// Insere um atomo na lista na direita
int inserirFim(TLista *lista, Tinfo x);
// insere um atomo na lista no fim
int inserirOrdenandoMeio(TLista *lista, TInfo x, int chave);
// insere uma atomo no meio da lista de forma ordenada
int remocaoListaCabeca(TLista *lista, TInfo *x, int chave);
// remove um atomo de uma lista dado a chave

#endif
