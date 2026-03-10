n, d, k = map(int, input().split())
w = list(map(int, input().split()))
print(sum(1 for i in range(n) if w[i] - d * k >= 1))