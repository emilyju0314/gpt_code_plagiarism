#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<pair<int, string>>> graph;
vector<int> visited;
bool hasContradiction;

void dfs(int node, string role) {
    visited[node] = 1;

    for (auto edge : graph[node]) {
        int neighbor = edge.first;
        string neighborRole = edge.second;

        if (visited[neighbor] == 0) {
            if (role == "imposter") {
                if (neighborRole == "imposter") {
                    hasContradiction = true;
                    return;
                }
                dfs(neighbor, "crewmate");
            } else {
                if (neighborRole == "crewmate") {
                    hasContradiction = true;
                    return;
                }
                dfs(neighbor, "imposter");
            }
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
        visited.assign(n + 1, 0);
        hasContradiction = false;

        for (int i = 0; i < m; i++) {
            int u, v;
            string role;
            cin >> u >> v >> role;
            graph[u].push_back({v, role});
        }
        
        int imposters = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, "imposter");
                if (hasContradiction) {
                    cout << -1 << endl;
                    break;
                } else {
                    imposters++;
                }
            }
        }

        if (!hasContradiction) {
            cout << imposters << endl;
        }
    }

    return 0;
}