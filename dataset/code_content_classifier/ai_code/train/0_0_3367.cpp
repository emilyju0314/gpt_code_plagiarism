#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> blocks(N);
    for (int i = 0; i < N; i++) {
        cin >> blocks[i].first >> blocks[i].second;
    }

    sort(blocks.begin(), blocks.end(), greater<pair<int, int>>());

    vector<int> dp(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (blocks[j].first >= blocks[i].first && blocks[j].second >= blocks[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_piles = *max_element(dp.begin(), dp.end());

    cout << max_piles << endl;

    return 0;
}