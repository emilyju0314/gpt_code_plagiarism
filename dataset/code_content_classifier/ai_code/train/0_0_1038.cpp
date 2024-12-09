#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isAdjacent(int u, int v) {
        return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
    }

    int getMinColors() {
        vector<int> colors(V, -1);
        int maxColor = 0;

        for (int i = 0; i < V; i++) {
            vector<bool> available(V, true);

            for (int j : adj[i]) {
                if (colors[j] != -1) {
                    available[colors[j]] = false;
                }
            }

            int color;
            for (color = 0; color < V; color++) {
                if (available[color]) {
                    break;
                }
            }

            colors[i] = color;
            maxColor = max(maxColor, color);
        }

        return maxColor + 1;
    }
};

int main() {
    int n, m;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        Graph g(n);

        for (int i = 0; i < n; i++) {
            cin >> m;
            vector<pair<int, int>> points(m);
            for (int j = 0; j < m; j++) {
                cin >> points[j].first >> points[j].second;
            }

            for (int j = 0; j < m; j++) {
                int nextIndex = (j + 1) % m;
                for (int k = 0; k < n; k++) {
                    if (k == i) {
                        continue;
                    }
                    for (int l = 0; l < m; l++) {
                        int nextKIndex = (l + 1) % m;
                        if (points[j] == make_pair(points[l].first, points[l].second) &&
                            points[nextIndex] == make_pair(points[nextKIndex].first, points[nextKIndex].second)) {
                            g.addEdge(i, k);
                            break;
                        }
                    }
                }
            }
        }

        cout << g.getMinColors() << endl;
    }

    return 0;
}