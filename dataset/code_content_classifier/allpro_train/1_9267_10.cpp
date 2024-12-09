#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n, W;
    cin >> n >> W;
    vector<ll> v(n);
    vector<ll> w(n);
    vector<ll> m(n);
    for(i = 0;i < n;++i){
        cin >> v.at(i) >> w.at(i) >> m.at(i);
    }
    ll INF = 1ll << 60;
    ll V_MAX = 50*n;
    vector<vector<ll>> dp(n+1,vector<ll>(V_MAX+1, INF));
    dp.at(0).at(0) = 0;
    for(i = 1;i <= n;++i){
        for(j = V_MAX;j >= 0;--j){
            if(j < v.at(i-1)) dp.at(i).at(j) = dp.at(i-1).at(j);
            else dp.at(i).at(j) = min(dp.at(i-1).at(j), dp.at(i-1).at(j - v.at(i-1)) + w.at(i-1));
        }
        --m.at(i-1);
        if(m.at(i-1)){
            for(j = V_MAX;j >= 0;--j){
                if(j >= v.at(i-1)) dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(j - v.at(i-1)) + w.at(i-1));
            }
            --m.at(i-1);
        }
    }
    vector<ll> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](ll i, ll j){
        return v.at(i)*w.at(j) > v.at(j)*w.at(i);
    });
    
    ll ans = 0;
    for(i = V_MAX;i >= 0;--i){
        if(dp.at(n).at(i) > W) continue;
        ll val = i;
        ll remain = W - dp.at(n).at(i);
        rep(j,n){
            ll ind = ord.at(j);
            ll greed = min(m.at(ind), remain/w.at(ind));
            remain -= greed*w.at(ind);
            val += greed*v.at(ind);
        }
        ans = max(ans, val);
    }
    cout << ans << endl;
    
    return 0;
}
