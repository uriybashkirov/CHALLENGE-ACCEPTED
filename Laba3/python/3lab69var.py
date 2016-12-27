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
            if 0 != (5 * a ** 2 - 9 * a * x + 4 * x ** 2):
                G = (5 * (-10 * a ** 2 + 27 * a * x + 28 * x ** 2)) / (5 * a ** 2 - 9 * a * x + 4 * x ** 2)
                print('X=' + str(x) + 'Y=' + str(round(G, 3)))
                val_x.append(x) #добавляем в список val_x значение x
                function.append(G) #добавляем в список function значение G
                if i > 1:
                    values1 = array(function[i-1:i]) #присваеваем переменной values1 и values2 значения массива(не списка)
                    values2 = array(function[i:i+1])#мы берём предыдущее и текущее знaчение y (values1 предыдущее, values2 текущее значение функции)
                    if ((values1 / values2) > 2) or ((values1 / values2) > 2): #считаем отношение, как в си
                        x += (step / 2)
                    elif ((values1 / values2) < 0.5) or ((values1 / values2) < 0.5):
                        x += (step * 2)
                    else:
                        x += step
                else:
                    x += step
                    i += 1
                print('Количество шагов: ', str(i))

            else:
                print(
                    'Функция G не может быть составлена, ибо является результатом деления на 0. Введите другие значения переменных.')
                break
        plt.plot(val_x, function)
        plt.show()
        i = 0
    elif n == 2:
        while x < x1:
            F = math.sin(28 * a ** 2 - 57 * a * x + 14 * x ** 2)
            if -1 <= F <= 1:
                print('X=' + str(x) + 'Y=' + str(round(F, 3)))
                val_x.append(x)
                function.append(F)
                if i > 1:
                    values1 = array(function[i-1:i])
                    values2 = array(function[i:i+1])
                    if ((values1 / values2) > 2) or ((values1 / values2) > 2):
                        x += (step / 2)
                    elif ((values1 / values2) < 0.5) or ((values1 / values2) < 0.5):
                        x += (step * 2)
                    else:
                        x += step
                else:
                    x += step
                    i += 1
                print('Количество шагов: ', str(i))

            else:
                print('Переменная F не принадлежит отрезку синуса от -1 до 1. Введите другие значения')
                break
        plt.plot(val_x, function)
        plt.show()
        i = 0
    elif n == 3:
        while x < x1:
            if (-27 * a ** 2 + 24 * a * x + 35 * x ** 2 + 1) > 0:
                Y = math.log(-27 * a ** 2 + 24 * a * x + 35 * x ** 2 + 1)
                print('X=' + str(x) + 'Y=' + str(round(F, 3)))
                val_x.append(x)
                function.append(Y)
                if i > 1:
                    values1 = array(function[i-1:i])
                    values2 = array(function[i:i+1])
                    if ((values1 / values2) > 2) or ((values1 / values2) > 2):
                        x += (step / 2)
                    elif ((values1 / values2) < 0.5) or ((values1 / values2) < 0.5):
                        x += (step * 2)
                    else:
                        x += step
                else:
                    x += step
                    i += 1
                print('Количество шагов: ', str(i))

            else:
                print(
                    'Логарифм не может быть найден при таких значениях переменных. Введите другие значения переменных.')
                break
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
