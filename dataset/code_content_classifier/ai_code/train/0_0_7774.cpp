#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> dp(K+1, 0);
    dp[0] = 1;

    // Calculate the prefix sum of the dp array
    for(int i = 1; i <= K; i++) {
        dp[i] = (dp[i-1] * 2) % MOD;
    }

    // Calculate the answer
    for(int i = 1; i <= K; i++) {
        if(i-N >= 0)
            dp[i] = (dp[i] + dp[i-N]) % MOD;
    }

    cout << dp[K] << endl;

    return 0;
}