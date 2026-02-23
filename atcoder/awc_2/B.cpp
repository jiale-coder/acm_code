#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (auto& x : a) {
    std::cin >> x;
  }
  std::set<int> se;
  for (int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    x--;
    se.insert(x);
  }
  int cnt = 0;
  LL tot = 0;
  for (int i = 0; i < n; i++) {
    if (se.contains(i) && a[i] < k) {
      cnt++;
      tot += a[i];
    }
  }
  std::cout << cnt << ' ' << tot << '\n';

  return 0;
}