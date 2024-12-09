#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    vector<long long> dp(N+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i] = (3 * dp[i-1]) % MOD;
    }

    cout << dp[N] << endl;

    return 0;
}