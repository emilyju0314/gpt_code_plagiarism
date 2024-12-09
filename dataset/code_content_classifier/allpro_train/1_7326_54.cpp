#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 7;
const int M = 100000 + 7;
const int inf = 1000000000 + 7;
const long long linf = 1ll * inf * (inf - 1);
const double pi = acos(-1);
const double eps = 1e-9;
const bool multipleTest = 0;
const int mod[2] = {(rand() % (inf - 1000) + 1000),
                    (rand() % (inf - 1000) + 1000)};
int lt[2][N];
struct Hash {
  string s;
  long long val[2][N];
  int n;
  void init(string& s_) {
    s = s_;
    n = s.size();
    val[0][0] = val[1][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2; ++j)
        val[j][i] = (1ll * val[j][i - 1] * mod[j] + s[i - 1]) % inf;
    }
  }
  long long get(int j, int u, int v) {
    long long res = val[j][v] - val[j][u - 1] * lt[j][v - u + 1];
    res %= inf;
    if (res < 0) res += inf;
    return res;
  }
  pair<int, int> get(int u, int v) {
    return make_pair(get(0, u, v), get(1, u, v));
  }
};
Hash a, b;
int n, m;
string s, t;
int k;
int dp[N][31];
int getLCP(int u, int v) {
  int lo = 1, hi = min(n - u, m - v), res = 0;
  while (lo <= hi) {
    int g = (lo + hi) >> 1;
    if (a.get(u + 1, u + g) == b.get(v + 1, v + g)) {
      res = g;
      lo = g + 1;
    } else
      hi = g - 1;
  }
  return res;
}
void solve() {
  cin >> n >> s >> m >> t >> k;
  lt[0][0] = lt[1][0] = 1;
  for (int i = 1; i < N; ++i) {
    lt[0][i] = (1ll * mod[0] * lt[0][i - 1]) % inf;
    lt[1][i] = (1ll * mod[1] * lt[1][i - 1]) % inf;
  }
  a.init(s);
  b.init(t);
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 0;
    for (int j = 0; j <= k; ++j) {
      if (j) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j < k) {
        int res = getLCP(i, dp[i][j]);
        if (res > 0)
          dp[i + res][j + 1] = max(dp[i + res][j + 1], dp[i][j] + res);
      }
    }
  }
  if (dp[n][k] == m)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
