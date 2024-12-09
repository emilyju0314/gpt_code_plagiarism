#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> p(M);
    for(int i = 0; i < M; i++) {
        cin >> p[i];
    }
    
    vector<vector<int>> dp(N, vector<int>(K+1, 0));
    dp[0][0] = 1;
    
    for(int k = 1; k <= K; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                int newPos = (i + p[j]) % N;
                dp[newPos][k] = (dp[newPos][k] + dp[i][k-1]) % MOD;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << dp[i][K] << endl;
    }
    
    return 0;
}