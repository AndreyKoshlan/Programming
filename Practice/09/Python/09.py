h1, m1 = map(int, input('Введите время 1: ').split(':'));
h2, m2 = map(int, input('Введите время 2: ').split(':'));
m1 = (h1*60) + m1;
m2 = (h2*60) + m2;
if (abs(m2 - m1) <= 15):
	print('Встреча состоится')
else:
	print('Встреча не состоится')