#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> dp(n + 1, -1e9);
    dp[1] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        vector<int> new_dp(n + 1, -1e9);
        for (int cur_pos = 1; cur_pos <= n; cur_pos++) {
            for (int new_pos = max(1, cur_pos - d); new_pos <= min(n, cur_pos + d); new_pos++) {
                int happiness = b - abs(a - new_pos);
                new_dp[new_pos] = max(new_dp[new_pos], dp[cur_pos] + happiness);
            }
        }

        dp = new_dp;
    }

    int max_happiness = *max_element(dp.begin(), dp.end());
    cout << max_happiness << endl;

    return 0;
}