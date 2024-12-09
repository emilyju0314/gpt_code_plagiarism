#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int t, n, m;
vector<vector<int>> dp;

int validConfigs(vector<string>& forest) {
    dp.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (forest[i][j] == '#') {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (forest[i][j] == '0') {
                if (j > 0) 
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if (j < m-1)
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        ans = (ans + dp[n-1][j]) % MOD;
    }

    return ans;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> m;
        vector<string> forest(n);
        for (int i = 0; i < n; i++) {
            cin >> forest[i];
        }

        cout << validConfigs(forest) << endl;
    }

    return 0;
}