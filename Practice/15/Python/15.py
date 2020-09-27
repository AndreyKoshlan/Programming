import random

msg_hello       = 	'\n'\
				 	'  ╔══════════════════════════════════════════════════════╗\n'\
				 	'  ║                                                      ║\n'\
				 	'  ║    ~ Угадай число ~                                  ║\n'\
				 	'  ║                                                      ║\n'\
				 	'  ║    • Компьютер загадывает случайное целое число N    ║\n'\
				 	'  ║      в диапазоне (0 <= N <= 100)                     ║\n'\
				 	'  ║    • Вам даётся 5 попыток угадать это число          ║\n'\
				 	'  ║                                                      ║\n'\
					'  ╚══════════════════════════════════════════════════════╝\n'
msg_not_enough  = 	'Загаданное число больше'
msg_too_many    = 	'Загаданное число меньше'
msg_win         = 	'Поздравляю! Вы угадали'
msg_fail        = 	'Вы проиграли. Было загадано:'
msg_second_try  = 	'Хотите начать сначала? (1 - ДА )'

min_random 	= 0
max_random 	= 100
attempt_lim	= 5

def TryingGuess(x, n):
	if x == n:
		return True #Guessed
	elif x < n:
		print(msg_not_enough)
	elif x > n:
		print(msg_too_many)
	return False #Not guessed

def UserGuess(n):
	isGuessed = False
	attempt = 0
	while (not isGuessed) and (attempt < attempt_lim):
		x = int(input('\n> '))
		isGuessed = TryingGuess(x, n)
		attempt += 1
	if isGuessed: 
		print('\n', msg_win, sep='')
	else:
		print('\n', msg_fail, ' ', n, sep='')

def UserRestart():
	print(msg_second_try)
	answer = int(input('\n> '))
	return answer == 1

print(msg_hello)
while True:
	n = random.randint(min_random, max_random)
	UserGuess(n)
	if not UserRestart():
		break