n, q = map(int, input().split())
d = [0] + list(map(int, input().split()))
tr = [0] * (n + 1)
LOGN = n.bit_length() - 1
def add(x, k):
  while x <= n:
    tr[x] += k
    x += x & -x
def find(k):
  pos, tot = 0, 0
  for i in range(LOGN, -1, -1):
    if pos + (1 << i) <= n and tot + tr[pos + (1 << i)] < k:
      tot += tr[pos + (1 << i)]
      pos += 1 << i
  return pos + 1
def ask(x):
  res = 0
  while x > 0:
    res += tr[x]
    x -= x & -x
  return res
for i in range(1, n + 1):
  add(i, 1)
for i in range(q):
  t = int(input())
  pos = find(t)
  if pos <= n:
    d[pos] -= 1
    if d[pos] == 0:
      add(pos, -1)
  print(ask(n))