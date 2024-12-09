#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> dp(W + 1, 0);

    for (int i = 0; i < N; i++) {
        int v, w, m;
        cin >> v >> w >> m;

        // For each item, we calculate its maximum value for each possible weight
        for (int j = 0; j < m; j++) {
            for (int k = W; k >= w; k--) {
                dp[k] = max(dp[k], dp[k - w] + v);
            }
        }
    }

    cout << dp[W] << endl;

    return 0;
}