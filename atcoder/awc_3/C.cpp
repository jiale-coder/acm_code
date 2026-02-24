#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> c(n);
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    c[i] = b - a;
    ans += a;
  }
  std::sort(c.begin(), c.end());
  for (int i = 0; i < k && c[i] < 0; i++) {
    ans += c[i];
  }
  std::cout << ans << '\n';

  return 0;
}