#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n, m, g;
    cin >> n >> m >> g;

    vector<int> gender(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> gender[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n * 104 + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < m; i++) {
        int appointedGender, w, ki, isFriend;
        cin >> appointedGender >> w >> ki;
        vector<int> dogs(ki);
        for (int j = 0; j < ki; j++) {
            cin >> dogs[j];
            dogs[j]--;
        }
        cin >> isFriend;

        for (int j = n; j >= 0; j--) {
            for (int k = n * 104; k >= 0; k--) {
                if (dp[j][k] != -1) {
                    int numGender = 0;
                    for (int id : dogs) {
                        numGender += gender[id] == appointedGender;
                    }

                    if (j + numGender <= n) {
                        dp[j + numGender][k + w] = max(dp[j + numGender][k + w], dp[j][k]);
                    }
                }
            }
        }

        if (isFriend) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n * 104; k++) {
                    if (dp[j][k] != -1) {
                        dp[n][k] = max(dp[n][k], dp[j][k] - g);
                    }
                }
            }
        }
    }

    int maxMoney = 0;
    for (int i = 0; i <= n * 104; i++) {
        maxMoney = max(maxMoney, dp[n][i]);
    }

    cout << maxMoney << endl;

    return 0;
}