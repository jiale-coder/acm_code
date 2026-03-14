n, x = map(int, input().split())
a = list(map(int, input().split()))
print(sum(1 for i in range(n) if a[i] < x))