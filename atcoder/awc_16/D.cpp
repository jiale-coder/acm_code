#include <bits/stdc++.h>

using LL = long long;

constexpr LL inf = std::numeric_limits<LL>::min() / 2;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, q;
  LL k;
  std::cin >> n >> k >> q;
  std::vector<LL> s(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s[i] = s[i - 1] + x;
  }
  std::vector<LL> f(n + 1);
  for (int i = 1; i <= n; i++) {
    // s[j] - s[i - 1] > k 的第一个数
    int l = i, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (s[mid] - s[i - 1] > k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    f[i] = l;
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << f[r] - f[l - 1] << '\n';
  }

  return 0;
}