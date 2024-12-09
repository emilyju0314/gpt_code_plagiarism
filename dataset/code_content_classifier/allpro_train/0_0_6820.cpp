#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - k]) % MOD;
            }
        }
    }

    vector<long long> cnt(K + 1, 0);
    for (int i = 0; i < N; i++) {
        long long num = A[i];
        for (int j = 0; j <= K; j++) {
            cnt[j] = (cnt[j] + dp[i][j]) % MOD;
            long long val = 1;
            while (val * 2 <= num) {
                val *= 2;
                for (int k = 0; k + val <= j; k++) {
                    dp[i + 1][j + val] = (dp[i + 1][j + val] + dp[i][j - k]) % MOD;
                }
            }
        }
    }
  
    long long ans = 0;
    for (int j = 0; j <= K; j++) {
        ans = (ans + dp[N][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}