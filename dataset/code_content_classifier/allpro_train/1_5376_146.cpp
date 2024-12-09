#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, q;
long long a[N], k[N];
long long g[N], s[N], u[N];
long long qg(int l, int r) {
  if (l == 0)
    return s[r];
  else
    return s[r] - s[l - 1];
}
long long trs[N << 2], laz[N << 2];
void up(int rt) { trs[rt] = trs[rt << 1] + trs[rt << 1 | 1]; }
void build(int l, int r, int rt) {
  laz[rt] = INF;
  if (l == r) {
    trs[rt] = u[l];
    return;
  }
  build(l, ((l + r) >> 1), rt << 1);
  build(((l + r) >> 1) + 1, r, rt << 1 | 1);
  up(rt);
}
void down(int l, int r, int rt) {
  long long& x = laz[rt];
  if (x != INF) {
    trs[rt << 1] = x * (((l + r) >> 1) - l + 1);
    trs[rt << 1 | 1] = x * (r - ((l + r) >> 1));
    laz[rt << 1] = laz[rt << 1 | 1] = x;
    x = INF;
  }
}
void cg(int ql, int qr, long long x, int l, int r, int rt) {
  if (ql <= l && qr >= r) {
    laz[rt] = x;
    trs[rt] = x * (r - l + 1);
    return;
  }
  down(l, r, rt);
  if (ql <= ((l + r) >> 1)) cg(ql, qr, x, l, ((l + r) >> 1), rt << 1);
  if (qr > ((l + r) >> 1)) cg(ql, qr, x, ((l + r) >> 1) + 1, r, rt << 1 | 1);
  up(rt);
}
long long qry(int ql, int qr, int l, int r, int rt) {
  if (ql <= l && qr >= r) {
    return trs[rt];
  }
  down(l, r, rt);
  long long res = 0ll;
  if (ql <= ((l + r) >> 1)) res += qry(ql, qr, l, ((l + r) >> 1), rt << 1);
  if (qr > ((l + r) >> 1))
    res += qry(ql, qr, ((l + r) >> 1) + 1, r, rt << 1 | 1);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i < n; i++) {
    scanf("%lld", &k[i]);
    g[i] = g[i - 1] + k[i];
  }
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + g[i];
  for (int i = 1; i <= n; i++) u[i] = a[i] - g[i - 1];
  build(1, n, 1);
  scanf("%d", &q);
  while (q--) {
    char op;
    scanf(" %c", &op);
    int l, r;
    scanf("%d%d", &l, &r);
    if (op == 's') {
      printf("%lld\n", qry(l, r, 1, n, 1) + qg(l - 1, r - 1));
    } else {
      long long k = qry(l, l, 1, n, 1);
      k += r;
      int L = l, R = n;
      while (L < R) {
        int m = (L + R + 1) / 2;
        if (qry(m, m, 1, n, 1) < k)
          L = m;
        else
          R = m - 1;
      }
      cg(l, L, k, 1, n, 1);
    }
  }
  return 0;
}
