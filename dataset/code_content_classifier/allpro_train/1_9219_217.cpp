#include <bits/stdc++.h>
const long long maxn = 1e5 + 9, modn = 1e9 + 7;
using namespace std;
long long n, m, l[maxn], r[maxn], q[maxn], s[4 * maxn], a[maxn];
void query(long long x, long long y, long long q, long long v = 1,
           long long l = 0, long long r = n) {
  if (x >= r || y <= l) return;
  if (l >= x && r <= y) {
    s[v] |= q;
    return;
  }
  long long mid = (l + r) / 2;
  query(x, y, q, 2 * v, l, mid);
  query(x, y, q, 2 * v + 1, mid, r);
}
void solve(long long ind, long long ans, long long v = 1, long long l = 0,
           long long r = n) {
  ans |= s[v];
  if (r - l == 1) {
    a[ind] = ans;
    return;
  }
  long long mid = (l + r) / 2;
  if (ind < mid)
    solve(ind, ans, 2 * v, l, mid);
  else
    solve(ind, ans, 2 * v + 1, mid, r);
}
void build(long long v = 1, long long l = 0, long long r = n) {
  if (r - l == 1) {
    s[v] = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * v, l, mid);
  build(2 * v + 1, mid, r);
  s[v] = s[2 * v] & s[2 * v + 1];
}
long long get(long long x, long long y, long long v = 1, long long l = 0,
              long long r = n) {
  long long k = (1 << 30) - 1;
  if (x >= r || y <= l) return k;
  if (l >= x && r <= y) return s[v];
  long long mid = (l + r) / 2;
  return (get(x, y, 2 * v, l, mid) & get(x, y, 2 * v + 1, mid, r));
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> q[i];
    query(l[i] - 1, r[i], q[i]);
  }
  for (long long i = 0; i < n; i++) solve(i, 0);
  build();
  for (long long i = 0; i < m; i++) {
    long long h = get(l[i] - 1, r[i]);
    if (h != q[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
