#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;

int main() {
    int N, F;
    cin >> N >> F;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    vector<vector<int>> dp(1 << N, vector<int>(N, -INF));
    vector<vector<int>> dist(1 << N, vector<int>(N, INF));

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {F, 0}});
    dist[F][N-1] = 0;

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_score = pq.top().second.first;
        int cur_pos = pq.top().second.second;
        pq.pop();

        if (dist[cur_score][cur_pos] < cur_dist) {
            continue;
        }

        for (int i = 0; i < N; i++) {
            if (cur_pos != i && (cur_score & (1 << i)) == 0) {
                int next_score;
                if (dist[cur_score][cur_pos] % 2 == 0) {
                    next_score = cur_score | (1 << i);
                    if (cur_dist + board[cur_pos][i] > dp[next_score][i]) {
                        dp[next_score][i] = cur_dist + board[cur_pos][i];
                        dist[next_score][i] = dist[cur_score][cur_pos] + 1;
                        pq.push({-dp[next_score][i], {next_score, i}});
                    }
                } else {
                    next_score = cur_score | (1 << i);
                    if (dp[next_score][i] == -INF) {
                        dp[next_score][i] = dp[cur_score][cur_pos] + board[i][cur_pos];
                        dist[next_score][i] = dist[cur_score][cur_pos] + 1;
                        pq.push({-dp[next_score][i], {next_score, i}});
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[(1 << N) - 1][i]);
    }

    if (ans > 0) {
        cout << "First" << endl;
    } else if (ans < 0) {
        cout << "Second" << endl;
    } else {
        cout << "Draw" << endl;
    }

    cout << dist[(1 << N) - 1][0] << endl;

    return 0;
}