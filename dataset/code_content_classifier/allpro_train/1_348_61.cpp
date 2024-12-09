#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int a[N], b[N], v[N << 2];
struct node {
  int ty, p, val;
} Q[N];
struct Tree {
  int l, r;
  long long sum;
  int mid() { return (l + r) >> 1; }
} tree[N << 2];
long long lazy[N << 2];
int sum = 0;
void pushup(int rt) {
  tree[rt].sum = max(tree[rt << 1].sum, tree[rt << 1 | 1].sum);
}
void pushdown(int rt) {
  if (lazy[rt]) {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    tree[rt << 1].sum += lazy[rt];
    tree[rt << 1 | 1].sum += lazy[rt];
    lazy[rt] = 0;
  }
}
void build(int l, int r, int rt) {
  tree[rt].l = l;
  tree[rt].r = r;
  lazy[rt] = 0;
  if (l == r) {
    tree[rt].sum = 0;
    return;
  }
  int m = tree[rt].mid();
  build(l, m, (rt << 1));
  build(m + 1, r, (rt << 1 | 1));
  pushup(rt);
}
void update(int c, int l, int r, int rt) {
  if (tree[rt].l == l && tree[rt].r == r) {
    lazy[rt] += c;
    tree[rt].sum += c;
    return;
  }
  if (tree[rt].l == tree[rt].r) return;
  int mid = tree[rt].mid();
  pushdown(rt);
  if (r <= mid)
    update(c, l, r, rt << 1);
  else if (l > mid)
    update(c, l, r, rt << 1 | 1);
  else {
    update(c, l, mid, rt << 1);
    update(c, mid + 1, r, rt << 1 | 1);
  }
  pushup(rt);
}
long long query(int l, int r, int rt) {
  if (tree[rt].l == tree[rt].r) return tree[rt].l;
  int mid = tree[rt].mid();
  pushdown(rt);
  if (tree[rt << 1 | 1].sum > 0)
    return query(mid + 1, r, rt << 1 | 1);
  else
    return query(l, mid, rt << 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[++sum] = a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    v[++sum] = b[i];
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++)
    cin >> Q[i].ty >> Q[i].p >> Q[i].val, v[++sum] = Q[i].val;
  sort(v + 1, v + 1 + sum);
  sum = unique(v + 1, v + 1 + sum) - v - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(v + 1, v + sum + 1, a[i]) - v;
  for (int i = 1; i <= m; i++) b[i] = lower_bound(v + 1, v + 1 + sum, b[i]) - v;
  for (int i = 1; i <= q; i++)
    Q[i].val = lower_bound(v + 1, v + 1 + sum, Q[i].val) - v;
  build(1, sum, 1);
  for (int i = 1; i <= n; i++) update(1, 1, a[i], 1);
  for (int i = 1; i <= m; i++) update(-1, 1, b[i], 1);
  for (int i = 1; i <= q; i++) {
    if (Q[i].ty == 1) {
      update(-1, 1, a[Q[i].p], 1);
      a[Q[i].p] = Q[i].val;
      update(1, 1, a[Q[i].p], 1);
    } else {
      update(1, 1, b[Q[i].p], 1);
      b[Q[i].p] = Q[i].val;
      update(-1, 1, b[Q[i].p], 1);
    }
    if (tree[1].sum <= 0)
      cout << -1 << endl;
    else
      cout << v[query(1, sum, 1)] << endl;
  }
}
