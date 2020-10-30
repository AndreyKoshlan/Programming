def bmi(weight: float, height: float):
	return weight / (height**2)

def print_bmi(bmi: float):
	if bmi < 18.5:
		print('Underweight')
	elif bmi < 25:
		print('Normal')
	elif bmi < 30:
		print('Overweight')
	else:
		print('Obesity')

print('Введите вес и рост:')
weight, height = map(float, input().split())
print_bmi(bmi(weight, height/100))