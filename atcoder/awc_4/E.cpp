#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, k;
  std::cin >> n >> k;
  LL sum = 0, ans = 0;
  std::map<LL, int> mp;
  mp[0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    sum += x;
    ans += mp[sum - k];
    mp[sum] += 1;
  }
  std::cout << ans << '\n';

  return 0;
}