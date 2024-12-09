#include<bits/stdc++.h>
using namespace std;
#define INF (1<<29)
int N;
int V[111];
int F[111][111];
int dp[111][111];
int solve(int now,int nex){
  if( dp[now][nex] != -1 ) return dp[now][nex];
  if( now == N && nex == N ) return dp[now][nex]=0;
  if( nex > N ) return dp[now][nex] = INF;
  int ret = solve(now,nex+1);
  if( F[now][nex] ){
    ret = min(ret,solve(nex+1,nex+1)+1);
  }
  return dp[now][nex] = ret;
}
int main(){
  //  while(   cin >> N ){
  cin >> N;
  memset(F,0,sizeof(F));
  for(int i=0;i<N;i++){
    cin >> V[i];
    F[i][i]=V[i];
  }
  for(int k=1;k<N;k++){
    for(int i=0;i<N;i++){
      int a = i, b = i+k;
      if( b>=N ) break;
      for(int j=a;j<b;j++){
	if( F[a][j] ){
	  if(F[a][j] == F[j+1][b]){
	    F[a][b] = F[a][j]+F[j+1][b];
	    F[b][a] = F[a][b];
	    break;
	  }
	}
      }
    }
  }
  /*  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      printf("%d %d -> %d\n",i,j,F[i][j]);
  */  memset(dp,-1,sizeof(dp));
  cout << solve(0,0) << endl;
}