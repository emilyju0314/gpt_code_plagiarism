#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double optimalBST(int n, vector<double>& p, vector<double>& q) {
    vector<vector<double>> dp(n+2, vector<double>(n+1, 0));

    // Initialize diagonal with q values
    for (int i = 1; i <= n; i++) {
        dp[i][i] = q[i-1];
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n-len+1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k+1][j] + accumulate(p.begin()+i-1, p.begin()+j, 0) + accumulate(q.begin()+i-1, q.begin()+j+1, 0));
            }
        }
    }

    return dp[1][n];
}

int main() {
    int n;
    cin >> n;

    vector<double> p(n), q(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    double result = optimalBST(n, p, q);
    cout << fixed << setprecision(8) << result << endl;

    return 0;
}