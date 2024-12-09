#include <bits/stdc++.h>
const int N = 204;
const long long mod = 1e9 + 7;
int n;
std::string s;
long long len[N + 1][2];
long long dp[N][N][N][2];
int calc(const std::string& t) {
  int tsz = t.size();
  for (int i = tsz; i > 0; --i) {
    if (s.substr(0, i) == t.substr(tsz - i, i)) return i;
  }
  return 0;
}
long long mod_sum(const long long a, const long long b) {
  return (a % mod + b % mod);
}
void add(long long& a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n >> s;
  const size_t ssz = s.size();
  if (s[0] == '(') {
    len[0][0] = 1;
  } else {
    len[0][1] = 1;
  }
  std::string pref = "";
  for (int i = 0; i < ssz; ++i) {
    pref += s[i];
    pref += '(';
    len[i + 1][0] = calc(pref);
    pref.pop_back();
    pref += ')';
    len[i + 1][1] = calc(pref);
    pref.pop_back();
  }
  dp[0][0][0][0] = 1;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int pos = 0; pos <= ssz; ++pos) {
        for (int f = 0; f < 2; ++f) {
          if (dp[i][j][pos][f] == 0) continue;
          if (j + 1 <= n)
            add(dp[i + 1][j + 1][len[pos][0]][f | (len[pos][0] == ssz)],
                dp[i][j][pos][f]);
          if (j > 0)
            add(dp[i + 1][j - 1][len[pos][1]][f | (len[pos][1] == ssz)],
                dp[i][j][pos][f]);
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= ssz; ++i) add(ans, dp[2 * n][0][i][1]);
  std::cout << ans;
  return 0;
}
