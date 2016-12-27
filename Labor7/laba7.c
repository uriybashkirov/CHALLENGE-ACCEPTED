#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct values_function_and_x{
    double x;
    double x_values[200];
    double y_values[200];
}g, f, y;
int main() {
    int k,m,i, restart, j, adaptive_step;
    double G, F, x,Y, a, x1, step, max_x, min_x, max_y, min_y, len_pattern, dif, sum_len_and_dif;
    char mas_x_and_y[400], pattern[400], mas_y[200], mas_x[200], *s, for_data[100];
    j = 0;
    restart = 1;
    char all_values[750];
    do {
        if (restart == 1) {

            printf("%s", "Введите начальную границу X = ");
            scanf("%s", for_data);
            x = atof(for_data);
            g.x=x;
            f.x=g.x;
            y.x=f.x;
            printf("%s", "Введите A = ");
            scanf("%s", for_data);
            a = atof(for_data);
            printf("%s", "Введите конечную границу Х1 = ");
            scanf("%s", for_data);
            x1 = atof(for_data);
            printf("%s", "Введите размер шага= ");
            scanf("%s", for_data);
            step = atof(for_data);
            printf("%s", "Включить адаптивный шаг? 1 если да, 0 если нет");
            scanf("%i", &adaptive_step);
            memset(mas_x_and_y, 0, 400);
            memset(mas_y, 0, 200);
            memset(mas_x, 0, 200);
            while (g.x <= x1) {
                memset(mas_x_and_y, 0, 400);
                memset(mas_y, 0, 200);
                memset(mas_x, 0, 200);
                if ((5 * pow(a, 2) - 9 * a * g.x + 4 * pow(g.x, 4)) != 0) {
                    G = (5 * (-10 * pow(a, 2) + 27 * a * g.x + 28 * pow(g.x, 2))) /
                        (5 * pow(a, 2) - 9 * a * g.x + 4 * pow(g.x, 4));

                    if (j == 0) {
                        printf("┌───────────────────┬───────────────────┐\n");
                        printf("│         X         │         Y         │\n");
                        printf("├───────────────────┼───────────────────┤\n");
                    }
                    if (adaptive_step == 1) { /*проверяется условие на включение адаптивного шага*/
                        g.x_values[j] = g.x;
                        g.y_values[j] = G;
                        printf("│%19.3lf│%19.3lf│\n", g.x, G);
                        if (j > 0) { /* адаптивный шаг считается если известны оба значения*/
                            if (((g.y_values[j - 1] / g.y_values[j]) > 2) || ((g.y_values[j] / g.y_values[j - 1]) >
                                                                              2)) { /* если коэфициент отношения между значениями слишком большой, то уменьшаем шаг*/
                                g.x += step / 2;
                            } else {
                                if (((g.y_values[j - 1] / g.y_values[j]) < 0.5) ||
                                    ((g.y_values[j] / g.y_values[j - 1]) <
                                     0.5)) { /*если коэфициент отношения между значениями слишком маленький, то увеличиваем шаг */
                                    g.x += step * 2;
                                } else g.x += step; /*если изменять шаг не нужно, то прссто прибавляем к значению Х размер обычного шага*/
                            }
                        } else g.x += step;
                    } else {
                        g.x_values[j] = g.x;
                        g.y_values[j] = G;
                        printf("X=%.3lf Y=%.3lf\n", g.x, G);
                        g.x += step;
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
                        max_x = g.x_values[i];
                        min_x = g.x_values[i];
                        max_y = g.y_values[i];
                        min_y = g.y_values[i];
                    }
                    if (max_x <
                        g.x_values[i])/*если текущее максимальное число меньше чем текущий элемент массива*/
                        max_x = g.x_values[i];/*то заменяем это максимальное число на этот элемент, аналогично и с 'y'*/
                    if (min_x >
                        g.x_values[i])/*если текущее минимальное число больше чем текущий элемент массива*/
                        min_x = g.x_values[i];/*то заменяем это минимальное число на этот элемент, аналогично и с 'y'*/
                    if (max_y < g.y_values[i])
                        max_y = g.y_values[i];
                    if (min_y > g.y_values[i])
                        min_y = g.y_values[i];
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

            for (i = 0; i < j; i++) {
                sprintf(mas_x, "%.2lf ", g.x_values[i]);
                sprintf(mas_y, "%.2lf ", g.y_values[i]);
                strcat(mas_x_and_y, mas_x);
                strcat(mas_x_and_y, mas_y);
            }

            printf("%s\n", mas_x_and_y);
            printf("Введите то, что хотите проверить:");
            scanf("%s", &pattern);

            s = strstr(mas_x_and_y, pattern); /*Ищем то, что ввели в pattern в массиву mas_x_and_y,
                * если не найдёт, то вернёт Null*/
            if (s != NULL) { /* Если нашло, то входим в цикл */
                while (s != NULL) { /*Выполнять поиск на совпадение, пока не вернёт null*/
                    s = strstr(mas_x_and_y, pattern); /* снова ищем совпадение*/
                    len_pattern = strlen(pattern); /* находим длину строки-шаблона*/
                    dif = s -
                          mas_x_and_y;/*находим разницу между длинами количеством знаков в оставшейся строке s и оригинальной mas_x_and_y */
                    sum_len_and_dif = len_pattern + dif; /* сумма длин строки-шаблона и разницы*/
                    for (j = 0; j <= sum_len_and_dif; ++j) {
                        memset(mas_x_and_y, '@', j); /* Заменяем символы включая найденный на другой знак*/
                        if (j == sum_len_and_dif) { /*когда индекс заменяемого символа будет равен индексу найденного
                                символа мы засчитываем это*/
                            i += 1;
                        }
                    }
                }
                printf("Количество найденных совпадений:%i\n", i);
            } else
                printf("Строка не найдена\n"); /*Если s = strstr(mas_x_and_y, pattern); вернёт нам null,
                    то значит ничего не нашлось*/
            memset(mas_x_and_y, 0, 400);
            memset(mas_y, 0, 200);
            memset(mas_x, 0, 200);
            k=j;
            j=0;
            while (f.x <= x1) {
                F = sin(28 * pow(a, 2) - 57 * a * f.x + 14 * pow(f.x, 2));
                if (j == 0) {
                    printf("┌───────────────────┬───────────────────┐\n");
                    printf("│         X         │         Y         │\n");
                    printf("├───────────────────┼───────────────────┤\n");
                }
                if (adaptive_step == 1) { /*проверяется условие на включение адаптивного шага*/
                    f.x_values[j] = f.x;
                    f.y_values[j] = F;
                    printf("│%14.3lf│%14.3lf│\n", f.x, F);
                    if (j > 0) { /* адаптивный шаг считается если известны оба значения*/
                        if (((f.y_values[j - 1] / f.y_values[j]) > 2) || ((f.y_values[j] / f.y_values[j - 1]) >
                                                                          2)) { /* если коэфициент отношения между значениями слишком большой, то уменьшаем шаг*/
                            f.x += step / 2;
                        } else {
                            if (((f.y_values[j - 1] / f.y_values[j]) < 0.5) ||
                                ((f.y_values[j] / f.y_values[j - 1]) <
                                 0.5)) { /*если коэфициент отношения между значениями слишком маленький, то увеличиваем шаг */
                                f.x += step * 2;
                            } else f.x += step; /*если изменять шаг не нужно, то прссто прибавляем к значению Х размер обычного шага*/
                        }
                    } else f.x += step;
                } else {
                    f.x_values[j] = f.x;
                    f.y_values[j] = G;
                    printf("│%14.3lf│%14.3lf│\n", f.x, F);
                    f.x += step;
                }
                j += 1;
                continue;

                break;
            }
            if (j != 0) {
                for (i = 0; i < j; i++) {
                    if (i == 0) {
                        /* задаём всем макимальным и минимальным значениям самые первые элементы массивов*/
                        max_x = f.x_values[i];
                        min_x = f.x_values[i];
                        max_y = f.y_values[i];
                        min_y = f.y_values[i];
                    }
                    if (max_x <
                        f.x_values[i])/*если текущее максимальное число меньше чем текущий элемент массива*/
                        max_x = f.x_values[i];/*то заменяем это максимальное число на этот элемент, аналогично и с 'y'*/
                    if (min_x >
                        f.x_values[i])/*если текущее минимальное число больше чем текущий элемент массива*/
                        min_x = f.x_values[i];/*то заменяем это минимальное число на этот элемент, аналогично и с 'y'*/
                    if (max_y < f.y_values[i])
                        max_y = f.y_values[i];
                    if (min_y > f.y_values[i])
                        min_y = f.y_values[i];
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
            for (i = 0; i < j; i++) {
                sprintf(mas_x, "%.2lf ", f.x_values[i]);
                sprintf(mas_y, "%.2lf ", f.y_values[i]);
                strcat(mas_x_and_y, mas_x);
                strcat(mas_x_and_y, mas_y);
            }

            printf("%s\n", mas_x_and_y);
            printf("Введите то, что хотите проверить:");
            scanf("%s", &pattern);

            s = strstr(mas_x_and_y, pattern); /*Ищем то, что ввели в pattern в массиву mas_x_and_y,
                * если не найдёт, то вернёт Null*/
            if (s != NULL) { /* Если нашло, то входим в цикл */
                while (s != NULL) { /*Выполнять поиск на совпадение, пока не вернёт null*/
                    s = strstr(mas_x_and_y, pattern); /* снова ищем совпадение*/
                    len_pattern = strlen(pattern); /* находим длину строки-шаблона*/
                    dif = s - mas_x_and_y;/*находим разницу между длинами количеством знаков в оставшейся строке s и оригинальной mas_x_and_y */
                    sum_len_and_dif = len_pattern + dif; /* сумма длин строки-шаблона и разницы*/
                    for (j = 0; j <= sum_len_and_dif; ++j) {
                        memset(mas_x_and_y, '@', j); /* Заменяем символы включая найденный на другой знак*/
                        if (j == sum_len_and_dif) { /*когда индекс заменяемого символа будет равен индексу найденного
                                символа мы засчитываем это*/
                            i += 1;
                        }
                    }
                }
                printf("Количество найденных совпадений:%i\n", i);
            } else
                printf("Строка не найдена\n"); /*Если s = strstr(mas_x_and_y, pattern); вернёт нам null,
                    то значит ничего не нашлось*/
            memset(mas_x_and_y, 0, 400);
            memset(mas_y, 0, 200);
            memset(mas_x, 0, 200);
            m=j;
            j=0;
            while (y.x <= x1) {

                Y = log(-27 * pow(a, 2) + 24 * a * y.x + 35 * pow(y.x, 2) + 1);
                if (Y > 0) {
                    if (j == 0) {
                        printf("┌───────────────────┬───────────────────┐\n");
                        printf("│         X         │         Y         │\n");
                        printf("├───────────────────┼───────────────────┤\n");
                    }
                    if (adaptive_step == 1) { /*проверяется условие на включение адаптивного шага*/
                        y.x_values[j] = y.x;
                        y.y_values[j] = Y;
                        printf("│%11.3lf│%11.3lf│\n", y.x, Y);
                        if (j > 0) { /* адаптивный шаг считается если известны оба значения*/
                            if (((y.y_values[j - 1] / y.y_values[j]) > 2) || ((y.y_values[j] / y.y_values[j - 1]) >
                                                                              2)) { /* если коэфициент отношения между значениями слишком большой, то уменьшаем шаг*/
                                y.x += step / 2;
                            } else {
                                if (((y.y_values[j - 1] / y.y_values[j]) < 0.5) ||
                                    ((y.y_values[j] / y.y_values[j - 1]) <
                                     0.5)) { /*если коэфициент отношения между значениями слишком маленький, то увеличиваем шаг */
                                    y.x += step * 2;
                                } else y.x += step; /*если изменять шаг не нужно, то прссто прибавляем к значению Х размер обычного шага*/
                            }
                        } else y.x += step;

                    } else {
                        y.x_values[j] = y.x;
                        y.y_values[j] = Y;
                        printf("X=%.3lf Y=%.3lf\n", y.x, Y);
                        y.x+= step;
                    }
                    j += 1;
                    continue;
                } else
                    printf("%s\n",
                           "Логарифм не может быть найден при таких значениях переменных. Введите другие значения переменных.");

                break;
            }
            if (j != 0) {
                for (i = 0; i < j; i++) {
                    if (i == 0) {
                        /* задаём всем макимальным и минимальным значениям самые первые элементы массивов*/
                        max_x = y.x_values[i];
                        min_x = y.x_values[i];
                        max_y = y.y_values[i];
                        min_y = y.y_values[i];
                    }
                    if (max_x <
                        y.x_values[i])/*если текущее максимальное число меньше чем текущий элемент массива*/
                        max_x = y.x_values[i];/*то заменяем это максимальное число на этот элемент, аналогично и с 'y'*/
                    if (min_x >
                        y.x_values[i])/*если текущее минимальное число больше чем текущий элемент массива*/
                        min_x = y.x_values[i];/*то заменяем это минимальное число на этот элемент, аналогично и с 'y'*/
                    if (max_y < y.y_values[i])
                        max_y = y.y_values[i];
                    if (min_y > y.y_values[i])
                        min_y = y.y_values[i];
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
            for (i = 0; i < j; i++) {
                sprintf(mas_x, "%.2lf ", y.x_values[i]);
                sprintf(mas_y, "%.2lf ", y.y_values[i]);
                strcat(mas_x_and_y, mas_x);
                strcat(mas_x_and_y, mas_y);
            }

            printf("%s\n", mas_x_and_y);
            printf("Введите то, что хотите проверить:");
            scanf("%s", &pattern);

            s = strstr(mas_x_and_y, pattern); /*Ищем то, что ввели в pattern в массиву mas_x_and_y,
                * если не найдёт, то вернёт Null*/
            if (s != NULL) { /* Если нашло, то входим в цикл */
                while (s != NULL) { /*Выполнять поиск на совпадение, пока не вернёт null*/
                    s = strstr(mas_x_and_y, pattern); /* снова ищем совпадение*/
                    len_pattern = strlen(pattern); /* находим длину строки-шаблона*/
                    dif = s -
                          mas_x_and_y;/*находим разницу между длинами количеством знаков в оставшейся строке s и оригинальной mas_x_and_y */
                    sum_len_and_dif = len_pattern + dif; /* сумма длин строки-шаблона и разницы*/
                    for (j = 0; j <= sum_len_and_dif; ++j) {
                        memset(mas_x_and_y, '@', j); /* Заменяем символы включая найденный на другой знак*/
                        if (j == sum_len_and_dif) { /*когда индекс заменяемого символа будет равен индексу найденного
                                символа мы засчитываем это*/
                            i += 1;
                        }
                    }
                }
                printf("Количество найденных совпадений:%i\n", i);
            } else
                printf("Строка не найдена\n"); /*Если s = strstr(mas_x_and_y, pattern); вернёт нам null,
                    то значит ничего не нашлось*/
        }

        printf("%s",
               "Хотите ли ещё раз просчитать функцию? \n Введите 1 если хотите просчитать заново. \n Введите 0 для отмены.");
        scanf("%i", &restart);

        if (restart == 0) break;
        else continue;
    } while (1);
    FILE *file;
    file = fopen("text.txt","w");  /*запись в файл*/
    fprintf(file, "\n\n\n");
    if ((k>j) && (k>m))  j=k;
    if ((m>j) && (m>k))  j=m;
    for (i = 0; i < j; i++)
    {
        fprintf(file,"%lf %lf %lf %lf %lf %lf\n",g.x_values[i], g.y_values[i],f.x_values[i],f.y_values[i], y.x_values[i],y.y_values[i]);
    }

    fclose(file);
    file = fopen("text.txt","r"); /*с файла считываются все данные*/


    while (!feof(file))
    {
        fscanf(file, "%s", all_values);
        printf("%s\n", all_values);
    }
    fclose(file);
    return 0;
}
