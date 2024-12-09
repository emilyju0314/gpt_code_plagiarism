#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100009];
int b[100009];
pair<int, int> tree[400009];
pair<int, int> lzy[400009];
void lzyUPD(int node, int l, int r) {
  if (lzy[node].first == -1) return;
  tree[node] = lzy[node];
  if (l != r) {
    lzy[node * 2] = lzy[node];
    lzy[node * 2 + 1] = lzy[node];
  }
  lzy[node] = {-1, -1};
}
void upd(int node, int l, int r, int s, int e, int x, int y) {
  lzyUPD(node, l, r);
  if (s <= l && e >= r) {
    lzy[node] = {x, y};
    lzyUPD(node, l, r);
    return;
  }
  if (s <= (l + r) / 2)
    upd(node * 2, l, (l + r) / 2, s, e, x, y);
  else
    lzyUPD(node * 2, l, (l + r) / 2);
  if (e >= (l + r) / 2 + 1)
    upd(node * 2 + 1, (l + r) / 2 + 1, r, s, e, x, y);
  else
    lzyUPD(node * 2 + 1, (l + r) / 2 + 1, r);
}
pair<int, int> query(int node, int l, int r, int k) {
  lzyUPD(node, l, r);
  if (l == r) {
    return tree[node];
  }
  if (k <= (l + r) / 2)
    return query(node * 2, l, (l + r) / 2, k);
  else
    return query(node * 2 + 1, (l + r) / 2 + 1, r, k);
}
int main() {
  memset(tree, -1, sizeof(tree));
  memset(lzy, -1, sizeof(lzy));
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y, k;
      cin >> x >> y >> k;
      x--;
      y--;
      upd(1, 0, n - 1, y, y + k - 1, x, y);
    } else {
      int id;
      cin >> id;
      id--;
      pair<int, int> ans = query(1, 0, n - 1, id);
      if (ans.first == -1) {
        cout << b[id] << endl;
      } else {
        cout << a[ans.first + (id - ans.second)] << endl;
      }
    }
  }
}
