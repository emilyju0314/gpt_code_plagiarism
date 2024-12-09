#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto &x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
inline int mul(int a, int b) { return (int)((long long)a * b % MOD); }
inline int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b /= 2;
  }
  return res;
}
inline int inv(int a) { return binpow(a, MOD - 2); }
int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), nxt(n + 1, -1), dp(n + 1);
    map<int, int> m[n + 1];
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == a[i + 1])
        nxt[i] = i + 1;
      else
        nxt[i] = (m[i + 1].count(a[i])) ? m[i + 1][a[i]] : -1;
      if (nxt[i] == -1) continue;
      int id = nxt[i] + 1;
      swap(m[i], m[id]);
      m[i][a[id]] = id;
      dp[i] = 1 + dp[id];
      ans += dp[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
