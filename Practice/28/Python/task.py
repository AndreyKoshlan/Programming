def sum_map(x1, x2):
	for key, value in x2.items():
		if key in x1:
			x1[key] += value
		else:
			x1[key] = value
	return x1

def get_factors(n):
	for i in range(2, n):
		if (n % i == 0):
			return sum_map(get_factors(i), get_factors(n // i))
	return {n:1} 

def print_factorization(n: int) -> None:
	f = get_factors(n)
	for i in range(len(f.items())):
		value = list(f.values())[i]
		key = list(f.keys())[i]
		print(key, end='');
		if (value > 1):
			print('^', value, sep='', end='')
		if i+1 < len(f.items()): print('*', end='')
	

x = int(input('Введите число: '))
print_factorization(x)