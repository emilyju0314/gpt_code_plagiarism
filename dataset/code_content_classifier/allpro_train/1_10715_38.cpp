#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    vector<ll>l(n);
    rep(0,i,n)cin>>l[i];
    sort(l.begin(),l.end());
    ll ans=0;
    rep(0,i,n){
        rep(i+1,j,n)ans+=lower_bound(l.begin(),l.end(),l[i]+l[j])-(l.begin()+j+1);
    }
    cout<<ans;
}
