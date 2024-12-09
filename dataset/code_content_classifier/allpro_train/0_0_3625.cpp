#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int price;
    int strength;
};

struct Event {
    int time;
    int condition;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].price >> items[i].strength;
    }

    vector<Event> events(M);
    for (int i = 0; i < M; i++) {
        cin >> events[i].time >> events[i].condition;
    }

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= N; j++) {
            if (dp[i][j] != -1) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                for (int k = 0; k + j <= N; k++) {
                    int time = events[i].time;
                    int condition = events[i].condition;
                    if (k * time + j >= N) {
                        dp[i + 1][k + j] = max(dp[i + 1][k + j], dp[i][j] + condition);
                    }
                }
            }
        }
    }

    int ans = -1;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, dp[M][i]);
    }

    cout << ans << endl;

    return 0;
}