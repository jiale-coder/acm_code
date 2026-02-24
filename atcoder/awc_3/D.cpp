#include <bits/stdc++.h>

using LL = long long;

constexpr LL inf = std::numeric_limits<LL>::min() / 2;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, k;
  LL m;
  std::cin >> n >> k >> m;
  std::vector<int> a(n);
  for (auto& ai : a) {
    std::cin >> ai;
  }
  LL ans = 0, cur = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && cur < m) {
      cur += a[j++];
    }
    if (cur >= m) {
      ans += std::max(0, n - 1 - std::max(j - 1, k + i - 1) + 1);
    }
    cur -= a[i];
  }
  std::cout << ans << '\n';

  return 0;
}