pattern = "a???55661"

def isInNumbers(c):
	return ord(c) in range(48, 57+1)

def isInLetters(c):
	return ord(c) in range(97, 122+1)

def isInPatternRange(c):
	return (isInLetters(c)) or\
		   (isInNumbers(c))

def IsCorrectTicket(s):
	if len(s) != len(pattern):
		return False
	b = True
	numbers, letters = 0, 0;
	for i in range(0, len(pattern)):
		if pattern[i] == "?":
			b = b and isInPatternRange(s[i])
		else:
			b = b and (s[i] == pattern[i])
		if isInLetters(s[i]):
			letters += 1;
		if isInNumbers(s[i]):
			numbers += 1;
		if not b: break;
	return b and (letters == 2) and (numbers == 7)

n = int(input('Введите количество билетов N: '))
s = input('Введите билеты: ').split()
isCorrectTicketFound = False;
for i in range(n):
	if IsCorrectTicket(s[i]):
		print(s[i], end=' ')
		isCorrectTicketFound = True;
if not isCorrectTicketFound:
	print(-1)