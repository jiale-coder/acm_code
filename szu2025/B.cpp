#include <bits/stdc++.h>

using LL = long long;
constexpr LL inf = std::numeric_limits<LL>::max() / 2;

struct Tag {
  LL add{0};
  void apply(const Tag& v) {
    add += v.add;
  }
};

struct Info {
  LL minv{inf}, even_minv{inf};
  void apply(const Tag& v) {
    if (minv != inf) {
      minv += v.add;
    }
    if (even_minv != inf) {
      even_minv += v.add;
    }
  }
};

Info operator+(const Info& a, const Info& b) {
  return {std::min(a.minv, b.minv), std::min(a.even_minv, b.even_minv)};
}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<Info> tr(4 * n + 1);
  std::vector<Tag> tag(4 * n + 1);
  auto pull = [&](int u) {
    tr[u] = tr[u << 1] + tr[u << 1 | 1];
  };
  auto push = [&](int u) {
    if (tag[u].add != 0) {
      tr[u << 1].apply(tag[u]);
      tr[u << 1 | 1].apply(tag[u]);
      tag[u << 1].apply(tag[u]);
      tag[u << 1 | 1].apply(tag[u]);
      tag[u].add = 0;
    }
  };
  auto build = [&](auto&& self, int u, int l, int r) -> void {
    if (l == r) {
      tr[u].minv = std::min<LL>(tr[u].minv, a[l]);
      if (l % 2 == 0) {
        tr[u].even_minv = std::min<LL>(tr[u].even_minv, a[l]);
      }
      return;
    }
    int mid = (l + r) >> 1;
    self(self, u << 1, l, mid);
    self(self, u << 1 | 1, mid + 1, r);
    pull(u);
  };
  auto modify = [&](auto&& self, int u, int l, int r, int ql, int qr, const Tag& v) -> void {
    if (l >= ql && r <= qr) {
      tr[u].apply(v);
      tag[u].apply(v);
      return;
    }
    push(u);
    int mid = (l + r) >> 1;
    if (ql <= mid) {
      self(self, u << 1, l, mid, ql, qr, v);
    }
    if (qr > mid) {
      self(self, u << 1 | 1, mid + 1, r, ql, qr, v);
    }
    pull(u);
  };
  auto findl = [&](auto&& self, int u, int l, int r, int ql, int qr, Info& v) -> int {
    if (l >= ql && r <= qr) {
      auto res = v + tr[u];
      if (res.minv > 0) {
        v = res;
        return n + 1;
      }
    }
    if (l == r) {
      return l;
    }
    push(u);
    int mid = (l + r) >> 1;
    int pos = n + 1;
    if (ql <= mid) {
      pos = self(self, u << 1, l, mid, ql, qr, v);
    }
    if (pos == n + 1 && qr > mid) {
      pos = self(self, u << 1 | 1, mid + 1, r, ql, qr, v);
    }
    return pos;
  };
  auto query = [&](auto&& self, int u, int l, int r, int ql, int qr) -> Info {
    if (l >= ql && r <= qr) {
      return tr[u];
    }
    push(u);
    int mid = (l + r) >> 1;
    if (qr <= mid) {
      return self(self, u << 1, l, mid, ql, qr);
    } else if (ql > mid) {
      return self(self, u << 1 | 1, mid + 1, r, ql, qr);
    }
    return self(self, u << 1, l, mid, ql, qr) + self(self, u << 1 | 1, mid + 1, r, ql, qr);
  };
  build(build, 1, 1, n);
  while (m--) {
    int l, r, k;
    std::cin >> l >> r >> k;
    Tag v{.add = k};
    modify(modify, 1, 1, n, l, r, v);
    Info res;
    int pos = findl(findl, 1, 1, n, 1, n, res);
    if (pos % 2 == 0) {
      std::cout << 0 << '\n';
    } else {
      auto ans = query(query, 1, 1, n, 1, std::min(n, pos));
      std::cout << (ans.even_minv == inf ? -1 : ans.even_minv) << '\n';
    }
  }

  return 0;
}