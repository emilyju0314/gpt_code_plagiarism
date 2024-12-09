#include <bits/stdc++.h>
using namespace std;
long long L[100100], r, g, pre[100100], lsh[100100];
int mn[100100 * 20], ls[100100 * 20], rs[100100 * 20];
int n, flag, poi;
long long f[100100], t[100100];
void pushup(int x) { mn[x] = min(mn[ls[x]], mn[rs[x]]); }
void modify(int &x, long long l, long long r, long long d, int val) {
  if (!x) x = ++poi;
  if (l == r) {
    mn[x] = min(mn[x], val);
    return;
  }
  int mid = l + r >> 1;
  if (d <= mid)
    modify(ls[x], l, mid, d, val);
  else
    modify(rs[x], mid + 1, r, d, val);
  pushup(x);
}
long long query(int x, long long l, long long r, long long LL, long long RR) {
  if (!x || RR < LL) return 2002122500;
  if (l >= LL && r <= RR) return mn[x];
  int mid = l + r >> 1;
  long long ans = 2002122500;
  if (LL <= mid) ans = min(ans, query(ls[x], l, mid, LL, RR));
  if (RR > mid) ans = min(ans, query(rs[x], mid + 1, r, LL, RR));
  return ans;
}
int rt, q;
long long p;
int main() {
  scanf("%d%I64d%I64d", &n, &g, &r);
  memset(mn, 48, sizeof(mn));
  p = g + r;
  for (int i = 1; i <= n + 1; i++) scanf("%I64d", &L[i]), L[i] += L[i - 1];
  for (int i = n; i; i--) {
    long long _t = (p - L[i] % p) % p;
    long long mn = query(rt, 0, p - 1, max(0ll, g - _t), p - _t - 1);
    if (g - _t < 0) mn = min(mn, query(rt, 0, p - 1, (p + g - _t), p - 1));
    if (mn > n)
      f[i] = L[n + 1] - L[i];
    else
      f[i] = L[mn] - L[i] + (p - (L[mn] - L[i]) % p) + f[mn];
    modify(rt, 0, p - 1, L[i] % p, i);
  }
  scanf("%d", &q);
  while (q--) {
    long long _t, ans;
    scanf("%lld", &_t);
    long long _ = _t % p;
    long long mn = query(rt, 0, p - 1, max(0ll, g - _), p - _ - 1);
    if (g - _ < 0) mn = min(mn, query(rt, 0, p - 1, (g - _ + p), p - 1));
    if (mn > n)
      ans = L[n + 1] + _t;
    else
      ans = L[mn] + _t + (p - (L[mn] + _t) % p) + f[mn];
    printf("%I64d\n", ans);
  }
  return 0;
}
