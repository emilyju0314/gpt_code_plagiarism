#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> concentrations(k);
    for (int i = 0; i < k; i++) {
        cin >> concentrations[i];
    }

    unordered_map<int, int> dp;
    dp[0] = 0;

    for (int i = 1; i <= 1000; i++) {
        int min_liters = INT_MAX;
        for (int j = 0; j < k; j++) {
            int diff = abs(i - concentrations[j]);
            if (dp.count(diff) > 0) {
                min_liters = min(min_liters, dp[diff] + 1);
            }
        }
        dp[i] = min_liters;
    }

    if (dp.count(n) > 0) {
        cout << dp[n] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}