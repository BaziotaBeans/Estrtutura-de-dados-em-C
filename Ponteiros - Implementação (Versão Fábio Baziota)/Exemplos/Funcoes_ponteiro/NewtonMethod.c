#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1.0E-10 /* erro de aproximação */

double Newton(double f(double), double a, double b);


int main(int argc, char const *argv[])
{
  double raiz;
  printf ("Funcao cosseno entre 0 e pi:\n");
  raiz = Newton (cos,0.0,3.141592);
  printf (" \t Raiz no ponto %g\n ", raiz);
  printf (" \t Valor de cos(%g) = %g\n ", raiz, cos(raiz));
  return 0;
}


double Newton(double f(double), double a, double b)
{
  double m, x;
  do
  {
    m = (a+b)/2.0;
    x = f(m);
    if ((fabs(x < EPSILON)) || (fabs(b - a < EPSILON))) break;
    if (f(a)*x > 0.0) a=m;
    else b=m;
  }while (1);
  return m;
}
