#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, D, X;
    cin >> N >> M >> D >> X;

    vector<int> cities(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i];
    }

    vector<pair<int, int>> enemies(M);
    for (int i = 0; i < M; i++) {
        cin >> enemies[i].first >> enemies[i].second;
    }

    vector<vector<int>> surveillance(D + 1, vector<int>(N, 0));

    for (int day = 1; day <= D; day++) {
        for (int i = 0; i < M; i++) {
            int enemy_x = enemies[i].first + X * (day - 1);
            int enemy_top = enemies[i].second - enemy_x;
            int enemy_bottom = enemies[i].second + enemy_x;
            for (int j = 0; j < N; j++) {
                if ((cities[j] >= enemy_x + enemy_top) && (cities[j] <= enemy_x + enemy_bottom)) {
                    surveillance[day][j]++;
                }
            }
        }
    }

    vector<vector<int>> dp(D + 1, vector<int>(N, INT_MAX));
    dp[0][0] = 0;

    for (int day = 1; day <= D; day++) {
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                dp[day][i] = min(dp[day][i], dp[day - 1][j] + surveillance[day][i] * abs(cities[i] - cities[j]));
            }
        }
    }

    int result = INT_MAX;
    for (int day = 0; day <= D; day++) {
        result = min(result, dp[day][N - 1]);
    }

    cout << result << endl;

    return 0;
}