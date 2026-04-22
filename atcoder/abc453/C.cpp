#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> l(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i];
  }
  int ans = 0;
  for (int i = 0; i < 1 << n; i++) {
    double cur = 0.5;
    int res = 0;
    int last = 1;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        cur += l[j];
      } else {
        cur -= l[j];
      }
      int dir = cur > 0 ? 1 : -1;
      if (dir != last) {
        res++;
      }
      last = dir;
    }
    ans = std::max(ans, res);
  }
  std::cout << ans << '\n';

  return 0;
}