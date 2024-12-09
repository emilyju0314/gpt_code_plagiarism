#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> snowDrifts(n);
    for (int i = 0; i < n; i++) {
        cin >> snowDrifts[i].first >> snowDrifts[i].second;
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (snowDrifts[i].first == snowDrifts[j].first || snowDrifts[i].second == snowDrifts[j].second) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            components++;
        }
    }

    cout << max(components - 1, 0) << endl;

    return 0;
}