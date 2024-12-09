#include<bits/stdc++.h>
#define N 2005
using namespace std;

int m,n,dp[2][N][N],sz[2],ans;
string st[2];

int func(int id,int p,int k,char c){
  int r=0,idr=(id+1)%2;
  if(p+1<sz[id]&&st[id][p+1]!=c){
    if(!dp[id][p+1][k])dp[id][p+1][k]=func(id,p+1,k,st[id][p+1]);
    r=max(r,dp[id][p+1][k]+1);
  }
  if(k<sz[idr]&&st[idr][k]!=c){
    if(!dp[idr][k][p+1])dp[idr][k][p+1]=func(idr,k,p+1,st[idr][k]);
    r=max(r,dp[idr][k][p+1]+1);
  }
  if(r==0&&st[id][p]=='I')r=1;
  return r;
}

int main(){
  cin>>m>>n>>st[0]>>st[1];
  sz[0]=st[0].size();
  sz[1]=st[1].size();
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
      if(st[0][i]=='I')dp[0][i][j]=max(dp[0][i][j],func(0,i,j,'I'));
      if(st[1][j]=='I')dp[1][j][i]=max(dp[1][j][i],func(1,j,i,'I'));
    }
  for(int i=0;i<2;i++)
    for(int j=0;j<N;j++)
      for(int k=0;k<N;k++)
	if(st[i][j]=='I')ans=max(ans,dp[i][j][k]);
  cout<<ans<<endl;
  return 0;
}