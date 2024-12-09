#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 401;
const int MAX_T = 401;

vector<vector<long long>> dp(MAX_N, vector<long long>(MAX_N, 0));

void precompute() {
    dp[0][0] = 1;
    for (int n = 1; n < MAX_N; n++) {
        for (int i = n; i >= 1; i--) {
            for (int j = i - 1; j >= 0; j--) {
                dp[n][i] = (dp[n][i] + dp[n-i][j]) % MOD;
            }
        }
    }
}

long long countIntervalFreePermutations(int n) {
    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + dp[n][i]) % MOD;
    }
    return result;
}

int main() {
    int t;
    long long p;
    cin >> t >> p;

    precompute();

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        long long result = countIntervalFreePermutations(n);
        cout << result << endl;
    }

    return 0;
}