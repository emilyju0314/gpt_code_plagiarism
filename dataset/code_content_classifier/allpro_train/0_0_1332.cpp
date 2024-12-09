#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] /= 100; // Converting probability to a fraction
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, 0.0)));
    dp[0][0][0] = 1.0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int h = 0; h <= n; h++) {
                dp[i][j][h] += dp[i-1][j][h] * (1 - p[i-1]);
                if(j > 0 && h > 0 && a[i-1] != -1) {
                    dp[i][j][h-1] += dp[i-1][j-1][h] * p[i-1];
                } else if (j > 0 && h > 0 && a[i-1] == -1) {
                    dp[i][j][h-1] += dp[i-1][j-1][h] * p[i-1];
                }
            }
        }
    }

    double probability = 0.0;
    for(int i = l; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            probability += dp[n][i][j];
        }
    }

    cout << fixed << setprecision(12) << probability << endl;

    return 0;
}