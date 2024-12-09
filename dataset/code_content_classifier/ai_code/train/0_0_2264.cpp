#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000000;

int main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<vector<int>>> dp(n1 + n2 + 1, vector<vector<int>>(k1 + 1, vector<int>(k2 + 1, 0)));
    dp[0][0][0] = 1;

    for(int i = 0; i <= n1 + n2; i++) {
        for(int j = 0; j <= k1; j++) {
            for(int k = 0; k <= k2; k++) {
                if(j < k1 && i < n1) {
                    dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD;
                }
                if(k < k2 && i < n2) {
                    dp[i + 1][0][k + 1] = (dp[i + 1][0][k + 1] + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for(int j = 0; j <= k1; j++) {
        for(int k = 0; k <= k2; k++) {
            result = (result + dp[n1 + n2][j][k]) % MOD;
        }
    }

    cout << result << endl;

    return 0;
}