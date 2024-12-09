#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> in_degree(n, 0);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    vector<long long> ans(n, 10e15);

    vector<int> sorted_vertices;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            sorted_vertices.push_back(i);
            ans[i] = a[i];
        }
    }

    for (int i = 0; i < sorted_vertices.size(); i++) {
        int u = sorted_vertices[i];
        for (int v : graph[u]) {
            in_degree[v]--;
            ans[v] = min(ans[v], ans[u]);
            if (in_degree[v] == 0) {
                sorted_vertices.push_back(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}