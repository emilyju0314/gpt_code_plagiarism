#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> b(n), prefix(n), dp(n);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            if(i == 0) {
                prefix[i] = b[i];
            } else {
                prefix[i] = (prefix[i-1] + b[i]) % MOD;
            }
        }

        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = ((prefix[i] >= 0) ? dp[i-1] : 0);
            for(int j = 0; j < i; j++) {
                if(prefix[i] - prefix[j] >= 0) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}