original_print = print

def create(length, begin, step):
	if step == 0:
		return length*[begin]
	else:
		return list(range(begin, begin+step*length, step))

def sort(arr):
	for p1 in range(1, len(arr)):
		p2 = p1
		while (p2 > 0) and (arr[p2] <= arr[p2-1]):
			arr[p2], arr[p2-1] = arr[p2-1], arr[p2]
			p2 -= 1
	return arr

def print(arr):
	original_print(' '.join(map(str, arr)))

length = int(input('Введите длину массива: '))
begin = int(input('Введите начальный член прогрессии: '))
step = int(input('Введите шаг арифметической прогрессии: '))
arr = create(length, begin, step)
sort(arr)
print(arr)