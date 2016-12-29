import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("text.dat")
plt.plot(data[:,0], data[:,1])
plt.xlabel('Количество точек')
plt.ylabel('Время выполнения')
plt.title('Зависимость времени выполнения программы от количества точек')
plt.show()

