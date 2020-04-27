/*
    Autor: BaziotaBeans
*/


/*------------------------------------------------------------------------------
Nome do arquivo interface: operacoesLista.h
Objectivo: disponibilizar os códigos de erro para listas e pilhas
------------------------------------------------------------------------------*/

#include <stdio.h>

#define LIST_EMPTY         -3
#define INVALID_INDEX      -2
#define NOT_FOUND          -1
#define OK                  0
#define LIST_FULL           1
#define TAM               100

typedef struct
{
	int chave;
	int valor;
}TItem;

typedef struct
{
	TItem item[TAM];
	int ultimo;
}TLista;

typedef enum {false,true}boolean;

/*---------------------------------------------------------------------------------------------------
Recebe : Lista Sequencial
Objectivo: Verificar se a lista Sequencial está vazia
Devolve : Verdadeiro ou Falso
---------------------------------------------------------------------------------------------------*/
boolean VaziaLista(TLista lista)
{
	return (lista.ultimo == -1 );
}
/*---------------------------------------------------------------------------------------------------
Recebe: Lista Sequencial
Objectivo: Verificar se a Lista Sequencial está cheia
Devolve : Verdadeiro ou Falso
---------------------------------------------------------------------------------------------------*/
boolean CheiaLista(TLista lista)
{
	return (lista.ultimo == TAM - 1);
}
/*------------------------------------------------------------------------------
Recebe: O vector Lista
Objectivo: Criar uma estrutura de dados do tipo Lista Sequencial
Devolve: Lista Sequencial com o índice ultimo inicializado
------------------------------------------------------------------------------*/
void InicializarLista(TLista *lista)
{
	lista->ultimo = -1;
}
/*---------------------------------------------------------------------------------------------------
Recebe: Lista Sequencial
Objectivo: Imprimir o conteudo de todos os elementos dessa estrutura
Devolve : Nada
---------------------------------------------------------------------------------------------------*/
void ImprimirLista(TLista lista)
{
	int i;
	printf ("\nConteudo da lista\n");
	for (i = 0; i <= lista.ultimo; i++)
		printf("Item %d -> Chave: %d  valor: %d \n", i, lista.item[i].chave, lista.item[i].valor);
}
/*---------------------------------------------------------------------------------------------------
Recebe: Lista sequencial e uma determinada posição
Objectivo:Consultar a informaçãode um determinado elemento
Devolve: Conteudo do elemento e código de erro
---------------------------------------------------------------------------------------------------*/
int ConsultarLista(TLista lista, TItem *x, int pos)
{
	if (VaziaLista(lista)) return LIST_EMPTY;
	else
	{
		*x = lista.item[pos];
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: O elemento a inserir, a posição de inserção e a Lista Sequencial
Objectivo: Inserer um elemento nessa posição
Devolve: Lista actualizada e o código de erro
---------------------------------------------------------------------------------------------------*/
int InserirNumaPosicao(TItem item, int pos, TLista *lista)
{
	if (CheiaLista(*lista)) return LIST_FULL;
	else if ( pos < 0 || pos > lista->ultimo+1 ) return INVALID_INDEX;
	else 
	{
		int aux;
		for ( aux= lista->ultimo; aux >= pos ; aux -- )
			lista->item[aux+1] = lista->item[aux];
		lista->item[pos] = item ;
		lista->ultimo++;
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: O elemento a inserir, a posição de inserção e a Lista Sequencial
Objectivo: Inserer um elemento nessa posição
Devolve: Lista actualizada e o código de erro
---------------------------------------------------------------------------------------------------*/
int Inserir(TItem item, TLista *lista)
{
	if (CheiaLista(*lista)) return LIST_FULL;
	else 
	{
		lista->item[++lista->ultimo] = item ;
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: Posição do elemento a ser removido e a Lista Sequencial
Objectivo: Remover o elemento que está nessa posição
Devolve : Lista actualizada, o conteúdo do elemento removido e código de erro
---------------------------------------------------------------------------------------------------*/
int RemoverElemento (int pos, TLista *lista, TItem *item)
{
	if (VaziaLista(*lista)) return LIST_EMPTY;
	else if (pos < 0 || pos > lista->ultimo ) return INVALID_INDEX;
	else
	{
		int aux;
		*item = lista->item[pos];
		for ( aux= pos; aux <= lista->ultimo-1; aux ++ )
			lista->item[aux] = lista->item[aux+1];
		lista->ultimo--;
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: O elemento que se quer encontrar e a Lista Sequencial.
Objectivo: Procurar o elemento na lista
Devolve : Se achou devolver o índice do elemento, senão devolver -1
---------------------------------------------------------------------------------------------------*/
int buscaSequencial( int x, TLista lista)
{
	int i;
	for ( i = 0 ; i <= lista.ultimo; i++)
		if (lista.item[i].valor == x)
			return i;
	return NOT_FOUND;
}

/*---------------------------------------------------------------------------------------------------
Recebe: Primeiro e do último elemento de uma lista e a lista sequencial
Objectivo: Calcular o número de elementos de uma lista sequencial
Devolve : Quantidade de elementos de uma lista sequencial
---------------------------------------------------------------------------------------------------*/
int TotalElementos( int i, int f, TLista lista)
{
	int k;
	if (i == f ) return 1 ;
	else
	{
		k = (i+f)/2;
		return TotalElementos(i,k,lista) + TotalElementos(k+1,f,lista);
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: Primeiro e do último elemento de uma lista e a lista sequencial
Objectivo: Calcular o número de zeros de uma lista sequencial
Devolve : Quantidade de zeros de uma lista sequencial
---------------------------------------------------------------------------------------------------*/
int TotalZeros( int i, int f, TLista lista)
{
	int meio = (f+i)/2;
	if (i > f)
		return 0 ;
	if (lista.item[i].chave == 0 )
		return 1 + TotalZeros (i +1, f, lista);
	return TotalZeros (i +1,meio, lista) + TotalZeros (meio +1, f, lista);
}
/*---------------------------------------------------------------------------------------------------
Recebe: Primeiro e do último elemento das listas e duas listas sequenciais
Objectivo: Verificar se duas listas são iguais
Devolve : verdadeiro ou falso
---------------------------------------------------------------------------------------------------*/
boolean Iguais( int i, int f, TLista l, TLista l2)
{
	if (i > f)
		return true;
	if (l.item[i].chave != l2.item[i].chave )
		return false;
	else
	{
		int meio = (f+i)/2;	
		return Iguais (i + 1, meio, l, l2) && Iguais (meio +1, f, l, l2);
	}
}




