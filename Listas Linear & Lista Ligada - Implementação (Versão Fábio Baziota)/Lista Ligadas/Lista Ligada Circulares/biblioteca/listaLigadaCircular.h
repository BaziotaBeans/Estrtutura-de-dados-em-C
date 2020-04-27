/*
  Autor: BaziotaBeans
  Data: 30/08/2018
  Hora: 16:09
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : listaLigadaCircular.h
Objectivo: Disponibilizar as operações comuns sobre uma lista Ligada Circular
--------------------------------------------------------------------------------------------------------*/
#ifndef LISTALIGCIRC_H_INCLUDED
#define LISTALIGCIRC_H_INCLUDED


//---------------------------------------------------------- Definição dos códigos de erro

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define LIST_EMPTY 2 // Lista vazia
#define NO_SPACE 5 // Não há espaço de memória

// Estrutura de Dados
typedef struct lista Tlista;

//------------------------------------------------------------- Protótipos das Funções

// Funções exportadas
void iniciarListaLigadaCircular(TLista *lista);
// inicializa uma lista ligada Circular
Boolean vaziaListaLigadaCircular(TLista *lista);
// verifica se a lista Sequencial está vazia
int imprimirListaLigadaCircular (TLista *lista);
// mostrar no ecran o conteudo de todos os seus elemntos
TAtomo *BuscarAtomo ( TLista *lista, int chave );
// Encontrar um átomo dado uma chave
int inserirAtomoFim ( TInfo x, TLista *lista );
// Inserir um átomo como essa informação no fim de uma lista ligada Circular
int inserirAtomoDireita ( TInfo x, TLista *lista );
// Inserir um átomo como essa informação na direita de uma lista ligada Circular
int inserirAtomoNoMeio ( TInfo x, TLista *lista, int chave );
// Inserir um átomo como essa informação no meio de uma lista ligada Circular
int removerAtomoChave (TLista *lista, TInfo *x);
// Remover um átomo dado uma chave
#endif
