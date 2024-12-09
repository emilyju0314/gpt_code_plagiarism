#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;
};

int findRoot(vector<int>& parent, int u) {
    if (parent[u] == u) return u;
    return parent[u] = findRoot(parent, parent[u]);
}

int minCostArborescence(int V, int E, vector<Edge>& edges, int root) {
    vector<int> parent(V), in(V, -1), visited(V, -1);
    int res = 0;
    
    while (true) {
        vector<int> inEdge(E, -1), minWeightEdge(V, INT_MAX);
        
        for (int i = 0; i < E; i++) {
            Edge& e = edges[i];
            if (e.to == root || e.from == e.to) continue;
            if (e.weight < minWeightEdge[e.to]) {
                minWeightEdge[e.to] = e.weight;
                inEdge[e.to] = i;
            }
        }
        
        in[root] = root;
        parent[root] = root;
        
        for (int v = 0; v < V; v++) {
            if (v == root) continue;
            if (minWeightEdge[v] == INT_MAX) return -1;
            res += minWeightEdge[v];
            
            int last = v;
            while (visited[last] != v && parent[last] == -1 && last != root) {
                visited[last] = v;
                last = edges[inEdge[last]].from;
            }
            
            if (last != root && parent[last] == -1) {
                for (int u = edges[inEdge[last]].from; u != last; u = edges[inEdge[u]].from) {
                    parent[u] = last;
                }
                parent[last] = last;
            }
        }
        
        if (findRoot(parent, 0) == findRoot(parent, root)) break;
        
        for (int i = 0; i < V; i++) {
            if (parent[i] == -1) parent[i] = root;
        }
        
        vector<int> nextId(V, 0);
        for (int i = 0; i < E; i++) {
            Edge& e = edges[i];
            e.from = findRoot(parent, e.from);
            e.to = findRoot(parent, e.to);
            if (e.from != e.to && e.weight == minWeightEdge[e.to]) {
                e.from = e.to;
                e.weight = 0;
            }
        }
    }
    
    return res;
}

int main() {
    int V, E, root;
    cin >> V >> E >> root;
    
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    
    int result = minCostArborescence(V, E, edges, root);
    cout << result << endl;
    
    return 0;
}