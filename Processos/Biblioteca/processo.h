/*
  Autor: 
  Data: 04/11/2018
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
#define TAMANHO 100


/*********************************Encapsulamento********************************************************/
typedef struct info TInfo;
typedef struct apontador TAtomo;
typedef struct fila TFilaDinamic;
typedef enum boolean Boolean;
/*********************************Fim Encapsulamento********************************************************/

//Funcoes Exportadas


TFilaDinamic* criar();
void iniciaFilaDinamica (TFilaDinamic *fila);
Boolean vaziaFilaDinamica (TFilaDinamic *fila);
int inserirFilaDinamica (TFilaDinamic *fila, TInfo *x);
int removerFilaDinamica (TFilaDinamic *fila, TInfo *x);
Boolean existe(TFilaDinamic *fila, int tempoDuracao);
int removerId(TFilaDinamic *fila, int tempoDuracao);
Boolean filaUnitaria(TFilaDinamic *fila);
void imprimir(TFilaDinamic *fila);
int lerTempo();
int lerID();
void inserirProcesso(TFilaDinamic *fila);
int lerQuantidadeProcesso();
int removerMaior(TFilaDinamic *fila);
void liberar(TFilaDinamic *fila);

#endif
