#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int n, m;
vector<pair<int, pair<int, int>>> edges;
vector<int> a;

void dfs(int v, vector<bool>& visited, vector<vector<int>>& adjList, vector<int>& tsorted) {
    visited[v] = true;
    for (int u : adjList[v]) {
        if (!visited[u]) {
            dfs(u, visited, adjList, tsorted);
        }
    }
    tsorted.push_back(v);
}

int main() {
    cin >> n >> m;

    a.resize(n);
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    sort(edges.begin(), edges.end());

    vector<vector<int>> adjList(n);
    for (auto& e : edges) {
        adjList[e.second.first - 1].push_back(e.second.second - 1);
    }

    vector<int> tsorted;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, visited, adjList, tsorted);
        }
    }

    for (int v : tsorted) {
        a[v] = INF;
        for (int u : adjList[v]) {
            a[v] = min(a[v], a[u] - 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }

    return 0;
}