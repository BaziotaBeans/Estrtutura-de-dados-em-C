/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : listaSequencial.h
Objectivo: Disponibilizar as operações comuns sobre uma lista sequencial
--------------------------------------------------------------------------------------------------------*/

#ifndef LISTASEQ_H_INCLUDED
#define LISTASEQ_H_INCLUDED


//---------------------------------------------------------- Definição dos códigos de erro

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define LIST_FULL 1 // Lista cheia
#define LIST_EMPTY 2 // Lista vazia
#define INVALID_INDEX 3 // Indice Inválido
#define TAM 10 // Tamanho do vector

//----------------------------------------------------------- Tipo de Dados a ser exportado
typedef struct lista TLista;
typedef struct x TItem;
//typedef struct lista TLista;


typedef enum { FALSE= 0, TRUE= 1 } boolean;
//------------------------------------------------------------- Protótipos das Funções


// Funções exportadas
void inicializarLista (TLista *lista);
// inicializa uma lista Sequencial
boolean vaziaLista (TLista *lista);
// verifica se a lista Sequencial está vazia
boolean cheiaLista (TLista *lista);
// verifica se a lista Sequencial está cheia
int consultarElemento (TLista lista, int pos, TItem *x);
// dado um índice, devolve o conteudo desse elemento
int BuscarElemento (TLista lista, int x);
// dado uma chave, procurar o elemento que contêm essa chave
int inserirElemento (TLista *lista, int pos, TItem x);
// inserir na lista um elemento numa determinada posição
int inserirElementoInicio (TLista *lista, TItem x);
// inserir no inicio da lista
int inserirElementoFim (TLista *lista, TItem x);
// inserir elemento no fim da lista
int imprimirElementos(TLista *lista);
// mostrar no ecran o conteudo de todos os seus elemntos
int removerElemento (TLista *lista, int pos, TItem *x);
// remover da lista o elemento que está numa determinada posição
void mensagemErro (int codret );
int lerNumValor();
// Ler o valor
int lerNumChave();
// Ler a chave
void inserir(TLista *lista, TItem x);
void imprimir(TLista *lista);
#endif // LISTASEQ_H_INCLUDED
