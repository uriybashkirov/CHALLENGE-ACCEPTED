#include <stdio.h>
#include <math.h>
int main()
{
    int x;
    float g;
    scanf("%d", &x);
    g = log((float)x)/log(2.0);
    printf("g = %f\n", g);
    return 0;
}