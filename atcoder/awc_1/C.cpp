#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> d(n);
  for (int i = 0; i < n; i++) {
    std::cin >> d[i];
  }
  std::sort(d.begin(), d.end(), std::greater<int>());
  LL ans = 0;
  for (int i = k; i < n; i++) {
    ans += d[i];
  }
  std::cout << ans << '\n';

  return 0;
}