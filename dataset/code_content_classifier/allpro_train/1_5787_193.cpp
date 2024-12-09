#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, T, S;
  int A[3000], B[3000];

  cin >> N >> T >> S;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  int dp[3001];
  fill_n( dp, 3001, 0);
  for(int i = 0; i < N; i++) {
    for(int j = 1; j <= T; j++) {
      dp[j] = max(dp[j], dp[j - 1]);
    }
    for(int j = T - B[i]; j >= 0; j--) {
      if(dp[j] == -1) continue;
      if(j < S && S < j + B[i]) continue;
      dp[j + B[i]] = max(dp[j + B[i]], dp[j] + A[i]);
    }
  }
  cout << dp[T] << endl;

  return(0);
}