#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<double, double>> casinos(n);
    for(int i = 0; i < n; i++) {
        cin >> casinos[i].first >> casinos[i].second;
    }

    vector<double> dp(n+1);
    dp[0] = 1.0;

    for(int i = 0; i < n; i++) {
        double prob_win = casinos[i].first / casinos[i].second;
        dp[i+1] = dp[i] * prob_win;
    }

    double sum = dp[n];
    for(int i = n-1; i > 0; i--) {
        dp[i] = dp[i] * (1 - casinos[i].first / casinos[i].second) + dp[i+1];
        sum += dp[i];
    }

    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            int idx, a, b;
            cin >> idx >> a >> b;
            casinos[idx-1] = {a, b};
            dp[0] = 1.0;

            for(int j = 0; j < n; j++) {
                double prob_win = casinos[j].first / casinos[j].second;
                dp[j+1] = dp[j] * prob_win;
            }

            sum = dp[n];
            for(int j = n-1; j > 0; j--) {
                dp[j] = dp[j] * (1 - casinos[j].first / casinos[j].second) + dp[j+1];
                sum += dp[j];
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << fixed << setprecision(10) << dp[l] / sum << endl;
        }
    }

    return 0;
}