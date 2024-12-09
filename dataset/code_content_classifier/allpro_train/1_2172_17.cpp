#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000 + 7;
const long long LL_INF = 1ll * INF * INF;
const int MAX_N = 200000 + 7;
const int multipleTest = 0;
template <typename T>
inline void addmod(T& a, const long long& b, const int MOD = INF) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
class InverseModule {
 public:
  static const int MOD = ::INF;
  static const int MAX_N = 2e5 + 7;
  int fact[MAX_N];
  int invFact[MAX_N];
  InverseModule() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
      fact[i] = (long long)fact[i - 1] * i % MOD;
      invFact[i] = inverse(fact[i], MOD);
    }
  }
  int inverse(int x, int n) {
    int r = n, newr = x;
    int t = 0, newt = 1;
    while (newr > 0) {
      int q = r / newr;
      int tmp = newr;
      newr = r % newr;
      r = tmp;
      tmp = newt;
      newt = t - q * newt;
      t = tmp;
    }
    if (t < 0) t += n;
    return t;
  }
  int C(int n, int k) {
    return (long long)fact[n] * invFact[n - k] % MOD * invFact[k] % MOD;
  }
  long long pw(long long x, long long k) {
    if (!k)
      return 1;
    else if (k & 1)
      return pw(x, k - 1) * x % MOD;
    long long tmp = pw(x, k / 2);
    return tmp * tmp % MOD;
  }
  pair<int, int> extended_euclid(int a, int b) {
    int s0 = 1, t0 = 0;
    int s1 = 0, t1 = 1;
    while (b > 0) {
      int q = a / b;
      int tmp = 0;
      tmp = s1;
      s1 = s0 - q * s1;
      s0 = tmp;
      tmp = t1;
      t1 = t0 - q * t1;
      t0 = tmp;
      tmp = b;
      b = a - q * b;
      a = tmp;
    }
    return {s0, t0};
  }
  int stirling_second_kind(int n, int k) {
    long long res = 0;
    for (int j = 0; j <= k; ++j) {
      long long temp = 1ll * C(k, j) * pw(j, n);
      if ((k - j) & 1)
        res = (res - temp + MOD) % MOD;
      else
        res = (res + temp) % MOD;
    }
    return res * invFact[k] % MOD;
  }
} inv;
int C(int n, int k) { return inv.C(n, k); }
int brute(int c[2][2]) {
  int n = c[0][0] + c[0][1] + c[1][0] + c[1][1];
  int res = 0;
  for (int mask = (0), _b = (1 << n); mask < _b; ++mask) {
    int last = 0;
    int d[2][2] = {{0, 0}, {0, 0}};
    for (int j = (0), _b = (n); j < _b; ++j) {
      int cur = 0;
      if (mask & (1 << j)) cur = 1;
      d[last][cur]++;
      last = cur;
    }
    bool check = true;
    for (int i = (0), _b = (2); i < _b; ++i)
      for (int j = (0), _b = (2); j < _b; ++j) check &= (c[i][j] == d[i][j]);
    res += check;
  }
  return res;
}
int calc_with_start(int start, const int c[2][2]) {
  if (start == 1) {
    int d[2][2];
    for (int u = (0), _b = (2); u < _b; ++u)
      for (int v = (0), _b = (2); v < _b; ++v) d[u][v] = c[u ^ 1][v ^ 1];
    return calc_with_start(0, d);
  }
  if (c[0][1] - c[1][0] > 1 || c[0][1] < c[1][0]) return 0;
  if (c[1][0] == 0) {
    if (c[0][1] > 0)
      return 1;
    else
      return c[1][1] == 0;
  }
  int comp0 = c[1][0];
  int comp1 = c[0][1] - 1;
  int res = 0;
  addmod(res, 1ll * C(c[0][0] + comp0, comp0) * C(c[1][1] + comp1, comp1));
  return res;
}
int calc(string& s, const int c[2][2]) {
  int n = c[0][0] + c[0][1] + c[1][1] + c[1][0] + 1;
  if (n > s.size())
    return 0;
  else if (n < s.size())
    return calc_with_start(1, c);
  int cur[2][2];
  for (int i = (0), _b = (2); i < _b; ++i)
    for (int j = (0), _b = (2); j < _b; ++j) cur[i][j] = c[i][j];
  int res = 0;
  int last = 1;
  for (int i = 1; i < n; ++i) {
    const int now = s[i] - '0';
    if (now == 1 && cur[last][0] > 0) {
      int d[2][2];
      bool check = true;
      for (int u = (0), _b = (2); u < _b; ++u)
        for (int v = (0), _b = (2); v < _b; ++v) d[u][v] = cur[u][v];
      --d[last][0];
      for (int u = (0), _b = (2); u < _b; ++u)
        for (int v = (0), _b = (2); v < _b; ++v) check &= (d[u][v] >= 0);
      if (check) addmod(res, calc_with_start(0, d));
    }
    --cur[last][now];
    last = now;
  }
  return res;
}
string u, v;
int c[2][2];
void solve() {
  cin >> u >> v;
  for (int i = (0), _b = (2); i < _b; ++i)
    for (int j = (0), _b = (2); j < _b; ++j) cin >> c[i][j];
  int res = calc(v, c) - calc(u, c);
  for (int i = 1; i < v.size(); ++i) {
    int last = v[i - 1] - '0';
    int cur = v[i] - '0';
    c[last][cur]--;
  }
  bool check = true;
  for (int i = (0), _b = (2); i < _b; ++i)
    for (int j = (0), _b = (2); j < _b; ++j) check &= (c[i][j] == 0);
  if (check) addmod(res, 1);
  addmod(res, 0);
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int Test = 1;
  if (multipleTest) cin >> Test;
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
