import math

a=int(input())
x=int(input())

G=((9*(7*a*a+39*a*x+20*x*x))/(9*a*a+59*a*x+30*x*x))
F=(math.tanh(9*a*a-14*a*x+5*x*x))
Y=(math.log(14*a*a-75*a*x+54*x*x+1)/math.log(10))

print("G = " + str(G))
print("F = " + str(F))
print("Y = " + str(Y))