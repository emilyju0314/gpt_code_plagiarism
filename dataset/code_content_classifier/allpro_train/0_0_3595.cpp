#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, h;
    double p;
    cin >> n >> h >> p;

    vector<int> trees(n);
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    vector<vector<double>> dp(n, vector<double>(n, 0));

    for (int d = 1; d < n; d++) {
        for (int i = 0; i + d < n; i++) {
            int j = i + d;

            double pl = p;
            double pr = 1 - p;

            dp[i][j] = pl * pl * dp[i+1][j-1] + pr * pr * dp[i+1][j-1] + (pl * pr + pr * pl) * (trees[j] - trees[i] + h);
        }
    }

    cout << fixed << setprecision(9) << dp[0][n-1] << endl;

    return 0;
}