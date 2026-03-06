n = int(input())
v = list(map(int, input().split()))
v.sort()
ans = 0
for i in range(1, n):
  ans += v[i] - v[i - 1]
print(ans)