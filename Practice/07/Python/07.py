import math

def isTrianagleExist(a, b, c):
	return (a + b > c) and (b + c > a) and (a + c > b)

def CalcAreaByLengths(a, b, c):
	if not isTrianagleExist(a, b, c):
		raise Exception('Треугольник не существует')
	try:
		p = (a+b+c)/2
		return math.sqrt(p*(p-a)*(p-b)*(p-c))
	except:
		raise Exception('Невозможно вычислить площадь треугольника')

def GetLength(x1, y1, x2, y2):
	return math.sqrt(math.pow(x1-x2, 2) + math.pow(y1-y2, 2))

def CalcAreaByCoord(q, w, e):
	a = GetLength(q[0], q[1], w[0], w[1])
	b = GetLength(w[0], w[1], e[0], e[1])
	c = GetLength(e[0], e[1], q[0], q[1])
	return CalcAreaByLengths(a, b, c)

def Calculate(way):
	if way == 1:
		print('\nВведите длины сторон треугольника:')
		a = float(input('> '))
		b = float(input('> '))
		c = float(input('> '))
		print("S =", CalcAreaByLengths(a, b, c))
	elif way == 2:
		print('\nВведите координаты точек треугольника:')
		q = list(map(float, input('> ').split()))
		w = list(map(float, input('> ').split()))
		e = list(map(float, input('> ').split()))
		print("S =",CalcAreaByCoord(q, w, e))
	else:
		raise Exception('Неизвестный тип ввода')

while True:
	print('Выберите способ ввода параметров треугольника:\n',
		'1. Длины сторон',
		'2. Координаты вершин\n', sep='\n')
	way = int(input('> '))
	try:
		Calculate(way)
		break
	except Exception as e:
		print(e)