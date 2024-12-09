#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int hp1, dt1, l1, r1, p1;
    int hp2, dt2, l2, r2, p2;

    cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
    cin >> hp2 >> dt2 >> l2 >> r2 >> p2;

    vector<vector<vector<double>>> dp(hp1 + 1, vector<vector<double>>(2, vector<double>(hp2 + 1, 0.0)));
    dp[0][0][0] = 1.0;

    for (int i = 0; i <= hp1; i++) {
        for (int j = 0; j <= hp2; j++) {
            for (int k = 0; k < 2; k++) {
                if (i == 0 && j == 0) continue;
                if (k == 0) {
                    dp[i][k][j] += (i > 0) ? dp[i - 1][1][j] : 0;
                } else {
                    dp[i][k][j] += (j > 0) ? dp[i][0][j - 1] * (1.0 - (p2 / 100.0)) : 0;
                    if (j > 0) {
                        for (int d = l1; d <= r1; d++) {
                            if (i - d >= 0) {
                                dp[i][k][j] += dp[i - d][0][j - 1] * (1.0 / (r1 - l1 + 1)) * (p2 / 100.0);
                            }
                        }
                    }
                }
            }
        }
    }

    double win_probability = 0.0;
    for (int i = 1; i <= hp1; i++) {
        win_probability += dp[i][1][0];
    }

    cout << fixed << setprecision(6) << win_probability << endl;

    return 0;
}