/*

      AUTOR: BAZIOTABEANS A.K.A 007
      HORA: 03:00
      Data: 10/10/2018
      Descricao: Projecto II de Algoritmo e Complexidade (ESTRUTURA DE DADOS) - DOMINO

*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : domino.h
Objectivo: Disponibilizar as operações comuns sobre um domino
--------------------------------------------------------------------------------------------------------*/
#ifndef DOMINO_H_INCLUDED
#define DOMINO_H_INCLUDED
/*--------------------------------------------------------------------------------------------
                                    Definição dos códigos de erro
--------------------------------------------------------------------------------------------*/

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define LIST_EMPTY 2 // Lista vazia
#define NO_SPACE 5 // Não há espaço de memória

/*--------------------------------------------------------------------------------------
			                               Estruturas de Dados - Pre-Declaradas
--------------------------------------------------------------------------------------*/
typedef enum boolean Boolean;
typedef struct peca TPeca;
typedef struct atomo TAtomo;
typedef struct lista TLista;
typedef struct jogada TJogada;
/*------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
			                               Protótipos das Funções

			                               Funções Exportadas
--------------------------------------------------------------------------------------*/
TJogada* criar();
// cria um atomo de lista
TJogada* recriar(TJogada *jogada, int nJogada);
// realoca o tamanho do atomo (vector de lista)
void iniciarLiista(TLista *lista);
// inicializa uma lista
Boolean isEmpty(TJogada *jogada, int i);
// Verificar se a lista esta vazia
int inserirDireita (TJogada *jogada, TPeca *x, int i);
// inserir um atomo a direita dada um informacao e a posicao no vector
int imprimirLista(TJogada *jogada, int i);
// Imprimir a lista
int imprimirGeral(TJogada *jogada);
// Imprimir a lista
TPeca* lerPecas();
// ler pecas e validar
int lerQuantidadePecas();
// Ler quantidade de pecas e validar
int ordenarDomino (TJogada *jogada, int i);
// ordenar o domino por completo
void trocarDados (TPeca *peca);
// Trocar as pecas x e y dentro de um atomo
void ligarLinksDireita (TLista *lista, TAtomo *peca, TAtomo *proximaPeca);
// ordenar a lista da direita
void ligarLinksEsquerda (TLista *lista, TAtomo *peca);
// ordenar a lista da esquerda
void trocarAntes (TLista *lista, TAtomo *proximaPeca, TAtomo *peca);
// troca as ligacoes dos ponteiros antes
void trocarDepois (TLista *lista, TAtomo *proximaPeca, TAtomo *peca);
// troca as ligacoes dos ponteiros depois
Boolean verificarDomino (TLista lista);
// verificar se o domino esta ordenado ou nao
void liberar(TJogada *jogada);
// funcao para liberar o ponteiro TJogada
void numeroDesordenado(TLista *lista, TJogada *jogada, int i);
// Ordenar as pecas desordenadas em funcao das pecas quantidade das pecas desordenadas
int numeroPecasDesordenado (TLista *lista);
// Retorna o numero de pecas desordenadas
/*--------------------------------------------------------------------------------------
			                               Fim Declaração de Funções
--------------------------------------------------------------------------------------*/
#endif
