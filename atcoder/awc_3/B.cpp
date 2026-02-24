#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  int cnt = 0;
  char last;
  for (int i = 0; i < n; i++) {
    char l, r;
    std::cin >> l >> r;
    if (i > 0) {
      if (l == last) {
        cnt++;
      }
    }
    last = r;
  }
  std::cout << cnt << '\n';
  
  return 0;
}