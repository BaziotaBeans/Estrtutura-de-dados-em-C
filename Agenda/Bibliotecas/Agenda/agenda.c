/*
  Autor: BaziotaBeans
  Data: 30/09/2018
  Hora: 03:33
*/

/* -------------------------------------------------------------------------------------------------------
Especificação de operacoes : agenda.c
Objectivo: Disponibilizar as operações comuns sobre uma agenda
--------------------------------------------------------------------------------------------------------*/
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*---------------------------------------------------------------------------------------------------------
																		Estruturas de Dados
---------------------------------------------------------------------------------------------------------*/
typedef enum boolean
{
	false, true
}Boolean;

typedef struct agenda
{
	TTarefa *tarefa [MAX_TAREFA];
	int ultimaTarefa;
}TAgenda;


typedef struct agendas
{
	TAgenda agendas[MAX_AGENDA];
	int ultimaAgenda;
}TAgendas;
/*----------------------------------------------------------------------------------------------------------
																	Definição de Funções
----------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------
Objectivo: Criar uma Agenda
Parâmetro Entrada: numero de Agendas
Parâmetro de Saída: agenda alocada
------------------------------------------------------------------------------------------------------- */
TAgendas* criarAgendas (int numeroAgendas)
{
	TAgendas *agendas = (TAgendas *) malloc (sizeof (TAgendas) * numeroAgendas);
	agendas->ultimaAgenda = numeroAgendas;
	for (int posicao = 0; posicao < numeroAgendas; posicao++)
		agendas->agendas[posicao].ultimaTarefa = -1;
	return agendas;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: inserir nova agenda
Parâmetro Entrada: numero de Agendas
Parâmetro de Saída: agenda alocad
------------------------------------------------------------------------------------------------------- */
TAgendas* inserirAgenda (TAgendas *agendas, int numeroAgendas)
{
		TAgendas *novaAgenda = (TAgendas *) realloc(agendas, sizeof(agendas) * (sizeof (TAgendas) * numeroAgendas));
		//TAgendas *novaAgenda = (TAgendas *) realloc(agendas, sizeof (agendas) + (sizeof (TAgendas) * numeroAgendas));
		for (int numeroAgenda = agendas->ultimaAgenda; numeroAgenda < agendas->ultimaAgenda + numeroAgendas; numeroAgenda++) agendas->agendas[numeroAgenda].ultimaTarefa = -1;
    agendas->ultimaAgenda += numeroAgendas;
    return novaAgenda;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: inserir tarefa
Parâmetro Entrada: Agenda
Parâmetro de Saída: Codigo de ERRO
------------------------------------------------------------------------------------------------------- */
int inserirTarefa (TAgendas *agendas)
{
	for (int numeroAgendas = 0, numeroTarefas = 0 , contAuxiliar = 0; numeroAgendas < agendas->ultimaAgenda; numeroAgendas++, contAuxiliar = 0)
	{
		numeroTarefas = lerNumeroTarefas (numeroAgendas);
		while (contAuxiliar++ < numeroTarefas)
		{
			agendas->agendas [numeroAgendas].tarefa [++agendas->agendas [numeroAgendas].ultimaTarefa] = criarTarefa (lerNumeroChegada (), lerTempoDuracao (), lerPenalidade ());
			if (agendas->agendas [numeroAgendas].tarefa [agendas->agendas [numeroAgendas].ultimaTarefa] == NULL) return MEMORIA_CHEIA;
			//if (tarefaValida (agendas->agendas [numeroAgendas].tarefa [agendas->agendas [numeroAgendas].ultimaTarefa])) return TAREFA_INVALIDA;
		}

	}
	return OPERACAO_EFECTUADA;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: escalonar uma tarefa
Parâmetro Entrada: Agenda e numero de agenda
Parâmetro de Saída: Codigo de ERRO
------------------------------------------------------------------------------------------------------- */
int escalonarTarefa (TAgendas *agendas, int numeroAgenda)
{
	//TAgendas *aux = criarAgendas(1);
	//aux = agendas;
	for(int i=0; i < agendas->agendas[numeroAgenda].ultimaTarefa; i++)
		for(int j=i+1; j <= agendas->agendas[numeroAgenda].ultimaTarefa ; j++)
			executar(agendas->agendas[numeroAgenda].tarefa[i], agendas->agendas[numeroAgenda].tarefa[j]);

		//imprimirAgendas(agendas);
		impressao(agendas, numeroAgenda);
		printf("\nESPERA TOTAL = %d\n", esperaTotal(agendas, numeroAgenda));
		return OPERACAO_EFECTUADA;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Ordenar uma tarefa
Parâmetro Entrada: Agenda e numero de agenda
Parâmetro de Saída: Codigo de ERRO
------------------------------------------------------------------------------------------------------- */
int ordenarTarefa(TAgendas *agendas, int numeroAgenda)
{
	TAgendas *aux = criarAgendas(1);
	aux = agendas;
	for(int i=0; i <= aux->agendas[numeroAgenda].ultimaTarefa; i++)
		for(int j=i+1; j <= aux->agendas[numeroAgenda].ultimaTarefa ; j++)
		{
			if(comparChegda(aux->agendas[numeroAgenda].tarefa[i], aux->agendas[numeroAgenda].tarefa[j]))
					trocar(&aux->agendas[numeroAgenda].tarefa[i], &aux->agendas[numeroAgenda].tarefa[j]);
		}
				//inserirAUX(aux, agendas->agendas[numeroAgenda].tarefa[i],numeroAgenda);
	imprimirAgendas(aux);
	return OPERACAO_EFECTUADA;
}
//------------------------------------------------------------------------------------------
int inserirAUX(TAgendas *agendas, TTarefa *tarefa, int numeroAgenda)
{
		agendas->agendas[numeroAgenda].tarefa[++agendas->agendas[numeroAgenda].ultimaTarefa] = criarAuxiliar(tarefa);
		return OPERACAO_EFECTUADA;
}
//--------------------------------------------------------------------------------------
int esperaTotal (TAgendas *agendas, int numeroAgenda)
{
	int esperaTotal = 0;
	if (verificarNumeroAgenda (&*agendas, numeroAgenda)) return NUMERO_INVALIDO;
	for (int numeroTarefas = 0; numeroTarefas <= agendas->agendas [numeroAgenda].ultimaTarefa; numeroTarefas++) esperaTotal += esperaTarefa (agendas->agendas [numeroAgenda].tarefa [numeroTarefas]);
	return esperaTotal;
}
//--------------------------------------------------------------------------------------
int lerNumeroAgendas ()
{
	int numeroAgendas;
	printf ("\nIntroduza o número de agendas que pretende criar: "); scanf("%d",&numeroAgendas);
	while (1)
	{
		if (numeroValido (numeroAgendas)) return numeroAgendas;
		printf ("\nERRO:(Numero invalido)\nIntroduza o número de agendas que pretende criar: "); scanf("%d",&numeroAgendas);
	}
}
//--------------------------------------------------------------------------------------
Boolean verificarNumeroAgenda (TAgendas *agendas, int numeroAgenda)
{
	return (numeroAgenda - 1 >= agendas->ultimaAgenda);
}
//--------------------------------------------------------------------------------------
void imprimirAgendas (TAgendas *agendas)
{
	for (int numeroAgendas = 0, numeroTarefas = 0; numeroAgendas < agendas->ultimaAgenda; numeroAgendas++, numeroTarefas = 0)
		while (numeroTarefas <= agendas->agendas[numeroAgendas].ultimaTarefa)
			imprimirTarefa (agendas->agendas[numeroAgendas].tarefa [numeroTarefas++]);
}
//--------------------------------------------------------------------------------------
void imprimirAgendasEspera (TAgendas *agendas)
{
	for (int numeroAgendas = 0, numeroTarefas = 0; numeroAgendas < agendas->ultimaAgenda; numeroAgendas++, numeroTarefas = 0)
		while (numeroTarefas <= agendas->agendas[numeroAgendas].ultimaTarefa)
			imprimirTempoEspera (agendas->agendas[numeroAgendas].tarefa [numeroTarefas++]);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
------------------------------------------------------------------------------------------------------- */
void liberar(TAgendas *agenda)
{
	free(agenda);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
-------------------------------------------------------------------------------------------------------*/
int terminoMaximo(TAgendas *agenda, int numeroAgenda)
{
		int maximo = 0;
		for(int i=0, aux = 0; i <= agenda->agendas[numeroAgenda].ultimaTarefa; i++)
		{
			aux = terminaTarefa(agenda->agendas[numeroAgenda].tarefa[i], iniciaTarefa(agenda->agendas[numeroAgenda].tarefa[i]));
			//(aux = terminaTarefa(agenda->agendas[numeroAgenda].tarefa[i]), iniciaTarefa(agenda->agendas[numeroAgenda].tarefa[i]))
			if (maximo < aux) maximo = aux;
		}
		return maximo;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
-------------------------------------------------------------------------------------------------------*/
void impressao(TAgendas *agenda, int numeroAgenda)
{
	int duracao = terminoMaximo(agenda, numeroAgenda);
	// CABECAL
	printf("tempo");
	for (int i=0; i<= agenda->agendas[numeroAgenda].ultimaTarefa; i++) printf("\tT00%d", i+1);
	for (int time = 0; time <= duracao; time++)
	{
		printf("\n%d", time);
		for (int numTarefa = 0; numTarefa <= agenda->agendas[numeroAgenda].ultimaTarefa; numTarefa++)
		{
			if (verificarTarefa(agenda->agendas[numeroAgenda].tarefa[numTarefa], time) == ESPERA) printf("\t-");
			else if (verificarTarefa(agenda->agendas[numeroAgenda].tarefa[numTarefa], time) == YES) printf("\t#");
			else printf("\t");
		}
	}
}
/*-------------------------------------------------------------------------------------------------------*/
