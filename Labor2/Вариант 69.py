import math

print ( ' Введите x = ')
x = int(input ( ) )

print ( ' Введите a = ' )
a = int(input ( ) )

print ( ' Введите:N = 1 для нахождения  переменной G. N = 2 для нахождения  переменной F. N = 3 для нахождения переменной Y. ' )
n = int(input ( ) )

if  n == 1:
    Y = ( ( 9 * ( 7 *a * a + 39 * a * x + 20 * x * x) ) / (9 * a * a + 59 * a * x + 30 * x * x)
    if (0 <= Y) or (Y >= 0):
        print( round ( Y, 3 ) )
    else:
        print ('Y не может быть результатом деления на 0.')
elif n == 2:
    F = math.tanh( 9 * a * a - 14 * a * x + 5 * x * x) ;
    if  F:
        print( round ( F, 3 ) );
elif n == 3:
    G = math.log ( 14 * a * a - 75 * a * x + 54 * x * x + 1) / log(10)
    if G >= 0:
        print( round ( G, 3 ) )
    else:
        print( ' Логарифм не может быть найден при таких значениях переменных. ' )
    else:
        print( ' Ошибка, попросите вывод результата одной из переменных G,F или Y. ' )
