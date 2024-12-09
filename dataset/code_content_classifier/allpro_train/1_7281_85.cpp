#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
using ll = long long;
int n, m, p, a[N];
struct TNode {
  int l, r;
  vector<ll> f;
  ll sum;
} t[N << 2];
inline int lc(int pos) { return pos << 1; }
inline int rc(int pos) { return pos << 1 | 1; }
void pushup(int pos) {
  t[pos].sum = t[lc(pos)].sum + t[rc(pos)].sum;
  int ptr = 0;
  for (int i = 1; i <= t[pos].r - t[pos].l + 1; i++)
    t[pos].f[i] = (LLONG_MAX >> 2);
  for (int i = 0; i <= t[lc(pos)].r - t[lc(pos)].l + 1; i++) {
    if (ptr > t[rc(pos)].r - t[rc(pos)].l + 1) --ptr;
    while (ptr <= t[rc(pos)].r - t[rc(pos)].l + 1) {
      ll ret = t[rc(pos)].f[ptr] - (t[lc(pos)].sum - i * 1ll * p);
      ll val = t[lc(pos)].f[i + 1] - 1 + (t[lc(pos)].sum - i * 1ll * p);
      if (val < t[rc(pos)].f[ptr]) {
        if (ptr > 0) --ptr;
        break;
      }
      t[pos].f[i + ptr] = min(t[pos].f[i + ptr], max(t[lc(pos)].f[i], ret));
      ++ptr;
    }
  }
}
void build(int pos, int l, int r) {
  t[pos].l = l;
  t[pos].r = r;
  t[pos].f.resize(r - l + 1 + 1);
  t[pos].f[0] = LLONG_MIN >> 2;
  t[pos].f.push_back(LLONG_MAX >> 2);
  if (l == r) {
    t[pos].sum = a[l];
    t[pos].f[1] = p - a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(lc(pos), l, mid);
  build(rc(pos), mid + 1, r);
  pushup(pos);
}
ll query(int pos, int l, int r, ll cur = 0) {
  if (t[pos].l == l && t[pos].r == r) {
    assert(cur < LLONG_MAX / 4);
    ll pp = upper_bound(t[pos].f.begin(), t[pos].f.end(), cur) -
            t[pos].f.begin() - 1;
    return cur + t[pos].sum - p * pp;
  }
  int mid = (t[pos].l + t[pos].r) >> 1;
  if (r <= mid)
    return query(lc(pos), l, r, cur);
  else if (l > mid)
    return query(rc(pos), l, r, cur);
  else
    return query(rc(pos), mid + 1, r, query(lc(pos), l, mid, cur));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << query(1, l, r) << endl;
  }
  return 0;
}
