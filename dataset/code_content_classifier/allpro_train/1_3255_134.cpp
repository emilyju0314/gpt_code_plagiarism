#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
void faster() {
  if (0) {
    freopen(
        "taskA"
        ".in",
        "r", stdin);
    freopen(
        "taskA"
        ".out",
        "w", stdout);
  }
  if (1) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
}
const int MAXN = (int)2e5 + 123;
const int MOD = (int)1e9 + 7;
const long double EPS = 3E-16;
namespace MATH_CAL {
const int mod = (int)1e9 + 7;
inline long long add(long long a, long long b) {
  return a + b >= mod ? a + b - mod : a + b;
}
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline long long mul(long long a, long long b) {
  return (long long)a * b % mod;
}
inline void Add(int &a, int b) { (a += b) >= mod ? a -= mod : 0; }
inline void Sub(int &a, int b) { (a -= b) < 0 ? a += mod : 0; }
inline long long qpow(long long x, long long n) {
  long long r = 1;
  for (; n; n /= 2, x = mul(x, x))
    if (n & 1) r = mul(r, x);
  return r;
}
inline long long mod_inv(long long x) { return qpow(x, mod - 2); }
}  // namespace MATH_CAL
using namespace MATH_CAL;
vector<long long> g[MAXN];
bool used[MAXN];
long long da[MAXN];
long long db[MAXN];
void dfs1(int V, int pr = -1) {
  if (used[V]) return;
  used[V] = 1;
  if (pr != -1) {
    da[V] = da[pr] + 1;
  }
  for (auto to : g[V]) {
    if (!used[to]) {
      dfs1(to, V);
    }
  }
}
void dfs2(int V, int pr = -1) {
  if (used[V]) return;
  used[V] = 1;
  if (pr != -1) {
    db[V] = db[pr] + 1;
  }
  for (auto to : g[V]) {
    if (!used[to]) {
      dfs2(to, V);
    }
  }
}
void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1);
  for (int i = 1; i <= n; i++) {
    used[i] = false;
  }
  dfs2(x);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (db[i] < da[i]) {
      ans = max(ans, da[i] * 2ll);
    }
  }
  cout << ans << endl;
}
int main() {
  faster();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
