#include <bits/stdc++.h>
using namespace std;
struct node {
  node *l, *r;
  int max_val, tag;
  node() {
    l = r = nullptr;
    max_val = tag = 0;
  }
  void push() {
    if (l == nullptr) l = new node();
    if (tag > l->tag) l->max_val = l->tag = tag;
    if (r == nullptr) r = new node();
    if (tag > r->tag) r->max_val = r->tag = tag;
    tag = 0;
  }
};
int query(int l, int r, int pos, node *p) {
  if (l == r)
    return p->max_val;
  else {
    int mid = (l + r) >> 1;
    p->push();
    if (pos <= mid)
      return query(l, mid, pos, p->l);
    else
      return query(mid + 1, r, pos, p->r);
  }
}
void modify(int l, int r, int ql, int qr, int val, node *p) {
  if (l == ql && r == qr) {
    if (val > p->max_val) p->max_val = p->tag = val;
  } else {
    int mid = (l + r) >> 1;
    p->push();
    if (qr <= mid)
      modify(l, mid, ql, qr, val, p->l);
    else if (ql > mid)
      modify(mid + 1, r, ql, qr, val, p->r);
    else {
      modify(l, mid, ql, mid, val, p->l);
      modify(mid + 1, r, mid + 1, qr, val, p->r);
    }
  }
}
set<pair<int, int> > vis;
node *U = new node();
node *L = new node();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    char type;
    cin >> type;
    if (vis.count(pair<int, int>{x, y})) {
      cout << 0 << endl;
    } else {
      if (type == 'U') {
        int pos = query(1, n, x, L);
        cout << y - pos << endl;
        if (pos != y) modify(1, n, pos + 1, y, x, U);
      } else {
        int pos = query(1, n, y, U);
        cout << x - pos << endl;
        if (pos != x) modify(1, n, pos + 1, x, y, L);
      }
      vis.insert(pair<int, int>{x, y});
    }
  }
  return 0;
}
