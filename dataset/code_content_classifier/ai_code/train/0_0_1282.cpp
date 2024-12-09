#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<pair<int, int>> ranges(H);
    for (int i = 0; i < H; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    vector<int> dp(W+1, H+1);
    dp[1] = 0;

    for (int i = 0; i < H; i++) {
        int left = 1, right = 1, sum = 0;
        for (int j = 1; j <= W; j++) {
            if (j < ranges[i].first) {
                sum += left;
            } else if (j > ranges[i].second) {
                sum -= right;
            }
            dp[j] = min(dp[j], sum);
            if (j < W && j < ranges[i].second) left++;
            if (j < W && j >= ranges[i].first) right++;
        }
    }

    for (int i = 0; i < H; i++) {
        if (dp[W] == H+1) {
            cout << -1 << endl;
        } else {
            cout << dp[W] + i + 1 << endl;
        }
    }

    return 0;
}