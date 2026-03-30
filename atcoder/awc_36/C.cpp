#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto& ai : a) {
    std::cin >> ai;
  }
  auto check = [&](LL x) {
    LL sum = 0;
    int cnt = 0;
    for (auto ai : a) {
      if (sum + ai > x) {
        sum = ai;
        cnt += 1;
      } else {
        sum += ai;
      }
      if (sum > x) {
        return false;
      }
    }
    return cnt <= k;
  };
  LL l = 1, r = 1e18;
  while (l < r) {
    LL mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  std::cout << l << '\n';

  return 0;
}