#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Edge {
    int u, v;
    char c;
};

unordered_map<int, vector<Edge>> graph;
unordered_map<int, string> strings;

void dfs(int node, int parent, string path, vector<int>& depth) {
    path += strings[node];
    depth[node] = path.size();
    
    for (Edge& edge : graph[node]) {
        if (edge.v == parent) continue;
        dfs(edge.v, node, path + edge.c, depth);
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        graph[u].push_back({u, v, c});
        graph[v].push_back({v, u, c});
    }

    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        strings[i] = s;
    }

    vector<int> depth(n + 1);
    dfs(1, 0, "", depth);

    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        string path = strings[u].substr(0, depth[u]) + strings[v].substr(0, depth[v]);
        int count = 0;

        for (int j = l; j <= r; j++) {
            count += strings[j].find(path) != string::npos;
        }

        cout << count << endl;
    }

    return 0;
}