#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;


int main()
{
  int N, T[50];
  static int dp[2][2501][2501];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
  }

  fill_n(**dp, 2 * 2501 * 2501, INF);
  dp[1][0][0] = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 2500; j >= 0; j--) {
      for(int k = 2500; k >= 0; k--) {
        if(j >= T[i]) dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[(i + 1) & 1][j - T[i]][k]);
        if(k >= T[i]) dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[(i + 1) & 1][j][k - T[i]]);
        dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[(i + 1) & 1][j][k] + T[i]);
      }
    }
    fill_n(*dp[(i + 1) & 1], 2501 * 2501, INF);
  }
  int ret = INF;
  for(int i = 0; i <= 2500; i++) {
    for(int j = 0; j <= 2500; j++) {
      ret = min(ret, max(i, max(j, dp[(N + 1) & 1][i][j])));
    }
  }
  cout << ret << endl;
}