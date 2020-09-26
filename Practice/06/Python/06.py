import math

def Calculate(a, b, c):
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


a = float(input())
b = float(input())
c = float(input())
try:
	Calculate(a, b, c)
except:
	print('Отсутствуют действительные корни')