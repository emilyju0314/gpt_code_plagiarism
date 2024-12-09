#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9+7;

struct Edge {
    int to, weight;
};

int main() {
    int n, m, T;
    cin >> n >> m >> T;

    vector<vector<Edge>> graph(n+1);
    vector<int> dist(n+1, INF);
    vector<int> parent(n+1, -1);

    for (int i = 1; i <= m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Edge e : graph[u]) {
            int v = e.to;
            int weight = e.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    int u = n;
    int count = 0;
    vector<int> path;
    while (u != -1 && dist[u] <= T) {
        count++;
        path.push_back(u);
        u = parent[u];
    }
    
    reverse(path.begin(), path.end());
    
    cout << count << endl;
    for (int v : path) {
        cout << v << " ";
    }

    return 0;
}