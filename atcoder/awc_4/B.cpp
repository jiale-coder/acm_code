#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, t;
  std::cin >> n >> t;
  LL tot = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    tot += std::max(a - 1LL * b * t, 0LL);
  }
  std::cout << tot << '\n';
  
  return 0;
}