#include <iostream>
#include <vector>

using namespace std;

vector<int> colors;
vector<vector<int>> tree;
int countBlack = 0;
int countWhite = 0;

void dfs(int node, int parentColor) {
    if (parentColor != colors[node]) {
        if (colors[node] == 1) {
            countBlack++;
        } else {
            countWhite++;
        }
    }
    
    for (int child : tree[node]) {
        if (child != parentColor) {
            dfs(child, colors[node]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    colors.resize(n);
    tree.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(0, -1); // Start the DFS from the root vertex
    
    cout << min(countBlack, countWhite) << endl;
    
    return 0;
}