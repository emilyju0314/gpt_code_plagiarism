#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5001][5001];
 
int main() {
  ll n,m,k,q,mod=1000000007;
  cin >> n >> m >> k >> q;
  dp[0][0]=1;
  for(int i=0; i<n; i++) {
    if(i/k%2==0) dp[1][i]=1;
  }
  ll x=n/k/2,N=k*2;
  for(int i=1; i<m; i++) {
    ll sum=0;
    for(int j=N-k; j<N; j++) sum+=dp[i][j];
    for(int j=0; j<n; j++) {
      sum-=dp[i][(j-k+N)%N];
      sum+=dp[i][j];
      dp[i+1][j]=sum*x;
      dp[i+1][j]%=mod;
    }
  }
  while(q--) {
    int a,b,c;
    cin >> a >> b >> c;
    cout << dp[b][(c-a+n)%n] << endl;
  }
  return 0;
}
