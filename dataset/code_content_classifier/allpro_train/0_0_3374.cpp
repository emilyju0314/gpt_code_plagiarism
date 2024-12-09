#include<bits/stdc++.h>
using namespace std;

int main() {
    string X, Y;

    while (true) {
        cin >> X;
        if (X == "#") {
            break;
        }

        cin >> Y;
        int A, E, S, R;
        cin >> A >> E >> S >> R;

        int lenX = X.size();
        int lenY = Y.size();

        vector<vector<vector<vector<long long>> dp(lenX + 1, vector<vector<long long>>(lenY + 1, vector<long long>(4, INT_MAX)));

        for (int i = 0; i <= lenX; i++) {
            for (int j = 0; j <= lenY; j++) {
                for (int k = 0; k < 4; k++) {
                    dp[i][j][k] = INT_MAX;
                }
            }
        }

        dp[0][0][0] = 0;

        for (int i = 0; i <= lenX; i++) {
            for (int j = 0; j <= lenY; j++) {
                for (int k = 0; k < 4; k++) {
                    if (j < lenY) {
                        dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][k] + A);
                        if (k < 2) {
                            dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k]);
                        }
                    }

                    if (i < lenX) {
                        dp[i + 1][j][2] = min(dp[i + 1][j][2], dp[i][j][k] + E);
                        if (k < 1) {
                            dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k]);
                        }
                    }

                    if (i < lenX && j < lenY) {
                        dp[i + 1][j + 1][3] = min(dp[i + 1][j + 1][3], dp[i][j][k] + S);
                    }
                }
            }
        }

        long long result = INT_MAX;

        for (int k = 0; k < 4; k++) {
            result = min(result, dp[lenX][lenY][k] + R);
        }

        cout << result << endl;
    }

    return 0;
}