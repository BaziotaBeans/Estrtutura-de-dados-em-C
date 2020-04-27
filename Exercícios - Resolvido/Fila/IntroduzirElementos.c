/*------------------------------------------------------------------------------
Nome do arquivo: RemoveRepetidos
Objectivo: repetir todos os elementos repetidos
------------------------------------------------------------------------------*/

#include <locale.h>
#include "operacoesFila.h"

//Função principal
int main()
{
	TFila fila,fila2;
	TItem item;
	int codRet,k;
	
	setlocale (LC_ALL,"portuguese");
	system ("CLS");
	system ("Color b0");
	InicializarFila ( &fila );
	InicializarFila ( &fila2 );
	
	printf ("\n****************************\nObjectivo:\nIntroduzir elementos na fila\n****************************\n\n");
	
	int opcao = 1;
	while ( opcao == 1 )
	{
		printf ("\nEntre com o valor a inserir na filaUm: ");
		scanf ("%d",&item.valor );
		InserirFila ( item, &fila );
		printf ("\nIntroduzir novo item na filaUm ? 1 - Sim 2 - Não\nSelecione a opção: ");
		scanf ("%d",&opcao);
	}
	
	ImprimirFila (fila);
	printf("\nTamanho filaUm: %d\n\n",TamanhoFila (fila));

	opcao = 1;
	while ( opcao == 1 )
	{
		printf ("\nEntre com o valor a inserir no inicio da filaDois: ");
		scanf ("%d",&item.valor );
		InserirFilaInicio ( item, &fila2 );
		printf ("\nIntroduzir novo item no inicio da filaDois ? 1 - Sim 2 - Não\nSelecione a opção: ");
		scanf ("%d",&opcao);
	}

	ImprimirFila (fila2);
	printf("\nfilaDois: Invertida\n");
	inverterFila (&fila2);
	ImprimirFila (fila2);	
	printf("\nTamanho filaDois: %d\n\n",TamanhoFila (fila2));

	printf ("\nItroduza a lista2 na lista1 depois da k_esima posição\nEntre com a k_esima posição: ");
	scanf ("%d",&k);
	
	codRet = InserirLista2NaLista1DepoisK_EsimaPos(k,&fila,fila2);
	
	if ( codRet == OK )
		printf ("Operação realizada com sucesso\n");
	else if( codRet == QUEUE_FULL )
		printf ("Erro QUEUE_FULL\n");
		
	else if( codRet == NO_MEMORY )
		printf ("Erro NO_MEMORY\n");
	
	else if( codRet == INVALID_INDEX )
		printf ("Erro INVALID_INDEX\n");
	
	//RemoverFila (&fila,&item);
	ImprimirFila (fila);
	printf("\nTamanho filaUm: %d\n\n",TamanhoFila (fila));
	
	system("pause");
	return main ();
}

