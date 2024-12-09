#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<int> subtreeSize;
vector<int> ans;

void dfs(int node, int parent) {
    subtreeSize[node] = 1;
    int totalPaths = 0;

    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            subtreeSize[node] += subtreeSize[child];
            totalPaths = max(totalPaths, subtreeSize[child]);
        }
    }

    totalPaths = max(totalPaths, (int)tree[node].size() - 1);
    
    ans[subtreeSize[node]] = max(ans[subtreeSize[node]], totalPaths + 1);
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    subtreeSize.resize(n + 1, 0);
    ans.resize(n + 1, 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}