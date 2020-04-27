/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : racional.h
Objectivo: Disponibilizar operações de Matriz:
Aceder: devolver o valor do elemento localizado na posição i e j da matriz;
Atribuir: atribuir um valor ao elemento localizado na posição i e j da matriz;
Adicionar: devolver uma nova matriz com o resultado da adição de duas
matrizes;
Subtrair: devolver uma matriz que é o resultado da subtração de duas
matrizes,
Multiplicar: devolver uma matriz que é o resultado da multiplicação de duas
matrizes;
Transpor: devolve uma matriz que é o resultado da transposição de uma
matriz.
--------------------------------------------------------------------------------------------------------*/
#ifndef TMATRIZ_H
#define TMATRIZ_H
#define MAXLIN 2
#define MAXCOL 2

typedef enum { FALSE= 0, TRUE= 1 } Boolean;
//------------------------------------------------------------- Protótipos das Funções


// Funções exportadas


float lerNumero();
void carregar(float A[][MAXCOL]);
//devolver o valor do elemento localizado na posição i e j da matriz;
float aceder(float A[][MAXCOL],int i, int j);
//atribuir um valor ao elemento localizado na posição i e j da matriz;
void atribuir(float A[][MAXCOL],int i, int j);
//devolver uma nova matriz com o resultado da adição de duas matrizes;
void adicionar(float A[][MAXCOL], float B[][MAXCOL], float C[][MAXCOL]);
//devolver uma matriz que é o resultado da subtração de duas matrizes,
void subtrair(float A[][MAXCOL], float B[][MAXCOL], float C[][MAXCOL]);
//devolver uma matriz que é o resultado da multiplicação de duas matrizes;
void multiplicar(float A[][MAXCOL], float B[][MAXCOL], float C[][MAXCOL]);
//devolve uma matriz que é o resultado da transposição de uma matriz.
void transpor(float A[][MAXCOL], float B[][MAXCOL]);
#endif
