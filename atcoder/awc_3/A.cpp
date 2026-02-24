#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  LL k;
  std::cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    LL a, b;
    std::cin >> a >> b;
    if (a * b >= k) {
      cnt++;
    }
  }
  std::cout << cnt << '\n';

  return 0;
}