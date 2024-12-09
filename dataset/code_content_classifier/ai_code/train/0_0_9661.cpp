#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pij(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pij[i][j];
        }
    }

    vector<double> dp(n, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                dp[j] = min(dp[j], dp[i] + 1.0 * pij[i][j] / 100);
            }
        }
    }

    cout << fixed << setprecision(15) << dp[n - 1] << endl;

    return 0;
}