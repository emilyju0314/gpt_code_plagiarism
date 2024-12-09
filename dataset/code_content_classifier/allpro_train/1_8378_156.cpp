#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
const LL mod=998244353;
int n,a[N],s;
LL dp[3333][3333],ans;
int main() {
  ios::sync_with_stdio(false);
  cin>>n>>s;
  for(int i=1;i<=n;i++)cin>>a[i];
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=a[i];j<=s;j++){
      dp[i][j]+=dp[i-1][j-a[i]];
      dp[i][j]%=mod;
    }
    for(int j=0;j<=s;j++){
      dp[i][j]+=dp[i-1][j]*2;
      dp[i][j]%=mod;
    }
  }
  cout<<dp[n][s]<<'\n';
  return 0;
}