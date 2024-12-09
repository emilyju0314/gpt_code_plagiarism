#include <bits/stdc++.h>
using namespace std;
long long d1[500005 * 16], a[500005], n, Q, opt, x, y, cnt;
long long v, d[500005 * 16];
long long ls[500005 * 16], rs[500005 * 16], rt;
void insert(long long &k, long long l, long long r, long long x) {
  if (!k) k = ++cnt;
  d1[k]++;
  if (l == r) {
    d[k] += l;
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid)
    insert(ls[k], l, mid, x);
  else
    insert(rs[k], mid + 1, r, x);
  d[k] = d[ls[k]] + d[rs[k]];
}
void del(long long k, long long l, long long r, long long x) {
  d1[k]--;
  if (l == r) {
    d[k] -= l;
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid)
    del(ls[k], l, mid, x);
  else
    del(rs[k], mid + 1, r, x);
  d[k] = d[ls[k]] + d[rs[k]];
}
long long query(long long k, long long l, long long r, double x) {
  if (!k) return 0;
  if (r <= x) return d[k];
  long long mid = (l + r) >> 1;
  if (mid >= x)
    return query(ls[k], l, mid, x);
  else
    return d[ls[k]] + query(rs[k], mid + 1, r, x);
}
long long query1(long long k, long long l, long long r, double x) {
  if (!k) return 0;
  if (r <= x) return d1[k];
  long long mid = (l + r) >> 1;
  if (mid >= x)
    return query1(ls[k], l, mid, x);
  else
    return d1[ls[k]] + query1(rs[k], mid + 1, r, x);
}
signed main() {
  scanf("%lld%lld", &n, &Q);
  for (long long i = 1; i <= n; i++)
    scanf("%lld", &a[i]), insert(rt, 0, 1000000000, a[i]);
  while (Q--) {
    scanf("%lld", &opt);
    if (opt == 1) {
      scanf("%lld%lld", &x, &y);
      del(rt, 0, 1000000000, a[x]);
      a[x] = y;
      insert(rt, 0, 1000000000, a[x]);
    } else {
      scanf("%lld", &v);
      double l = 0;
      double r = 1e16;
      while (l + 1e-7 < r) {
        double mid = (l + r) / 2;
        if (mid * query1(rt, 0, 1000000000, mid) -
                query(rt, 0, 1000000000, mid) >=
            v)
          r = mid;
        else
          l = mid;
      }
      printf("%.8lf\n", l);
    }
  }
  return 0;
}
