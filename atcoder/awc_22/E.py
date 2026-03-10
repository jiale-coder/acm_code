n, m = map(int, input().split())
kInf = 10**9

d = [[kInf for i in range(n)] for i in range(n)]
for i in range(n):
  d[i][i] = 0

for i in range(m):
  u, v, w = map(int, input().split())
  u -= 1; v -= 1
  d[u][v] = d[v][u] = min(w, d[u][v])

for k in range(n):
  for i in range(n):
    for j in range(n):
      d[i][j] = min(d[i][j], d[i][k] + d[k][j])

dp = [[kInf for i in range(n)] for i in range(1 << n)]
dp[1][0] = 0

for s in range(1 << n):
  for i in range(n):
    if dp[s][i] == kInf:
      continue
    for j in range(n):
      if s >> j & 1:
        continue
      dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + d[i][j])

ans = kInf

for i in range(n):
  ans = min(ans, dp[(1 << n) - 1][i] + d[i][0])

print(-1 if ans == kInf else ans)