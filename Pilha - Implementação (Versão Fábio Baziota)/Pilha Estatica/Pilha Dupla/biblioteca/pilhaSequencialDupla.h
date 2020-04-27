/*
  Autor: Baiota Beans
  Data: 09/09/2018
  Hora: 17:15
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : pilhaSequencialDuplo.h
Objectivo: Disponibilizar as operações sobre uma pilha sequencial
--------------------------------------------------------------------------------------------------------*/
#ifndef PILHASEQDUPLO_H_INCLUDED
#define PILHASEQDUPLO_H_INCLUDED

//---------------------------------------------------------- Definição dos códigos de erro

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define STACK_FULL 1 // Pilha Cheia
#define STACK_EMPTY 2 // Pilha Vazia

#define TAM 100 // Tamanho do vector

//----------------------------------------------------------- Tipo de Dados a ser exportado
typedef struct pilha TPDupla;
//------------------------------------------------------------- Protótipos das Funções
// Funções exportadas
void inicializarPilhaDupla ( TPDupla *pilha );
// inicialiizar uma pilha dupla
int tamanhoPilhaDupla ( TPDupla pilha, int np );
// ver o tamanho da pilha dupla
Boolean pilhaDuplaVazia ( TPDupla pilha, int np );
// Verificar se uma pilha dupla está vazia
Boolean pilhaDuplaCheia ( TPDupla pilha )
// Verificar se a pilha está cheia
int empilhar ( TPDupla *pilha, TItem x, int np );
// Inserir um elemento numa pilha dupla
int desempilhar (TDUpla *pilha, TItem *x, int np)
// Remover um elemento que está no topo da pilha dupla
int acessoPilha ( TPilha pilha, int *x );
// Consultar um elemento da pilha dupla
#endif
