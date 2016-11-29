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
    /*
     * Добавляю оператор выбора переменных (switch) согласно заданию.
     */

    switch (r){
        /*оператор case выражение которого соответствует значению выражения switch*/
        case 'G':
            G=-((9*(7*a*a+39*a*x+20*x*x))/(9*a*a+59*a*x+30*x*x));
            printf("G = %lf \n", G);
            break;

        case 'F':
            F=(tanh(9*a*a-14*a*x+5*x*x));
            printf("F = %lf \n", F);
            break;

        case 'Y':
            /*Применил оператор выбора if.Первая часть выражения будет выполнятся если Y > 0 .Оператор else выполняется если выражение ложно  */
                Y = (log(14 * a * a - 75 * a * x + 54 * x * x + 1) / log(10));
                printf("Y = %lf \n", Y);
                break;

            /* Оператор default выполняется если ни одно из значений case  не равно значению switch. */
        default: printf("%s\n", "Ошибка. Для вывода результата укажите одну из переменных G,F,Y.");



    }
    return 0;
}
