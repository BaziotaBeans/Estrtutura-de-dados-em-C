/*
  Autor: BaziotaBeans
  Data: 30/09/2018
  Hora: 03:34
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : agenda.h
Objectivo: Disponibilizar as operações comuns sobre uma agenda
--------------------------------------------------------------------------------------------------------*/
#ifndef AGENDA_INCLUDE
#define AGENDA_INCLUDE
#include "../Tarefa/tarefa.h"
#define MAX_AGENDA 9999
    /*--------------------------------------------------------------------------------------
			    Estruturas de Dados
    --------------------------------------------------------------------------------------*/
    typedef struct agenda TAgenda;
    typedef struct agendas TAgendas;
/*--------------------------------------------------------------------------------------
			Declaração de Funções
--------------------------------------------------------------------------------------*/
//Criar o numero de agendas que o cliente quiser.
TAgendas* criarAgendas (int numeroAgendas);

TAgendas* inserirAgenda (TAgendas *agendas, int numeroAgendas);

//Inserir uma tarefa na Agenda.
int inserirTarefa (TAgendas *agendas);

//Realizar o escalonamento das tarefas contidas na agenda, seleccionando qual delas será executada primeiro em relação as outras.
int escalonarTarefa (TAgendas *agendas, int numeroAgenda);


int ordenarTarefa(TAgendas *agendas, int numeroAgenda);

//Retorna o tempo de espera total de uma agenda.
int esperaTotal (TAgendas *agendas, int numeroAgenda);

//Ler o numero de agendas que o cliente pretende criar em uma determinada agenda, retornar o mesmo numero se for válido, caso contrário, retorna uma mensagem de erro.
int lerNumeroAgendas ();

//Verificar se o numero de agenda entrado pelo usuario e valido.
Boolean verificarNumeroAgenda (TAgendas *agendas, int numeroAgenda);

void imprimirAgendas (TAgendas *agendas);

int inserirAUX(TAgendas *agendas, TTarefa *tarefa, int numeroAgenda);

void imprimirAgendasEspera (TAgendas *agendas);

void liberar(TAgendas *agenda);

int terminoMaximo(TAgendas *agenda, int numeroAgenda);

void impressao(TAgendas *agenda, int numeroAgenda);

#endif
