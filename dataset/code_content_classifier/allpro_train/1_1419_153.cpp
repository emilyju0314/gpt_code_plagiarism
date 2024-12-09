#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int res = 0;
  register char c = getchar(), f = 1;
  while (c < 48 || c > 57) {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= 48 && c <= 57)
    res = (res << 3) + (res << 1) + (c & 15), c = getchar();
  return f ? res : -res;
}
inline void write(long long x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
const int N = 1e5 + 10, L = 20;
struct node {
  int sz, a[L];
  inline node(int x = -1) {
    if (~x) {
      sz = 1;
      for (int i = 0; i < L; ++i, x >>= 1) a[i] = x & 1;
    } else
      sz = 0, memset(a, 0, sizeof(a));
  }
  inline node operator+(const node& p) const {
    node r = *this;
    r.sz += p.sz;
    for (int i = 0; i < L; ++i) r.a[i] += p.a[i];
    return r;
  }
  inline node operator^(int x) const {
    node r = *this;
    for (int i = 0; i < L; ++i, x >>= 1) r.a[i] = x & 1 ? sz - a[i] : a[i];
    return r;
  }
} a[N], sum[N];
inline void write(const node& x) {
  long long r = 0;
  for (int i = 0; i < L; ++i) r += (long long)x.a[i] << i;
  write(r);
}
int n, m, rt, w[N], lc[N], rc[N], tag[N], tot = 0;
inline void pu(int x) { sum[x] = sum[lc[x]] + sum[rc[x]] + a[x]; }
int build(int l, int r) {
  if (l > r) return 0;
  int mid = (l + r) >> 1, x = mid;
  w[x] = ++tot;
  lc[x] = build(l, mid - 1), rc[x] = build(mid + 1, r);
  pu(x);
  return x;
}
inline void add(int x, int t) {
  a[x] = a[x] ^ t, sum[x] = sum[x] ^ t, tag[x] ^= t;
}
inline void pd(int x) {
  if (tag[x]) add(lc[x], tag[x]), add(rc[x], tag[x]), tag[x] = 0;
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (w[x] < w[y]) {
    pd(x), rc[x] = merge(rc[x], y), pu(x);
    return x;
  } else {
    pd(y), lc[y] = merge(x, lc[y]), pu(y);
    return y;
  }
}
void split(int rt, int k, int& x, int& y) {
  if (!rt) return x = y = 0, void();
  pd(rt);
  if (sum[lc[rt]].sz < k) {
    x = rt;
    split(rc[x], k - sum[lc[x]].sz - 1, rc[x], y);
    pu(x);
  } else {
    y = rt;
    split(lc[y], k, x, lc[y]);
    pu(y);
  }
}
int op, l, r, x, y, z;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) sum[i] = a[i] = read();
  m = read();
  rt = build(1, n);
  while (m--) {
    op = read(), l = read(), r = read();
    if (op == 1) {
      split(rt, r, x, z);
      split(x, l - 1, x, y);
      write(sum[y]), putchar('\n');
      rt = merge(merge(x, y), z);
    } else {
      split(rt, r, x, z);
      split(x, l - 1, x, y);
      add(y, read());
      rt = merge(merge(x, y), z);
    }
  }
}
