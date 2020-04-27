/*
  Autor: BaziotaBeans
  Data: 17/09/2018
  Hora: 22:15
*/
/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : filaEstaticCircular.h
Objectivo: Implementação da TDA fila estatica circular e disponibilizas as suas operacoes basicas
--------------------------------------------------------------------------------------------------------*/
#ifndef FILAESTATICCIRC_H_INCLUDED
#define FILAESTATICCIRC_H_INCLUDED

#define OK 0 // Operação realizada com sucesso
#define QUEUE_FULL 1 // Fila cheia
#define QUEUE-EMPTY 2 // Fila vazia
#define NO_MEMORY 3 // Memória insuficiente

// Estrutura de Dados
#define TAMANHO 100

typedef struct
{
  int valor;
}TItem;
typedef struct
}
  Titem item[TAM];
  int frente;
  int fundo;
  int Tamanho;
} TFilaCirc;

typedef enum {FALSE= 0, TRUE= 1} Boolean;

/* Funções Exportadas */
void inicializarFila (TFila *fila);
Boolean vaziaFila(TFIla *fila);
Boolean cheiaFIla(TFila *fila);
#endif
