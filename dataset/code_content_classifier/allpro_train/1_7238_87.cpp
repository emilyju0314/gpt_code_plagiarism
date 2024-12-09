#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
vector<vector<vector<int> > > dp[maxn];
int sum[3][maxn], sumb[maxn];
bool a[3][maxn], both[maxn];
int n, p, k;
void input_and_pre() {
  cin >> n >> p >> k;
  p = min(p, 2 * ((n / k) + 1));
  for (int i = 0; i < maxn; i++) {
    dp[i].resize(p + 1);
    for (int j = 0; j < (p + 1); j++) {
      dp[i][j].resize(k + 1);
      for (int kk = 0; kk < (k + 1); kk++) {
        dp[i][j][kk].resize(2);
      }
    }
  }
  int r;
  cin >> r;
  for (int i = 0; i < r; i++) {
    int x;
    cin >> x;
    a[0][x] = 1;
    both[x] = 1;
  }
  int s;
  cin >> s;
  for (int i = 0; i < s; i++) {
    int x;
    cin >> x;
    a[1][x] = 1;
    both[x] = 1;
  }
  for (int i = 1; i <= maxn - 1; i++) {
    sumb[i] = sumb[i - 1] + both[i];
    sum[0][i] = sum[0][i - 1] + a[0][i];
    sum[1][i] = sum[1][i - 1] + a[1][i];
  }
}
int main() {
  input_and_pre();
  for (int i = n; i >= 1; i--) {
    dp[i][0][0][0] = 0;
    dp[i][0][0][1] = 0;
    for (int j = 1; j <= k - 1; j++) {
      for (int m = 0; m <= 1; m++) {
        dp[i][0][j][m] = sum[m][i + j - 1] - sum[m][i - 1];
      }
    }
    for (int j = 1; j <= p; j++) {
      dp[i][j][0][0] =
          max(dp[i + 1][j][0][0], max(a[0][i] + dp[i + 1][j - 1][k - 1][0],
                                      a[1][i] + dp[i + 1][j - 1][k - 1][1]));
      dp[i][j][0][1] = dp[i][j][0][0];
      for (int kk = 1; kk <= k - 1; kk++) {
        for (int m = 0; m <= 1; m++) {
          if (a[m][i] == 1)
            dp[i][j][kk][m] = dp[i + 1][j][max(int(0), kk - 1)][m] + 1;
          else {
            int A, B, C;
            A = dp[i + 1][j][max(int(0), kk - 1)][m];
            B = a[m][i] + dp[i + 1][j - 1][k - 1][m];
            C = (sumb[i + kk - 1] - sumb[i - 1]) +
                dp[i + kk][j - 1][k - kk][!m];
            dp[i][j][kk][m] = max(A, max(B, C));
          }
        }
      }
    }
  }
  cout << dp[1][p][0][0];
}
