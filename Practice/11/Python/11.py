x = float(input("Введите число возводимое в степень: "))
y = int(input("Введите степень: "))
if (y < 0):
	x = 1/x
	y = -y
value = 1
for i in range(y):
	value *= x
print(value)