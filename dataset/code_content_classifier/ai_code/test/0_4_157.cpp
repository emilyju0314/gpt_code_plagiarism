#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        vector<long long> dp_next(n+1, 0);
        
        for (int j = 0; j <= n; j++) {
            if (j + 1 <= n) {
                dp_next[j+1] = (dp_next[j+1] + dp[j]) % MOD;
            }
            if (s[i] == '1') {
                dp_next[max(0, j-k)] = (dp_next[max(0, j-k)] + dp[j]) % MOD;
            }
        }
        
        dp = dp_next;
    }
    
    long long result = 0;
    for (int i = 0; i <= n; i++) {
        result = (result + dp[i]) % MOD;
    }
    
    cout << result << endl;

    return 0;
}