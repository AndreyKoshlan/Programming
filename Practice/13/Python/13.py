import sys
import math

x = int(input('Введите число: '))
msearch = math.ceil(math.sqrt(x))
for i in range(2, msearch+1):
	if x == i:
		break;
	if x % i == 0:
		print('Составное')
		sys.exit()
print('Простое')