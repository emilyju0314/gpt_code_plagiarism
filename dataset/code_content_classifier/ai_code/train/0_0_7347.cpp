#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <set>

using namespace std;

struct Taxi {
    int fare;
    int limit;
};

struct Road {
    int from;
    int to;
};

int main() {
    int N, K;
    cin >> N >> K;

    vector<Taxi> taxis(N);
    for (int i = 0; i < N; i++) {
        cin >> taxis[i].fare >> taxis[i].limit;
    }

    vector<vector<int>> adjList(N);
    for (int i = 0; i < K; i++) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    const int INF = numeric_limits<int>::max();

    vector<vector<int>> dp(N, vector<int>(N, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] != INF) {
                for (int k : adjList[j]) {
                    int dist = (i == j ? 0 : 1);
                    int cost = taxis[j].fare;
                    if (dist > taxis[j].limit) {
                        cost += taxis[j].fare * (dist - taxis[j].limit);
                    }
                    dp[k][i + dist] = min(dp[k][i + dist], dp[i][j] + cost);
                }
            }
        }
    }

    int minFare = INF;
    for (int i = 0; i < N; i++) {
        minFare = min(minFare, dp[N - 1][i]);
    }

    cout << minFare << endl;

    return 0;
}