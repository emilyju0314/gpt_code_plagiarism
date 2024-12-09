#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000

using namespace std;

int V, E;
vector<vector<int>> graph;
int dp[1 << 15][15];

int tsp(int mask, int pos) {
    if (mask == (1 << V) - 1) {
        return (graph[pos][0] == INF ? INF : graph[pos][0]);
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int next = 0; next < V; next++) {
        if ((mask & (1 << next)) == 0 && graph[pos][next] != INF) {
            ans = min(ans, graph[pos][next] + tsp(mask | (1 << next), next));
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cin >> V >> E;

    graph.assign(V, vector<int>(V, INF));

    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s][t] = d;
        graph[t][s] = d;
    }

    for (int i = 0; i < (1 << 15); i++) {
        for (int j = 0; j < 15; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = tsp(1, 0); // Starting from vertex 0
    cout << ans * 2 << endl;

    return 0;
}