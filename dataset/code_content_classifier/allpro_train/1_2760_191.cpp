#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

  for(int n,t,l,b,m[200]={};cin>>n>>t>>l>>b&&n!=0;){
    memset(m,0,sizeof(m));
    double dp[200][200]={},r=0;
    dp[0][0]=1.0;
    for(int i=0,a;i<l;i++){
      cin>>a;
      m[a]=1;
    }
    for(int i=0,a;i<b;i++){
      cin>>a;
      m[a]=2;
    }
    for(int i=0;i<t;i++){
      for(int j=0;j<n;j++){
	for(int k=1;k<=6;k++){
	  int how=j+k;
	  if(how>n) how=n-(how-n);
	  if(m[how]==1) dp[i+2][how]+=dp[i][j]/6.0;
	  else if(m[how]==2) dp[i+1][0]+=dp[i][j]/6.0;
	  else dp[i+1][how]+=dp[i][j]/6.0;
	}
      }
    }
    /* for(int i=0;i<=t;i++){
       for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
       cout<<endl;
       }*/
    for(int i=1;i<=t;i++) r+=dp[i][n];
    cout<<fixed<<setprecision(12)<<r<<endl;  
  }
  return 0;
  
}