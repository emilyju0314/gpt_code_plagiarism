#include <bits/stdc++.h>
using namespace std;
struct seg {
  long long l, r, data, lazy;
};
struct block {
  long long l, r, data;
  bool operator<(const block &a) const { return l > a.l; }
};
block line[2000001];
seg tree[2][1000001];
long long ans, dp[1000001], n, m, a[1000001];
void build(long long tk, long long k, long long l, long long r) {
  tree[tk][k].l = l;
  tree[tk][k].r = r;
  long long mid = (l + r) / 2;
  if (l == r) return;
  build(tk, k * 2, l, mid);
  build(tk, k * 2 + 1, mid + 1, r);
  return;
}
void spread(long long tk, long long k) {
  tree[tk][k * 2].data += tree[tk][k].lazy;
  tree[tk][k * 2].lazy += tree[tk][k].lazy;
  tree[tk][k * 2 + 1].data += tree[tk][k].lazy;
  tree[tk][k * 2 + 1].lazy += tree[tk][k].lazy;
  tree[tk][k].lazy = 0;
  return;
}
void add(long long tk, long long k, long long l, long long r, long long d) {
  if (l > r) return;
  if (tree[tk][k].l == l && tree[tk][k].r == r) {
    tree[tk][k].data += d;
    tree[tk][k].lazy += d;
    return;
  }
  spread(tk, k);
  long long mid = (tree[tk][k].l + tree[tk][k].r) / 2;
  if (l <= mid && r <= mid) {
    add(tk, k * 2, l, r, d);
    tree[tk][k].data = max(tree[tk][k * 2].data, tree[tk][k * 2 + 1].data);
    return;
  }
  if (l >= mid + 1 && r >= mid + 1) {
    add(tk, k * 2 + 1, l, r, d);
    tree[tk][k].data = max(tree[tk][k * 2].data, tree[tk][k * 2 + 1].data);
    return;
  }
  add(tk, k * 2, l, mid, d);
  add(tk, k * 2 + 1, mid + 1, r, d);
  tree[tk][k].data = max(tree[tk][k * 2].data, tree[tk][k * 2 + 1].data);
  return;
}
long long query(long long tk, long long k, long long l, long long r) {
  if (l > r) return -1e18;
  if (tree[tk][k].l == l && tree[tk][k].r == r) return tree[tk][k].data;
  spread(tk, k);
  long long mid = (tree[tk][k].l + tree[tk][k].r) / 2;
  if (l <= mid && r <= mid) return query(tk, k * 2, l, r);
  if (l >= mid + 1 && r >= mid + 1) return query(tk, k * 2 + 1, l, r);
  return max(query(tk, k * 2, l, mid), query(tk, k * 2 + 1, mid + 1, r));
}
signed main() {
  long long x, y, z;
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  build(0, 1, 1, n);
  for (long long i = 1; i <= m; ++i)
    cin >> line[i].l >> line[i].r >> line[i].data;
  sort(line + 1, line + m + 1);
  long long lst = n, lt = 0;
  for (long long i = 1; i <= m; ++i) {
    for (long long j = line[i].l; j <= lst; ++j) add(0, 1, j, n, -a[j]);
    lst = line[i].l - 1;
    add(0, 1, line[i].r, n, line[i].data);
    dp[i] = max(query(0, 1, line[i].r, n), 0ll);
    add(0, 1, 1, line[i].l - 1, max(dp[i] - lt, 0ll));
    lt = max(lt, dp[i]);
  }
  for (long long i = 1; i <= m; ++i) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
