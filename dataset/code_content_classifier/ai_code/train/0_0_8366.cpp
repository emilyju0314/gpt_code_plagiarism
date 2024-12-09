#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<double> p(n);
    vector<double> u(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }

    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(a + 1, vector<double>(b + 1, 0.0)));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= a; j++) {
            for (int k = 0; k <= b; k++) {
                dp[i][j][k] = i > 0 ? dp[i - 1][j][k] : 0.0;
                if (j > 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + p[i - 1]);
                }
                if (k > 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + u[i - 1]);
                }
                if (j > 0 && k > 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + max(p[i - 1], u[i - 1]));
                }
            }
        }
    }

    cout << fixed << setprecision(2) << dp[n][a][b] << endl;

    return 0;
}