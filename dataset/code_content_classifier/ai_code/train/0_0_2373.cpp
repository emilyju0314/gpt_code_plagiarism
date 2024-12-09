#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        indegree[b] += c;
        outdegree[a] += c;
    }

    vector<int> direction(m, 0);

    vector<bool> visited(n, false);
    vector<int> stack;
    stack.push_back(0);
    visited[0] = true;

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        for (auto& [v, idx] : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                stack.push_back(v);

                if (indegree[u] < outdegree[u]) {
                    direction[idx] = 0;
                } else {
                    direction[idx] = 1;
                }

                indegree[v] -= adj[v][idx].second + 1 - direction[idx];
                outdegree[u] -= adj[v][idx].second + 1 - direction[idx];
            }
        }
    }

    for (auto d : direction) {
        cout << d << endl;
    }

    return 0;
}