#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  const int m = std::__lg(n);
  std::vector st(n + 1, std::vector<int>(m + 1));
  for (int i = 0; i <= m; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      if (!i) {
        st[j][i] = a[j];
      } else {
        st[j][i] = std::max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
  auto query = [&](int l, int r) {
    const int k = std::__lg(r - l + 1);
    return std::max(st[l][k], st[r - (1 << k) + 1][k]);
  };
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << query(l, r) << '\n';
  }

  return 0;
}