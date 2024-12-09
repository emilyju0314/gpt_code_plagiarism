#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;

ll add(ll a,ll b){
  return (a+b+mod+mod)%mod;
}

ll mul(ll a,ll b){
  return (a*b)%mod;
}

ll mpow(ll a,ll b){
  ll res=1;
  for(int i=0;i<b;i++)res=mul(res,a);
  return res;
}


ll d,s,t[301];
ll sum=0;


int dp[2][2][900001];

int main(){
  
  cin>>d;
  for(int i=0;i<d;i++){
    cin>>t[i];
    sum+=t[i];
  }

  cin>>s;
  dp[0][0][0]=1;

  ll ans=0;
  
  for(int i=0;i<=d;i++){
    int ai=i&1;
    int bi=1-ai;
    fill( (ll*) dp[bi], (ll*)dp[bi+1],0);
    for(int j=0;j<2;j++){
      for(int k=0;k<=s;k++){

        if(i==d){
          if(j==0)ans=add(ans, mul( dp[ai][j][k],mpow(s-k,d) ) );
          else ans=add(ans, -mul( dp[ai][j][k],mpow(s-k,d) ) );
        }
        
        dp[bi][j][k]+=dp[ai][j][k];
        dp[bi][j][k]%=mod;
        if(k+t[i]<=s){
          dp[bi][1-j][k+t[i]]+=dp[ai][j][k];
          dp[bi][1-j][k+t[i]]%=mod;
        }
        
      }
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}