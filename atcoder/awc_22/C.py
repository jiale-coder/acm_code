n, m, k, t = map(int, input().split())
b = list(map(int, input().split()))
s = [0] * (n + 1)
for x in b:
  s[x] += 1
for i in range(n + 1):
  s[i] += s[i - 1]
for i in range(k):
  l, r = map(int, input().split())
  print("YES" if s[r] - s[l - 1] >= t else "NO")