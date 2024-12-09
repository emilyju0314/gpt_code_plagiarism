#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
const ll inf=1e18;
int main(void){
    ll a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a+2),t(b+2);
    rep(0,i,a)cin>>s[i+1];
    rep(0,i,b)cin>>t[i+1];
    s[0]=-inf,s[a+1]=inf;
    t[0]=-inf,t[b+1]=inf;
    while(q--){
        ll x;
        cin>>x;
        ll ns=upper_bound(s.begin(),s.end(),x)-s.begin();
        ll nt=upper_bound(t.begin(),t.end(),x)-t.begin();
        ll ans=inf;
        for(ll S:{s[ns-1],s[ns]}){
            for(ll T:{t[nt-1],t[nt]}){
                ans=min({ans,abs(x-S)+abs(S-T),abs(x-T)+abs(T-S)});
            }
        }
        cout<<ans<<endl;
    }
    
}
