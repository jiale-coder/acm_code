#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t, x;
  std::cin >> t >> x;
  int cur = 0;
  for (int i = 0; i <= t; i++) {
    int a;
    std::cin >> a;
    bool ok = false;
    if (i == 0) {
      cur = a;
      ok = true;
    } else if (std::abs(a - cur) >= x) {
      cur = a;
      ok = true;
    }
    if (ok) {
      std::cout << i << ' ' << cur << '\n';
    }
  }

  return 0;
}