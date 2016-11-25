#include <stdio.h>
#include <math.h>

int main() {
    int n,i, restart, j, adaptive_step;
    double G, F, Y, x, a, x1, step, y_values[200], x_values[200], max_x,min_x,max_y,min_y;
    j = 0;
    restart = 1;
    do {
        if (restart == 1) {
            printf("%s", "Введите начальную границу X = ");
            scanf("%lf", &x);
            printf("%s", "Введите A = ");
            scanf("%lf", &a);
            printf("%s", "Введите конечную границу Х1 = ");
            scanf("%lf", &x1);
            printf("%s", "Введите размер шага= ");
            scanf("%lf", &step);
            printf("%s",
                   "Введите: \n N = 1 для нахождения значения переменной G. \n N = 2 для нахождения значения переменной F. \n N = 3 для нахождения значения переменной Y. \n");
            scanf("%i", &n);
            printf("%s", "Включить адаптивный шаг? 1 если да, 0 если нет");
            scanf("%i", &adaptive_step);
            FILE *file;
            file = fopen("text.txt",
                         "w+");/*открываем фаил или создаем его если его нет, перезаписываем файл каждый раз(потому что стиит w)*/
            switch (n) {
                case 1:
                    while (x <= x1) {
                        if ((5 * pow(a, 2) - 9 * a * x + 4 * pow(x, 4)) != 0) {
                            G = (5 * (-10 * pow(a, 2) + 27 * a * x + 28 * pow(x, 2))) /
                                (5 * pow(a, 2) - 9 * a * x + 4 * pow(x, 4));
                            fprintf(file, "%.2lf\n%.2lf\n", x, G);
                            if (j == 0) {
                                printf("┌───────────────────┬───────────────────┐\n");
                                printf("│         X         │         Y         │\n");
                                printf("├───────────────────┼───────────────────┤\n");
                            }
                            if (adaptive_step == 1) { /*проверяется условие на включение адаптивного шага*/
                                x_values[j] = x;
                                y_values[j] = G;
                                printf("│%19.3lf│%19.3lf│\n",x,G );
                                if (j > 0) { /* адаптивный шаг считается если известны оба значения*/
                                    if (((y_values[j - 1] / y_values[j]) > 2) || ((y_values[j] / y_values[j - 1]) >
                                                                                  2)) { /* если коэфициент отношения между значениями слишком большой, то уменьшаем шаг*/
                                        x += step / 2;
                                    } else {
                                        if (((y_values[j - 1] / y_values[j]) < 0.5) ||
                                            ((y_values[j] / y_values[j - 1]) <
                                             0.5)) { /*если коэфициент отношения между значениями слишком маленький, то увеличиваем шаг */
                                            x += step * 2;
                                        } else x += step; /*если изменять шаг не нужно, то прссто прибавляем к значению Х размер обычного шага*/
                                    }
                                }
                            } else {
                                x_values[j] = x;
                                y_values[j] = G;
                                printf("X=%.3lf Y=%.3lf\n", x, G);
                                x += step;
                            } /* если адаптивный не срабатывает, т.е. не зачем увеличивать или уменьшать шаг, то просто прибавляем значение r*/
                            j += 1;
                            continue;
                        } else
                            printf("%s\n",
                                   "G не может быть результатом деления на 0. Введите другие значения переменных.");
                        break;
                    }
                    if (j != 0) {
                        for (i = 0; i < j; i++) {
                            if (i == 0) {
                                /* задаём всем макимальным и минимальным значениям самые первые элементы массивов*/
                                max_x = x_values[i];
                                min_x = x_values[i];
                                max_y = y_values[i];
                                min_y = y_values[i];
                            }
                            if (max_x < x_values[i])/*если текущее максимальное число меньше чем текущий элемент массива*/
                                max_x = x_values[i];/*то заменяем это максимальное число на этот элемент, аналогично и с 'y'*/
                            if (min_x > x_values[i])/*если текущее минимальное число больше чем текущий элемент массива*/
                                min_x =x_values[i];/*то заменяем это минимальное число на этот элемент, аналогично и с 'y'*/
                            if (max_y < y_values[i])
                                max_y = y_values[i];
                            if (min_y > y_values[i])
                                min_y = y_values[i];
                        }

                        printf("├───────────────────┴────┬──────────────┤\n");
                        printf("│Максимальное значение Х:│%14.4lf│\n", max_x);
                        printf("├────────────────────────┼──────────────┤\n");
                        printf("│Минимальное значение Х: │%14.4lf│\n", min_x);
                        printf("├────────────────────────┼──────────────┤\n");
                        printf("│Максимальное значение Y:│%14.4lf│\n", max_y);
                        printf("├────────────────────────┼──────────────┤\n");
                        printf("│Минимальное значение Y: │%14.4lf│\n", min_y);
                        printf("└────────────────────────┴──────────────┘\n");
                    }
                    break;
                case 2:
                    while (x <= x1) {
                        F = sin(28 * pow(a, 2) - 57 * a * x + 14 * pow(x, 2));
                        if ((F >= -1) && (F <= 1)) {
                            fprintf(file, "%.2lf\n%.2lf\n", x, F);
                            if (j == 0) {
                                printf("┌───────────────────┬───────────────────┐\n");
                                printf("│         X         │         Y         │\n");
                                printf("├───────────────────┼───────────────────┤\n");
                            }
                            if (adaptive_step == 1) { /*проверяется условие на включение адаптивного шага*/
                                x_values[j] = x;
                                y_values[j] = F;
                                printf("│%11.3lf│%11.3lf│\n",x,F );
                                if (j > 0) { /* адаптивный шаг считается если известны оба значения*/
                                    if (((y_values[j - 1] / y_values[j]) > 2) || ((y_values[j] / y_values[j - 1]) >
                                                                                  2)) { /* если коэфициент отношения между значениями слишком большой, то уменьшаем шаг*/
                                        x += step / 2;
                                    } else {
                                        if (((y_values[j - 1] / y_values[j]) < 0.5) ||
                                            ((y_values[j] / y_values[j - 1]) <
                                             0.5)) { /*если коэфициент отношения между значениями слишком маленький, то увеличиваем шаг */
                                            x += step * 2;
                                        } else x += step; /*если изменять шаг не нужно, то прссто прибавляем к значению Х размер обычного шага*/
                                    }
                                }
                            } else {
                                x_values[j] = x;
                                y_values[j] = G;
                                printf("X=%.3lf Y=%.3lf\n", x, F);
                                x += step;
                            }
                            j += 1;
                            continue;
                        }
                        printf("%s\n",
                               "Переменная F не принадлежит отрезку синуса от -1 до 1. Введите другие значения");
                        break;
                    }
                    if (j != 0) {
                        for (i = 0; i < j; i++) {
                            if (i == 0) {
                                /* задаём всем макимальным и минимальным значениям самые первые элементы массивов*/
                                max_x = x_values[i];
                                min_x = x_values[i];
                                max_y = y_values[i];
                                min_y = y_values[i];
                            }
                            if (max_x < x_values[i])/*если текущее максимальное число меньше чем текущий элемент массива*/
                                max_x = x_values[i];/*то заменяем это максимальное число на этот элемент, аналогично и с 'y'*/
                            if (min_x > x_values[i])/*если текущее минимальное число больше чем текущий элемент массива*/
                                min_x =x_values[i];/*то заменяем это минимальное число на этот элемент, аналогично и с 'y'*/
                            if (max_y < y_values[i])
                                max_y = y_values[i];
                            if (min_y > y_values[i])
                                min_y = y_values[i];
                        }
                        printf("├───────────────────┴────┬──────────────┤\n");
                        printf("│Максимальное значение Х:│%14.4lf│\n", max_x);
                        printf("├────────────────────────┼──────────────┤\n");
                        printf("│Минимальное значение Х: │%14.4lf│\n", min_x);
                        printf("├────────────────────────┼──────────────┤\n");
                        printf("│Максимальное значение Y:│%14.4lf│\n", max_y);
                        printf("├────────────────────────┼──────────────┤\n");
                        printf("│Минимальное значение Y: │%14.4lf│\n", min_y);
                        printf("└────────────────────────┴──────────────┘\n");
                    }
                    break;
                case 3:
                    while (x <= x1) {
                        Y = log(-27 * pow(a, 2) + 24 * a * x + 35 * pow(x, 2) + 1);
                        if (Y > 0) {
                            fprintf(file, "%.2lf\n%.2lf\n", x, Y);
                            if (j == 0) {
                                printf("┌───────────────────┬───────────────────┐\n");
                                printf("│         X         │         Y         │\n");
                                printf("├───────────────────┼───────────────────┤\n");
                            }
                            if (adaptive_step == 1) { /*проверяется условие на включение адаптивного шага*/
                                x_values[j] = x;
                                y_values[j] = Y;
                                printf("│%11.3lf│%11.3lf│\n",x,Y );
                                if (j > 0) { /* адаптивный шаг считается если известны оба значения*/
                                    if (((y_values[j - 1] / y_values[j]) > 2) || ((y_values[j] / y_values[j - 1]) >
                                                                                  2)) { /* если коэфициент отношения между значениями слишком большой, то уменьшаем шаг*/
                                        x += step / 2;
                                    } else {
                                        if (((y_values[j - 1] / y_values[j]) < 0.5) ||
                                            ((y_values[j] / y_values[j - 1]) <
                                             0.5)) { /*если коэфициент отношения между значениями слишком маленький, то увеличиваем шаг */
                                            x += step * 2;
                                        } else x += step; /*если изменять шаг не нужно, то прссто прибавляем к значению Х размер обычного шага*/
                                    }
                                }
                            } else {
                                x_values[j] = x;
                                y_values[j] = Y;
                                printf("X=%.3lf Y=%.3lf\n", x, Y);
                                x += step;
                            }
                            j += 1;
                            continue;
                        } else
                            printf("%s\n",
                                   "Логарифм не может быть найден при таких значениях переменных. Введите другие значения переменных.");
                        break;
                    }if (j != 0) {
                for (i = 0; i < j; i++) {
                    if (i == 0) {
                        /* задаём всем макимальным и минимальным значениям самые первые элементы массивов*/
                        max_x = x_values[i];
                        min_x = x_values[i];
                        max_y = y_values[i];
                        min_y = y_values[i];
                    }
                    if (max_x < x_values[i])/*если текущее максимальное число меньше чем текущий элемент массива*/
                        max_x = x_values[i];/*то заменяем это максимальное число на этот элемент, аналогично и с 'y'*/
                    if (min_x > x_values[i])/*если текущее минимальное число больше чем текущий элемент массива*/
                        min_x =x_values[i];/*то заменяем это минимальное число на этот элемент, аналогично и с 'y'*/
                    if (max_y < y_values[i])
                        max_y = y_values[i];
                    if (min_y > y_values[i])
                        min_y = y_values[i];
                }
                printf("├───────────────────┴────┬──────────────┤\n");
                printf("│Максимальное значение Х:│%14.4lf│\n", max_x);
                printf("├────────────────────────┼──────────────┤\n");
                printf("│Минимальное значение Х: │%14.4lf│\n", min_x);
                printf("├────────────────────────┼──────────────┤\n");
                printf("│Максимальное значение Y:│%14.4lf│\n", max_y);
                printf("├────────────────────────┼──────────────┤\n");
                printf("│Минимальное значение Y: │%14.4lf│\n", min_y);
                printf("└────────────────────────┴──────────────┘\n");
            }
                    break;

                default:
                    printf("%s\n",
                           "Ошибка, попросите вывод результата одной из переменных G,F или Y.");
            }

        }


        printf("%s",
               "Хотите ли ещё раз просчитать функцию? \n Введите 1 если хотите просчитать заново. \n Введите 0 для отмены.");
        scanf("%i", &restart);

        if (restart == 0) break;
        else continue;
    } while (1);

    return 0;
