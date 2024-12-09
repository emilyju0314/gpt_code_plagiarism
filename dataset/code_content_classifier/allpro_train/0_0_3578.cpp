#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, set<int>& group) {
    visited[node] = true;
    group.insert(node);

    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next, adj, visited, group);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<set<int>> groups;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            set<int> group;
            dfs(i, adj, visited, group);
            groups.push_back(group);
        }
    }

    cout << groups.size() << endl;
    for (auto g : groups) {
        cout << g.size() << " ";
        for (int node : g) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}