#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, vector<int>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int xi, yi, ki;
        cin >> xi >> yi >> ki;
        vector<int> visions(ki);
        for (int j = 0; j < ki; j++) {
            cin >> visions[j];
        }
        graph[xi].push_back({yi, visions});
    }

    vector<vector<int>> dp(2*n+1, vector<int>(n+1));
    dp[1][1] = 1;

    for (int i = 1; i <= 2*n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] > 0) {
                for (auto p : graph[j]) {
                    int v = p.first;
                    vector<int> visions = p.second;
                    bool valid = true;
                    for (int k = 0; k < visions.size(); k++) {
                        if (i - k - 1 < 0 || visions[k] != dp[i - k - 1][j]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        dp[i+1][v] = (dp[i+1][v] + dp[i][j]) % MOD;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 2*n; i++) {
        cout << dp[i][n] << endl;
    }

    return 0;
}