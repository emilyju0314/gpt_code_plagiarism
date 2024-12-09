#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

vec ans(2e5+10),dp(2e5+10),a(2e5+10);
ll n;
vector<set<ll>> G(2e5+10);

void dfs(ll f, ll ff,ll R) {
  ll l=0,r=R;
  while(r-l>1) {
    ll m=(r+l)/2;
    if(dp[m]<a[f]) l=m;
    else r=m;
  }
  ll pre=dp[r];
  dp[r]=a[f];
  if(r==R) ans[f]=R++;
  else ans[f]=R-1;
  for(ll t:G[f]) if(t!=ff) dfs(t,f,R);
  dp[r]=pre;
}

int main() {
  cin >> n;
  for(ll i=0;i<n;i++) cin >> a[i];
  for(ll i=0;i<n-1;i++) {
    ll u,v;
    cin >> u >> v;
    u--,v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  for(ll i=0;i<=n;i++) dp[i]=inf;
  dfs(0,-1,1);
  for(ll i=0;i<n;i++) cout << ans[i] << endl;
}