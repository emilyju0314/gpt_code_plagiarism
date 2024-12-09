#include <bits/stdc++.h>
using namespace std;
long long a[100005];
struct node {
  long long r, l, lazy, sum, mx;
} tree[400005];
void buildtree(long long i, long long l, long long r) {
  tree[i].l = l;
  tree[i].r = r;
  tree[i].lazy = 0;
  if (tree[i].r == tree[i].l) {
    tree[i].sum = a[l];
    tree[i].mx = a[l];
    return;
  }
  buildtree(i * 2, l, (r + l) / 2);
  buildtree(i * 2 + 1, (l + r) / 2 + 1, r);
  tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
  tree[i].mx = max(tree[i * 2].mx, tree[i * 2 + 1].mx);
}
void downadd(long long v) {
  if (!tree[v].lazy) return;
  tree[v * 2].lazy = tree[v].lazy;
  tree[v * 2 + 1].lazy = tree[v].lazy;
  tree[v * 2].mx = tree[v].lazy;
  tree[v * 2 + 1].mx = tree[v].lazy;
  tree[v * 2].sum = tree[v].lazy * (tree[v * 2].r - tree[v * 2].l + 1);
  tree[v * 2 + 1].sum =
      tree[v].lazy * (tree[v * 2 + 1].r - tree[v * 2 + 1].l + 1);
  tree[v].lazy = 0;
}
void update(long long i, long long l, long long r, long long k) {
  if (tree[i].l >= l && tree[i].r <= r) {
    tree[i].sum = (tree[i].r - tree[i].l + 1) * k;
    tree[i].lazy = k;
    tree[i].mx = k;
    return;
  }
  downadd(i);
  long long m = (tree[i].l + tree[i].r) / 2;
  if (l <= m) update(i * 2, l, r, k);
  if (r > m) update(i * 2 + 1, l, r, k);
  tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
  tree[i].mx = max(tree[i * 2].mx, tree[i * 2 + 1].mx);
}
long long query(long long i, long long l, long long r) {
  if (tree[i].l >= l && tree[i].r <= r) {
    return tree[i].mx;
  }
  downadd(i);
  long long ans = 0, m = (tree[i].r + tree[i].l) / 2;
  if (l <= m) ans = max(ans, query(i * 2, l, r));
  if (r > m) ans = max(ans, query(i * 2 + 1, l, r));
  return ans;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long q;
  cin >> q;
  buildtree(1, 1, n);
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x = min(x, n);
    long long v = query(1, 1, x);
    cout << v << endl;
    update(1, 1, x, v + y);
  }
}
