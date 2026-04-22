#include <bits/stdc++.h>

using LL = long long;

struct Node {
  Node* l{nullptr};
  Node* r{nullptr};
  LL sum{0};
};

void update(Node*& u, Node* v, int l, int r, int x, int val) {
  u = new Node();
  if (v) {
    *u = *v;
  }
  u->sum += val;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) {
    update(u->l, v ? v->l : nullptr, l, mid, x, val);
  } else {
    update(u->r, v ? v->r : nullptr, mid + 1, r, x, val);
  }
}

LL query(Node* u, int l, int r, int ql, int qr) {
  if (!u || ql > r || qr < l) {
    return 0;
  }
  if (l >= ql && r <= qr) {
    return u->sum;
  }
  int mid = (l + r) >> 1;
  return query(u->l, l, mid, ql, qr) + query(u->r, mid + 1, r, ql, qr);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<Node*> root(n + 1, nullptr);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, y;
      std::cin >> x >> y;
      root[x] = root[y];
    } else if (op == 2) {
      int x, y, z;
      std::cin >> x >> y >> z;
      int old = query(root[x], 1, m, y, y);
      int diff = z - old;
      Node* cur{nullptr};
      update(cur, root[x], 1, m, y, diff);
      root[x] = cur;
    } else {
      int x, l, r;
      std::cin >> x >> l >> r;
      std::cout << query(root[x], 1, m, l, r) << '\n';
    }
  }

  return 0;
}