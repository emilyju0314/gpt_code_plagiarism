#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> compatibility(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> compatibility[i][j];
        }
    }

    vector<long long> dp(1 << N, 0);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << N); mask++) {
        int count = __builtin_popcount(mask);
        for (int j = 0; j < N; j++) {
            if (compatibility[count][j] && !(mask & (1 << j))) {
                dp[mask | (1 << j)] = (dp[mask | (1 << j)] + dp[mask]) % MOD;
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}