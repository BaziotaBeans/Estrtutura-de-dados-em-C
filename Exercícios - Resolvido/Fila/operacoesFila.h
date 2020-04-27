/*-------------------------------------------------------------------------------------------
Ficheiro: operacoesFila.h
Objectivo: disponibilizar os metodos para manipular fila
-------------------------------------------------------------------------------------------*/
#include <stdio.h>

#define OK 0 // Operacao realizada com sucesso
#define QUEUE_FULL 1 // Fila cheia
#define QUEUE_EMPTY 2 // Fila vazia
#define NO_MEMORY 3 // Memoria insuficiente
#define INVALID_INDEX 4 // Indice invalido
#define TAM 100

typedef struct
{
	int valor;
	
}TItem;

typedef struct
{
	TItem item[TAM];
	int frente;
	int fundo;
} TFila;

typedef enum {false,true}boolean;

/*---------------------------------------------------------------------------------------------------
Recebe: Uma fila
Objectivo: Verificar se a fila está cheia
Devolve : true ou false
---------------------------------------------------------------------------------------------------*/
boolean CheiaFila(TFila fila)
{
	return ( fila.fundo == TAM - 1);
}
/*---------------------------------------------------------------------------------------------------
Recebe: Uma fila
Objectivo: Verificar se a fila está vazia
Devolve : true ou false
---------------------------------------------------------------------------------------------------*/
boolean VaziaFila(TFila fila)
{
	return ( ( fila.frente == -1 ) && (fila.fundo == -1) );
}
/*---------------------------------------------------------------------------------------------------
Recebe: Uma fila
Objectivo: Criar uma estrutura de dados do tipo fila
Devolve : Fila
---------------------------------------------------------------------------------------------------*/
void InicializarFila(TFila *fila)
{
	fila->frente = -1;
	fila->fundo = -1;
}
/*---------------------------------------------------------------------------------------------------
Recebe: Um elemento qualquer e uma fila
Objectivo: Inserir um elemento no fundo da fila
Devolve : Fila actualizada e o correspondente codigo de erro.
---------------------------------------------------------------------------------------------------*/
int InserirFila(TItem x, TFila *fila)
{
	if (CheiaFila(*fila)) return QUEUE_FULL;
	else 
	{
		++fila->fundo;
		fila->item[fila->fundo] = x;
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: Fila
Objectivo: Remover um elemento na frente da fila
Devolve : Fila actualizada, o conteudo do elemento removido, correspondente
codigo de erro.
---------------------------------------------------------------------------------------------------*/
int RemoverFila( TFila *fila, TItem *x)
{
	if (VaziaFila(*fila)) return QUEUE_EMPTY;
	else
	{
		++fila->frente;
		*x = fila->item[fila->frente];
		if (fila->frente == fila-> fundo)
			InicializarFila(fila);
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: Fila
Objectivo: Determinar o numero de elementos da fila
Devolve : Numero inteiro maior ou igual a zero
---------------------------------------------------------------------------------------------------*/
int TamanhoFila(TFila fila)
{
	return (fila.fundo - fila.frente);
}
/*---------------------------------------------------------------------------------------------------
Recebe: Fila
Objectivo: Imprimir a fila
Devolve : 
---------------------------------------------------------------------------------------------------*/
void ImprimirFila(TFila fila)
{
	int i;
	printf ("\nConteudo da fila \n\nFrente - ");
	
	for ( i=fila.frente + 1; i <= fila.fundo; i ++)
		printf ("%d ",fila.item[i].valor);
	printf ("- Fundo\n");
}
/*---------------------------------------------------------------------------------------------------
Recebe: Fila
Objectivo: Imprimir a fila
Devolve : 
---------------------------------------------------------------------------------------------------*/
int InserirFilaInicio(TItem x,TFila *fila)
{
	TFila aux; TItem item;
	InicializarFila (&aux);
	if (CheiaFila(*fila)) return QUEUE_FULL;
	else 
	{
		while (!VaziaFila (*fila))
		{
			RemoverFila (fila,&item);
			InserirFila (item,&aux);
		}
		InserirFila (x,fila);
		while (!VaziaFila (aux))
		{
			RemoverFila (&aux,&item);
			InserirFila (item,fila);
		}		
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: A k esima posição e as duas filas
Objectivo: Inserir a fila 2 na fila 1 depois da k_ésima posição
Devolve :  fila1 actualizada
---------------------------------------------------------------------------------------------------*/
int InserirLista2NaLista1DepoisK_EsimaPos(int k,TFila *fila,TFila fila2)
{
	TFila aux; TItem item;
	InicializarFila (&aux);
	if ( CheiaFila(*fila) ) return QUEUE_FULL;
	if ( fila->fundo+TamanhoFila (fila2) >= TAM ) return NO_MEMORY;
	if ( k > fila->fundo || k < -1) return INVALID_INDEX;
	else{
		int i = 0;
		while (!VaziaFila (*fila)){
			if ( i < k + 1){		
				RemoverFila (fila,&item);
				InserirFila (item,&aux);
			}
			else if (!VaziaFila (fila2)){
				RemoverFila (&fila2,&item);
				InserirFila (item,&aux);
			}
			else{
				RemoverFila (fila,&item);
				InserirFila (item,&aux);
			}	
			++ i;	
		}
		while (!VaziaFila (aux)){
			RemoverFila (&aux,&item);
			InserirFila (item,fila);
		}		
		return OK;
	}
}
/*---------------------------------------------------------------------------------------------------
Recebe: a fila
Objectivo: inverter a fila
Devolve :  fila actualizada
---------------------------------------------------------------------------------------------------*/
int inverterFila(TFila *fila)
{
	TItem item;
	TFila aux;
	InicializarFila ( &aux );
	if (VaziaFila (*fila)) return QUEUE_EMPTY;
	while ( ! VaziaFila (*fila) )
	{
		RemoverFila (fila,&item);
		InserirFila(item,&aux);
	}
	while ( ! VaziaFila (aux) )
	{
		RemoverFila (&aux,&item);
		InserirFilaInicio(item, fila);
	}
	return OK;
}

