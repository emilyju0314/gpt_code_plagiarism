#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> corridors(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int room1, room2;
        cin >> room1 >> room2;
        corridors[room1 - 1][room2 - 1] = 1;
        corridors[room2 - 1][room1 - 1] = 1;
    }

    vector<double> probabilities(n);
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }

    vector<vector<double>> dp(1 << n, vector<double>(n, 0));
    dp[(1 << a - 1) | (1 << b - 1)][a - 1] = 1;
    dp[(1 << a - 1) | (1 << b - 1)][b - 1] = 1;

    for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                for (int k = 0; k < n; k++) {
                    if (corridors[j][k] && j != k) {
                        dp[mask | (1 << k)][k] += dp[mask][i] * probabilities[k] * (1 - probabilities[j]) / n;
                    }
                }
            }
        }
    }

    vector<double> result(n, 0);
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << i)) && (mask & (1 << j))) {
                    result[i] += dp[mask][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(10) << result[i] << " ";
    }
    cout << endl;

    return 0;
}