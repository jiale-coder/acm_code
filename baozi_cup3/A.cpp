
#include <bits/stdc++.h>

using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector g(n + 1, std::vector<int>{});
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}