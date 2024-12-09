#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> restoreRootedTree(int N, int M, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(N + 1);
    vector<int> parent(N + 1, 0);

    for (int i = 0; i < N - 1 + M; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        parent[v] = u;
    }

    vector<int> root(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (parent[i] == 0) {
            root[i] = i;
            break;
        }
    }

    vector<int> result(N + 1);
    queue<int> q;
    q.push(root[1]);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            parent[v] = u;
            q.push(v);
        }
    }

    for (int i = 1; i <= N; i++) {
        result[i] = parent[i];
    }

    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(N - 1 + M);
    for (int i = 0; i < N - 1 + M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> result = restoreRootedTree(N, M, edges);

    for (int i = 1; i <= N; i++) {
        cout << result[i] << endl;
    }

    return 0;
}