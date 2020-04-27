#include "Bibliotecas/Agenda/agenda.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>


/*------------------------------------------------------------------------------------------------------
                          FUNCOES COM Interface COM O UTILIZADOR
------------------------------------------------------------------------------------------------------*/

void criar(TAgendas *agenda, int numeroAgenda);
void init(TAgendas *agenda);
void ajuda();
int opc_menu_init();
void menuPrincipal();
void telaLinha2();
void exibir();
void interface(TAgendas *agenda);
void menu();
int opcMenu();
void aguardar3();
void aguardar();
void tela();
void telaLinha();
void reCriar(TAgendas *agenda, int numeroAgenda);
void qualquer();


void main ()
{
	TAgendas *agenda;
	init(agenda);
}


/*-------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
void reCriar(TAgendas *agenda, int numeroAgenda)
{
	int flag = 0, enter;
	agenda = inserirAgenda(agenda, numeroAgenda);
	inserirTarefa(agenda);
	for (int i=0; i < numeroAgenda; i++) escalonarTarefa(agenda, i);
	while(flag == 0)
  {
      printf("Pressione 1 para continuar: \n"); scanf("%d", &enter);
      if(enter == 1) flag = 1;
  }
}


void qualquer()
{
	int flag = 0, enter;
	printf("########\n");
	while(flag == 0)
  {
      printf("Pressione 1 para continuar: \n"); scanf("%d", &enter);
      if(enter == 1) flag = 1;
  }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
void criar(TAgendas *agenda, int numeroAgenda)
{
	int flag = 0, enter;
	//agenda = inserirAgenda(agenda, numeroAgenda);
	agenda = criarAgendas(numeroAgenda);
	inserirTarefa(agenda);
	for (int i=0; i < numeroAgenda; i++) escalonarTarefa(agenda, i);
	while(flag == 0)
  {
      printf("Pressione 1 para continuar: \n"); scanf("%d", &enter);
      if(enter == 1) flag = 1;
  }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Funcao que vai gerar todas as funcoes
Parâmetro Entrada: nada
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
void init(TAgendas *agenda)
{
  int n, cond = 0;
  int flag = 1;
  int opc;
  aguardar3();
  while(flag)
  {
    system("reset");
    menuPrincipal();
    exibir();
    switch (opc_menu_init())
    {
      case 0:
          system("reset");
          printf("O Programa Encerrou\n");
					liberar(agenda);
          flag = 0;
          break;
      case 1:
          system("reset");
          //interface(agenda);
					if (cond == 0)
					{
						criar(agenda, lerNumeroAgendas());
						cond = 1;
					}
          break;
      case 2:
          system("reset");
          ajuda();
          break;
			/*case 3:
					system("reset");
					if (cond == 1) reCriar(agenda, lerNumeroAgendas());
					break;*/
    }
  }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Exibir ajuda do Programa em funcao do pedido do usuario
Parâmetro Entrada: nada
Parametro de saída: As rescpectivas mensagens
-------------------------------------------------------------------------------------------------------*/
void ajuda()
{
    int flag = 0;
    int enter;
    printf("\t\t\tOBJECTIVO DO PROGRAMA\n\n");
    printf("Um programa que auxilie no gerenciamento do tempo dos professores\n");
    printf("No fim exibir o correspondente escalonamento\n");
    while(flag == 0)
    {
        printf("Pressione 1 para continuar: \n"); scanf("%d", &enter);
        if(enter == 1) flag = 1;
    }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Validar as opcoes do gerador de funcao
Parâmetro Entrada: nada
Parametro de saída: A rescpectiva funcao
-------------------------------------------------------------------------------------------------------*/
int opc_menu_init()
{
    int op, yes;
    int flag = 1;
    while (flag)
    {
        system("reset");
        menuPrincipal();
        exibir();
        printf("Digite Aqui:\n"); scanf("%d",&op);
        if (op >= 1 && op <= 2) return op;
        else if(op == 0)
        {
          system("clear");
          printf("\nO senhor tem certeza que pretende Encerrar o Programa\n1 - Sim\n2 - Não\n");
          printf("Digite aqui: "); scanf("%d",&yes);
          if(yes == 1) return op;
          while((yes > 2) && (yes!=1))
          {
            system("clear");
            printf("\nErro, por favor entre com a opção válida\nPara encerrar o Programa Digite");
            printf("\n1 - Sim\n2 - Não\nDigite aqui: "); scanf("%d",&yes);
          }
          if(yes == 1) return op;
        }
        else
        {
           printf("\nErro, entre com a opção válida\n");
        }
    }
}

/*-------------------------------------------------------------------------------------------------------
Objectivo: Exibir Apenas uma Mensagem
Parâmetro Entrada: nada
Parametro de saída: A Mensagem a ser exibida
-------------------------------------------------------------------------------------------------------*/
void menuPrincipal()
{
  telaLinha2();
  printf("\n \tBEM VINDO AO GERENCIADOR DE TEMPO DE TAREFAS Vers.1.1.2\n");
  telaLinha2();
  printf("\n\n");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Imprimir 20 linhas tracejados
Parâmetro Entrada: nada
Parametro de saída: As respectivas linhas tracejadas
-------------------------------------------------------------------------------------------------------*/
void telaLinha2()
{
    for (int i = 0; i < 20; i++) printf("____");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Exibir mensagem
Parâmetro Entrada: nada
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
void exibir()
{
  printf("Entre com:      \n\n");
  printf("1 - Para Criar Agenda e Escalonar\n");
  printf("2 - Para Obter Ajuda\n");
	//printf("3 - Inserir Uma nova Agenda e Escalonar\n");
  printf("0 - Para Sair  \n");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Para Mostrar a interface
Parâmetro Entrada: nada
Parametro de saída: A respectiva interface
-------------------------------------------------------------------------------------------------------*/
void interface(TAgendas *agenda)
{
    int flag = 1, valor = 0;
    int opc, p, enter, num;
    while (flag)
    {
        system("clear");
        aguardar();

        tela();
        menu();
        switch (opcMenu())
        {
            case 0:
                system("reset");
                flag = 0;
                break;
            case 1:
                system("reset");
                //grafico_serial();
								num = lerNumeroAgendas();
								criar(agenda,num);
								escalonarTarefa(agenda, num);
								p = 1;
                printf("\nCRIAR AGENDA\n");
                break;
            case 2:
                system("reset");
								if(p == 1)
								{
									escalonarTarefa(agenda, lerNumeroAgendas());
									while(valor == 0)
								  {
								      printf("Pressione 1 para continuar: \n"); scanf("%d", &enter);
								      if(enter == 1) valor = 1;
								  }
								}
                break;
        }
    }

}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Exibir Menu de Opcoes
Parâmetro Entrada: nada
Parametro de saída: O Menu de Opcoes
-------------------------------------------------------------------------------------------------------*/
void menu()
{
    printf("\n\n 0 - Voltar\n 1 - Criar Agenda\n 2 - Escalonar");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Para escolha de Menu
Parâmetro Entrada: nada
Parametro de saída: O valor inteiro correspondete ao menu escolhido
-------------------------------------------------------------------------------------------------------*/
int opcMenu()
{
    int op;
    int flag = 1;
    while (flag)
    {
        printf("\nDigite aqui:"); scanf("%d",&op);
        if (op >= 0 && op <= 2) return op;
        printf("\nErro, entra com opção válida: ");
    }
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Imprimir uma mensagem
Parâmetro Entrada: nada
Parametro de saída: a mensagem a ser imprimida
-------------------------------------------------------------------------------------------------------*/
void aguardar3()
{
    for(int i = 0; i<4; i++)
    {
        sleep(1);
        system("clear");
        printf("\nInicializando o Programa por favor aguarde alguns segundos.");
        sleep(1);
        system("clear");
        printf("\nInicializando o Programa por favor aguarde alguns segundos..");
        sleep(1);
        system("clear");
        printf("\nInicializando o Programa por favor aguarde alguns segundos...");
    }
    printf("\n");
    system("clear");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Para aguardar
Parâmetro Nada
Parametro de saída: Nada
-------------------------------------------------------------------------------------------------------*/
void aguardar()
{
    for(int i = 0; i<3; i++)
    {
        sleep(1);
        system("clear");
        printf("\nAguarde Por Favor.");
        sleep(1);
        system("clear");
        printf("\nAguarde Por Favor..");
        sleep(1);
        system("clear");
        printf("\nAguarde Por Favor...");
    }
    printf("\n");
    system("clear");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Exibir Tela
Parâmetro Entrada: nada
Parametro de saída: A Tela
-------------------------------------------------------------------------------------------------------*/
void tela()
{
    system("reset");
    printf("#"); telaLinha();
    printf("\n\t\t\tProjecto I de ALGORITMO & COMPLEXIDADE");
    printf("\n#"); telaLinha();

}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Exibir Linha
Parâmetro Entrada: nada
Parametro de saída: As Correspondete Linhas tracejadas
-------------------------------------------------------------------------------------------------------*/
void telaLinha()
{
    for (int i = 0; i < 25; i++) printf("+#-");
}
