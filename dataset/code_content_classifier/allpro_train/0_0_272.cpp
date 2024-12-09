#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500005;

int n;
vector<pair<int, int>> adj[MAXN]; // adjacency list representation of the tree
int longest_start[MAXN]; // longest path starting at each village
int longest_end[MAXN]; // longest path ending at each village

void dfs(int u, int parent) {
    for (auto edge : adj[u]) {
        int v = edge.first;
        if (v != parent) {
            dfs(v, u);
            int length = edge.second ? longest_start[v] : longest_end[v];
            if (length + 1 > longest_start[u]) {
                longest_end[u] = longest_start[u];
                longest_start[u] = length + 1;
            } else if (length + 1 > longest_end[u]) {
                longest_end[u] = length + 1;
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    dfs(0, -1);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        id--;

        int u = adj[id][0].first;
        int v = adj[id][1].first;

        int ans = max(longest_start[u] + longest_end[v] + 1, longest_start[v] + longest_end[u] + 1);
        cout << ans << endl;
    }

    return 0;
}