/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : racional.h
Objectivo: Disponibilizar operações adição e multiplicação de números
racionais
--------------------------------------------------------------------------------------------------------*/
#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED


// Tipo de Dados a ser exportado
//typedef struct racional TRacional;
/*
typedef struct
{
  float numerador;
  float denomidador;
}TRacional;*/

typedef struct racional *TRacional;

// Funções exportadas
float lerNumero();
// Retorna um numero inteiro não negativo
TRacional criar(int num, int den);
// Recebe dois numeros inteiros e retorna um número racional
TRacional adicao(TRacional v1, TRacional v2);
// Recebe dois números racionais e retorna a sua adição
TRacional subtrair(TRacional v1, TRacional v2);
// Recebe dois números racionais e retorna a sua subtracao
TRacional multiplicacao(TRacional v1, TRacional v2);
// recebe dois números racionais e retorna a sua multiplicacão
#endif
