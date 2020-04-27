#include "funcoes.h"
#include <stdio.h>

int factorial(int n)
{
    if(n < 2) return 1;
    return n*factorial(n-1);
}


int potencia(int x, int y)
{
    if(y == 0) return 1;
    return x*potencia(x, y - 1);
}
