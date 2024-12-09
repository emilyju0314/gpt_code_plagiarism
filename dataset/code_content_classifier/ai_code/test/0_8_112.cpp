#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<vector<pair<int, char>>> adj; // Adjacency list to represent the tree
vector<string> strings; // Array to store the input strings
map<pair<int, int>, string> paths; // Map to store the paths between nodes

void dfs(int u, int parent, string path) {
    for (auto edge : adj[u]) {
        int v = edge.first;
        char c = edge.second;
        if (v != parent) {
            paths[{u, v}] = path + c;
            paths[{v, u}] = path + c;
            dfs(v, u, path + c);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    adj.resize(n + 1);
    strings.resize(m);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for (int i = 0; i < m; i++) {
        cin >> strings[i];
    }

    dfs(1, 0, "");

    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        string path = paths[{u, v}];
        int count = 0;

        for (int j = l - 1; j < r; j++) {
            count += strings[j].find(path) != string::npos;
        }

        cout << count << endl;
    }

    return 0;
}