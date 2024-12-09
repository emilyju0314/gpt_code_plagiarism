#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++) {
        vector<int> prefix(K+2, 0);
        prefix[0] = dp[i][0];
        for(int j = 1; j <= K+1; j++) {
            prefix[j] = (prefix[j-1] + dp[i][j-1]) % MOD;
        }

        for(int j = 0; j <= K; j++) {
            dp[i+1][j] = (prefix[j+1] - prefix[max(0, j-a[i])] + MOD) % MOD;
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}