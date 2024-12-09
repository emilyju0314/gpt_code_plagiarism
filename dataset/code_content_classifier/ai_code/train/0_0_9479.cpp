#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> marbles(n);
    for (int i = 0; i < n; i++) {
        cin >> marbles[i].first >> marbles[i].second;
    }

    sort(marbles.begin(), marbles.end());

    vector<long long> dp(n);
    dp[0] = marbles[0].second;
    long long ans = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = marbles[i].second;
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(marbles[i].first - marbles[j].first));
        }
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}