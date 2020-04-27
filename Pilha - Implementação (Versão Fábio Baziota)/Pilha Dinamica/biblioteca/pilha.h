/*
  Autor: Baiota Beans
  Data: 09/09/2018
  Hora: 21:41
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : pilha.h
Objectivo: Disponibilizar as operações sobre uma pilha dinamica
--------------------------------------------------------------------------------------------------------*/
#ifndef PILHADIM_H_INCLUDED
#define PILHADIM_H_INCLUDED
// Códigos de erro
#define NOT_FOUND -1// Item não existe
#define OK 0 // Operação realizada com sucesso
#define STACK_EMPTY 2 // Pilha vazia
#define NO_SPACE 5 // Não há espaço de memória

// Faça como exercício
// Estrutura de dados
typedef struct
{
  int chave;
  float valor;
}TInfo;
typedef struct apontador
{
  TInfo info;
  apontador *prox;
}TAtomo;

typedef struct
{
  TAtomo * topo;
}TPilhaDinamic;

typedef enum { FALSE = 0, TRUE = 1 } Boolean;

#endif // PILHASEQ_H_INCLUDED
