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
        int current_mex = 0;
        dp[current_mex] = 1;

        for(int i = 0; i < n; i++) {
            if(a[i] > current_mex) {
                cout << 0 << endl;
                continue;
            }

            dp[a[i]] = (dp[a[i]] + dp[current_mex]) % MOD;
            current_mex = (a[i] + 1) % MOD;
        }

        int total_subsequences = 0;
        for(auto& it : dp) {
            total_subsequences = (total_subsequences + it.second) % MOD;
        }

        cout << total_subsequences << endl;
    }

    return 0;
}