#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int dp[N][N][N][N];
int n;
char g[N][N];
const int INF = 1e9;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> (g[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (g[i][j] == '#') dp[i][j][i][j] = 1;
    }
  }
  for (int lenx = 1; lenx <= n; lenx++)
    for (int leny = 1; leny <= n; leny++) {
      if (lenx == 1 && leny == 1) continue;
      for (int i = 1; i + lenx - 1 <= n; i++)
        for (int j = 1; j + leny - 1 <= n; j++) {
          int ri = i + lenx - 1;
          int rj = j + leny - 1;
          dp[i][j][ri][rj] = INF;
          for (int k = i; k + 1 <= ri; k++)
            dp[i][j][ri][rj] =
                min(dp[i][j][ri][rj], dp[i][j][k][rj] + dp[k + 1][j][ri][rj]);
          for (int k = j; k + 1 <= rj; k++)
            dp[i][j][ri][rj] =
                min(dp[i][j][ri][rj], dp[i][j][ri][k] + dp[i][k + 1][ri][rj]);
          dp[i][j][ri][rj] = min(dp[i][j][ri][rj], max(ri - i + 1, rj - j + 1));
        }
    }
  cout << dp[1][1][n][n] << endl;
  return 0;
}
