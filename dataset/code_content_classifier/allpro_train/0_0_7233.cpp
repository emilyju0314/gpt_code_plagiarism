#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
    int value;
    vector<pair<int, int>> edges;
};

vector<Vertex> tree;
vector<int> a;
int removed_leaves = 0;

int dfs(int v, int parent_distance) {
    int distance = a[v];
    for (auto edge : tree[v].edges) {
        int u = edge.first;
        int edge_weight = edge.second;
        distance = max(distance, a[v] + dfs(u, parent_distance + edge_weight));
    }
    
    if (distance > parent_distance) {
        removed_leaves++;
        return 0;
    }
    return distance;
}

int main() {
    int n;
    cin >> n;
    
    tree.resize(n);
    a.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        tree[p - 1].edges.push_back({i + 1, c});
    }
    
    dfs(0, 0);
    
    cout << removed_leaves << endl;
    
    return 0;
}