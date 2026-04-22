#include <bits/stdc++.h>

using LL = long long;

constexpr int mod = 998244353;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> c(n + 1), cp(n + 1);
  for (int i = 0; i < n; i++) {
    int l, r;
    std::cin >> l >> r;
    c[l] += 1;
    c[r + 1] -= 1;
    int nl = std::max(l, n - r);
    int nr = std::min(r, n - l);
    if (nl <= nr) {
      cp[nl] += 1;
      cp[nr + 1] -= 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    c[i] += c[i - 1];
    cp[i] += cp[i - 1];
  }
  std::vector<int> f(n + 1), inv(n + 1), finv(n + 1);
  f[0] = f[1] = inv[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = 1LL * f[i - 1] * i % mod;
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    finv[i] = 1LL * finv[i - 1] * inv[i] % mod;
  }
  auto C = [&](int a, int b) -> int {
    if (b < 0 || a < 0 || a < b) {
      return 0;
    }
    return 1LL * f[a] * finv[a - b] % mod * finv[b] % mod;
  };
  int ans = 0;
  for (int x = 1; x < n; x++) {
    int y = n - x;
    int z = cp[x] + c[y] - cp[y] - y;
    ans = (ans + 1LL * C(cp[x], z) * C(c[x] - cp[x], x - z) % mod) % mod;
  }
  std::cout << ans << '\n';


  return 0;
}