#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
const long long inf = 1000 * 1000 * 1000 + 7;
const long long INF = LLONG_MAX;
const long long MOD = 998244353;
const long long N = 3e5 + 10, base = 1 << 19;
long long drz[2 * base][2];
void wstaw(long long x, long long v) {
  x += base;
  drz[x][0] = drz[x][1] = v;
  while (x /= 2) {
    drz[x][0] = drz[2 * x][0] + drz[2 * x + 1][0];
    drz[x][1] = max(drz[2 * x][1], drz[2 * x + 1][1]);
  }
}
long long sum(long long a, long long b, long long p = 0, long long k = base - 1,
              long long x = 1) {
  if (k < a || p > b) return 0;
  if (p >= a && k <= b) return drz[x][0];
  long long sr = (p + k) / 2;
  return sum(a, b, p, sr, 2 * x) + sum(a, b, sr + 1, k, 2 * x + 1);
}
long long get(long long x, long long v) {
  if (drz[x][1] < v) return base;
  if (x >= base) return x - base;
  if (drz[2 * x][1] >= v) return get(2 * x, v);
  return get(2 * x + 1, v);
}
long long maxi(long long a, long long b, long long v, long long p = 0,
               long long k = base - 1, long long x = 1) {
  if (k < a || p > b) return base;
  if (p >= a && k <= b) {
    if (drz[x][1] >= v) return get(x, v);
    return base;
  }
  long long sr = (p + k) / 2;
  long long pom = maxi(a, b, v, p, sr, 2 * x);
  if (pom != base)
    return pom;
  else
    return maxi(a, b, v, sr + 1, k, 2 * x + 1);
}
void solve() {
  long long n, q;
  cin >> n >> q;
  for (long long i = ((1)); i <= ((n + 1) - 1); i++) {
    long long a;
    cin >> a;
    wstaw(i, a);
  }
  while (q--) {
    long long pos, val;
    cin >> pos >> val;
    wstaw(pos, val);
    long long pom = drz[base + 1][0];
    long long res = -1;
    if (pom == 0) {
      cout << "1\n";
      continue;
    }
    long long pocz = 1;
    for (long long i = ((0)); i <= ((30) - 1); i++) {
      if (drz[pocz + base + 1][0] == pom && pocz < n) res = pocz + 1;
      pocz = maxi(pocz + 2, base - 1, pom + drz[pocz + base + 1][0]);
      pocz--;
      if (pocz > n) break;
      pom = sum(0, pocz);
    }
    cout << res << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cout << setprecision(9) << fixed;
  cerr << setprecision(6) << fixed;
  long long test = 1;
  while (test--) {
    solve();
  }
}
