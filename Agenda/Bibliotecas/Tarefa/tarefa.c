/*
  Autor: BaziotaBeans
  Data: 30/09/2018
  Hora: 03:19
*/

/* -------------------------------------------------------------------------------------------------------
Especificação de operacoes : tarefa.c
Objectivo: Disponibilizar as operações comuns sobre uma tarefa
--------------------------------------------------------------------------------------------------------*/
#include "tarefa.h"
#include <stdio.h>
#include <stdlib.h>
/*---------------------------------------------------------------------------------------------------------
																		Estruturas de Dados
---------------------------------------------------------------------------------------------------------*/
typedef enum boolean
{
	false, true
}Boolean;

typedef struct tarefa
{
	int chegada;
	int duracao;
	int penalidade;
	int tempoEspera;
}TTarefa;
/*----------------------------------------------------------------------------------------------------------
																	Definição de Funções
----------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------
Objectivo: Criar uma tarefa, com os seus respectivos dados
Parâmetro Entrada: Tempo de chegada, duracao e penalidade
Parâmetro de Saída:A Tarefa alocada
------------------------------------------------------------------------------------------------------- */
TTarefa* criarTarefa (int chegada, int duracao, int penalidade)
{
	TTarefa *tarefa = (TTarefa *) malloc (sizeof (TTarefa));
	tarefa->chegada = chegada;
	tarefa->duracao = duracao;
	tarefa->penalidade = penalidade;
	tarefa->tempoEspera = 0;
	return tarefa;
}


TTarefa* alorcarTarefa()
{
	TTarefa *tarefa = (TTarefa *) malloc (sizeof (TTarefa));
	return tarefa;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: inicializar espera
Parâmetro Entrada:
Parâmetro de Saída:
------------------------------------------------------------------------------------------------------- */

/*--------------------------------------------------------------------------------------------------------
Objectivo: Determina o momento em que a tarefa começou a ser executada.
Parâmetro Entrada: Tarefa
Parâmetro de Saída: Chegada da tarefa
------------------------------------------------------------------------------------------------------- */
int iniciaTarefa (TTarefa *tarefa)
{
	//return tarefa->chegada;
	return (tarefa->tempoEspera + tarefa->chegada);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Determina o momento em que a tarefa foi encerrada.
Parâmetro Entrada: Tarefa
Parâmetro de Saída: duracao da tarefa
------------------------------------------------------------------------------------------------------- */
int terminaTarefa (TTarefa *tarefa, int inicio)
{
	return ((inicio + tarefa->duracao) - 1);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: retorna o tempo de espera da tarefa, aplicando a penalidade por tempo de espera: E i ∗ P i ,
onde E i é o tempo de espera da tarefa i e P i é a penalidade por espera da tarefa i.
Parâmetro Entrada: Tarefa
Parâmetro de Saída: O tempo de espera da tarefa
------------------------------------------------------------------------------------------------------- */
int esperaTarefa (TTarefa *tarefa)
{
	return (tarefa->penalidade * tarefa->tempoEspera);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Validar um Numero de Tarefa e tempo de chegada
Parâmetro Entrada: numero lido
Parâmetro de Saída: Verdadeiro (se o numero e maior ou igual a zero) & Falseo (se o numero e menor que zero)
------------------------------------------------------------------------------------------------------- */
Boolean numeroValido (int numeroLido)
{
	return (numeroLido >= 0);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Validar o numero de tempo de duracao e penalidade
Parâmetro Entrada: numero lido
Parâmetro de Saída: Verdadeiro (se o numero e maior ou igual a 1) & Falso (se o numero e menor que 1)
------------------------------------------------------------------------------------------------------- */
Boolean numeroValidoPD (int numeroLido)
{
	return (numeroLido >= 0);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Ler o numero de tarefa
Parâmetro Entrada: numero da Agenda
Parâmetro de Saída: numero de tarefa
------------------------------------------------------------------------------------------------------- */
int lerNumeroTarefas (int numeroAgenda)
{
	int numeroTarefas;
	printf ("\nDigite o número de tarefas que pretende criar na agenda %d: ", numeroAgenda + 1); scanf ("%d", &numeroTarefas);
	while(1)
	{
			if (numeroValido (numeroTarefas)) return numeroTarefas;
			printf ("\nERRO:(Numero invalido)\nDigite o número de tarefas que pretende criar na agenda %d: ", numeroAgenda + 1); scanf ("%d", &numeroTarefas);
	}
	//return NUMERO_INVALIDO;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Ler o tempo de chegada
Parâmetro Entrada: Nada
Parâmetro de Saída: tempo de chegada
------------------------------------------------------------------------------------------------------- */
int lerNumeroChegada ()
{
	int numeroChegada;
	printf ("\nDigite o número de chegada da tarefa: "); scanf ("%d", &numeroChegada);
	while(1)
	{
			if (numeroValido (numeroChegada)) return numeroChegada;
			printf ("\nERRO:(Numero invalido)\nDigite o número de chegada da tarefa: "); scanf ("%d", &numeroChegada);
	}
	//return NUMERO_INVALIDO;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Ler o tempo de duracao
Parâmetro Entrada: Nada
Parâmetro de Saída: tempo de chegada
------------------------------------------------------------------------------------------------------- */
int lerTempoDuracao ()
{
	int tempoDuracao;
	printf ("\nDigite o tempo de duração da tarefa: "); scanf ("%d", &tempoDuracao);
	while(1)
	{
			if (numeroValidoPD (tempoDuracao)) return tempoDuracao;
			printf ("\nERRO:(Numero invalido)\nDigite o tempo de duração da tarefa: "); scanf ("%d", &tempoDuracao);
	}
	//return NUMERO_INVALIDO;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Ler o tempo de penalidade
Parâmetro Entrada: Nada
Parâmetro de Saída: tempo de chegada
------------------------------------------------------------------------------------------------------- */
int lerPenalidade ()
{
	int penalidade;
	printf ("\nDigite a penalidade da tarefa: "); scanf ("%d", &penalidade);
	while(1)
	{
			if (numeroValidoPD (penalidade)) return penalidade;
			printf ("\nERRO:(Numero invalido)\nDigite a penalidade da tarefa: "); scanf ("%d", &penalidade);
	}
	//return NUMERO_INVALIDO;
}
//--------------------------------------------------------------------------------------
Boolean tarefaValida (TTarefa *tarefa)
{
	return (tarefa->chegada != NUMERO_INVALIDO && tarefa->duracao != NUMERO_INVALIDO && tarefa->penalidade != NUMERO_INVALIDO);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Imprimir a tarefa
Parâmetro Entrada: tarefa
Parâmetro de Saída: Nada
------------------------------------------------------------------------------------------------------- */
void imprimirTarefa (TTarefa *tarefa)
{
	printf ("\nChegada: %d\nDuracao: %d\nPenalidade: %d\n", tarefa->chegada, tarefa->duracao, tarefa->penalidade);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: comparar duas tarefas
Parâmetro Entrada: duas tarefa
Parâmetro de Saída: uma tarefa
------------------------------------------------------------------------------------------------------- */
TTarefa* comparar(TTarefa *tarefa1, TTarefa *tarefa2)
{
	if (tarefa1->chegada == tarefa2->chegada)
	{
		if (tarefa1->penalidade <= tarefa2->penalidade) return tarefa1;
		else return tarefa2;
	}
	else if (tarefa1->chegada > tarefa2->chegada) return tarefa2;
	else return tarefa1;
}

Boolean comparChegda(TTarefa *tarefa1, TTarefa *tarefa2)
{
	return (tarefa1->chegada > tarefa2->chegada);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Alocar um espaco para uma tarefa
Parâmetro Entrada: tarefa
Parâmetro de Saída: tarefa alocada
------------------------------------------------------------------------------------------------------- */
TTarefa *criarAuxiliar(TTarefa *tarefa)
{
	TTarefa *aux = (TTarefa *) malloc (sizeof (TTarefa));
	aux = tarefa;
	return aux;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Trocar duas tarefa
Parâmetro Entrada: duas tarefa
Parâmetro de Saída: Nada
------------------------------------------------------------------------------------------------------- */
void trocar (TTarefa **tarefa1, TTarefa **tarefa2)
{
	TTarefa *aux;  //= (TTarefa *) malloc (sizeof (TTarefa));
	aux = *tarefa1;
	*tarefa1 = *tarefa2;
	*tarefa2 = aux;
	//printf("\nSIM trocou %d | %d\n", tarefa1->chegada, tarefa2->chegada);
}
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída: Nada
------------------------------------------------------------------------------------------------------- */
int executar(TTarefa *tarefa1, TTarefa *tarefa2)
{
    if (tarefa1->chegada <= tarefa2->chegada)
    {
      if (tarefa1->penalidade <= tarefa2->penalidade)
      {
        if (tarefa1->duracao == tarefa2->chegada)
              tarefa2->tempoEspera++;
        if (tarefa1->duracao > tarefa2->chegada)
              tarefa2->tempoEspera += tarefa1->duracao - tarefa2->chegada;
      }
      else
      {
        if (tarefa2->duracao == tarefa1->chegada) tarefa1->tempoEspera++;
        if (tarefa1->duracao > tarefa1->chegada) tarefa1->tempoEspera += tarefa2->duracao - tarefa1->chegada;
      }
    }
    else
    {
      if (tarefa1->penalidade <= tarefa2->penalidade)
      {
        if (tarefa1->duracao == tarefa2->chegada) tarefa2->tempoEspera++;
        if (tarefa1->duracao > tarefa2->chegada) tarefa2->tempoEspera += tarefa1->duracao - tarefa2->chegada;
      }
      else
      {
        if (tarefa2->duracao == tarefa1->chegada) tarefa1->tempoEspera++;
        if (tarefa2->duracao > tarefa1->chegada) tarefa1->tempoEspera += tarefa2->duracao - tarefa1->chegada;
      }
    }
    return OPERACAO_EFECTUADA;
}
/*--------------------------------------------------------------------------------------------------------
Objectivo: Trocar duas tarefa
Parâmetro Entrada: duas tarefa
Parâmetro de Saída: Nada
------------------------------------------------------------------------------------------------------- */
void imprimirTempoEspera (TTarefa *tarefa)
{
	printf ("\nTempo Espera: %d", tarefa->tempoEspera);
}

int verificarTarefa(TTarefa *tarefa, int tempo)
{
    if (tempo >= iniciaTarefa(tarefa))
    {
        if (tempo <= terminaTarefa(tarefa, iniciaTarefa(tarefa))) return YES;
        else return TERMINATE;
    }
    else
    {
        if (tempo >= tarefa->chegada) return ESPERA;
        else return TERMINATE;
    }
}

/*
int verificarTarefa(TTarefa *tarefa, int tempo)
{
		if (tempo >= iniciaTarefa(tarefa))
		{
			if (tempo <= terminaTarefa(tarefa, iniciaTarefa(tarefa))) return YES;
			else return TERMINATE;
		}
		if (tempo >= tarefa->chegada)
		{
			if (tempo >= tarefa->chegada)
			{
				if (tempo <= terminaTarefa(tarefa, iniciaTarefa(tarefa)))
				{
					if (tempo < iniciaTarefa(tarefa))
					{
						return ESPERA;
					}
				}
			}
		}
		else return TERMINATE;
}*/
