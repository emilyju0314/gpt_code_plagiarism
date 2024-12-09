#include <bits/stdc++.h>
using namespace std;

int n,L,dp[1<<18][19],p[1<<18];
string s;
inline int F(int a,int b){
  if(a>b) swap(a,b);
  return (s[b-a-1]=='0'?a:b);
}
int g(int S,int W){
  if(!W)return p[S];
  if(~dp[S][W])return dp[S][W];
  return dp[S][W]=F(g(S,W-1),g((S+(1<<(W-1)))%L,W-1));
}

int main(){
  memset(dp,-1,sizeof(dp));
  cin>>n>>s;
  for(int i=0;i<(L=1<<n);i++)cin>>p[i];
  for(int i=0;i<L;i++)cout<<g(i,n)<<endl;
}

