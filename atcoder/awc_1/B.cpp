#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, l, r;
  std::cin >> n >> l >> r;
  int id = -1, maxv = -1;
  for (int i = 1; i <= n; i++) {
    int p;
    std::cin >> p;
    if (p >= l && p <= r && p > maxv) {
      id = i;
      maxv = p;
    }
  }
  std::cout << id << '\n';

  return 0;
}