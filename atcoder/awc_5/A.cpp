#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, k;
  std::cin >> n >> k;
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    int p;
    std::cin >> p;
    ans += p % k == 0 ? p : 0;
  }
  std::cout << ans << '\n';

  return 0;
}