#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
  }
  while (m--) {
    int p, v;
    std::cin >> p >> v;
    s[p] = v;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += s[i] < k;
  }
  std::cout << ans << '\n';
  
  return 0;
}