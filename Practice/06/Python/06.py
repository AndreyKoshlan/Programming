import math

def Calculate(a, b, c):
	if (a == 0 and b == 0 and c == 0):
		print('Результат не определен')
		return
	if a == 0:
		print('x =', -c/b)
	else:
		d = b*b - 4*a*c;
		x1 = (-b+math.sqrt(d)) / (2*a)
		x2 = (-b-math.sqrt(d)) / (2*a)
		if x1 == x2:
			print('x =', x1)
		else:
			print('x1 =', x1)
			print('x2 =', x2)


while True:
	print('Введите число A: ')
	a = float(input())
	print('Введите число B: ')
	b = float(input())
	print('Введите число C: ')
	c = float(input())
	try:
		Calculate(a, b, c)
		break
	except:
		print('Отсутствуют действительные корни')