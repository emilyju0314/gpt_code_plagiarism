#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

  int n,k; cin >> n >> k;

  static int dp[101010][21]; //iが最大でj個の集合の数
  for(int i = 1; i <= n; i++) dp[i][1] = 1;
  for(int i = 2; i <= n; i++){
    for(int j = 1; j*j <= i; j++){
      if(i%j == 0){
        for(int k = 1; k < 20; k++){
          dp[i][k+1] += dp[j][k];
          if(j*j == i || j == 1) continue;
          dp[i][k+1] += dp[i/j][k];
        }
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans += dp[i][k];
  }
  cout << ans << endl;

  return 0;
}

