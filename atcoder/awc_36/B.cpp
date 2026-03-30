#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  std::cin >> q;
  std::unordered_set<int> se;
  while (q--) {
    int t, x;
    std::cin >> t >> x;
    if (t == 1) {
      se.insert(x);
    } else {
      std::cout << (se.contains(x) ? "Yes" : "No") << '\n';
    }
  }

  return 0;
}