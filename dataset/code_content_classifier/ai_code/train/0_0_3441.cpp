#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9+7;

int main() {
    int N, M;
    cin >> N >> M;
    
    string S;
    cin >> S;
    
    vector<vector<int>> dp(N, vector<int>(2, 0));
    
    dp[0][S[0] == 'R' ? 1 : 0] = 1;
    
    for (int i = 1; i < M; i++) {
        vector<vector<int>> new_dp(N, vector<int>(2, 0));
        
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[j][k] == 0) continue;
                
                int next_j = (j + 1) % N;
                int next_k = S[i] == 'R' ? 1 : 0;
                
                if (k == next_k) {
                    new_dp[next_j][next_k] = (new_dp[next_j][next_k] + dp[j][k]) % MOD;
                }
                
                new_dp[next_j][!next_k] = (new_dp[next_j][!next_k] + dp[j][k]) % MOD;
            }
        }
        
        dp = new_dp;
    }
    
    int total_ways = 0;
    for (int j = 0; j < N; j++) {
        total_ways = (total_ways + dp[j][S[M-1] == 'R' ? 1 : 0]) % MOD;
    }
    
    cout << total_ways << endl;
    
    return 0;
}