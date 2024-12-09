#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll n,k;
  cin>>n>>k;
  ll a[n];
  for(ll i=0;i<n;i++)
    cin>>a[i];
  ll l=0,r=1000000005;
  while(r>l+1)
  {
    ll m=l+r;
    m/=2;
    ll op=0;
    for(ll i=0;i<n;i++)
      op+=(a[i]-1)/m;
    if(op<=k)
      r=m;
    else
      l=m;
  }
  cout<<r;
}