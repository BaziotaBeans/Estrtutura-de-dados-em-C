#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double lerN();


int main(int argc, char const *argv[])
{
  double (*p)(double);
  p = sqrt;
  printf("The Squart is %.2lf\n", p(lerN()));
  return 0;
}


double lerN()
{
  double n;
  printf("Digite um numero: "); scanf("%lf",&n);
  return n;
}
