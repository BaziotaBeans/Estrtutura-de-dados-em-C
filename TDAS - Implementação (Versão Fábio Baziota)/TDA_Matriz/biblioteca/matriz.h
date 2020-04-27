/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : matriz.h
Objectivo: Implementação da TDA (Matriz) e Disponibilizar operações adição e multiplicação de números reais
--------------------------------------------------------------------------------------------------------*/
#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

/*Tipo exportado*/

typedef  matriz TMatriz;
/*OU typedef struct matriz *Matriz; e dai não usa ponteiros nas funções*/

/* Funções Exportadas */

/* Função libera - Libera a memória de uma matriz */
void libera (TMatriz* mat);
/* Função cria - Aloca e retorna matriz m por n */
//TMatriz* cria(int m, int n);

//Outra alternativa (+melhor)
TMatriz* cria (int m, int n, int *flagErro);

/* Função acessa - Retorna o valor do elemento [i][j]*/
float acessa(TMatriz* mat, int i, int j);
/* Função atribui - Atribui valor ao elemento [i][j]*/
void atribui (TMatriz* mat, int i, int j, float v);
/* Função linhas - Retorna o no. de linhas da matriz*/
int linhas (TMatriz* mat);
/* Função colunas - Retorna o no. de colunas da matriz*/
int colunas (TMatriz* mat);

#endif
