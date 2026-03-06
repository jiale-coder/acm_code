n, m, s = map(int, input().split())
d = list(map(int, input().split()))
hp = [0] * n
for i in range(m):
  p, r = map(int, input().split())
  hp[p - 1] = r
gg = 0
for i in range(n):
  if gg:
    s -= d[i] << 1
  else:
    s -= d[i]
  if s <= 0:
    gg = 1
  s += hp[i]
print(s)