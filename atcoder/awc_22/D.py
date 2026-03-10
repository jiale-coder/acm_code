n, k = map(int, input().split())
a = [0] + list(map(int, input().split()))
c = [0] * (n + 2)
ans = 0
for i in range(n + 1):
  c[i] ^= c[i - 1]
  cur = a[i] ^ c[i]
  if cur == 1:
    if i + k - 1 <= n:
      ans += 1
      c[i] ^= 1; c[i + k] ^= 1
    else:
      ans = -1
      break
print(ans)