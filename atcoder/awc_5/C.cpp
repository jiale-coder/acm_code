
#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto& ai : a) {
    std::cin >> ai;
  }
  std::vector<int> pre(n), suf(n);
  pre[0] = a[0];
  suf[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++) {
    pre[i] = std::max(a[i], pre[i - 1] - k);
  }
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = std::max(a[i], suf[i + 1] - k);
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    ans += std::max(pre[i], suf[i]) - a[i];
  }
  std::cout << ans << '\n';

  return 0;
} 