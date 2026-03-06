n = int(input())
a = list(map(int, input().split()))
tot = sum(a)
print("Yes" if tot % n == 0 else "No")