#include <bits/stdc++.h>


void solve() {
  int n;
  std::cin >> n;
  int ans = 0, ok = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    ans ^= x;
    if (x > 1) {
      ok = 1;
    }
  }
  if ((ok && ans == 0) || (!ok && n % 2)) {
    std::cout << "Jiuhui" << '\n';
  } else {
    std::cout << "Akie" << '\n';
  }
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