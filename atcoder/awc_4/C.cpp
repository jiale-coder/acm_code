
#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<LL> h(n);
  for (auto& hi : h) {
    std::cin >> hi;
  }
  std::sort(h.begin(), h.end());
  LL ans1 = std::abs(h[0]) + std::abs(h[n - 1]) + std::abs(h[n - 1] - h[0]);
  std::cout << ans1 << '\n';

  return 0;
}