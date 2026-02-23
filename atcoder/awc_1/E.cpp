#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, k;
  std::cin >> n >> k;
  std::vector<int> h(n);
  for (auto& hi : h) {
    std::cin >> hi;
  }
  std::multiset<int> se;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    se.insert(h[i]);
    if (i >= k - 1) {
      ans = std::max(*se.rbegin() - *se.begin(), ans); 
      se.erase(se.find(h[i - k + 1]));
    }
  }
  std::cout << ans << '\n';

  return 0;
}