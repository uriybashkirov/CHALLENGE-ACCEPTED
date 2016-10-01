#include <stdio.h>
#include <math.h>

int main()
{
    double F,Y,x,a;
    char G;
    int b;

    scanf("%lf", &a);
    scanf("%lf", &x);

    G=((9*(7*a*a+39*a*x+20*x*x))/9*a*a+59*a*x+30*x*x);
    F=(tanh(9*a*a-14*a*x+5*x*x));
    Y=(log(14*a*a-75*a*x+54*x*x+1)/log(10));

    scanf("%d", &b);

    switch (b)
    {
        case 1:
            if (G > 0) {
                printf("%s\n", "Hello, is tue G > 0 ");
                printf("%d\n", G);
            }
            else {
                printf("%s\n" , "This is else,G < 0 ");
            }
                break;

        case 2:
            if (F > 0) {
                printf("%s\n", "Hello , F > 0 ");
                printf("%f\n", F);
            }
            else {
                printf("%s\n" , "Hello is else , F < 0");
            }
                break;

        case 3:
            if (Y > 0){
                printf("%s\n", "Hello is true , Y > 0");
                printf("%f\n", Y);
            }
            else {
                printf("%s\n", "Hello is else , Y < 0 ");
            }

            break;

    }

    return 0;
}