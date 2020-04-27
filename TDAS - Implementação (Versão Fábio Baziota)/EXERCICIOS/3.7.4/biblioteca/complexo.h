/* -------------------------------------------------------------------------------------------------------
Autor: Beans
Especificação do Interface : complexo.h
Objectivo: Disponibilizar operações de adição, multiplicação, subtracção e divisão de numeros complexos.
racionais
Data: 20/08/2018
--------------------------------------------------------------------------------------------------------*/
#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
// Tipo de Dados a ser exportado

/*
typedef struct
{
  float real;
  float imaginario;
} TItem;*/

typedef struct
{
    float real;
    float imaginario;
    float denomidador;
    //TItem *item;
}TComplexo;

// Funções exportadas
float lerNumero();
//Retorna um numero real não negativo
TComplexo criar (float real, float imag);
// Recebe dois numeros reais e retorna um número complexo
void remover(TComplexo *comp, float real, float imag);
//Remover os ados de um número complexo.
//Aceder
TComplexo adicao(TComplexo z1, TComplexo z2);
// Recebe dois números complexos e retorna a sua adição
TComplexo subtrair(TComplexo z1, TComplexo z2);
// Recebe dois números complexos e retorna a sua subtracao
TComplexo multiplicacao(TComplexo z1, TComplexo z2);
// recebe dois números complexos e retorna a sua multiplicacão
TComplexo dividir(TComplexo z1, TComplexo z2);
// // recebe dois números complexos e retorna a sua divisão
#endif
