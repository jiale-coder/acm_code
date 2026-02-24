#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  std::vector<int> w(n), c(m);
  for (auto& wi : w) {
    std::cin >> wi;
  }
  for (auto& ci : c) {
    std::cin >> ci;
  }
  std::vector<LL> tot(1 << n);
  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        tot[i] += w[j];
      }
    }
  }
  std::vector<int8_t> dp(1 << n);
  dp[0] = 1;
  for (auto ci : c) {
    auto ndp = dp;
    for (int s = 0; s < 1 << n; s++) {
      if (!dp[s]) {
        continue;
      }
      for (int ns = s; ns < 1 << n; ns = s | (ns + 1)) {
        if (tot[ns ^ s] <= ci) {
          ndp[ns] = 1;
        }
      }
    }
    dp.swap(ndp);
  }
  std::cout << (dp[(1 << n) - 1] ? "Yes" : "No") << '\n';

  return 0;
}