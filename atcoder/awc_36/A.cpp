#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> book(n);
  for (int i = 0; i < n; i++) {
    int m;
    std::cin >> m;
    book[i].resize(m);
    for (int j = 0; j < m; j++) {
      std::cin >> book[i][j];
    }
  }
  int q;
  std::cin >> q;
  int req_fail_cnt = 0;
  while (q--) {
    int v, d;
    std::cin >> v >> d;
    v--, d--;
    if (book[v][d] > 0) {
      book[v][d]--;
    } else {
      req_fail_cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < book[i].size(); j++) {
      std::cout << book[i][j] << " \n"[j + 1 == book[i].size()];
    }
  }
  std::cout << req_fail_cnt << '\n';

  return 0;
}