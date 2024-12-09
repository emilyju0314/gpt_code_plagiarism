#include <iostream>
#include <vector>

using namespace std;

vector<int> apples;
vector<vector<int>> tree;
vector<int> totalWeight;

void dfs(int node) {
    // Base case: leaf node
    if (tree[node].size() == 0) {
        totalWeight[node] = apples[node];
        return;
    }
    
    int weight = 0;
    for (int child : tree[node]) {
        dfs(child);
        weight += totalWeight[child];
    }
    
    totalWeight[node] = weight;
}

int main() {
    int n;
    cin >> n;
    
    apples.resize(n);
    tree.resize(n);
    totalWeight.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        tree[x].push_back(y);
    }
    
    dfs(0);
    
    int applesToRemove = 0;
    for (int i = 0; i < n; i++) {
        if (totalWeight[i] % 2 != 0) {
            applesToRemove += 1;
        }
    }
    
    cout << applesToRemove << endl;
    
    return 0;
}