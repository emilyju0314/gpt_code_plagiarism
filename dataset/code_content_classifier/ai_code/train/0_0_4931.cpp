#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ratings(N+1);
    vector<vector<double>> dp(1 << N, vector<double>(N+1, 0.0));
    
    for (int i = 1; i <= N; i++) {
        cin >> ratings[i];
    }

    dp[1][ratings[1]] = 1.0;
    
    for (int bit = 1; bit < (1 << N); bit++) {
        for (int i = 1; i <= N; i++) {
            if (bit & (1 << i)) {
                for (int j = 1; j <= N; j++) {
                    if (!(bit & (1 << j))) {
                        double prob_win = 0.0;
                        double total_prob = 0.0;

                        for (int k = 0; k <= 100; k++) {
                            if (k <= ratings[i]) {
                                prob_win += dp[bit | (1 << j)][j] * (k <= ratings[j] ? 1.0 : 0.0) * 0.01;
                            }
                            total_prob += dp[bit | (1 << j)][j] * 0.01;
                        }

                        dp[bit][i] += dp[bit | (1 << j)][j] * prob_win / total_prob;
                    }
                }
            }
        }
    }
    
    double ans = 0.0;
    for (int i = 1; i <= N; i++) {
        if (i != ratings[1]) {
            ans = max(ans, dp[(1 << N) - 1][i]);
        }
    }

    cout << fixed << ans << endl;

    return 0;
}