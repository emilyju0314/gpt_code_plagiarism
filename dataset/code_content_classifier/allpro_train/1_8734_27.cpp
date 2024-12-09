#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
#define F first
#define S second
const ll MOD=1000000007;
const ll E=1e18;

const ll MX=1100;
ll dp[MX][MX]={};


int main(){
  ll n;
  while(cin>>n){
    if(n==0){return 0;}
    vector<pair<pll,ll>> A(n);
    for(auto &I:A){cin>>I.F.F>>I.F.S>>I.S;}
    sort(A.begin(),A.end(),[](pair<pll,ll> a,pair<pll,ll> b){return a.F.S==b.F.S?a.F.F<b.F.F:a.F.S<b.F.S;});
    //for(auto &I:A){cout<<I.F.F<<I.F.S<<I.S<<endl;}
    for(int i=0;i<=n;i++){
      for(int t=0;t<=n;t++){
	dp[i][t]=0;
      }
    }
  
    for(int i=0;i<=n;i++){
      for(int t=0;t<=i;t++){
        if(i!=0){dp[i][t]=max(dp[i][t],dp[i-1][t]);}
	if(t!=0){dp[i][t]=max(dp[i][t],dp[i][t-1]);}
	if(i!=0 && t!=0){dp[i][t]=max(dp[i][t],dp[i-1][t-1]);}
	for(int j=i;j<n;j++){
	  auto I=A[j];
	  if(i==0 || I.F.F>A[i-1].F.S){dp[j+1][t]=max(dp[j+1][t],dp[i][t]+I.S);}
	  if(t==0 || I.F.F>A[t-1].F.S){dp[j+1][i]=max(dp[j+1][i],dp[i][t]+I.S);}
	}
	//	cout<<dp[i][t]<<" ";
      }
      //cout<<endl;
    }
    cout<<dp[n][n]<<endl;
  }

  return 0;
}

