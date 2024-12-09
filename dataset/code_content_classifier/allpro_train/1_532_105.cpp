#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 5, MOD = 1e9 + 7;
struct SegTree {
  SegTree *lson, *rson;
  int l, r;
  int L = MAXN, R = 0;
  int tag = 1;
} * root, tree[MAXN << 1];
int n, m, q, tot;
set<int> L[MAXN], R[MAXN];
map<pair<int, int>, bool> vis;
inline void update(SegTree* root) {
  root->L = min(root->lson->L, root->rson->L);
  root->R = max(root->lson->R, root->rson->R);
  if (!root->lson->tag || !root->rson->tag || root->lson->L <= root->rson->R)
    root->tag = 0;
  else
    root->tag = 1;
}
inline void build(SegTree*& root, int l, int r) {
  root = &tree[tot++], root->l = l, root->r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(root->lson, l, mid), build(root->rson, mid + 1, r);
  update(root);
}
inline void modify(SegTree* root, int pos, int val, int tag) {
  if (root->l == pos && root->r == pos) {
    if (tag == 1)
      root->L = val;
    else
      root->R = val;
    root->tag = root->L > root->R;
    return;
  }
  int mid = (root->l + root->r) >> 1;
  if (pos <= mid)
    modify(root->lson, pos, val, tag);
  else
    modify(root->rson, pos, val, tag);
  update(root);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  build(root, 1, n);
  while (q--) {
    int x, y;
    cin >> x >> y;
    int i = (x + 1) >> 1, j = (y + 1) >> 1;
    if (x & 1) {
      if (!vis[{x, y}])
        L[i].insert(j);
      else
        L[i].erase(j);
      modify(root, i, L[i].empty() ? MAXN : *L[i].begin(), 1);
    } else {
      if (!vis[{x, y}])
        R[i].insert(j);
      else
        R[i].erase(j);
      auto it = R[i].end();
      modify(root, i, R[i].empty() ? 0 : *(--it), 2);
    }
    vis[{x, y}] ^= 1;
    root->tag ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
