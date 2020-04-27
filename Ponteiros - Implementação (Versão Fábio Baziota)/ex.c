#include <stdio.h>
#include <stdlib.h>





int main()
{
	float x = -1.0;
	float *p = &x;
	*p = 5.0;
	printf("\n%f\n",x);
	return 0;
}
