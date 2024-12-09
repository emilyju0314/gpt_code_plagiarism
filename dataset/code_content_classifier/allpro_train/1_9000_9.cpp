#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll n,a[10000];

  cin>>n;
  for(ll i=0;i<n;i++)cin>>a[i];

  sort(a,a+n);
  ll ans=1;
  for(ll i=0;i<n;i++)
    if(ans>=a[i])ans+=a[i];
    else break;
  cout<<ans<<endl;
  return 0;
}