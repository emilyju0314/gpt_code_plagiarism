#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    double dp[105][105] = {0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = 1.0*j/i + (i-1.0)/i*dp[i-1][j] + (j-1.0)/i*dp[i-1][j-1];
        }
    }

    cout << fixed << setprecision(10) << dp[n][k] << endl;

    return 0;
}