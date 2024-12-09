#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;
vector<pair<int, int>> adj[MAX_N];
bool visited[MAX_N];
int edgeValues[MAX_N];
int pathXOR[MAX_N];

void dfs(int node, int parent) {
    visited[node] = true;
    for (auto edge : adj[node]) {
        int nextNode = edge.first;
        int edgeValue = edge.second;
        if (nextNode != parent) {
            if (!visited[nextNode]) {
                edgeValues[nextNode] = edgeValue;
                pathXOR[nextNode] = pathXOR[node] ^ edgeValue;
                dfs(nextNode, node);
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

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < n - 1; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            adj[x].push_back({y, v});
            adj[y].push_back({x, v});
        }

        int root = 1;
        edgeValues[root] = 0;
        pathXOR[root] = 0;
        dfs(root, -1);

        bool possible = true;
        while (m--) {
            int a, b, p;
            cin >> a >> b >> p;
            int xorValue = pathXOR[a] ^ pathXOR[b];
            if (__builtin_popcount(xorValue) % 2 != p) {
                possible = false;
            }
        }

        if (possible) {
            cout << "YES\n";
            for (int i = 2; i <= n; i++) {
                cout << i << " " << (i == root ? 1 : (i % n) + 1) << " " << edgeValues[i] << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}