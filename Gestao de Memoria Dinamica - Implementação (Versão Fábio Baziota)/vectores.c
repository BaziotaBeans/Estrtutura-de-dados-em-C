/*
    Autor: Manuel Meneses Jr.
    Data:
    Objectivo: um programa que calcula a média e a variância para n números reias.
*/

#include <stdio.h>
#include <stdlib.h>

float media (int n, float *v);
float variancia (int n, float *v, float m);


int main(int argc, char const *argv[])
{
  /*int sizeof nome da variável;
  int sizeof ( tipo de dados);*/

  /*
  1o- Calcular coma função sizeof() o número de bytes para armazenar a estrutura;
  2o- Invocar a função malloc() para retornar um apontador genérico que
  aponta para o primeiro byte desse bloco de memória;
  3o- Converter o ponteiro genérico retornado pela função malloc() para
  um ponteiro cujo tipo de dados é compatível com o tipo do vector.
  */

  int i, n;
  float *v;
  float med, var;
  printf("Digite o numero de elementos: \n"); scanf("%d", &n); // lê o número de elementos
  v = (float *) malloc(sizeof(float) *n); // Solicita um bloco de memória
  if(v == NULL)
  {
    printf ("Erro: Nao ha memória suficiente \n ");
    return 1;
  }

  for ( i = 0; i < n; i++ ) // carrega os n elementos no vector
  {
      printf("\nDigite o elemento do vector: "); scanf("%f", &v[i]);
  }

  med = media(n,v); // calcula a média
  var = variancia(n,v,med); // calcula a mediana

  printf ("Media = %f Variancia = %f \n", med, var);

  free(v); // liberta os blocos de memoria

  return 0;
}


/*----------------------------------------------------------------------------------------
  Objectivo: calcular a média
  Recebe: número de elementos do vector e um ponteiro para o primeiro elemento do vector.
  Devolve:
  Retorna: média
-----------------------------------------------------------------------------------------*/
float media (int n, float *v)
{
  float s = 0.0;
  for (int i = 0; i < n; i++) s += v[i];
  return s/n;
}
/*----------------------------------------------------------------------------------------
  Objectivo: calcular a mediana (variância)
  Recebe: número de elementos do vector, um ponteiro para o primeiro elemento do vector e o valor da média.
  Devolve:
  Retorna: variância
-----------------------------------------------------------------------------------------*/
float variancia (int n, float *v, float m)
{
  float s = 0.0;
  for (int i = 0; i < n; i++) s += (v[i] - m) * (v[i] - m);
  return s/n;
}
