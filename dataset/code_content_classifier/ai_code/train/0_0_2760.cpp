#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double computeProbability(int N, int T, int L, int B, vector<bool>& lose_turn, vector<bool>& go_back) {
    // Initialize a 2D DP array to store the probabilities
    // dp[i][j] represents the probability of reaching square i in j turns
    vector<vector<double>> dp(N+1, vector<double>(T+1, 0.0));
    
    // Initialize base case
    dp[0][0] = 1.0;
    
    // Iterate over each turn
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i <= N; i++) {
            // Compute the probability of reaching square i in t turns
            dp[i][t] = 0.0;
            for (int j = 1; j <= 6; j++) {
                int prev_square = max(i - j, 0);
                // Skip the square if it is a "Go back to the start" square
                if (go_back[prev_square]) {
                    dp[0][t] += dp[i][t-1] / 6.0;
                } else {
                    // If it is a "Lose one turn" square, skip this turn
                    if (lose_turn[prev_square]) {
                        dp[prev_square][t-1] += dp[i][t-1] / 6.0;
                    } else {
                        dp[prev_square][t] += dp[i][t-1] / 6.0;
                    }
                }
            }
        }
    }
    
    // Return the probability of reaching the goal in T turns
    return dp[N][T];
}

int main() {
    int N, T, L, B;
    
    while (true) {
        cin >> N >> T >> L >> B;
        
        if (N == 0 && T == 0 && L == 0 && B == 0) {
            break;
        }
        
        vector<bool> lose_turn(N+1, false);
        vector<bool> go_back(N+1, false);
        
        for (int i = 0; i < L; i++) {
            int idx;
            cin >> idx;
            lose_turn[idx] = true;
        }
        
        for (int i = 0; i < B; i++) {
            int idx;
            cin >> idx;
            go_back[idx] = true;
        }
        
        double probability = computeProbability(N, T, L, B, lose_turn, go_back);
        cout << fixed << setprecision(6) << probability << endl;
    }
    
    return 0;
}