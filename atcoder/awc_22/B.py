n, m, t = map(int, input().split())
a = list(map(int, input().split()))
need = 0
for i in range(n):
  need += max(0, t - a[i])
print(-1 if need > m else need)