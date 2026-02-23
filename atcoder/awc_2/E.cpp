#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  LL s;
  std::cin >> n >> s;
  std::vector<LL> a(n);
  for (auto& ai : a) {
    std::cin >> ai;
  }
  std::unordered_map<LL, LL> mp;
  LL ans = 0;
  auto dfs1 = [&](auto&& self, int u, LL cur) -> void {
    if (cur > s) {
      return;
    }
    if (u >= n / 2) {
      mp[cur] += 1;
      return;
    }
    self(self, u + 1, cur);
    self(self, u + 1, cur + a[u]);
  };
  auto dfs2 = [&](auto&& self, int u, LL cur) -> void {
    if (cur > s) {
      return;
    }
    if (u >= n) {
      if (auto it = mp.find(s - cur); it != mp.end()) {
        ans += it->second;
      }
      return;
    }
    self(self, u + 1, cur);
    self(self, u + 1, cur + a[u]);
  };
  dfs1(dfs1, 0, 0);
  dfs2(dfs2, n / 2, 0);
  std::cout << ans << '\n';

  return 0;
}