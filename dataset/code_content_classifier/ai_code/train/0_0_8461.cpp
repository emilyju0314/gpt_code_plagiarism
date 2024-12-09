#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<double>> dp(m+1, vector<double>(n+1, 0));

    for(int i = m; i >= 0; i--) {
        for(int j = n; j >= 0; j--) {
            if(i == 0 && j == 0) {
                continue;
            }
            if(i == 0) {
                dp[i][j] = 1.0;
                continue;
            }
            if(j == 0) {
                dp[i][j] = 0.0;
                continue;
            }

            double prob_shrek = (double)i / (i + j);
            double prob_donkey = (double)j / (i + j);

            double win_prob = prob_shrek + prob_donkey * (1.0 - dp[i][j-1]);

            dp[i][j] = prob_shrek * (1.0 - dp[i-1][j]) + prob_donkey * win_prob;
        }
    }

    cout << fixed << setprecision(9) << dp[m][n] << " " << fixed << setprecision(9) << 1 - dp[m][n] << endl;

    return 0;
}