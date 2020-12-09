stack = 5*[float("inf")]
n = int(input('Введите число N: '))
lst = list(map(int, input('Введите N чисел: ').split()))
for i in range(len(lst)):
	#adding elements
	if max(stack) > lst[i]:
		stack += [lst[i]]
		stack.sort()
		if len(stack) > 5:
			stack.pop()
	#print
	for j in range(len(stack)-1, -1, -1):
		if stack[j] != float("inf"): print(stack[j], end=' ')
	print()