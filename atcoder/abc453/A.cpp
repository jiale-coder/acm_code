#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  while (s.size() && s.back() == 'o') {
    s.pop_back();
  }
  std::reverse(s.begin(), s.end());
  std::cout << s << '\n';

  return 0;
}