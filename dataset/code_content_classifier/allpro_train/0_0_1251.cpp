#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> scoreSmall(n), scoreLarge(n), timeSmall(n), timeLarge(n);
    vector<double> probFail(n);
    vector<vector<double>> dp(n + 1, vector<double>(t + 1, -1e18));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> scoreSmall[i] >> scoreLarge[i] >> timeSmall[i] >> timeLarge[i] >> probFail[i];
        probFail[i] = 1 - probFail[i]; // the probability that the solution is correct
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= t; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]); // don't solve the i-th problem

            // solve the Small input of the i-th problem
            if (j + timeSmall[i] <= t) {
                dp[i + 1][j + timeSmall[i]] = max(dp[i + 1][j + timeSmall[i]], dp[i][j] + scoreSmall[i]);
            }

            // solve the Large input of the i-th problem
            if (j + timeSmall[i] + timeLarge[i] <= t) {
                dp[i + 1][j + timeSmall[i] + timeLarge[i]] = max(dp[i + 1][j + timeSmall[i] + timeLarge[i]], dp[i][j] + scoreSmall[i] + probFail[i] * scoreLarge[i]);
            }
        }
    }

    double maxPoints = 0, minTimePenalty = 1e18;
    for (int j = 0; j <= t; j++) {
        maxPoints = max(maxPoints, dp[n][j]);
    }

    for (int j = 0; j <= t; j++) {
        if (dp[n][j] == maxPoints) {
            minTimePenalty = min(minTimePenalty, (double)j);
        }
    }

    cout << fixed << setprecision(9) << maxPoints << " " << minTimePenalty << endl;
    
    return 0;
}