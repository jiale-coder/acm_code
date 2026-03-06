## trick记录

1. 对于一类相邻的操作 $a_i+=v, a_{i+1}-=v$，问所有数能不能变成一样，当且仅当 $\sum a \mod n=0$，因为相邻操作，我们总可以任意分配 $\sum a$

2. 对于一类区间覆盖问题求区间值问题，如果值域很大可以直接考虑用map然后差分+扫描线，利用差分点的性质，这些差分点会分成若干个连续的区间，每段区间他们的 $cur$ 是不变的
    - 这里要注意两个坑点，如果是区间点覆盖，那么是 `mp[l] += k, mp[r + 1] -= k`，但如果是区间覆盖相当于包括实数，那么是 `mp[l] += k, mp[r] -= k`，看成线段

3. 对于一类线段树二分问题，求在 $[l,r]$ 区间内第一个满足某个条件的点，或者最后一个满足某个条件的点，可以考虑如下模板:
```cpp

struct Info {};

Info operator+(const Info& a, const Info& b) {}

std::vector<Info> tr(4 * n + 1);

// 其中tmp维护的是当且从在 [ql, qr] 范围内，从左到右完整的线段树节点的合并的答案
auto findl = [&](auto& self, int u, int l, int r, int ql, int qr, Info& params, const std::funciont<bool(const Info&)& func>) -> int {
    if (l >= ql && r <= qr) {
        auto tmp = params + tr[u];
        if (!func(tmp)) {
            params = tmp;
            return -1;
        }
    }

    if (l == r) {
        return l;
    }

    int mid = (l + r) >> 1;
    int pos = -1;
    if (ql <= mid) {
        pos = self(self, u << 1, l, mid, ql, qr, params);
    }
    if (pos == -1 && qr > mid) {
        pos = self(self, u << 1, mid + 1, r, ql, qr, params);
    }
    return pos;
};

// 其中tmp维护的是当且从在 [ql, qr] 范围内，从右到左完整的线段树节点的合并的答案
// func 是一个判断条件
auto findr = [&](auto& self, int u, int l, int r, int ql, int qr, Info& params, const std::funciont<bool(const Info&)& func) -> int {
    if (l >= ql && r <= qr) {
        auto tmp = tr[u] + params;
        if (!func(tmp)) {
            params = tmp;
            return -1;
        }
    }

    if (l == r) {
        return l;
    }

    int mid = (l + r) >> 1;
    int pos = -1;
    if (qr > mid) {
        pos = self(self, u << 1, mid + 1, r, ql, qr, params);
    }
    if (pos == -1 && ql <= mid) {
        pos = self(self, u << 1, l, mid, ql, qr, params);
    }
    return pos;
};

```

