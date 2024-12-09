#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string s;
    cin >> s;
    
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    
    for (char c : s) {
        vector<long long> next(N + 1, 0);
        if (c == 'X') {
            for (int i = 0; i < N; i++) {
                next[i + 1] = dp[i];
            }
        } else {
            for (int i = N - 1; i >= 0; i--) {
                next[i] = (next[i] + dp[i]) % MOD;
                next[i + 1] = (next[i + 1] + dp[i] * (N - i)) % MOD;
            }
        }
        dp = next;
    }
    
    long long p = 0, q = 0, r = 0;
    for (int i = 0; i <= N; i++) {
        p = (p + dp[i]) % MOD;
        q = (q + dp[i] * (N - i)) % MOD;
        r = (r + dp[i] * (N - i) * (N - i)) % MOD;
    }
    
    cout << p << " " << q << " " << r << endl;
    
    return 0;
}