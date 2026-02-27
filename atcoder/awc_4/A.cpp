#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, s, t;
  std::cin >> n >> s >> t;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    tot += a;
  }
  s += tot / 60;
  if (s < t || (s == t && tot % 60 == 0)) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }

  return 0;
}