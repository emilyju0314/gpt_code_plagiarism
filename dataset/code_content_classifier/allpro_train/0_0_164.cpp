#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K, C, T;
    cin >> N >> K >> C >> T;

    vector<vector<long long>> dp(2, vector<long long>(N + 1, 0));
    dp[0][1] = 1;

    for (int k = 0; k < K; k++) {
        int a, b, t;
        cin >> a >> b >> t;

        vector<long long> new_dp(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            for (int j = a; j < a + b; j++) {
                int new_i = min(N, j - 1 + i - a);
                new_dp[new_i] = (new_dp[new_i] + dp[k % 2][i]) % MOD;
            }
        }

        for (int i = 1; i <= N; i++) {
            dp[(k + 1) % 2][i] = new_dp[i];
        }
    }

    long long result = 0;
    for (int i = 0; i <= T; i++) {
        result = (result + dp[K % 2][(C + i) % N]) % MOD;
    }

    cout << result << endl;

    return 0;
}