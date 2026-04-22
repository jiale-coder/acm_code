#include <bits/stdc++.h>


void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  if (n % 2 == 0) {
    int l = (n - 1) / 2, r = n / 2;
    int id = 1, c = n / 2 % 2;
    while (l >= 0 && r < n) {
      if (c % 2 == 0) {
        p[l--] = id + 1;
        p[r++] = id;
      } else {
        p[l--] = id;
        p[r++] = id + 1;
      }
      id += 2;
      c ^= 1;
    }
  } else {
    p[n / 2] = 1;
    int id = 2, c = (n - 1) / 2 % 2;
    int l = n / 2 - 1, r = n / 2 + 1;
    while (l >= 0 && r < n) {
      if (c % 2 == 0) {
        p[l--] = id + 1;
        p[r++] = id;
      } else {
        p[l--] = id;
        p[r++] = id + 1;
      }
      id += 2;
      c ^= 1;
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << p[i] << " \n"[i == n - 1];
  }
  // for (int n = 1; n <= 8; n++) {
  //   std::vector<int> p(n);
  //   std::iota(p.begin(), p.end(), 0);
  //   auto calc = [&](const std::vector<int>& vec) {
  //     int64_t ans = 0;
  //     for (int i = 0; i < n; i++) {
  //       for (int j = i; j < n; j++) {
  //         int64_t prod = 1;
  //         for (int k = i; k <= j; k++) {
  //           prod *= p[k] + 1;
  //         }
  //         ans += prod;
  //       }
  //     }
  //     return ans;
  //   };
  //   std::vector<int> ans;
  //   int64_t res = 1e18;
  //   do {
  //     auto val = calc(p);
  //     if (res > val) {
  //       res = val;
  //       ans = p;
  //     } else if (res == val && ans > p) {
  //       ans = p;
  //     }
  //   } while (std::next_permutation(p.begin(), p.end()));
  //   std::cout << n << '\n';
  //   for (int i = 0; i < ans.size(); i++) {
  //     std::cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
  //   }
  // }
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