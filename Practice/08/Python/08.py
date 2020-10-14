while 1:
	try:
		print(eval(input('Введите выражение: ')))
		break;
	except ZeroDivisionError:
		print('Деление на "0" невозможно')
	except Exception:
		print('Ошибка вычисления')
