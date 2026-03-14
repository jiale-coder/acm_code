h, w, n = map(int, input().split())
s = []
vis = [[0 for i in range(w)] for i in range(h)]
tot = 0
for i in range(h):
  s.append(input())
  tot += s[-1].count('#')
t = input()
x, y = 0, 0
vis[x][y] = 1
for c in t:
  dx, dy = x, y
  if c == 'U':
    dx -= 1
  if c == 'D':
    dx += 1
  if c == 'L':
    dy -= 1
  if c == 'R':
    dy += 1
  if dx >= 0 and dx < h and dy >= 0 and dy < w:
    x, y = dx, dy
    vis[x][y] = 1
print(tot - sum(vis[i][j] and s[i][j] == '#' for i in range(h) for j in range(w)))