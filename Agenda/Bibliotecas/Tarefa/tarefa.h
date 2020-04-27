/*
  Autor: BaziotaBeans
  Data: 30/09/2018
  Hora: 03:34
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : tarefa.h
Objectivo: Disponibilizar as operações comuns sobre uma tarefa
--------------------------------------------------------------------------------------------------------*/
#ifndef TAREFA_INCLUDE
#define TAREFA_INCLUDE
/*----------------------------------------------------------------------------------------------------------
                                    Definição dos códigos de erro
----------------------------------------------------------------------------------------------------------*/
#define NUMERO_INVALIDO -3
#define NUMERO_VALIDO -2
#define TAREFA_INVALIDA -1
#define OPERACAO_EFECTUADA 0
#define MEMORIA_CHEIA 1
#define YES 2
#define TERMINATE 3
#define ESPERA 4
//----------------------------------------------------------------------------------------------------------
#define MAX_TAREFA 999 //Numero Maximo de tarefa
/*----------------------------------------------------------------------------------------------------------
			                             Estruturas de Dados - ENCAPSULAMENTO
----------------------------------------------------------------------------------------------------------*/
typedef enum boolean Boolean;
typedef struct tarefa TTarefa;
/*-----------------------------------------------------------------------------------------------------------
		                                   Funções exportadas
-----------------------------------------------------------------------------------------------------------*/
TTarefa* criarTarefa (int chegada, int duracao, int penalidade);
//Criar uma tarefa com os seus respectivos dados e retornar a tarefa criada.
TTarefa* alorcarTarefa();
//Alocar Tarefa

//Atribuir no campo tempoEspera o valor 0
int iniciaTarefa (TTarefa *tarefa);
//Determina o momento em que uma tarefa começa; retorna o seu tempo de chegada.
int terminaTarefa (TTarefa *tarefa, int inicio);
//Determina o momento em que uma tarefa termina; retorna o seu tempo de duracao.
int esperaTarefa (TTarefa *tarefa);
//Retorna o tempo de espera de uma tarefa;
Boolean numeroValido (int numeroLido);
//Verifica se o número lido é positivo, se este for positivo, a execução do programa continua, caso contrário, uma mensagem de erro é enviada e depois a execução do programa termina.
Boolean numeroValidoPD (int numeroLido);
//Verifica se o número lido é positivo, se este for positivo, a execução do programa continua, caso contrário, uma mensagem de erro é enviada e depois a execução do programa termina.
int lerNumeroTarefas (int numeroAgenda);
//Ler o numero de tarefas que o cliente pretende criar em uma determinada agenda, retornar o mesmo numero se for válido, caso contrário, retorna uma mensagem de erro.
int lerNumeroChegada ();
//Ler o numero de chegada da tarefa a ser criada, retornar o mesmo numero se for válido, caso contrário, retorna uma mensagem de erro.
int lerTempoDuracao ();
//Ler o tempo de duração da tarefa a ser criada , retornar o mesmo tempo se for válido, caso contrário, retorna uma mensagem de erro.
int lerPenalidade ();
//Ler a penalidade da tarefa a ser criada, retornar a mesma penalidade se for válida, caso contrário, retorna uma mensagem de erro.
Boolean tarefaValida (TTarefa *tarefa);
//Verifica se todos os campos da tarefa são válidos.
void imprimirTarefa (TTarefa *tarefa);
//Imprimir Tarefa
TTarefa* comparar(TTarefa *tarefa1, TTarefa *tarefa2);

Boolean comparChegda(TTarefa *tarefa1, TTarefa *tarefa2);

//Comparar duas tarefa
TTarefa *criarAuxiliar(TTarefa *tarefa);
//Aloca um espaco para a tarefa depois retorna a tarefa alocada
void trocar (TTarefa **tarefa1, TTarefa **tarefa2);
//Troca duas tarefas
int executar (TTarefa *tarefa1, TTarefa *tarefa2);
// Executa uma parte do escalonamento
void imprimirTempoEspera (TTarefa *tarefa);

int verificarTarefa(TTarefa *tarefa, int tempo);
#endif
