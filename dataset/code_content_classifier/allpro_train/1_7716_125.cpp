#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
const int mod = 1e9 + 7;
inline int add(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}
inline int sub(int x, int y) {
  int res = x - y;
  if (res < 0) res += mod;
  return res;
}
inline int mul(int x, int y) {
  long long res = (long long)x * y;
  res -= res / mod * mod;
  return res;
}
inline int lowbit(int x) { return x & -x; }
int n, c[MAXN];
void upd(int x, int v) {
  for (; x <= n; x += lowbit(x)) c[x] = add(c[x], v);
}
int get(int x, int y) {
  int res = 0;
  x--;
  for (; y; y -= lowbit(y)) res = add(res, c[y]);
  for (; x; x -= lowbit(x)) res = sub(res, c[x]);
  return res;
}
pair<int, int> a[MAXN];
int lcnt[MAXN], rcnt[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].second = i;
  sort(a + 1, a + 1 + n);
  for (int i = 1, val, p; i <= n; i++) {
    val = a[i].first;
    p = a[i].second;
    lcnt[i] = get(1, p);
    upd(p, p);
  }
  memset(c, 0, sizeof(c));
  int ans = 0;
  for (int i = 1, val, p; i <= n; i++) {
    val = a[i].first;
    p = a[i].second;
    rcnt[i] = get(p + 1, n);
    upd(p, n - p + 1);
    int t = mul(p, n - p + 1);
    t = add(t, mul(p, rcnt[i]));
    t = add(t, mul(n - p + 1, lcnt[i]));
    ans = add(ans, mul(t, val));
  }
  printf("%d\n", ans);
  return 0;
}
