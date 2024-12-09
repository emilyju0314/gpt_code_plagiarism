#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1000005;
vector<int> obstacles[MAX_N];
int dp[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        obstacles[x1].push_back(y1 - 1);
        obstacles[x2].push_back(y2);
    }

    dp[1] = 1;
    for (int i = 1; i <= n; ++i) {
        sort(obstacles[i].begin(), obstacles[i].end());

        for (int j : obstacles[i]) {
            if (j == 0) {
                dp[i] = 0;
            } else {
                dp[i] -= dp[j];
                if (dp[i] < 0) {
                    dp[i] += MOD;
                }
            }
        }

        if (i < n) {
            dp[i + 1] = dp[i];
        }
    }

    cout << dp[n] << endl;

    return 0;
}