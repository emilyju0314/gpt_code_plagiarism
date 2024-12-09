#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> colors;
vector<vector<int>> adj_list;

int find_root(int v, int parent) {
    int root = v;
    for (int i = 0; i < adj_list[v].size(); i++) {
        int u = adj_list[v][i];
        if (u != parent) {
            int child_root = find_root(u, v);
            if (colors[child_root] != colors[v]) {
                root = child_root;
            }
        }
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    
    adj_list.resize(n+1);
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    colors.resize(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }
    
    int root = find_root(1, 0);
    
    set<int> unique_colors;
    for (int i = 0; i < adj_list[root].size(); i++) {
        int child_color = colors[adj_list[root][i]];
        unique_colors.insert(child_color);
    }
    
    if (unique_colors.size() <= 1) {
        cout << "YES" << endl;
        cout << root << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}