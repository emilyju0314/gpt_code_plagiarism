#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int T[2005]={0};
int main(){
  ll n,k;cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>T[i];
  }
  ll a=0,b=0,ans = 0;
  for(int i=1;i<=n-1;i++){
    for(int j=i+1;j<=n;j++){
      if(T[i]>T[j])a++;
      else if(T[i]<T[j])b++;
    }
  }
  ans+=a*((((k+1)*k)/2)%MOD)%MOD;
  ans+=b*((((k-1)*k)/2)%MOD)%MOD;
  cout<<ans%MOD<<endl;
}