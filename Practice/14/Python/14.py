import math

n = int(input('Введите целое число: '))
if n > 0:
	print( math.trunc(math.log2(n))+1 )
else:
	print(0)