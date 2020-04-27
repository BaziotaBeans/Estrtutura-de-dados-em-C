/*
  Autor: BaziotaBeans
  Data: 09/08/2018
  Hora: 03:19
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : listaLigada.h
Objectivo: Disponibilizar as operações comuns sobre uma lista Ligadas
--------------------------------------------------------------------------------------------------------*/
#ifndef LISTALIG_H_INCLUDED
#define LISTALIG_H_INCLUDED

//---------------------------------------------------------- Definição dos códigos de erro

#define NOT_FOUND -1 // Item não existe
#define OK 0 // Operação realizada com sucesso
#define LIST_EMPTY 2 // Lista vazia
#define NO_SPACE 5 // Não há espaço de memória


//----------------------------------------------------------- Tipo de Dados a ser exportado
//typedef struct lista *Tlista; //Encapsulamento
// Estrutura de Dados
typedef struct
{
  int chave;
  int valor;
}TInfo;

typedef struct Atomo
{
  TInfo info;
  struct Atomo *prox;
}TAtomo;

typedef struct
{
  TAtomo *primeiro;
  TAtomo *ultimo;
}TLista;
typedef enum { FALSE = 0, TRUE= 1 } Boolean;
//------------------------------------------------------------- Protótipos das Funções

// Funções exportadas
void iniciarListaLigada ( TLista *lista );
// inicializa uma lista Ligada
Boolean vaziaListaLigada ( TLista *Lista );
// verifica se a lista Sequencial está vazia
void imprimirListaLigada (TLista *lista);
// mostrar no ecran o conteudo de todos os seus elemntos
//void imprimirListaLigadaRecursiva ( TAtomo *paux )
// mostrar no ecran o conteudo de todos os seus elemntos(RECURSIVO)
TAtomo *BuscarAtomo ( TLista *lista, int chave );
// Encontrar um átomo dado uma chave
int inserirAtomoFim ( TInfo x, TLista *lista );
// Inserir um átomo como essa informação no fim de uma lista ligada
int inserirOrdenando (TLista *lista, Tinfo x, int chave);
// Inserir um átomo de forma ordenada
int inserirAntesDaChave(TLista *lista, Tinfo x, int chave);
// Inserir um átomo antes da chave dada
int inserirDepoisDaChave(TLista *lista, Tinfo x, int chave);
// Inserir um átomo depois da chave dada
int inserirAtomoInicio ( TInfo x, TLista *lista );
// Inserir um átomo no inicio da lista
int removerAtomoChave (TLista *lista, int *x, int chave);
// Remover um átomo dado uma chave
void imprimirAtomo(TAtomo *paux);
#endif // LISTALIG_H_INCLUDED
