#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> values;
vector<bool> visited;

bool dfs(int node, int parent, int target, int add) {
    if (node == target) {
        values[node] += add;
        return true;
    }
    
    visited[node] = true;
    
    for (int child : tree[node]) {
        if (!visited[child] && dfs(child, node, target, add)) {
            values[node] += add;
            return true;
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    tree.resize(n);
    values.resize(n);
    visited.assign(n, false);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        
        u--; v--;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
        values[u] = values[v] = val;
    }
    
    bool possible = true;
    vector<pair<pair<int, int>, int>> operations;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (values[i] + values[j] > 0 && (values[i] + values[j]) % 2 == 0) {
                int add = (values[i] + values[j]) / 2;
                
                if (dfs(i, -1, j, add)) {
                    operations.push_back({{i, j}, add});
                } else if (dfs(j, -1, i, add)) {
                    operations.push_back({{j, i}, add});
                } else {
                    possible = false;
                    break;
                }
            }
        }
    }
    
    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << operations.size() << endl;
        
        for (auto op : operations) {
            cout << op.first.first + 1 << " " << op.first.second + 1 << " " << op.second << endl;
        }
    }
    
    return 0;
}