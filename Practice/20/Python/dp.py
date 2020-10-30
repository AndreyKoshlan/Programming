from operator import attrgetter

class _Drink:
	name: str = ''
	price: int = 0
	v: int = 0

	count: int = 0

	def __init__(self, name, price, v):
		self.name = name
		self.price = price
		self.v = v

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

def DP(money, drinks):
	history = []
	if money == 0:
		return 0, history #first drink (v = 0)
	maxv = 0
	dpvalue = 0
	for i in range(len(drinks)):
		if money-drinks[i].price < 0:
			continue
		dpvalue, temphistory = DP(money-drinks[i].price, drinks)
		if dpvalue+drinks[i].v >= maxv:
			maxv = dpvalue+drinks[i].v
			history = temphistory+[i]
	return maxv, history

money = int(input())
n = int(input())
drinks = []
for i in range(n):
	name, price, v = input().split()
	drinks.append(_Drink(name, int(price), int(v)))
temp, history = DP(money, drinks)
printResult(history, money, drinks)