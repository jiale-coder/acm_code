#include <bits/stdc++.h>

using LL = long long;

constexpr LL inf = std::numeric_limits<LL>::min() / 2;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector dp(n, std::vector<LL>(m + 1, inf));
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i];
  }
  std::vector<std::deque<int>> dq(m + 1);
  for (int i = 0; i < n; i++) {
    if (b[i] <= m) {
      dp[i][b[i]] = a[i];
    }
    for (int v = b[i]; v <= m; v++) {
      auto& q = dq[v - b[i]];
      while (q.size() && i - q.front() > k) {
        q.pop_front();
      }
      if (q.size()) {
        dp[i][v] = std::max(dp[i][v], dp[q.front()][v - b[i]] + a[i]);
      }
    }
    for (int v = 0; v <= m; v++) {
      auto& q = dq[v];
      while (q.size() && dp[q.back()][v] < dp[i][v]) {
        q.pop_back();
      }
      q.push_back(i);
    }
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      ans = std::max(ans, dp[i][j]);
    }
  }
  std::cout << ans << '\n';

  return 0;
}