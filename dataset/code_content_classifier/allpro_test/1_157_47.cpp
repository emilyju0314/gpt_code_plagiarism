#include <bits/stdc++.h>
using namespace std;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const int MOD2 = 998244353;
using namespace std;
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void usaco(const string &USACO_TAG) {
  setIn(USACO_TAG + ".in");
  setOut(USACO_TAG + ".out");
}
const bool MULTIPLE_TEST_CASE = false;
const int MAXN = 5e3 + 5;
long long dp[MAXN][MAXN];
void pre() {
  for (int i = 1; i < MAXN; i++) {
    dp[i][0] = 1;
    dp[i][i] = 1;
  }
  for (int i = 1; i < MAXN; i++) {
    for (int j = 1; j <= i; j++) {
      if (i == j) continue;
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
      if (dp[i][j] >= MOD2) dp[i][j] %= MOD2;
    }
  }
}
long long nck(int n, int k) {
  if (n == k || k == 0) {
    return 1;
  }
  return dp[n][k];
}
void run_case() {
  pre();
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cum[i] = cum[i - 1] + (s[i - 1] == '1');
  }
  bool f = 0;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (cum[j] - cum[i - 1] == k) f = 1;
    }
  }
  if (!f) {
    cout << 1;
    exit(0);
    ;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (cum[j] - cum[i - 1] <= k) {
        int ones = cum[j] - cum[i - 1];
        if (s[i - 1] == '0') ones--;
        if (s[j - 1] == '0') ones--;
        int nn = j - i - 1;
        if (nn < 0 || nn < ones || ones < 0) continue;
        ans = ans + nck(nn, ones);
        if (ans >= MOD2) ans %= MOD2;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);
  ;
  int t;
  if (MULTIPLE_TEST_CASE)
    cin >> t;
  else
    t = 1;
  while (t--) run_case();
}
