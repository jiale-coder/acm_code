#include <bits/stdc++.h>

constexpr int M = 1e5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> pos(M + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]].push_back(i);
  }
  std::vector<std::array<int, 3>> tr(n + 1);
  auto update = [&](int x, int l, int r, int v) {
    for (int i = x; i <= n; i += i & -i) {
      if (tr[i][0] < v) {
        tr[i] = {v, l, r};
      }
    }
  };
  auto query = [&](int x) {
    std::array<int, 3> res{};
    for (int i = x; i; i -= i & -i) {
      if (res[0] < tr[i][0]) {
        res = tr[i];
      }
    }
    return res;
  };
  std::map<std::array<int, 2>, std::array<int, 2>> f;
  int ans = 0;
  std::array<int, 2> tar{};
  for (int i = n - 1; i >= 1; i--) {
    const auto& vec = pos[a[i]];
    std::vector<int> rp;
    for (auto j : vec) {
      if (j > i) {
        rp.push_back(j);
      }
    }
    if (rp.empty()) {
      continue;
    }
    std::vector<std::array<int, 3>> tmp;
    for (auto j : rp) {
      auto res = query(j - 1);
      std::array<int, 3> uf{};
      if (uf[0] < res[0] + 2) {
        uf = {res[0] + 2, i, j};
        f[{i, j}] = {res[1], res[2]};
      }
      tmp.push_back(std::move(uf));
    }
    for (const auto& f : tmp) {
      update(f[2], f[1], f[2], f[0]);
      if (ans < f[0]) {
        ans = f[0];
        tar = {f[1], f[2]};
      }
    }
  }
  std::vector<int> p;
  p.reserve(ans);
  while (tar[0]) {
    p.push_back(a[tar[0]]);
    tar = f[tar];
  }
  int sz = p.size();
  for (int i = sz - 1; i >= 0; i--) {
    p.push_back(p[i]);
  }
  std::cout << p.size() << '\n';
  for (int i = 0; i < p.size(); i++) {
    std::cout << p[i] << " \n"[i + 1 == p.size()];
  }

  return 0;
}