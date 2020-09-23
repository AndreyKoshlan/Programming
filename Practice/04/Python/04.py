orig_a, orig_b = map(int, input().split())

#С дополнительной переменной
a = orig_a
b = orig_b
c = a
a = b
b = c
print('С помощью дополнительной переменной:', 'a =', a, 'b =',b)

#Без дополнительной переменной
a = orig_a
b = orig_b
a = a+b
b = a-b
a = a-b
print('Без помощи дополнительной переменной:', 'a =', a, 'b =',b)