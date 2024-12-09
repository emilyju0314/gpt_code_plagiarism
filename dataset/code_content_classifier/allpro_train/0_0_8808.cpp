#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, vector<int>>> keys;

    for(int i = 0; i < M; i++) {
        int cost, num_boxes;
        cin >> cost >> num_boxes;

        vector<int> boxes(num_boxes);
        for(int j = 0; j < num_boxes; j++) {
            cin >> boxes[j];
            boxes[j]--;
        }

        keys.push_back({cost, boxes});
    }

    int INF = 1e9;
    vector<int> dp(1 << N, INF);
    dp[0] = 0;

    for(int mask = 0; mask < (1 << N); mask++) {
        for(auto key : keys) {
            int new_mask = mask;
            for(auto box : key.second) {
                new_mask |= (1 << box);
            }
            dp[new_mask] = min(dp[new_mask], dp[mask] + key.first);
        }
    }

    if(dp[(1 << N) - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << N) - 1] << endl;
    }

    return 0;
}