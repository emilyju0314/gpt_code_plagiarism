#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lengths(n);
    vector<int> costs(n);

    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    int max_jump = *max_element(lengths.begin(), lengths.end());
    vector<int> dp(max_jump + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i <= max_jump; i++) {
        for (int j = 0; j < n; j++) {
            if (i + lengths[j] <= max_jump) {
                dp[i + lengths[j]] = min(dp[i + lengths[j]], dp[i] + costs[j]);
            }
        }
    }

    int min_cost = 1e9;
    for (int i = 0; i <= max_jump; i++) {
        min_cost = min(min_cost, dp[i]);
    }

    if (min_cost == 1e9) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }

    return 0;
}