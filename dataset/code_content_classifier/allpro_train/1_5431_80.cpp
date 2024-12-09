#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

ll power(ll x,ll n){
    if(n==0) return 1;
    ll res=power(x*x%mod,n/2);
    if(n&1) res=res*x%mod;
    return res;
}

int main(){
  int r1,c1,r2,c2;
  cin>>r1>>c1>>r2>>c2;
  ll a[r2+c2+2+1];
  a[0]=1;
  rep(i,1,r2+c2+2+1) a[i]=a[i-1]*i%mod;
  ll b[r2+c2+2+1];
  b[0]=1;
  rep(i,1,r2+c2+2+1) b[i]=power(a[i],1e9+5);
  ll x=a[r2+c2+2]*b[r2+1]%mod*b[c2+1]%mod;
  ll y=a[r2+c1+1]*b[r2+1]%mod*b[c1]%mod;
  ll z=a[r1+c2+1]*b[r1]%mod*b[c2+1]%mod;
  ll w=a[r1+c1]*b[r1]%mod*b[c1]%mod;
  ll ans=x-y-z+w;
  while(ans<0){
    ans+=mod;
  }
  cout<<ans<<endl;
}
