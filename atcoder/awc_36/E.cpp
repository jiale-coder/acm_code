#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  std::cin >> h >> w;
  std::vector a(h, std::vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cin >> a[i][j];
    }
  }
  LL ans = 0;
  for (int s = 0; s < 1 << w; s++) {
    LL base = 0;
    for (int i = 0; i < w; i++) {
      if (s >> i & 1) {
        for (int j = 0; j < h; j++) {
          base += a[j][i];
        }
      }
    }
    LL dp = 0;
    for (int i = 0; i < h; i++) {
      LL ndp = dp, cost = 0;
      for (int j = 0; j < w; j++) {
        cost += a[i][j];
        if (s >> j & 1) {
          cost -= a[i][j];
        }
      }
      ndp = std::max(ndp, dp + cost);
      dp = ndp;
    }
    ans = std::max(ans, dp + base);
  }
  std::cout << ans << '\n';

  return 0;
}