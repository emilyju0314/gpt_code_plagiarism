#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> table(3, vector<long long>(n));
    vector<vector<long long>> dp(3, vector<long long>(n, 0));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }

    dp[0][0] = table[0][0];
    for(int j = 1; j < n; j++) {
        dp[0][j] = max(dp[0][j-1], dp[2][j-1]) + table[0][j];
        dp[1][j] = max({dp[0][j-1], dp[1][j-1], dp[2][j-1]}) + table[1][j];
        dp[2][j] = max(dp[1][j-1], dp[2][j-1]) + table[2][j];
    }

    cout << max({dp[0][n-1], dp[1][n-1], dp[2][n-1]}) << endl;

    return 0;
}