pattern = "a???55661"

def isInPatternRange(c):
	return (ord(c) in range(48, 57+1)) or\
		   (ord(c) in range(97, 122+1))

def IsCorrectTicket(s):
	if len(s) != len(pattern):
		return False
	b = True
	for i in range(0, len(pattern)):
		if pattern[i] == "?":
			b = b and isInPatternRange(s[i])
		else:
			b = b and (s[i] == pattern[i])
		if not b: break;
	return b

n = int(input('Введите количество билетов N: '))
s = input('Введите билеты: ').split()
isCorrectTicketFound = False;
for i in range(n):
	if IsCorrectTicket(s[i]):
		print(s[i], end=' ')
		isCorrectTicketFound = True;
if not isCorrectTicketFound:
	print(-1)