#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d,t[200],a[200],b[200],c[200];
  cin>>d>>n;
  for(int i=0;i<d;i++)cin>>t[i];
  for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
  int dp[201][101];
  for(int i=0;i<201;i++)
    for(int j=0;j<101;j++)
      dp[i][j]=-1;
  for(int i=0;i<n;i++)
    if(a[i]<=t[0]&&t[0]<=b[i])dp[0][c[i]]=0;
      
  
  for(int i=0;i<d-1;i++){
    for(int j=0;j<101;j++){
      if(dp[i][j]==-1)continue;
      for(int k=0;k<n;k++)
	if(a[k]<=t[i+1]&&t[i+1]<=b[k]){
	  dp[i+1][c[k]]=max(dp[i+1][c[k]],dp[i][j]+abs(j-c[k]));
	  // cout<<i<<" "<<j<<endl;
	}
    }
  }
  int ans=0;
  for(int i=0;i<101;i++)ans=max(ans,dp[d-1][i]);
  cout<<ans<<endl;
  return 0;
}

