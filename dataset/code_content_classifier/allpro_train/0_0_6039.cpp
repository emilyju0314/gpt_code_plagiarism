#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    
    vector<vector<long long>> dp(N, vector<long long>(K + 1));
    vector<long long> count(K + 1);
    long long ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = (j == A[i % M]) ? (count[j - 1] + 1) % MOD : count[j] % MOD;
            count[j] = (count[j] + dp[i][j]) % MOD;
        }
        ans = (ans + dp[i][K]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}