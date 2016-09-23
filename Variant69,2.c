#include <stdio.h>
#include <math.h>

int main()
{
    char r;
    double G,F,Y,a,x;

    printf("Введите x: \n");
    scanf ("%lf", &x);

    printf("Введите a: \n");
    scanf ("%lf", &a);

    printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
    scanf ("%s", &r);

    switch (r){
        case 'G':
            G=-((9*(7*a*a+39*a*x+20*x*x))/9*a*a+59*a*x+30*x*x);
            printf("G = %lf \n", G);
            break;

        case 'F':
            F=(tanh(9*a*a-14*a*x+5*x*x));
            printf("F = %lf \n", F);
            break;

        case 'Y':
            Y=(log(14*a*a-75*a*x+54*x*x+1)/log(10));
            printf("Y = %lf \n", Y);
            break;
    }

    return 0;
}