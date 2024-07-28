#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX_N = 12;
const int MAX_M = 1024;

int dp[MAX_N][MAX_M];
int cost[MAX_N];
int compatibility[MAX_N];

int main() {
    int n, m;
    while (cin >> n >> m && n && m) {
        // 初始化
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            int w;
            cin >> cost[i] >> w;
            compatibility[i] = 0;
            for (int j = 0; j < w; ++j) {
                int c;
                cin >> c;
                compatibility[i] |= 1 << (c - 1);
            }
        }

        // 動態規劃
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1 << m); ++j) {
                if (dp[i][j] == -1) {
                    continue;
                }
                // 狀態轉移
                for (int k = 0; k < (1 << m); ++k) {
                    if ((k & compatibility[i]) == 0) {
                        dp[i+1][k] = max(dp[i+1][k], dp[i][j] + (j == k ? 0 : cost[i]));
                    }
                }
            }
        }

        // 找出最大值
        int ans = 0;
        for (int i = 0; i < (1 << m); ++i) {
            ans = max(ans, dp[n][i]);
        }

        cout << ans << endl;
    }

    return 0;
}
