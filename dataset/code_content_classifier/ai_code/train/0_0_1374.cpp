#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    
    vector<vector<pair<int, int>>> balls(N+1); // (weight, color) pairs for each color
    for (int i = 0; i < N; i++) {
        int c, w;
        cin >> c >> w;
        balls[c].push_back({w, c});
    }
    
    for (int i = 1; i <= N; i++) {
        sort(balls[i].begin(), balls[i].end(), greater<pair<int, int>>()); // sort by weight in descending order
    }
    
    vector<long long> dp(N+1), sum(N+1);
    dp[0] = 1; // base case
    sum[0] = 1; // cumulative sum
    
    for (int i = 1; i <= N; i++) {
        dp[i] = sum[i-1];
        for (int j = 1; j <= balls[i].size(); j++) {
            for (int k = j; k > 0; k--) {
                if (balls[i][j-1].first <= X && j == k) {
                    dp[i] = (dp[i] + dp[i-1]) % MOD;
                } else if (balls[i][j-1].first + balls[i][k-1].first <= Y) {
                    dp[i] = (dp[i] + sum[i-1] - sum[i-k-1] + MOD) % MOD;
                } else {
                    break;
                }
            }
        }
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }
    
    cout << dp[N] << endl;
    
    return 0;
}