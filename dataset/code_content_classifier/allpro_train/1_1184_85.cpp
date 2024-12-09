#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, m, q, A[600005], a[600005], pre[600005], suf[600005], ans;
struct BIT {
  long long c[600005];
  void init() { memset(c, 0, sizeof(c)); }
  void modify(long long x, long long k) {
    for (; x <= m; x += x & -x) c[x] += k;
  }
  long long query(long long x) {
    long long res = 0;
    for (; x; x -= x & -x) res += c[x];
    return res;
  }
} t;
struct Segment_Tree {
  long long cnt, ls[600005 << 2], rs[600005 << 2], sum[600005 << 2],
      B[600005 << 2], D[600005 << 2], BC[600005 << 2], CD[600005 << 2],
      BCD[600005 << 2];
  void push_up(long long k) {
    sum[k] = (sum[ls[k]] + sum[rs[k]]) % 1000000007;
    B[k] = (B[ls[k]] + B[rs[k]]) % 1000000007;
    D[k] = (D[ls[k]] + D[rs[k]]) % 1000000007;
    BC[k] = (BC[ls[k]] + BC[rs[k]] + B[ls[k]] * sum[rs[k]] % 1000000007) %
            1000000007;
    CD[k] = (CD[ls[k]] + CD[rs[k]] + sum[ls[k]] * D[rs[k]] % 1000000007) %
            1000000007;
    BCD[k] = (BCD[ls[k]] + BCD[rs[k]] + B[ls[k]] * CD[rs[k]] % 1000000007 +
              BC[ls[k]] * D[rs[k]] % 1000000007) %
             1000000007;
  }
  void modify(long long k, long long l, long long r, long long x, long long Pre,
              long long Suf, long long val) {
    if (l == r) {
      B[k] = Pre;
      D[k] = Suf;
      sum[k] += val;
      return;
    }
    long long mid = (l + r) >> 1;
    if (x <= mid) {
      if (!ls[k]) ls[k] = ++cnt;
      modify(ls[k], l, mid, x, Pre, Suf, val);
    } else {
      if (!rs[k]) rs[k] = ++cnt;
      modify(rs[k], mid + 1, r, x, Pre, Suf, val);
    }
    push_up(k);
  }
} T;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) A[i] = a[i] = read();
  sort(a + 1, a + 1 + n);
  m = unique(a + 1, a + 1 + n) - a - 1;
  for (long long i = 1; i <= n; i++)
    A[i] = lower_bound(a + 1, a + 1 + m, A[i]) - a;
  for (long long i = 1; i <= n; i++) pre[i] = t.query(A[i]), t.modify(A[i], 1);
  t.init();
  for (long long i = n; i >= 1; i--) suf[i] = t.query(A[i]), t.modify(A[i], 1);
  T.cnt = m;
  for (long long i = 1; i <= n; i++) T.modify(A[i], 1, n, i, pre[i], suf[i], 1);
  for (long long i = 1; i <= m; i++) ans += T.BCD[i], ans %= 1000000007;
  ;
  q = read();
  while (q--) {
    long long opt = read(), x = read();
    ans = (ans + 1000000007 - T.BCD[A[x]]) % 1000000007;
    if (opt == 1)
      T.modify(A[x], 1, n, x, 0, 0, -1);
    else
      T.modify(A[x], 1, n, x, pre[x], suf[x], 1);
    ans = (ans + T.BCD[A[x]]) % 1000000007;
    printf("%lld\n", ans);
  }
  return 0;
}
