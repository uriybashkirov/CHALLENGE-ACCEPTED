from numpy import *
import numpy as np
import matplotlib.pyplot as plt

function = []
val_x = []

uslovie = int(1)
for_y = int(1)
for_values = int(1)
i = int(0)
j = int(0)
values1 = float(0)
values2 = float(0)
while uslovie == 1:
    x = float(input('Введите x = '))
    a = float(input('Введите a = '))
    x1 = float(input('Введите x1 = '))
    step = float(input('Введите размер шага= '))
    n = float(input(
        'Введите: \nN = 1 для нахождения значения переменной G.\nN = 2 для нахождения значения переменной F.\nN = 3 для нахождения значения переменной Y.'))
    if n == 1:
        while x < x1:
            if (9 * a * a + 59 * a * x + 30 * x * x) != 0:
                G = -((9 * (7 * a * a + 39 * a * x + 20 * x * x)) / (9 * a * a + 59 * a * x + 30 * x * x))
                if i == 0:
                    print('┌───────────────────┬───────────────────┐')
                    print('│         X         │         Y         │')
                    print('├───────────────────┼───────────────────┤')
                print('│{:^19}'.format(x) + '│{:^19}'.format(round(G, 3)) + '│')
                val_x.append(x)  # добавляем в список val_x значение x
                function.append(G)  # добавляем в список function значение G
                if i > 1:
                    values1 = array(
                        function[i - 1:i])  # присваеваем переменной values1 и values2 значения массива(не списка)
                    values2 = array(function[
                                    i:i + 1])  # мы берём предыдущее и текущее знaчение y (values1 предыдущее, values2 текущее значение функции)
                    if ((values1 / values2) > 2) or ((values2 / values1) > 2):  # считаем отношение, как в си
                        x += (step / 2)
                    elif ((values1 / values2) < 0.5) or ((values2 / values1) < 0.5):
                        x += (step * 2)
                    else:
                        x += step
                else:
                    x += step
                i += 1


            else:
                print(
                    'Функция G не может быть составлена, ибо является результатом деления на 0. Введите другие значения переменных.')
                break
        print('├───────────────────┴────┬──────────────┤')
        print('│Максимальное значение Х:│' + '{:^14}'.format(max(val_x)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Минимальное значение Х: │' + '{:^14}'.format(min(val_x)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Максимальное значение Y:│' + '{:^14}'.format(round(max(function), 2)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Минимальное значение Y: │' + '{:^14}'.format(round(min(function), 2)) + '│')
        print('└────────────────────────┴──────────────┘')
        print('Количество шагов: ', str(i))
        plt.plot(val_x, function)
        plt.show()
        i = 0
    elif n == 2:
        while x < x1:
            F = math.sin(28 * a ** 2 - 57 * a * x + 14 * x ** 2)
            if i == 0:
                print('┌───────────────────┬───────────────────┐')
                print('│         X         │         Y         │')
                print('├───────────────────┼───────────────────┤')
            print('X=' + str(x) + 'Y=' + str(round(F, 3)))
            val_x.append(x)
            function.append(F)
            if i > 1:
                values1 = array(function[i - 1:i])
                values2 = array(function[i:i + 1])
                if ((values1 / values2) > 2) or ((values1 / values2) > 2):
                    x += (step / 2)
                elif ((values1 / values2) < 0.5) or ((values1 / values2) < 0.5):
                    x += (step * 2)
                else:
                    x += step
            else:
                x += step
            i += 1
        print('├───────────────────┴────┬──────────────┤')
        print('│Максимальное значение Х:│' + '{:^14}'.format(max(val_x)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Минимальное значение Х: │' + '{:^14}'.format(min(val_x)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Максимальное значение Y:│' + '{:^14}'.format(round(max(function), 2)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Минимальное значение Y: │' + '{:^14}'.format(round(min(function), 2)) + '│')
        print('└────────────────────────┴──────────────┘')
        print('Количество шагов: ', str(i))
        plt.plot(val_x, function)
        plt.show()
        i = 0
    elif n == 3:
        while x < x1:
            Y = (log(14 * a * a - 75 * a * x + 54 * x * x + 1) / log(10))
            if i == 0:
                print('┌───────────────────┬───────────────────┐')
                print('│         X         │         Y         │')
                print('├───────────────────┼───────────────────┤')
            print('X=' + str(x) + 'Y=' + str(round(F, 3)))
            val_x.append(x)
            function.append(Y)
            if i > 1:
                values1 = array(function[i - 1:i])
                values2 = array(function[i:i + 1])
                if ((values1 / values2) > 2) or ((values1 / values2) > 2):
                    x += (step / 2)
                elif ((values1 / values2) < 0.5) or ((values1 / values2) < 0.5):
                    x += (step * 2)
                else:
                    x += step
            else:
                x += step
            i += 1
        print('├───────────────────┴────┬──────────────┤')
        print('│Максимальное значение Х:│' + '{:^14}'.format(max(val_x)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Минимальное значение Х: │' + '{:^14}'.format(min(val_x)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Максимальное значение Y:│' + '{:^14}'.format(round(max(function), 4)) + '│')
        print('├────────────────────────┼──────────────┤')
        print('│Минимальное значение Y: │' + '{:^14}'.format(round(min(function), 4)) + '│')
        print('└────────────────────────┴──────────────┘')
        print('Количество шагов: ', str(i))
        plt.plot(val_x, function)
        plt.show()
        i = 0
    else:
        print('Ошибка, попросите вывод результата одной из переменных G,F или Y.')

    val_x.clear()
    function.clear()
    print('Хотите ли провести вычисления ещё раз? Введите 1 для продолжение или 0 для выхода')
    uslovie = int(input())
    if uslovie == 0:
        break
    else:
        continue