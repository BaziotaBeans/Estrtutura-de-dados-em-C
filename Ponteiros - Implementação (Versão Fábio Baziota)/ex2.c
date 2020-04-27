#include <stdio.h>
#include <stdlib.h>





int main()
{
	float x = 1.0, y = 5, z;
  float *p = &x;
  z = (*p) + y;
	printf("\n%f\n",z);
	return 0;
}
