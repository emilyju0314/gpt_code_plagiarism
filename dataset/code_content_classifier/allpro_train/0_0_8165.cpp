#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Edge {
    int u, v;
    Edge(int u_, int v_) : u(u_), v(v_) {}
};

vector<int> permutation;
vector<int> colors;
vector<vector<int>> adj_list;
vector<set<int>> available_colors;

void dfs(int node, int color) {
    permutation.push_back(node);
    colors[node] = color;
    for (int neighbor : adj_list[node]) {
        if (colors[neighbor] == -1) {
            set<int>& neighbor_colors = available_colors[neighbor];
            neighbor_colors.erase(color);
            if (neighbor_colors.empty()) {
                cout << -1 << "\n";
                exit(0);
            }
            dfs(neighbor, *neighbor_colors.begin());
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        permutation.clear();
        colors.assign(1 << n, -1);
        adj_list.assign(1 << n, vector<int>());
        available_colors.assign(1 << n, set<int>());
        
        for (int i = 0; i < n * (1 << (n - 1)); i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        
        permutation.push_back(0);
        for (int neighbor : adj_list[0]) {
            available_colors[0].insert(neighbor);
        }
        
        dfs(0, 0);
        
        for (int node : permutation) {
            cout << node << " ";
        }
        cout << "\n";
        
        for (int color : colors) {
            cout << color << " ";
        }
        cout << "\n";
    }
    
    return 0;
}