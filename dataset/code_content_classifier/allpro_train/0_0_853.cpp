#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> points;
vector<int> dp;

int dfs(int node, int parent) {
    int res = points[node];
    for (int child : graph[node]) {
        if (child == parent) continue;
        res = max(res, dfs(child, node) + points[node] - 1);
    }
    return dp[node] = res;
}

int main() {
    int N;
    cin >> N;

    points.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    graph.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);       
    }

    dp.resize(N);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dfs(i, -1));
    }

    cout << ans << endl;

    return 0;
}