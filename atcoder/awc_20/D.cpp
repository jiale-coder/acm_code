#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, l;
  std::cin >> n >> l;
  std::map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x, r;
    std::cin >> x >> r;
    mp[std::max(0, x - r)] += 1;
    mp[std::min(x + r, l)] -= 1;
  }
  int last = 0, cur = 0;
  for (auto [t, v] : mp) {
    if (last < t && cur == 0) {
      std::cout << "No\n";
      return 0;
    }
    cur += v;
    last = t;
  }
  std::cout << (last < l && cur == 0 ? "No" : "Yes") << '\n';

  return 0;
}