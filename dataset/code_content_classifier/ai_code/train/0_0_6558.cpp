#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

vector<vector<long long>> dp;

void preprocess(int N, int L, int R) {
    dp.resize(N+1, vector<long long>(R-L+1));
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= R-L; j++) {
            if (i == 0 && j == 0) dp[i][j] = 1LL;
            if (i > 0 && j > 0) dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % MOD;
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
        }
    }
}

int main() {
    int N, M, L, R;
    cin >> N >> M >> L >> R;
    
    preprocess(N, L, R);
    
    long long ans = (dp[N-1][R-L] - dp[M-1][R-L] + MOD) % MOD;
    cout << ans << endl;
    
    return 0;
}