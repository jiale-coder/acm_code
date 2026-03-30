#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::array<int, 2>> seg(n);
  for (auto& [l, r] : seg) {
    std::cin >> l >> r;
    r--;
  }
  std::sort(seg.begin(), seg.end());
  std::priority_queue<int, std::vector<int>, std::greater<>> pq;
  int cnt = 0;
  for (const auto& [l, r] : seg) {
    if (pq.size() && pq.top() < l) {
      pq.pop();
    } else {
      cnt++;
    }
    pq.push(r);
  }
  std::cout << cnt << '\n';

  return 0;
}