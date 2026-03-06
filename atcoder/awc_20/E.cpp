#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> w(n + 1), c(m + 1);
  std::vector<int> vec;
  for (int i = 1; i <= n; i++) {
    std::cin >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> c[i];
  }
  std::vector<int> tr(4 * m + 1);
  auto modify = [&](auto&& self, int u, int l, int r, int x, int v) -> void {
    if (l == r) {
      tr[u] = v;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
      self(self, u << 1, l, mid, x, v);
    } else {
      self(self, u << 1 | 1, mid + 1, r, x, v);
    }
    tr[u] = std::max(tr[u << 1], tr[u << 1 | 1]);
  };
  auto findl = [&](auto&& self, int u, int l, int r, int ql, int qr, int target, int& params) -> int {
    if (l >= ql && r <= qr) {
      if (std::max(params, tr[u]) < target) {
        params = tr[u];
        return -1;
      }
    }
    if (l == r) {
      return l;
    }
    int mid = (l + r) >> 1;
    int pos = -1;
    if (ql <= mid) {
      pos = self(self, u << 1, l, mid, ql, qr, target, params);
    }
    if (pos == -1 && qr > mid) {
      pos = self(self, u << 1 | 1, mid + 1, r, ql, qr, target, params);
    }
    return pos;
  };
  for (int i = 1; i <= m; i++) {
    modify(modify, 1, 1, m, i, c[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int params = 0;
    auto pos = findl(findl, 1, 1, m, 1, m, w[i], params);
    if (pos != -1) {
      ans++;
      modify(modify, 1, 1, m, pos, 0);
    }
  }
  std::cout << ans << '\n';

  return 0;
}