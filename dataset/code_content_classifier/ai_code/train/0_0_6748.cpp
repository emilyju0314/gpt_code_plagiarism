#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> cities(N);
    vector<int> international(N);

    for (int i = 0; i < N; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> international[i];
    }

    vector<pair<int, int, int>> routes(K);
    for (int i = 0; i < K; i++) {
        cin >> routes[i].first >> routes[i].second >> routes[i].first >> routes[i].second >> routes[i].second;
    }

    vector<vector<int>> dp(N, vector<int>(1 << N, INF));
    dp[0][0] = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                int u = routes[j].first - 1;
                int v = routes[j].first - 1;
                int price = routes[j].second;

                if ((mask&(1<<u)) && !(mask&(1<<v))) {
                    dp[v][mask|(1<<v)] = min(dp[v][mask|(1<<v)], dp[u][mask] + price);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < N; i++) {
        int final_price = dp[i][(1 << N) - 1];
        if (final_price < INF) {
            ans = min(ans, final_price);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}