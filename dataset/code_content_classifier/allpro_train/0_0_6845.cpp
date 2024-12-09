#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    long long maxProfit = 0;
    long long currentSum = 0;
    vector<long long> dp(n, 0);

    for (int i = 0; i < n; i++) {
        dp[i] = a - tasks[i].second;
        for (int j = i - 1; j >= 0; j--) {
            dp[i] = max(dp[i], dp[j] - (tasks[i].first - tasks[j].first) * 1LL * (tasks[i].first - tasks[j].first) + a - tasks[i].second);
        }
        maxProfit = max(maxProfit, dp[i]);
    }

    cout << maxProfit << endl;

    return 0;
}