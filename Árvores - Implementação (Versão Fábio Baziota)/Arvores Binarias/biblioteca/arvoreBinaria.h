/*
    Autor: BaziotaBeans
    Data: 13/10/2018
    Hora: 22:23
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : arvoreBinaria.h
Objectivo: Implementação da TDA árvore binária dinâmica e as suas operações                             */


#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

/*----------------------------------------------------------------------------------------------------------
                                            Códigos de Erro
-----------------------------------------------------------------------------------------------------------*/


#define NOT_FOUND -1 //Item não existe
#define OK 0         //Operação realizada com sucesso
#define TREE_EMPTY 2 //Arvore vazia
#define NO_SPACE 5   //Não há espaço na memória
#define DESCENDING_FOUND 1 //Encontrou um descendente
#define DESCENDING_NOT_FOUND 3//Não encontrou o descendente
#define NOT_FOUND_FATHER 4
#define NOT_FOUND_TERMINAL 6
#define NOT_TERMINAL 7  


/*----------------------------------------------------------------------------------------------------------
                                            ESTRUTURA DE DADOS
-----------------------------------------------------------------------------------------------------------*/

typedef struct arvore TAB;
typedef struct x TInfo;
typedef struct raiz TAtomo;

typedef enum {true = 1, false = 0} Boolean;


/*----------------------------------------------------------------------------------------------------------
                                            FUNÇÕES EXPORTADAS
-----------------------------------------------------------------------------------------------------------*/

void iniciaArvoreBinaria (TAB *arvore);
int iniciaAtomoRaiz (TAB *arvore, TInfo x);
Boolean VaziaArvoreBinaria (TAB *arvore);
int inserirFilhoEsquerdo (TAB *arvore, TInfo x, int chavepai);
int removerFolha (TAB *arvore, TInfo * x, int chavepai, int chave);
void visitaAtomo (int x);
void preOrdemRecursivo (TAtomo *raiz);
int preOrdemIterativo (TAtomo *raiz);
void inOrdemRecursivo (TAtomo *raiz);
int inOrdemIterativo (TAtomo *raiz);
void posOrdemRecursivo(TAtomo *raiz);
int posOrdemIterativo(TAtomo *raiz);
int contaAtomos (TAtomo *raiz);
TAtomo *copiaArvore (TAtomo *raiz );
Boolean iguais (TAtomo *raiz1, TAtomo *raiz2);
void visitaNivel (TAtomo *raiz, int nivel);
int maximo (TAtomo *raiz);
int altura (TAtomo *raiz);
Boolean constroiRaiz (TAtomo *raiz );
TAtomo *constroiSubArvore (TAtomo *raiz );

#endif






