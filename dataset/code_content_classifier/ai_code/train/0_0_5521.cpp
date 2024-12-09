#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<long long>> dp(2, vector<long long>(N + 1, 0));
    vector<pair<int, int>> walls(N);
    for (int i = 0; i < N; i++) {
        cin >> walls[i].first >> walls[i].second;
    }

    sort(walls.begin(), walls.end());

    dp[0][0] = 1;

    for (int i = 1; i <= H; i++) {
        int curr = i % 2;
        int prev = (i - 1) % 2;
        
        for (int j = 1; j <= W; j++) {
            dp[curr][j] = 0;
        }

        for (int j = 1; j <= W; j++) {
            if (binary_search(walls.begin(), walls.end(), make_pair(i, j))) {
                dp[curr][j] = 0;
            } else {
                dp[curr][j] = (dp[prev][j] + dp[curr][j-1]) % MOD;
            }
        }
    }

    cout << dp[H % 2][W] << endl;
    
    return 0;
}