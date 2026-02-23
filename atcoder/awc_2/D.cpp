#include <bits/stdc++.h>

using LL = long long;

constexpr LL inf = std::numeric_limits<LL>::min() / 2;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  std::vector<int> c(n), r(m);
  for (auto& ci : c) {
    std::cin >> ci;
  }
  for (auto& ri : r) {
    std::cin >> ri;
  }
  std::sort(c.begin(), c.end());
  std::sort(r.begin(), r.end());
  int low = 0, high = std::min(n, m);
  auto check = [&](int x) {
    for (int i = 0; i < x; i++) {
      if (r[m - x + i] < c[i]) {
        return false;
      }
    }
    return true;
  };
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (check(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  std::cout << low << '\n';

  return 0;
}