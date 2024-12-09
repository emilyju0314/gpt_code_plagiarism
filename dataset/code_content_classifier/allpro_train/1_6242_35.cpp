#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 1e9 + 7;
const long long mod2 = 998244353;
const long long mod3 = 999999391;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> mat(n, vector<char>(m));
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) {
      cin >> mat[i][j];
    }
  }
  vector<vector<long long>> dp1(n, vector<long long>(m)),
      dp1b(n, vector<long long>(m));
  vector<vector<long long>> dp2(n, vector<long long>(m)),
      dp2b(n, vector<long long>(m));
  vector<vector<long long>> dp3(n, vector<long long>(m)),
      dp3b(n, vector<long long>(m));
  dp1[0][0] = 1;
  dp2[0][0] = 1;
  dp3[0][0] = 1;
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) {
      if (mat[i][j] == '#') continue;
      if (((i - 1) < (n) and (j) < (m) and (i - 1) >= 0 and (j) >= 0)) {
        dp1[i][j] += dp1[i - 1][j];
        dp2[i][j] += dp2[i - 1][j];
        dp3[i][j] += dp3[i - 1][j];
      }
      if (((i) < (n) and (j - 1) < (m) and (i) >= 0 and (j - 1) >= 0)) {
        dp1[i][j] += dp1[i][j - 1];
        dp2[i][j] += dp2[i][j - 1];
        dp3[i][j] += dp3[i][j - 1];
      }
      dp1[i][j] %= mod1;
      dp2[i][j] %= mod2;
      dp3[i][j] %= mod3;
    }
  }
  dp1b[n - 1][m - 1] = 1;
  dp2b[n - 1][m - 1] = 1;
  dp3b[n - 1][m - 1] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (mat[i][j] == '#') continue;
      if (((i + 1) < (n) and (j) < (m) and (i + 1) >= 0 and (j) >= 0)) {
        dp1b[i][j] += dp1b[i + 1][j];
        dp2b[i][j] += dp2b[i + 1][j];
        dp3b[i][j] += dp3b[i + 1][j];
      }
      if (((i) < (n) and (j + 1) < (m) and (i) >= 0 and (j + 1) >= 0)) {
        dp1b[i][j] += dp1b[i][j + 1];
        dp2b[i][j] += dp2b[i][j + 1];
        dp3b[i][j] += dp3b[i][j + 1];
      }
      dp1b[i][j] %= mod1;
      dp2b[i][j] %= mod2;
      dp3b[i][j] %= mod3;
    }
  }
  if (dp1[n - 1][m - 1] == 0 and dp2[n - 1][m - 1] == 0 and
      dp3[n - 1][m - 1] == 0) {
    return cout << 0 << endl, 0;
  }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      if (i == j and i == 0) continue;
      if (i == n - 1 and j == m - 1) continue;
      if ((dp1[i][j] * dp1b[i][j]) % mod1 == dp1[n - 1][m - 1]) {
        if ((dp2[i][j] * dp2b[i][j]) % mod2 == dp2[n - 1][m - 1]) {
          if ((dp3[i][j] * dp3b[i][j]) % mod3 == dp3[n - 1][m - 1]) {
            return cout << 1 << endl, 0;
          }
        }
      }
    }
  cout << 2 << endl;
}
