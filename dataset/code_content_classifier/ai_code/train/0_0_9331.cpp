#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, N;
    cin >> H >> N;

    vector<pair<int, int>> spells(N);
    for (int i = 0; i < N; i++) {
        cin >> spells[i].first >> spells[i].second;
    }

    vector<long long> dp(H + 1, 1e18);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            dp[min(j + spells[i].first, H)] = min(dp[min(j + spells[i].first, H)], dp[j] + spells[i].second);
        }
    }

    cout << dp[H] << endl;

    return 0;
}