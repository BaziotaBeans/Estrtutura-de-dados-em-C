/*
  Autor: BaziotaBeans
  Data: 17/09/2018
  Hora: 23:40
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : filaDinamica.h
Objectivo: Implementação da TDA fila dinamica e disponibilizas as suas operacoes basicas
--------------------------------------------------------------------------------------------------------*/
#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED
/*Códigos de Erros*/
#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define QUEUE_EMPTY 2 // Fila vazia
#define NO_SPACE 5 // Não há espaço de memória

// Estrutura de Dados



typedef enum { FALSE= 0, TRUE= 1 } Boolean;

typedef boolean Boolean;
typedef info TInfo;
typedef atomo TAtomo;
typedef fila TFilaDinamic;



void iniciaFilaDinamica (TFilaDinamic *fila);
Boolean vaziaFilaDinamica (TFilaDinamic *fila);
int inserirFilaDinamica (TFilaDinamic *fila, TInfo x);
int removerFilaDinamica (TFilaDinamic *fila, TInfo *x);

#endif


