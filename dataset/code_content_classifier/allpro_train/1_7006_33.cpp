#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

int main()
{
  int N, D, P[50][50], V[50];
  int dp[50][50];
  int rev[50][50];

  cin >> N >> D;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < D; j++) {
      cin >> P[i][j];
    }
  }


  for(int i = 0; i < D; i++) {
    V[i] = INF;
    for(int j = 0; j < N; j++) V[i] = min(V[i], P[j][i]);
  }

  fill_n(*dp, 50 * 50, INF);
  for(int i = 0; i < N; i++) {
    if(V[D - 1] == P[i][D - 1]) {
      dp[D - 1][i] = 0;
      rev[D - 1][i] = -1;
    }
  }
  for(int i = D - 2; i >= 0; i--) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        if(V[i] == P[k][i]) {
          if(dp[i][k] > dp[i + 1][j] + (j != k)) {
            dp[i][k] = dp[i + 1][j] + (j != k);
            rev[i][k] = j;
          }
        }
      }
    }
  }
  int p = min_element(dp[0], dp[1]) - dp[0];
  cout << accumulate(V, V + D, 0) << " " << dp[0][p] << endl;
  vector< int > vs;
  for(int i = 0; i < D; i++) {
    cout << p + 1 << endl;
    p = rev[i][p];
  }
}