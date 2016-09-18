#include <stdio.h>
#include <math.h>
int main()
{
    float x,a,g;
    scanf("%f", &a); scanf("%f", &x);
    g = a+x; printf("g1 = %f\n", g);
    g = a+x*a; printf("g2 = %f\n", g);
    g = (a+x)*a; printf("g3 = %f\n", g);
    g = (a+x)/3.5f; printf("g4 = %f\n", g);
    g = (a+x)/(2+a); printf("g5 = %f\n", g);
    g /= 10; printf("g6 = %f\n", g);

    return 0;
}