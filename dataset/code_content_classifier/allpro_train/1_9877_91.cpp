#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n,m;
  cin >> n >> m;
  ll d[n+2],ans=1<<30;
  d[0]=0;
  d[n+1]=1<<30;
  for(int i=0,x; i<n; i++) {
    cin >> x;
    d[i+1]=x+d[i];
  }
  for(int i=0; i<n; i++) {
    ll x=lower_bound(d,d+n+1,d[i]+m)-d;
    if(x<=n) ans=min(ans,x-i);
  }
  if(ans==1<<30) ans=0;
  cout << ans << endl;
  return 0;
}
