/*
  Autor: BaziotaBeans
  Hora: 03:10
  Data: 03/09/2018
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : pilhaSequencialSimples.h
Objectivo: Disponibilizar as operações sobre uma pilha sequencial
--------------------------------------------------------------------------------------------------------*/
#ifndef PILHASEQSIMPLE_H_INCLUDED
#define PILHASEQSIMPLE_H_INCLUDED

//---------------------------------------------------------- Definição dos códigos de erro

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define STACK_FULL 1 // Pilha Cheia
#define STACK_EMPTY 2 // Pilha Vazia

#define TAM 100 // Tamanho do vector

//----------------------------------------------------------- Tipo de Dados a ser exportado
typedef struct pilha TPilha;
//------------------------------------------------------------- Protótipos das Funções
// Funções exportadas
void InicializarPilha ( TPilha *pilha );
// inicializa uma Pilha Sequencial
boolean vaziaPilha ( TPilha pilha );
// verifica se a Pilha Sequencial está vazia
boolean cheiaPilha (TPilha pilha);
// verifica se a Pilha Sequencial está cheia
int consultaPilha ( TPilha pilha, int x );
// Devolve o conteudo do elemento que está no topo da pilha
int tamanhoPilha ( Tpilha pilha );
// Devolve o número de elementos inserido numa pilha
int empilhar ( int x, TPilha *pilha );
#endif // PILHASEQ_H_INCLUDED
