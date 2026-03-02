
#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, l, r, t;
  std::cin >> n >> l >> r >> t;
  std::vector<std::array<int, 3>> vec;
  for (int i = 1; i <= n; i++) {
    int p, s;
    std::cin >> p >> s;
    if (p >= l && p <= r && s >= t) {
      vec.push_back({p, s, i});
    }
  }
  std::sort(vec.begin(), vec.end(), [&](const auto& a, const auto& b) {
    if (a[0] != b[0]) {
      return a[0] < b[0];
    }
    if (a[1] != b[1]) {
      return a[1] > b[1];
    }
    return a[2] < b[2];
  });

  if (vec.empty()) {
    std::cout << -1 << '\n';
  } else {
    std::cout << (vec.front())[2] << '\n';
  }

  return 0;
} 