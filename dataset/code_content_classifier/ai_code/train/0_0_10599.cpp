#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> graph(n+1);
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
        edges[i] = make_pair(u, v);
    }

    vector<pair<int, int>> new_edges;

    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        int new_u = -1, new_v = -1;
        for (int j = 1; j <= n; j++) {
            if (j != u && j != v && graph[u].find(j) == graph[u].end() && graph[v].find(j) == graph[v].end()) {
                new_u = u;
                new_v = j;
                graph[u].insert(j);
                graph[j].insert(u);
                break;
            }
        }

        if (new_u == -1) {
            cout << -1 << endl;
            return 0;
        } else {
            new_edges.push_back(make_pair(new_u, new_v));
        }
    }

    for (int i = 0; i < m; i++) {
        cout << new_edges[i].first << " " << new_edges[i].second << endl;
    }

    return 0;
}