#include <bits/stdc++.h>

using LL = long long;

constexpr LL inf = std::numeric_limits<LL>::min() / 2;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto& ai : a) {
    std::cin >> ai;
  }
  auto check = [&](LL limits) {
    // >= limits
    LL sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum >= limits) {
        cnt++;
        sum = 0;
      }
    }
    return cnt >= k;
  };
  LL l = 1, r = 1e18;
  while (l < r) {
    LL mid = (l + r + 1) >> 1;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  std::cout << l << '\n';

  return 0;
}