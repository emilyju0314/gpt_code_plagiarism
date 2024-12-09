#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> start_time;
vector<int> child_count;

void dfs(int v) {
    static int current_time = 0;
    current_time++;
    start_time[v] = current_time;
    
    for(int u : tree[v]) {
        dfs(u);
        child_count[v] += child_count[u] + 1;
    }
    
    random_shuffle(tree[v].begin(), tree[v].end());
}

int main() {
    int n;
    cin >> n;
    
    tree.resize(n);
    start_time.resize(n);
    child_count.resize(n, 0);
    
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        tree[p-1].push_back(i);
    }
    
    dfs(0);
    
    for(int i = 0; i < n; i++) {
        cout << start_time[i] + child_count[i] << " ";
    }
    
    return 0;
}