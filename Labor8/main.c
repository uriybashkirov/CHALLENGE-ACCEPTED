#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_for_x(int x, int x_end) {
    return x + rand() % (x_end - x);
}

int rand_for_y(int y, int y_end) {
    return y + rand() % (y_end - y);
}


int main() {
    double rad;
    int y_start, x_and_y_end,x_start, i = 0, l, amount_of_points;
    l = 0;
    x_start = -5;
    y_start = x_start;
    x_and_y_end = 5;
    printf("Введите радиус окружности: ");
    scanf("%lf", &rad);
    FILE *file;
    file = fopen("text.dat", "w+");

    for (amount_of_points = 200; amount_of_points < 5000; amount_of_points+=200) { 

        clock_t time; /* найдем время выполнения программы */
        time = clock();

        int x[amount_of_points];
        int y[amount_of_points];

        for (i = 0; i < amount_of_points; ++i) {
            x[i] = rand_for_x(x_start, x_and_y_end);
            y[i] = rand_for_y(y_start, x_and_y_end);
        }

        i = 1 + rand() % (amount_of_points - 1); /*тот же алгоритм */
        printf("Координаты случайно выбранной точки [%i,%i]\n", x[i], y[i]);

        i = 0;
        while ((x[i] > 0.0000001) || (x[i] <= -0.0000001)) {
            if (x[i] * x[i] + y[i] * y[i] <= rad * rad) {
                l++;
            }
            i++;
        }
        printf("Количество точек, принадлежащих окружности составляет: %i\n", l);

        time = clock() - time;
        printf("Время выполнения: %f\n", (double)time/CLOCKS_PER_SEC);
        fprintf(file, "%i %f\n",amount_of_points,(double)time/CLOCKS_PER_SEC);

    }

    fclose(file);

    return 0;
}

