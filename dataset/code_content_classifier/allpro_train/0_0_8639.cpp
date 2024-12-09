#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> dp(N + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] += (dp[j] * dp[i - j - 1]) % MOD;
            dp[i] %= MOD;
        }
    }

    long long result = 0;
    for (int i = 1; i <= N; i++) {
        result += (dp[i] * (i + 1)) % MOD;
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}