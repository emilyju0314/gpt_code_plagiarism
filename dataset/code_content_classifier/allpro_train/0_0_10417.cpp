#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<vector<int>> c(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << n); mask++) {
        vector<int> keys(m, INT_MAX);
        vector<int> cost(m, 0);
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                for(int j = 0; j < m; j++) {
                    keys[j] = min(keys[j], c[i][j]);
                    cost[j] += c[i][j];
                }
            }
        }

        vector<int> profit(m);
        for(int j = 0; j < m; j++) {
            profit[j] = b[j] - keys[j];
        }

        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        int total_profit = accumulate(profit.begin(), profit.end(), 0);
        if(total_profit > 0) {
            ans = min(ans, total_cost);
        }
    }

    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}