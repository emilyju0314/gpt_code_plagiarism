#include<bits/stdc++.h>
using namespace std;

int N,K;
int dp[2][1001][1001];
int dm[2][1001][1001];
int a[1000];

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++)scanf("%d",&a[i]);
  sort(a,a+N);
  fill( (int*)dp[0], (int*)dp[1], 1e9);
  int ans=1e9;
  for(int T=1;T<=K;T++){
    int t=T%2;
    int u=1-t;
    for(int i=0;i<N;i++){
      dp[0][i][i+1]=0;
      dp[1][i][i+1]=0;
    }
    for(int w=2;w<=N;w++){
      for(int i=0;i+w<=N;i++){
        int j=i+w;
        int si=i+1;
        int ti=j-1;
        if(w>2){
          si=dm[t][i][j-1];
          ti=dm[t][i+1][j];
        }
        dp[t][i][j]=1e9;
        for(int k=si;k<=ti;k++){
          if(dp[t][i][j] > dp[u][i][k]+dp[u][k][j]+a[j-1]-a[k-1]){
            dp[t][i][j]=dp[u][i][k]+dp[u][k][j]+a[j-1]-a[k-1];
            dm[t][i][j]=k;
          }
        }
      }
    }
  }
  printf("%d\n",dp[K%2][0][N]);
  return 0;
}