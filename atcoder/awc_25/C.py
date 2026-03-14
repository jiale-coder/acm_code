n, m = map(int, input().split())
d = list(map(int, input().split()))
d.sort(reverse=True)
print(0 if m == n else d[m])