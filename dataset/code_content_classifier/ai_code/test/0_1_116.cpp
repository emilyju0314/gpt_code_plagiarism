#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 998244353

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<int, int> dp;
        dp[0] = 1;
        int mex = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] > mex) {
                dp[a[i]] += dp[mex];
                dp[a[i]] %= MOD;
            } else if(a[i] == mex) {
                mex++;
            }
        }

        int ans = 0;
        for(auto p : dp) {
            ans = (ans + p.second) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}