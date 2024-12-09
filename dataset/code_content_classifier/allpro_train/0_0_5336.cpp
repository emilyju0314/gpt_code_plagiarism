#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight, id;
};

vector<int> parent, size;

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (size[u] < size[v])
        swap(u, v);
    size[u] += size[v];
    parent[v] = u;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    parent.resize(n + 1);
    size.assign(n + 1, 1);
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].id = i;
    }
    
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    
    vector<int> ans(m);
    
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j] = j;
            size[j] = 1;
        }
        
        for (int j = 0; j < m; j++) {
            if (j == i)
                continue;
            if (find(edges[j].u) != find(edges[j].v))
                merge(edges[j].u, edges[j].v);
        }
        
        int root = find(1);
        bool is_critical = false;
        for (int j = 2; j <= n; j++) {
            if (find(j) != root) {
                is_critical = true;
                break;
            }
        }
        
        if (is_critical)
            ans[edges[i].id] = edges[i].weight;
        else
            ans[edges[i].id] = -1;
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}