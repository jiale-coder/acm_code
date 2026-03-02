#include <bits/stdc++.h>

using LL = long long;

constexpr int inf = std::numeric_limits<int>::max() / 2;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  std::vector d(n, std::vector<int>(n, inf));
  for (int i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  while (m--) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--, v--;
    d[u][v] = d[v][u] = std::min(d[u][v], w);
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  std::vector dp(1 << n, std::vector<int>(n, -inf));
  dp[1 << s][s] = p[s];
  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] == -inf) {
        continue;
      }
      for (int k = 0; k < n; k++) {
        if (!(i >> k & 1)) {
          dp[i | (1 << k)][k] = std::max(dp[i | (1 << k)][k], dp[i][j] + p[k] - d[j][k]);
        }
      }
    }
  }
  int ans = -inf;
  int ns = (1 << s) | (1 << t);
  for (int i = ns; i < 1 << n; i = ns | (i + 1)) {
    ans = std::max(ans, dp[i][t]);
  }
  std::cout << ans << '\n';

  return 0;
}