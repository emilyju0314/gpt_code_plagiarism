#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;

    vector<vector<int>> happiness(N+1, vector<int>(6, 0));

    for (int i = 0; i < M; i++) {
        int d, a, k, t;
        cin >> d >> a >> k >> t;

        for (int j = a; j < a + k; j++) {
            happiness[j][d] = max(happiness[j][d], t);
        }
    }

    vector<vector<int>> dp(N+1, vector<int>(L+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= L; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j]);

            for (int x = 1; x <= j; x++) {
                for (int y = 0; y < 5; y++) {
                    if (i-y >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i-y][j-x] + happiness[i][y]);
                    }
                }
            }
        }
    }

    cout << dp[N][L] << endl;

    return 0;
}