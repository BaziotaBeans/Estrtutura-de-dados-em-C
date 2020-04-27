/*

      AUTOR: BAZIOTABEANS A.K.A 007
      HORA: 04:00
      Data: 10/10/2018
      Descricao: Projecto II de Algoritmo e Complexidade (ESTRUTURA DE DADOS) - DOMINO

*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface do cliente : Main.c
Objectivo: Disponibilizar as operações comuns sobre um domino em funcao do cliente
--------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------
                                  Importacao das Bibliotecas
--------------------------------------------------------------------------------------------------------*/
#include "domino.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*--------------------------------------------------------------------------------------------------------
                                  Prototipos de funcao do cliente

                                  FUNCOES COM Interface COM O UTILIZADOR
--------------------------------------------------------------------------------------------------------*/
void qualquer();
void init(TJogada *jogada);
void ajuda();
int opc_menu_init();
void menuPrincipal();
void telaLinha2();
void exibir();
void menu();
int opcMenu();
void aguardar3();
void aguardar();
void tela();
void telaLinha();
void interface(TJogada *jogada);
void aguardarLiberar();
/*-------------------------------------------------------------------------------------------------------------------------------
                                                                  Varivavel Global
-------------------------------------------------------------------------------------------------------------------------------*/
int i = 1; //Essa variavel serve para indexar a posicao das pecas no vector
/*------------------------------------------------------------------------------------------------------------------------------
                                                              Funcao Principal (Main)
------------------------------------------------------------------------------------------------------------------------------*/
void main()
{
  TJogada *jogada = criar();
  if (jogada == NULL)
  {
    printf("\n O programa vai Abortar!!! nao ha espaco\n");
    exit(EXIT_FAILURE);
  }
  init(jogada);
  exit(EXIT_SUCCESS);
}
/*--------------------------------------------------------------------------------------------------------------------------------
                                                        Impletação das funcoes do Cliente
---------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parâmetro de Saída:
------------------------------------------------------------------------------------------------------- */
void qualquer()
{
	int flag = 0, enter;
	printf("\n--------------------------------------\n");
  printf("Pressione 1 para continuar: \n"); scanf("%d", &enter);
  if (enter != 1)
  {
    while(flag == 0)
    {
        printf("ERRO:(Valor invalido)\nPor favor Pressione 1 para continuar: \n"); scanf("%d", &enter);
        if(enter == 1) flag = 1;
    }
  }
}

/*-------------------------------------------------------------------------------------------------------
Objectivo: Funcao que vai gerar todas as funcoes
Parâmetro Entrada: nada
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
void init(TJogada *jogada)
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
          liberar(jogada);
          aguardarLiberar();
          printf("O Programa Encerrou\n");
          flag = 0;
          break;
      case 1:
          system("reset");
          interface(jogada);
          qualquer();
          break;
      case 2:
          system("reset");
          ajuda();
          break;
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
    printf("\t\t\tOBJECTIVO DO PROGRAMA\n");
    printf("\nTodos conhecem o jogo de dominos, em que pecas com dois valores devem ser colocadas na mesa em sequencia, ");
    printf("\nde tal forma que os valores de pecas imediatamente vizinhas sejam iguais.");
    printf("\nO objectivo desse jogo e determinar se e possivel colocar todas as pecas de um dado conjunto em uma formacao valida.");
    printf("\nRegras Do Jogo:");
    printf("\nRegra - 1: Os valores da peca x e y devem estar no intervalo fechado de 0 a 6");
    printf("\nRegra - 2: A quantidade de pecas devem estar no intervalo fechado de 0 a 28");
    printf("\nSobre o Desenvolvedor visita o perfil do facebook Fabio Aristoteles Baziota");
    while(flag == 0)
    {
        printf("\nPressione 1 para continuar: \n"); scanf("%d", &enter);
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
  printf("\n \tBEM VINDO AO DOMINO - BEANS VERSAO 2.0.5\n");
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
  printf("1 - Jogar\n");
  printf("2 - Para Obter Ajuda\n");
  printf("0 - Para Sair  \n");
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
    printf("\n\t\t\tProjecto II de ALGORITMO & COMPLEXIDADE");
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
/*-------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
void interface(TJogada *jogada)
{
  int n;
  do
  {
    n = lerQuantidadePecas();
    if (n == 0) break;
    jogada = recriar(jogada, i);
    for (int j=0; j < n; j++)
    {
      inserirDireita(jogada, lerPecas(), i - 1);
    }
    ordenarDomino(jogada, i - 1);
    i++;
  } while(n != 0);
  imprimirGeral(jogada);
  liberar(jogada);
  jogada = criar();
  i = 1;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo:
Parâmetro Entrada:
Parametro de saída:
-------------------------------------------------------------------------------------------------------*/
void aguardarLiberar()
{
    for(int i = 0; i<3; i++)
    {
        sleep(1);
        system("clear");
        printf("\nAguarde um instante o programa esta liberando espaco.");
        sleep(1);
        system("clear");
        printf("\nAguarde um instante o programa esta liberando espaco..");
        sleep(1);
        system("clear");
        printf("\nAguarde um instante o programa esta liberando espaco...");
    }
    printf("\n");
    system("clear");
}
