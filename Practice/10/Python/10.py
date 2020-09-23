s, l1, r1, l2, r2 =  map(int, input().split())
x = l1
y = r2

if x + y < s:
  x = min(s-y, r1)
else:
  y = max(s-x, l2)

if x + y == s:
  print(x, y)
else:
  print(-1)
