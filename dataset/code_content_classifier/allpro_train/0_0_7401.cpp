#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> color(500001, -1);
unordered_map<int, set<int>> edges[51];
unordered_map<int, set<int>> colorEdges[51];

bool bipartite(int c) {
    vector<int> visited(500001, 0);
    vector<int> color(500001, 0);
    set<int> s;
    s.insert(c);
    visited[c] = 1;
    color[c] = 1;
    while (!s.empty()) {
        int v = *s.begin();
        s.erase(s.begin());
        for (int u : colorEdges[c][v]) {
            if (color[u] == 0) {
                color[u] = 3 - color[v];
                visited[u] = true;
                s.insert(u);
            } else if (color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= k; j++) {
            edges[j][a].insert(b);
            edges[j][b].insert(a);
        }
    }

    for (int i = 0; i < q; i++) {
        int e, c;
        cin >> e >> c;

        if (color[e] != -1) {
            colorEdges[color[e]][edges[color[e]][e].begin()].erase(e);
            edges[color[e]][e].erase(edges[color[e]][e].begin());
        }

        color[e] = c;
        colorEdges[c][edges[c][e].begin()].insert(e);
        edges[c][e] = edges[c][e];
        
        if (bipartite(c)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            
            color[e] = -1;
            colorEdges[c][e].erase(edges[c][e].begin());
            edges[c][e] = edges[c][e];
        }
    }

    return 0;
}