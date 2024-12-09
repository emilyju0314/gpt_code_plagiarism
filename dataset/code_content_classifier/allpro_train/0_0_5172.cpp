#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<long long>> dp(N+1, vector<long long>(N*N+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N*N; j++) {
            for (int k = 0; k < i; k++) {
                if (j - k*k < 0) break;
                dp[i][j] = (dp[i][j] + dp[i-1][j-k*k]) % MOD;
            }
        }
    }

    long long result = 0;
    for (int j = N*N; j <= N*N*2; j++) {
        result = (result + dp[N][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}