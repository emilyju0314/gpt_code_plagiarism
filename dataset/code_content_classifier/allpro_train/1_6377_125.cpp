#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 1e9 + 7;
const long long infL = 1e18;
int setbit(int n, int pos) { return n = n | (1 << pos); }
int resetbit(int n, int pos) { return n = n & ~(1 << pos); }
bool checkbit(int n, int pos) { return (bool)(n & (1 << pos)); }
template <typename T>
T mul(T x, T y) {
  x %= mod;
  y %= mod;
  return (x * y) % mod;
}
template <typename T>
T add(T x, T y) {
  x %= mod;
  y %= mod;
  return (x + y) % mod;
}
template <typename T>
T modPow(T x, T k, T mod) {
  if (k == 0) return 1;
  if (k & 1) {
    return ((x % mod) * modPow(x, k - 1, mod) % mod) % mod;
  } else {
    T ret = modPow(x, k / 2, mod);
    ret %= mod;
    return (ret * ret) % mod;
  }
}
template <typename T>
T ext_gcd(T num1, T num2, T &X, T &Y) {
  T r2, r1, q2, q1, x2, x1, y2, y1, x, y, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = num1, r1 = num2; r1 != 0;
       y2 = y1, y1 = y, x2 = x1, x1 = x, r2 = r1, r1 = r) {
    q1 = r2 / r1;
    x = x2 - q1 * x1;
    y = y2 - q1 * y1;
    r = r2 % r1;
  }
  X = x2;
  Y = y2;
  return r2;
}
template <typename T>
void print(const T &v) {
  cerr << v << ' ';
}
template <typename T1, typename... T2>
void print(const T1 &first, const T2 &...rest) {
  print(first);
  print(rest...);
}
template <typename T>
T modInv(T x, T m) {
  return modPow(x, m - 2, m);
}
template <typename T>
void dbg_a(T a[], int n = 10) {
  for (int i = 0; i < n; i++) cerr << a[i] << ' ';
  cerr << "\n";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "[ " << p.first << ", " << p.second << " ]";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
  return os << " ]";
}
long long modAdd(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
const int M = (int)1e6 + 10;
const int mx = (int)10000 + 123;
const int nx = 500 + 2;
int vis[M + 2], dp[M + 2][27], ans = 0, f;
vector<int> g[M + 2];
string s;
void func(int u) {
  vis[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (vis[v] == 1) {
      f = 1;
      return;
    }
    if (vis[v] == 0) func(v);
    for (int j = 0; j < 26; j++)
      dp[u][j] = max(dp[u][j], dp[v][j]), ans = max(ans, dp[u][j]);
  }
  dp[u][s[u] - 'a']++;
  ans = max(ans, dp[u][s[u] - 'a']);
  vis[u] = 2;
}
void solve() {
  int n, q;
  cin >> n >> q;
  cin >> s;
  s = "d" + s;
  for (int _ = 0; _ < q; _++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
  }
  f = ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      func(i);
    }
  }
  if (f)
    cout << -1;
  else
    cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, c = 0;
  while (t--) {
    solve();
  }
}
