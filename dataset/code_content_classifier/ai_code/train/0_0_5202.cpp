#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for(int j = 0; j < n; j++) {
        dp[j][j] = 1;
    }

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = (dp[i + 1][j] + dp[i][j - 1]) % MOD;
            if(cards[i] == cards[j]) {
                for(int k = i + 1; k < j; k++) {
                    if(cards[i] > cards[k]) {
                        dp[i][j] = (dp[i][j] + 1LL * dp[i + 1][k - 1] * dp[k + 1][j] % MOD) % MOD;
                    }
                }
            }
        }
    }

    int total_ways = dp[0][n - 1];
    int total_games = n * (n - 1) / 2;
    
    int inverse_total_games = 499122177; // Modular inverse of 2*n % MOD

    int probability = 1LL * total_ways * inverse_total_games % MOD;

    cout << probability << endl;

    return 0;
}