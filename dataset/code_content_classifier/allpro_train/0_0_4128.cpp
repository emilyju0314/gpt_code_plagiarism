#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> values;
vector<int> max_values;
vector<int> min_values;

void dfs(int node, int parent) {
    max_values[node] = values[node];
    min_values[node] = values[node];
    
    for(int child : tree[node]) {
        if(child != parent) {
            dfs(child, node);
            max_values[node] = max(max_values[node], max_values[child]);
            min_values[node] = min(min_values[node], min_values[child]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    values.resize(n);
    tree.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    max_values.resize(n);
    min_values.resize(n);
    
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    dfs(0, -1);
    
    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, abs(max_values[i] - values[i]));
        result = max(result, abs(min_values[i] - values[i]));
    }
    
    cout << result << endl;
    
    return 0;
}