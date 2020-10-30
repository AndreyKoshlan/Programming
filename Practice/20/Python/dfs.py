class _Drink:
	name: str = ''
	price: int = 0
	v: int = 0

	count: int = 0

	def __init__(self, name, price, v):
		self.name = name
		self.price = price
		self.v = v

maxv = 0;
maxhistory = []

def printResult(history, money, drinks):
	v = 0
	if len(history) <= 0:
		print(-1)
		return
	for i in history:
		v += drinks[i].v
		money -= drinks[i].price
		drinks[i].count += 1
	for i in range(len(drinks)):
		if drinks[i].count > 0:
			print(drinks[i].name, drinks[i].count)
	print(v, money, sep='\n') 

def DFS(money, drinks, v, history):
	global maxv
	global maxhistory
	if v > maxv:
		maxv = v
		maxhistory = history
	for i in range(len(drinks)):
		if money-drinks[i].price >= 0:
			DFS(money-drinks[i].price, drinks, v+drinks[i].v, history+[i])

money = int(input())
n = int(input())
drinks = []
for i in range(n):
	name, price, v = input().split()
	drinks.append(_Drink(name, int(price), int(v)))
DFS(money, drinks, 0, [])
printResult(maxhistory, money, drinks)