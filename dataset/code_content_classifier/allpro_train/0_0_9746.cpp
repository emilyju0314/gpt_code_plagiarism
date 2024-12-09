#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m, t, x;
    cin >> n >> m >> t >> x;

    vector<vector<pair<int, vector<double>>> trains(n+1, vector<pair<int, vector<double>>>(n+1));
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<double> probs(t);
        for (int j = 0; j < t; j++) {
            cin >> probs[j];
            probs[j] /= 100000.0;
        }

        trains[a][b] = make_pair(c, probs);
    }

    vector<vector<double>> dp(n+1, vector<double>(t+1, 1e9));
    dp[1][0] = 0.0;

    for (int time = 0; time < t; time++) {
        for (int station = 1; station <= n; station++) {
            for (int dest = 1; dest <= n; dest++) {
                if (trains[station][dest].first != 0) {
                    for (int i = 0; i <= t - time; i++) {
                        dp[dest][time + i] = min(dp[dest][time + i], dp[station][time] + (double)trains[station][dest].first + x * (i > 0));
                    }
                }
            }
        }
    }

    double minCost = 1e9;
    for (int time = t; time >= 0; time--) {
        minCost = min(minCost, dp[n][time]);
    }

    cout << fixed << setprecision(10) << minCost << endl;
    
    return 0;
}