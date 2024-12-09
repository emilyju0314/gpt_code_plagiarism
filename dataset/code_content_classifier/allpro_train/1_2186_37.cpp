#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T &a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T &a, Args &...args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007ll;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
template <class T>
void outv(T &a) {
  for (auto &x : a) cout << x << ' ';
}
static mt19937 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
auto __fast_io__ = (ios_base::sync_with_stdio(false), cin.tie(nullptr));
int32_t main() {
  string s, t;
  __read(s, t);
  int n = s.length();
  int m = t.length();
  vector<vector<short>> dp(n + 1, vector<short>(m + 1, SHRT_MAX));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int b = isalnum(s[i]) ? 1 : -1;
    int nx = i + (b == 1 ? 1 : 0);
    while (nx < n && b > 0) {
      b += isalpha(s[nx]) ? 1 : -1;
      nx++;
    }
    if (b > 0) {
      nx = i;
    }
    for (int j = 0; j <= m; ++j) {
      if (dp[i][j] == SHRT_MAX) {
        continue;
      }
      dp[i + 1][j] = min(dp[i + 1][j], static_cast<short>(dp[i][j] + 1));
      dp[nx][j] = min(dp[nx][j], dp[i][j]);
      if (j < m && s[i] == t[j]) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
      }
      if (s[i] == '.' && j > 0) {
        dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
      }
    }
  }
  cout << dp[n][m];
  return 0;
}
