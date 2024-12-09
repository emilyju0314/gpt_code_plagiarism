#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> isInteresting;
vector<int> visited;

void dfs(int node) {
    visited[node] = 1;

    for (int neigh : graph[node]) {
        if (!visited[neigh]) {
            dfs(neigh);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        graph.clear();
        graph.resize(n + 1);
        isInteresting.assign(n + 1, 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            visited.assign(n + 1, 0);
            dfs(i);

            if (count(visited.begin(), visited.end(), 1) != n) {
                isInteresting[i] = 0;
            }
        }

        vector<int> interestingCities;
        for (int i = 1; i <= n; i++) {
            if (isInteresting[i]) {
                interestingCities.push_back(i);
            }
        }

        if ((int) interestingCities.size() < n / 5) {
            cout << "-1\n";
        } else {
            for (int city : interestingCities) {
                cout << city << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}