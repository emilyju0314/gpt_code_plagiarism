#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V, XLeft, XRight;
    cin >> N >> V >> XLeft >> XRight;

    vector<pair<pair<int, int>, int>> moles(N); // (position, time), points
    for (int i = 0; i < N; i++) {
        int X, T, P;
        cin >> X >> T >> P;
        moles[i] = make_pair(make_pair(X, T), P);
    }

    sort(moles.begin(), moles.end());

    vector<vector<int>> dp(N + 1, vector<int>(200001, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 200001; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            int distToLeft = abs(XLeft - moles[i].first.first);
            int distToRight = abs(XRight - moles[i].first.first);
            int minDist = min(distToLeft, distToRight);
            if (moles[i].first.second - j >= minDist / V) {
                if (distToLeft <= distToRight) {
                    dp[i + 1][moles[i].first.second] = max(dp[i + 1][moles[i].first.second], dp[i][j] + moles[i].second);
                } else {
                    dp[i + 1][moles[i].first.second] = max(dp[i + 1][moles[i].first.second], dp[i][j] + moles[i].second);
                }
            }
        }
    }

    int maxPoints = 0;
    for (int i = 0; i < 200001; i++) {
        maxPoints = max(maxPoints, dp[N][i]);
    }

    cout << maxPoints << endl;

    return 0;
}