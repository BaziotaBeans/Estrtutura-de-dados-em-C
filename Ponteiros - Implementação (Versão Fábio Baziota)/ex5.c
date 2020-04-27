#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main(int argc, char const *argv[])
{

    double (*p)(double);
    p = sqrt;
    printf("%lf\n", p(4));
    return 0;
}
