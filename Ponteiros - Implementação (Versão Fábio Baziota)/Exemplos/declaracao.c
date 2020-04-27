#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{

  float x = 9;
  float *p;

  p = &x;
  *p = 30;
  p++;
  printf("%f\n",x);
  return 0;
}
