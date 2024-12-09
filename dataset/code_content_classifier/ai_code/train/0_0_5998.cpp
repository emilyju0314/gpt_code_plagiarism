#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<double>> a(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<double> dp(1 << n);
    dp[(1 << n) - 1] = 1;

    for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        vector<int> alive;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) alive.push_back(i);
        }

        for (int i = 0; i < alive.size(); i++) {
            for (int j = i + 1; j < alive.size(); j++) {
                int x = alive[i], y = alive[j];
                dp[mask ^ (1 << y)] += dp[mask] * a[x][y];
                dp[mask ^ (1 << x)] += dp[mask] * a[y][x];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6) << dp[1 << i] << " ";
    }

    return 0;
}