#include <bits/stdc++.h>

using LL = long long;

constexpr LL inf = std::numeric_limits<LL>::min() / 2;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 2>> seg(m);
  for (int i = 0; i < m; i++) {
    auto& [l, r] = seg[i];
    std::cin >> l >> r;
  }
  std::sort(seg.begin(), seg.end());
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i = 1, j = 0; i <= n; i++) {
    while (j < m && seg[j][0] <= i) {
      pq.push(seg[j++][1]);
    }
    if (pq.size() && pq.top() < i) {
      std::cout << "No\n";
      return 0;
    }
    if (pq.size()) {
      pq.pop();
    }
  }
  std::cout << (pq.empty() ? "Yes" : "No") << '\n';

  return 0;
}