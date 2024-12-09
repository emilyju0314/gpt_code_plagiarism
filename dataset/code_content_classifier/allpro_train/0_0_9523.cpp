#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9
#define EPS 1e-9

struct Edge {
    int from, to, capacity, flow;
};

int n, m;
vector<vector<int>> adj;
vector<Edge> edges;
vector<int> parent;

double fordFulkerson(int source, int sink) {
    double maxFlow = 0;
    
    while (true) {
        parent.assign(n, -1);
        parent[source] = -2;
        queue<int> q;
        q.push(source);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int i : adj[u]) {
                Edge& e = edges[i];
                if (parent[e.to] == -1 && e.capacity - e.flow > 0) {
                    parent[e.to] = i;
                    q.push(e.to);
                }
            }
        }
        
        if (parent[sink] == -1) {
            break;
        }
        
        double minFlow = INF;
        for (int u = sink; u != source; u = edges[parent[u]].from) {
            minFlow = min(minFlow, (double)(edges[parent[u]].capacity - edges[parent[u]].flow));
        }
        
        for (int u = sink; u != source; u = edges[parent[u]].from) {
            edges[parent[u]].flow += minFlow;
            edges[parent[u] ^ 1].flow -= minFlow;
        }
        
        maxFlow += minFlow;
    }
    
    return maxFlow;
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        
        int source = 0, sink = n - 1;
        adj.assign(n, vector<int>());
        edges.clear();
        
        for (int i = 0; i < m; i++) {
            int vertices;
            cin >> vertices;
            
            for (int j = 0; j < vertices; j++) {
                int x, y;
                cin >> x >> y;
                
                adj[x].push_back(edges.size());
                edges.push_back({x, y, 1, 0});
                adj[y].push_back(edges.size());
                edges.push_back({y, x, 0, 0});
            }
        }
        
        double flow = fordFulkerson(source, sink);
        cout << fixed << flow << endl;
    }
    
    return 0;
}