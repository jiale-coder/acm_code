## trick记录

1. 树状数组上二分，求第一个满足 $s[1\backsim p]\ge k$ 的位置 $p$

```python
LOGN = n.bit_length() - 1

# 利用 tr[i] = a[i - lowbit(i) + 1] + a[i - lowbit(i)] + ... + a[i] 的区间和

# 按二进制位，从大到小尝试


def find(k):
  pos, tot = 0, 0
  for i in range(LOGN, -1, -1):
    if pos + (1 << i) <= n and tot + tr[pos + (1 << i)] < k:
      tot += tr[pos + (1 << i)]
      pos += 1 << i
  return pos + 1
```

## python技巧

1. python 中的二分函数

```python
import bisect

a = [1, 2, 3, 4, 10, 12]

# bisect_left 求第一个 >= k 的下标
pos = bisect.bisect_left(a, 4)

# bisect_right 求第一个 > k 的下标
pos = bisect.bisect_right(a, 2)

```