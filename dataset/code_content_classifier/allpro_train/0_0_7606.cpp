#include <iostream>
#include <string>

using namespace std;

const long long MOD = 1000000007;

int main() {
    string sentence, spell;
    cin >> sentence >> spell;

    int n = sentence.size();
    int m = spell.size();

    long long dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == 0) {
                continue;
            }
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (j < m && sentence[i] == spell[j]) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}