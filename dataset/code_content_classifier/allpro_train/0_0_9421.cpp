#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int N;
    string s;
    cin >> N >> s;

    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (s[i-1] == '<') {
                for (int k = j; k <= N; k++) {
                    dp[i][k] = (dp[i][k] + dp[i-1][j]) % mod;
                }
            } else {
                for (int k = 0; k < j; k++) {
                    dp[i][k] = (dp[i][k] + dp[i-1][j]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = (ans + dp[N][i]) % mod;
    }

    cout << ans << endl;

    return 0;
}