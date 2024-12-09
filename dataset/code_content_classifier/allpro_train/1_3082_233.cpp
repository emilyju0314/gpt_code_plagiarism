#include <bits/stdc++.h>
const int oo = 2139063143;
const int N = 101000;
const int P = 1000000007;
using namespace std;
inline void sc(int &x) {
  x = 0;
  static int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
}
inline void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
inline void pr(int x) { print(x), putchar('\n'); }
struct TREE {
  int ls, rs, w;
} t[N * 40];
int rt[N], totp = 0;
int change(int pre, int l, int r, int w, int d) {
  int p = ++totp;
  t[p] = t[pre];
  t[p].w += d;
  if (l == r) return p;
  int mid = (l + r) >> 1;
  if (w <= mid)
    t[p].ls = change(t[pre].ls, l, mid, w, d);
  else
    t[p].rs = change(t[pre].rs, mid + 1, r, w, d);
  return p;
}
int query(int p, int l, int r, int L) {
  if (L <= l) return t[p].w;
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid)
    return query(t[p].ls, l, mid, L) + t[t[p].rs].w;
  else
    return query(t[p].rs, mid + 1, r, L);
  return ans;
}
int n, k;
int calc(int l, int r) { return query(rt[r], 1, n, l); }
int a[N];
int f[N], g[N];
void solve(int wl, int wr, int l, int r) {
  int mid = (l + r) >> 1, pos = 0;
  f[mid] = 0;
  for (int i = wl; i <= min(wr, mid - 1); i++) {
    int sb = g[i] + calc(i + 1, mid);
    if (sb > f[mid]) f[mid] = sb, pos = i;
  }
  if (l == r) return;
  if (l < mid) solve(wl, pos, l, mid - 1);
  if (r > mid) solve(pos, wr, mid + 1, r);
}
int las[N];
int main() {
  sc(n), sc(k);
  for (int i = 1; i <= n; i++) {
    sc(a[i]);
    int pre = rt[i - 1];
    if (las[a[i]]) rt[i] = change(pre, 1, n, las[a[i]], -1), pre = rt[i];
    rt[i] = change(pre, 1, n, i, 1);
    las[a[i]] = i;
  }
  for (int i = 1; i <= k; i++) {
    solve(0, n, 1, n);
    memcpy(g, f, sizeof(int) * (n + 1));
  }
  pr(f[n]);
  return 0;
}
