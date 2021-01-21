while 1:
	try:
		a, op, b = input('Введите выражение: ').split()
		a, b = map(float, (a, b))
		if op == '+':
			print(a+b)
			break
		if op == '-':
			print(a-b)
			break
		if op == '*':
			print(a*b)
			break
		if op == '/':
			print(a/b)
			break
		raise
	except ZeroDivisionError:
		print('Деление на "0" невозможно')
	except Exception:
		print('Ошибка вычисления')
