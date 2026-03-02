#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  std::cin >> n;
  int cnt = 0;
  LL sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    if (a > b) {
      cnt++;
      sum += a - b;
    }
  }
  std::cout << cnt << ' ' << sum << '\n';

  return 0;
}