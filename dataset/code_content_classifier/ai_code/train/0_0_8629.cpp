#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> T(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    int M = (1 << m) - 1;
    vector<int> dp(M + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < m; j++) {
            if (T[i][j] == '1') {
                num |= (1 << j);
            }
        }

        for (int j = M; j >= 0; j--) {
            dp[j | num] = (dp[j | num] + dp[j]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        if ((i & (i - 1)) == 0) {
            ans = (ans + dp[i]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}