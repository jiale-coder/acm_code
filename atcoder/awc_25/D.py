import bisect

n, s, q = map(int, input().split())
x = list(map(int, input().split()))
par = []
for i in range(n):
  par.append([x[i], i])
par.sort()
s -= 1
last = s
while q > 0:
  pr = bisect.bisect_left(par, [x[s] + 1, -1])
  pl = bisect.bisect_left(par, [x[s], -1])
  d = [10**18, 10**9]
  # print(par[pr][0], par[pr][1])
  # print(par[pl][0], par[pl][1])
  def update(v):
    if d[0] > abs(v[0] - x[s]):
      d[0] = abs(v[0] - x[s])
      d[1] = v[1]
    elif d[0] == abs(v[0] - x[s]):
      d[1] = min(d[1], v[1])
  if pr < n:
    update(par[pr])
  if pl > 0:
    update(par[pl - 1])
  if last == d[1]:
    break
  last = s
  s = d[1]
  q -= 1
ans = last if q % 2 == 1 else s
print(ans + 1)