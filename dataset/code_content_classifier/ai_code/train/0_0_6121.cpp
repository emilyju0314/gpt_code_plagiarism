#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, d;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].d;
    }

    int Tmax;
    cin >> Tmax;

    for (int t = 0; t < Tmax; t++) {
        int Nnew;
        cin >> Nnew;

        if (Nnew == 0) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < Nnew; i++) {
                int new_id, dst;
                cin >> new_id >> dst;

                vector<int> dist(V + 1, INT_MAX);
                vector<int> prev(V + 1, -1);

                dist[dst] = 0;
                queue<int> q;
                q.push(dst);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (Edge e : edges) {
                        int v = (u == e.u) ? e.v : e.u;
                        int d = e.d;
                        if (dist[v] > dist[u] + d) {
                            dist[v] = dist[u] + d;
                            prev[v] = u;
                            q.push(v);
                        }
                    }
                }

                int current = dst;
                while (prev[current] != -1) {
                    current = prev[current];
                    if (current == dst) {
                        cout << "-1\n";
                    } else {
                        cout << current << endl;
                    }
                }
            }
        }
    }

    return 0;
}