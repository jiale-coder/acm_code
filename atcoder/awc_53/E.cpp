#include <bits/stdc++.h>

constexpr int mod = 998244353;

void add(int& x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}

struct Mat {
  std::vector<std::vector<int>> mat_;
  int n_, m_;
  Mat(int n, int m) : n_(n), m_(m) {
    mat_.assign(n, std::vector<int>(m));
  }
  Mat operator*(const Mat& rhs) const {
    assert(m_ == rhs.n_);
    Mat c(n_, rhs.m_);
    for (int i = 0; i < c.n_; i++) {
      for (int j = 0; j < c.m_; j++) {
        for (int k = 0; k < m_; k++) {
          add(c.mat_[i][j], 1LL * mat_[i][k] * rhs.mat_[k][j] % mod);
        }
      }
    }
    return c;
  }
};


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;
  Mat g(n, n);
  while (m--) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--, v--;
    g.mat_[u][v] = w;
  }
  Mat f(n, n);
  f.mat_[0][0] = 1;
  f = f * g;
  k--;
  while (k) {
    if (k & 1) {
      f = f * g;
    }
    g = g * g;
    k >>= 1;
  }
  std::cout << f.mat_[0][n - 1] << '\n';

  return 0;
}