#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

const int inf = ( 1 << 28);

int dp[20001][256];
int solve(int n,int m,int *cbook,int *in){
  rep(i,n+1)rep(j,256)dp[i][j]=inf;
  dp[0][128]=0;

  rep(i,n){
    rep(j,256){
      if (dp[i][j] == inf)continue;
      rep(k,m){
	int next=j+cbook[k];
	if (next<0)next=0;
	else if (next>255)next=255;
	dp[i+1][next]=min(dp[i+1][next],dp[i][j]+(next-in[i])*(next-in[i]));
      }
    }
  }
  
  int ans = inf;
  rep(i,256)ans=min(ans,dp[n][i]);
  return ans;
}


int main(){
  int n,m;
  int in[20000],cbook[200];
  while(cin>>n>>m && n){
    rep(i,m)cin>>cbook[i];
    rep(i,n)cin>>in[i];
    cout << solve(n,m,cbook,in) << endl;
  }
}