#include <bits/stdc++.h>
using namespace std;
double dp[2001][2000];
int main() {
  int n,m,i,j,k;
  while(cin>>n>>m&&n){
    string s;
    cin>>s;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(i=0;i<m;i++)for(j=0;j<n;j++)for(k=1;k<=6;k++)dp[i+1][(j+k)%n]+=dp[i][j]/6;
    double ans=0;
    for(j=0;j<n;j++){
      double sum=0;
      for(i=0;i<n;i++)sum+=dp[m][i]*(s[(j+i)%n]=='R');
      ans=max(ans,sum);
    }
    printf("%.10f\n",ans);
  }
  return 0;
}
