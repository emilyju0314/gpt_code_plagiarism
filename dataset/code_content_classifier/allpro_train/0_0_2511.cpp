#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> difficulties(N);
    for (int i = 0; i < N; i++) {
        cin >> difficulties[i];
    }

    sort(difficulties.begin(), difficulties.end());

    vector<long long> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            if (i - j >= 0 && difficulties[i-1] - difficulties[i-j-1] <= T) {
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}