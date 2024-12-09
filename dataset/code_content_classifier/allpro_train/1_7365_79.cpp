#include <bits/stdc++.h>
using namespace std;
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (0) {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
  }
}
const int PX[8] = {1, 0, -1, 0, 1, 1, -1, -1},
          PY[8] = {0, 1, 0, -1, -1, 1, 1, -1}, N = 1e5 + 10, INF = 1e9,
          MOD = 1e9 + 7;
const long long INFL = 1e18, MODL = 1e9 + 7;
const long double EPS = 1e-6;
template <typename t1, typename t2>
inline bool setMax(t1& a, t2 b) {
  if (a < b) return a = b, true;
  return false;
}
template <typename t1, typename t2>
inline bool setMin(t1& a, t2 b) {
  if (a > b) return a = b, true;
  return false;
}
inline long long rnd(long long l = 1, long long r = INFL) {
  unsigned long long ans = rand();
  ans = (ans << 16LL) ^ rand();
  ans = (ans << 16LL) ^ rand();
  ans = (ans << 16LL) ^ rand();
  ans %= r - l + 1;
  return (long long)ans + l;
}
int n, m, a[N], c[N], p[N];
inline bool cmp(int x, int y) { return c[x] < c[y]; }
int main() {
  file();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) p[i] = i;
  sort(p + 1, p + n + 1, cmp);
  int pos = 1;
  for (int i = 0; i < m; ++i) {
    int t, cnt;
    cin >> t >> cnt;
    long long sum = 0;
    long long x = min(cnt, a[t]);
    sum += x * c[t];
    cnt -= x;
    a[t] -= x;
    while (cnt) {
      while (pos <= n && !a[p[pos]]) ++pos;
      if (pos > n) {
        sum = 0;
        break;
      }
      x = min(cnt, a[p[pos]]);
      cnt -= x;
      a[p[pos]] -= x;
      sum += c[p[pos]] * x;
    }
    cout << sum << '\n';
  }
}
