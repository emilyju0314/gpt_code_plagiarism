#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<double>> probabilities(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> probabilities[i][j];
        }
    }

    vector<double> dp(1 << n, 0);
    dp[1] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {
        int count = __builtin_popcount(mask);

        if (__builtin_popcount(mask) % 2 == 1) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < n; j++) {
                        if (!(mask & (1 << j)) && i != j) {
                            dp[mask | (1 << j)] += dp[mask] * probabilities[i][j];
                        }
                    }
                }
            }
        }
    } 

    double answer = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            answer += dp[(1 << n) - 1] * probabilities[i][0];
        }
    }

    cout << fixed;
    cout.precision(9);
    cout << answer << endl;

    return 0;
}