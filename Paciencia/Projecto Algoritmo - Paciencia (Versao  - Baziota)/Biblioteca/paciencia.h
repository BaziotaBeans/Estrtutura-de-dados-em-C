/*
  Autor: Baiota Beans
  Data: 01/11/2018
  Hora: 15:25
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : paciencia.h
Objectivo: Disponibilizar as operações sobre uma pilha dinamica
--------------------------------------------------------------------------------------------------------*/
#ifndef PACIENCIA_H_INCLUDED
#define PACIENCIA_H_INCLUDED
// Códigos de erro
#define NOT_FOUND -1// Item não existe
#define OK 0 // Operação realizada com sucesso
#define STACK_EMPTY 2 // Pilha vazia
#define NO_SPACE 5 // Não há espaço de memória
#define BARALHO_IS_EMPTY 6
#define INVALID_INDEX 7;
// Constantes - Cartas

#define MAX_MOVIMENTACAO 1000

#define A 1
#define J 11
#define Q 12
#define K 13

// Constantes - Naipe
#define CORACAO C
#define ESPADA E
#define OURO O
#define PAUS P

#define COR_VERMELHA 14
#define COR_PRETO 15

#define MAX_BARALHO 52

// Estrutura de dados
typedef struct carta TCarta;
typedef struct baralho TBaralho;
typedef struct pointer TAtomo;
typedef struct pilha TPilhaDinamic;
typedef enum boolean Boolean;

TBaralho* criarBaralho ();
TPilhaDinamic* criarPilha ();
void iniciaPilhaDinamica ( TPilhaDinamic *pilha );
Boolean vaziaPilhaDinamica(TPilhaDinamic *pilha);
int empilhar ( TPilhaDinamic *pilha , TCarta x );
int desempilhar ( TPilhaDinamic *pilha, TCarta *x );
//int imprimirPilha (TPilhaDinamic *pilha);
void imprimirPilha (TPilhaDinamic *pillha);
int autoInserting(TBaralho *baralho);
int carregar(TBaralho *baralho, int i, int peso, char cor, char naipe);
void imprimirBaralho(TBaralho *baralho);
TBaralho* embaralharCarta(TBaralho *baralho);
int removerElemento (TBaralho *baralho, int pos, TCarta *x);
Boolean isEmpty(TBaralho *baralho);
void simulation1();
TCarta *criarCarta();
void simulation2(TBaralho *baralho);
int inserir(TPilhaDinamic *pilha, int pos, TBaralho *baralho);
int distribuirParaPilhaJogada(TPilhaDinamic *pilha,TBaralho *baralho);
int distribuirParaPilhaEstoque(TPilhaDinamic *pilha,TBaralho *baralho);
Boolean isOrder(TPilhaDinamic *pilha);
int empilharAux(TPilhaDinamic *pOrigem, TPilhaDinamic *pDestino, int i);
void insert(TPilhaDinamic *pilha, TBaralho *baralho);
void simulation3 ();
Boolean validSaidaStack(TPilhaDinamic *p1, TPilhaDinamic *p2, TPilhaDinamic *p3, TPilhaDinamic *p4);
int contar (TPilhaDinamic *pilha);
int movimentar(TPilhaDinamic *pilhaOrigem, TPilhaDinamic *pilhaDestino);
int compararA(TPilhaDinamic *stack1, Boolean *estado, TPilhaDinamic *stack2);
void abrir(TPilhaDinamic *pilha);
int comparar(TPilhaDinamic *stack1, Boolean *estado, TPilhaDinamic *stack2);
//int ler
#endif // PILHASEQ_H_INCLUDED
