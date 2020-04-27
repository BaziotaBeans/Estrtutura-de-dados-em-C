#include <stdio.h>
#include "listaSequencial.h"


typedef struct
{
  int chave;
  int valor;
}TItem;

typedef struct
{
  TItem item[TAM];
  int ultPos;
} TLista;


/*-------------------------------------------------------------------------------------------------------
Objectivo: Criar uma estrutura de dados do tipo lista sequencial
Parâmetro Entrada: Lista sequencial
Parâmetro de saída: Lista sequencial
------------------------------------------------------------------------------------------------------- */
void inicializarLista (TLista *lista)
{
  lista->ultPos = -1;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a lista sequencial está vazia
Parâmetro Entrada: Lista sequencial
Retorno da Função: Verdadeiro ou falso
--------------------------------------------------------------------------------------------------------*/
boolean vaziaLista (TLista *lista)
{
  return ( lista->ultPos == -1 );
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a lista sequencial está cheia
Parâmetro Entrada: Lista sequencial
Retorno da Função: Verdadeiro ou falso
--------------------------------------------------------------------------------------------------------*/
boolean cheiaLista (TLista *lista)
{
  return ( lista->ultPos == TAM - 1);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo:Consultar a informação elemento dado uma posição
Paramatro Entrada: Lista sequencial e posição de consulta
Parâmetro de saída: O conteudo do elemento que está nessa posição
Retorno da Função: Código de erro: INVALID_INDEX ou OK
--------------------------------------------------------------------------------------------------------*/
int consultarElemento (TLista lista, int pos, TItem *x)
{
  if ( pos < 0 || pos > lista.ultPos) return INVALID_INDEX;
  *x = lista.item[pos];
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Procurar um elemento dado uma chave
Paramatro Entrada: Lista sequencial e chave de busca
Retorno da Função: -1 se o elemento não existe ou
posição relativa do elemento na lista
--------------------------------------------------------------------------------------------------------*/
int buscarElemento (TLista lista, int x)
{
  for (int i = 0; i <= lista.ultPos; i++)
    if (lista.item[i].chave == x ) return i;
  return NOT_FOUND;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento numa determinada posição da lista.
Parâmetro Entrada: Elemento a inserir, posição de inserção e a lista
Parâmetro de Saída: Lista actualizada.
Retorno da Função: Código de erro: LISTA_FULL, INVALID_INDEX ou OK.
--------------------------------------------------------------------------------------------------------*/
int inserirElemento (TLista *lista, int pos, TItem x)
{
  if (cheiaLista(lista)) return LIST_FULL;
  if (vaziaLista(lista)) return LIST_EMPTY;
  if ( pos < 0 || pos > lista->ultPos+1 ) return INVALID_INDEX;
  for ( int aux = lista->ultPos; aux >= pos ; aux-- ) lista->item[aux+1] = lista->item[aux];
  lista->item[pos] = x ;
  //lista->ultPos++;
  lista->ultPos = lista->ultPos + 1;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento no inicio da lista.
Parâmetro Entrada: Elemento a inserir e a lista
Parâmetro de Saída: Lista actualizada.
Retorno da Função: Código de erro: LISTA_FULL, INVALID_INDEX ou OK.
--------------------------------------------------------------------------------------------------------*/
int inserirElementoInicio (TLista *lista, TItem x)
{
  if (cheiaLista(lista)) return LIST_FULL;
  for (int aux = lista->ultPos; aux >= 0; aux--) lista->item[aux+1] = lista->item[aux];
  lista->item[0] = x;
  lista->ultPos = lista->ultPos + 1;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Inserir um elemento no fim da lista.
Parâmetro Entrada: Elemento a inserir e a lista
Parâmetro de Saída: Lista actualizada.
Retorno da Função: Código de erro: LISTA_FULL, INVALID_INDEX ou OK.
--------------------------------------------------------------------------------------------------------*/
int inserirElementoFim (TLista *lista, TItem x)
{
  if (cheiaLista(lista)) return LIST_FULL;
  lista->item[lista->ultPos + 1] = x;
  lista->ultPos = lista->ultPos + 1;
  return OK;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Imprimir o conteudo de todos os elementos da Lista Sequencial
Parâmetro Entrada Lista Sequencial
Valor de Retorno: Código de erro: LIST_EMPTY ou OK.
-------------------------------------------------------------------------------------------------------*/
int imprimirElementos (TLista *lista)
{
  if (vaziaLista(lista)) return LIST_EMPTY;
  for (int i = 0; i <= lista->ultPos; i++) printf( " (Chev: %d|Valor: %d)-> ", lista->item[i].chave, lista->item[i].valor);
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Remover um elemento de uma posição qualquer da lista
Parâmetro Entrada: Posição do elemento a remover a a lista sequencial
Parâmetro de Saída: Lista actualizada e o conteúdo do elemento removido
Valor de Retorno: Código de erro: LIST_EMPTY, INVALID_KEY ou OK
--------------------------------------------------------------------------------------------------------*/
int removerElemento (TLista *lista, int pos, TItem *x)
{
  if ( vaziaLista(lista) ) return LIST_EMPTY;
  if (pos < 0 || pos > lista->ultPos )  return INVALID_INDEX;
  *x = lista->item[pos];
  for ( int aux= pos; aux <= lista->ultPos-1; aux ++ ) lista->item[aux] = lista->item[aux+1];
  lista->ultPos--;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Imprimir as mensagens do módulo
Parâmetro Entrada: Código do erro
--------------------------------------------------------------------------------------------------------*/
void mensagemErro (int codret )
{
  switch (codret)
  {
    case NOT_FOUND:
    printf( "\nErro: Código não existe" );
    break;
    case LIST_FULL:
    printf( "\n Erro: Lista Cheia" );
    break;
    case LIST_EMPTY:
    printf( "\n Erro: Lista Vazia" );
    break;
    case INVALID_INDEX:
    printf( "\n Erro: Indice Invalido" );
    break;
  }
}

int lerNumValor()
{
  int n;
  printf("\nDigite o valor do elemento: "); scanf("%d",&n);
  return n;
}

int lerNumChave()
{
  int n;
  printf("\nDigite a chave: "); scanf("%d",&n);
  while(1)
  {
      if ((n >= 1) && (n <= TAM)) return n;
      printf("\nERRO: valor da chave nao pode ser negativo \nDigite novamente a chave: "); scanf("%d",&n);
  }
}

void inserir(TLista *lista, TItem x)
{
  for(int i = 0; i <= TAM - 1; i++)
  {
    lista->ultPos = lista->ultPos + 1;
    lista->item[lista->ultPos] = x;
  }
}

void imprimir(TLista *lista)
{
  for(int i = 0; i <= lista->ultPos; i++) printf( " (Chev: %d|Valor: %d)-> ", lista->item[i].chave, lista->item[i].valor);
}
