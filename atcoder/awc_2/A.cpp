#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int a;
    std::cin >> a;
    if (a == k) {
      std::cout << i << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';

  return 0;
}