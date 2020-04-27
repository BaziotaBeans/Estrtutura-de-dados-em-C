#include "processo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void qualquer();


void  main(int argc, char const *argv[])
{

  TFilaDinamic *fila = criar();
  if (fila == NULL) exit(1);
  int enter;
  while (1)
  {
    system("reset");
    printf("\nBEM VINDO AO SIMULADOR DE PROCESSOS\n");
    inserirProcesso(fila);
    imprimir(fila);
    if (removerId(fila, removerMaior(fila)) == OK) printf("\nRemovido com sucesso\n");
    else printf("\nNao foi possivel remover\n");
    imprimir(fila);
    qualquer();
    system("reset");
    printf("\nDigite 1 para sair: "); scanf("%d", &enter);
    if (enter == 1) break;
    liberar(fila);
    fila = criar();
  }
  exit(EXIT_SUCCESS);
}


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
