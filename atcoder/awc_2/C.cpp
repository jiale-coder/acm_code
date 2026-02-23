#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i];
  }
  int l = 0, r = 1e9;
  auto check = [&](int d) {
    for (int i = 0; i < n; i++) {
      if (a[i] + 1LL * d * b[i] < m) {
        return false;
      }
    }
    return true;
  };
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  std::cout << l << '\n';

  return 0;
}