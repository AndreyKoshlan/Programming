print('Введите параметры x₀, u₀, t: \n> ', end='')
x0, u0, t = map(float, input().split())
a = 9.8
print( 
	'S =', abs(u0 * t - (a*t*t)/2) 
	)