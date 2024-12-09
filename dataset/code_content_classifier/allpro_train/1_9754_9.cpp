#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  int k, m;
  cin >> s >> k >> m;
  int n = s.size();
  if (n == 1) {
    cout << "0";
    return 0;
  }
  vector<vector<int> > c(26, vector<int>(26, 0));
  for (int i = 0; i < m; ++i) {
    char a, b;
    int koszt;
    cin >> a >> b >> koszt;
    c[a - 'a'][b - 'a'] = koszt;
  }
  int dp[100][101][26];
  for (int i = 0; i < 100; ++i)
    for (int j = 0; j < 101; ++j)
      for (int k = 0; k < 26; ++k) dp[i][j][k] = -INF;
  for (int i = 0; i < 26; ++i) dp[0][(int)(s[0] - 'a' != i)][i] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i + 1; ++j) {
      for (int l = 0; l < 26; ++l) {
        for (int o = 0; o < 26; ++o) {
          int rozne = (s[i] - 'a' != l);
          if (rozne && j == 0) continue;
          if (dp[i - 1][j - rozne][o] != -INF)
            dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - rozne][o] + c[o][l]);
        }
      }
    }
  }
  int odp = -INF;
  for (int i = 0; i <= k; ++i)
    for (int j = 0; j < 26; ++j) odp = max(odp, dp[n - 1][i][j]);
  cout << odp;
  return 0;
}
