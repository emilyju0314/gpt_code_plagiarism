#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define IINF (INT_MAX)
#define MAX_U 102
#define MAX_S 102
#define MAX_C 10002
#define MAX_T 102
#define MAX_N 102
#define MAX_D 102

using namespace std;

int pre1[MAX_U][MAX_S],pre2[MAX_C],S,T,U,N,O,D,e[MAX_T],c[MAX_T],h[MAX_N],a[MAX_N],dp[MAX_D][MAX_S];

int main(){
  rep(i,MAX_U)rep(j,MAX_S)pre1[i][j] = -IINF;
  rep(i,MAX_D)rep(j,MAX_S)dp[i][j] = -IINF;
  rep(i,MAX_C)pre2[i] = -IINF;

  cin >> S >> T >> U >> N >> O >> D;
  pre1[0][0] = pre2[0] = dp[0][S] = 0;
  rep(i,T)cin >> e[i] >> c[i];
  rep(i,N)cin >> h[i] >> a[i];

  rep(i,T)for(int j=U-1;j>=0;j--)rep(k,S+1)if(pre1[j][k] != -IINF){
      if( k + e[i] > S ) continue;
      pre1[j+1][k+e[i]] = max(pre1[j+1][k+e[i]],pre1[j][k]+c[i]);
    }

  rep(i,N)rep(j,MAX_C)if(pre2[j]!=-IINF){
    if( j + a[i] >= MAX_C ) continue;
    pre2[j+a[i]] = max(pre2[j+a[i]],pre2[j]+h[i]);
  }
  REP(i,1,MAX_C)pre2[i] = max(pre2[i],pre2[i-1]);

  rep(i,D){
    rep(j,S+1){
      rep(k,j+1){
	if(dp[i][j]==-IINF)continue;
	if(pre1[U][k]==-IINF)continue;
	if(pre2[pre1[U][k]] == -IINF) continue;
	int new_j = min( j + O - k , S );
	dp[i+1][new_j] = max(dp[i+1][new_j],dp[i][j]+pre2[pre1[U][k]]);
      }      
    }
  }

  int answer = -1;
  rep(i,MAX_S)answer = max(dp[D][i],answer);
  cout << answer << endl;

  return 0;
}