/*
    Autor: BaziotaBeans
    Data: 14/10/2018
    Hora: 18:16
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : arvoreBuscaBinaria.h
Objectivo: Implementação da TDA árvore de busca binária dinâmica e as suas operações                             */


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

TAtomo *busca(TAB *arvore, int x);
TAtomo *buscaRecursiva(TAB *arvore, int x, TAtomo *pbusca);
TAtomo *criarFolha(TInfo x);
#endif






