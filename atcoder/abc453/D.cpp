#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> grid(h);
  int x1, y1, x2, y2;
  for (int i = 0; i < h; i++) {
    std::cin >> grid[i];
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == 'S') {
        x1 = i, y1 = j;
      } else if (grid[i][j] == 'G') {
        x2 = i, y2 = j;
      }
    }
  }
  std::vector<std::vector<std::vector<int>>> dis(h, std::vector<std::vector<int>>(w, std::vector<int>(4, -1)));
  std::vector<std::vector<std::vector<std::array<int, 3>>>> last(h, std::vector<std::vector<std::array<int, 3>>>(w, std::vector<std::array<int, 3>>(4, {-1, -1})));
  std::queue<std::array<int, 3>> que;
  auto convert = [&](int x) {
    if (x == 0) return 'R';
    if (x == 1) return 'L';
    if (x == 2) return 'D';
    return 'U';
  };
  for (int i = 0; i < 4; i++) {
    dis[x1][y1][i] = 0;
    que.push({x1, y1, i});
  }
  const std::vector<std::array<int, 2>> crt{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  while (que.size()) {
    auto [x, y, dir] = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      auto [dx, dy] = crt[i];
      if (grid[x][y] == 'o' && i != dir) {
        continue;
      }
      if (grid[x][y] == 'x' && i == dir) {
        continue;
      }
      int ux = dx + x, uy = dy + y;
      if (ux < 0 || ux >= h || uy < 0 || uy >= w || dis[ux][uy][i] != -1 || grid[ux][uy] == '#') {
        continue;
      }
      dis[ux][uy][i] = dis[x][y][dir] + 1;
      last[ux][uy][i] = {x, y, dir};
      que.push({ux, uy, i});
    }
  }
  int dir = -1;
  for (int i = 0; i < 4; i++) {
    if (dis[x2][y2][i] != -1) {
      if (dir == -1 || dis[x2][y2][dir] > dis[x2][y2][i]) {
        dir = i;
      }
    }
  }
  if (dir == -1) {
    std::cout << "No" << '\n';
  } else {
    std::cout << "Yes" << '\n';
    std::string s;
    int x = x2, y = y2;
    while (x != x1 || y != y1) {
      s += convert(dir);
      auto [nx, ny, ndir] = last[x][y][dir];
      x = nx, y = ny, dir = ndir;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s << '\n';
  }
  
  return 0;
}