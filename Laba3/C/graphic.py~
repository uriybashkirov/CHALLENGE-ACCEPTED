import matplotlib.pyplot as plt

data = open('/home/prostoimbo/Documents/Project3/text.txt', 'r') # открываем фаил по этому пути и просто читаем его
y = []
x = []
for line in data: # читаем по строчно из файла дата

    x.append(line.split()) #в массив добавляем значения Х в 1,3,5,7... строках

    for line in data:
        y.append(line.split()) #в массив добавляем значения Y в следующей строке после Х(2,4,6,8...)
        break

plt.plot(x, y)#  присваиваем координаты для нашего графика
plt.show()#отображаем график
