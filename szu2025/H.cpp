#include <bits/stdc++.h>

using LL = long long;

void solve() {
  int n;
  LL p;
  std::cin >> n >> p;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i];
  }
  auto check = [&](int t) {
    LL dp = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      LL ndp = -1e18;
      if (t >= b[i]) {
        ndp = std::max<LL>({ndp, dp + a[i], a[i]});
      }
      dp = ndp;
      ans = std::max(ans, dp);
    }
    return ans >= p;
  };
  int l = 0, r = 1e9 + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l == 1e9 + 1) {
    l = -1;
  }
  std::cout << l << '\n';
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