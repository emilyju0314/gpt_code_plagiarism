#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-6;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char nl = '\n';
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
void ckmin(T& a, T b) {
  a = min(a, b);
}
template <class T>
void ckmax(T& a, T b) {
  a = max(a, b);
}
int pct(int x) { return __builtin_popcount(x); }
int pct(long long x) { return __builtin_popcountll(x); }
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << h;
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void unsyncIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void setIO(string s = "") {
  unsyncIO();
  if ((int)s.size()) {
    setIn(s + ".in"), setOut(s + ".out");
  }
}
long long pow(long long b, long long e, long long m = 0LL,
              long long ans = 1LL) {
  while (e) {
    if (e & 1LL) {
      ans *= b;
      if (m) ans %= m;
    }
    b *= b, e >>= 1LL;
    if (m) b %= m;
  }
  return ans;
}
int dp[2000010];
void precompute() {
  dp[2] = 4;
  for (int i = 3; i < 2000010; ++i) {
    long long cur = dp[i - 1] + 2LL * dp[i - 2] + 4LL * (i % 3 == 2);
    cur %= MOD;
    dp[i] = cur;
  }
}
void solve(int tcn) {
  int n;
  cin >> n, --n;
  cout << dp[n] << nl;
}
int main() {
  setIO();
  precompute();
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
