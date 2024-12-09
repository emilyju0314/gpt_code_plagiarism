#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2000;
vector<int> adj[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][v] = dp[v][u] = max(dp[u][v], dp[u][parent] + 1);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        dp[u][v] = dp[v][u] = -1;
    }

    dfs(1, 0);

    int totalHappiness = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] != -1) {
                totalHappiness += dp[i][j];
            }
        }
    }

    cout << totalHappiness / 2 << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (dp[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}