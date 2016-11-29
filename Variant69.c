#include <stdio.h>
#include <math.h>

int main()
{
    double G,F,Y,x,a;

    scanf("%lf", &a);
    scanf("%lf", &x);

    G=(9*(7*a*a+39*a*x+20*x*x))/(9*a*a+59*a*x+30*x*x);
    F=(tanh(9*a*a-14*a*x+5*x*x));
    Y=(log(14*a*a-75*a*x+54*x*x+1)/log(10));

    printf("%f\n", G);
    printf("%f\n", F);
    printf("%f\n", Y);

    return 0;
}
