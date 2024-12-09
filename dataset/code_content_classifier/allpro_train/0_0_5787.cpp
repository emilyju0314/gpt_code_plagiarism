#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T, S;
    cin >> N >> T >> S;

    vector<pair<int, int>> nightShops(N);
    for (int i = 0; i < N; i++) {
        cin >> nightShops[i].first >> nightShops[i].second;
    }

    vector<int> dp(T + 1, 0); // dp[i] stores the maximum fun value achievable within time i

    for (int i = 0; i < N; i++) {
        for (int j = T; j >= nightShops[i].second; j--) {
            if (nightShops[i].second <= S && S <= nightShops[i].second + nightShops[i].first) {
                // Taro can see the fireworks at this night shop
                dp[j] = max(dp[j], dp[j - nightShops[i].second] + nightShops[i].first);
            }
        }
    }

    int maxFun = 0;
    for (int i = 0; i <= T; i++) {
        maxFun = max(maxFun, dp[i]);
    }

    cout << maxFun << endl;

    return 0;
}