#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

static ll p = 1000000000+7;

int main(){
  int n; cin >> n;
  ll dp[n][64];
  fill(dp[0],dp[1],1);
  dp[0][11] = 0; //AGC
  dp[0][14] = 0; //ACG
  dp[0][35] = 0; //GAC

  REP(i,n-3){
    REP(j,64){
      dp[i+1][j] = (((dp[i][j/4]+dp[i][j/4+16])%p+dp[i][j/4+32])%p+dp[i][j/4+48])%p;
    }

    dp[i+1][11] = 0;
    dp[i+1][14] = 0;
    dp[i+1][35] = 0;

    dp[i+1][27] += p - dp[i][6]; //ATGC
    dp[i+1][39] += p - dp[i][9]; //AGTC
    dp[i+1][43] += p - dp[i][10]; //AGGC

    REP(j,64){
      dp[i+1][j] %= p;
    }
  }

  ll ans = 0;
  REP(j,64){
    ans += dp[n-3][j];
    ans %= p;
  }
  cout << ans << endl;
  return 0;
}
