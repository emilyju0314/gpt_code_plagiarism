#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    unordered_map<int, int> degree;
    vector<pair<int, int>> remaining_edges;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        degree[u]++;
        degree[v]++;
    }

    int remaining_count = (n + m + 1) / 2;
    
    for(const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        
        if(degree[u] <= degree[v] * 2 && degree[v] <= degree[u] * 2) {
            remaining_edges.push_back({u, v});
            degree[u]--;
            degree[v]--;
            remaining_count--;
        }
    }

    cout << remaining_count << endl;
    for(const auto& edge : remaining_edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}