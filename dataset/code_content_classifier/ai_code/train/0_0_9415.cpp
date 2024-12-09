#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;

int main() {
    int t, k;
    cin >> t >> k;
    
    vector<pair<ll, ll>> segments;
    
    for(int i=0; i<t; i++) {
        ll l, r;
        cin >> l >> r;
        segments.push_back({l, r});
    }
    
    ll dp[1005], dp1[1005];
    memset(dp, 0, sizeof(dp));
    memset(dp1, 0, sizeof(dp1));
    
    dp[0] = 1;
    for(int i=1; i<=1000; i++) {
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                dp1[i] += dp[i-j];
                dp1[i] %= MOD;
            }
        }
        dp[i] = (dp[i-1] + dp1[i]) % MOD;
    }
    
    for(auto seg : segments) {
        ll ans = (dp1[seg.second] - dp1[seg.first-1] + MOD) % MOD;
        cout << ans << endl;
    }
    
    return 0;
}