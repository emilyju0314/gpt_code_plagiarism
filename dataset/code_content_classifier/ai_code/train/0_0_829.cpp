#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> adj[100005];
vector<int> subtreeTypes[100005];
map<vector<int>, int> subtreeTypeToCount;
int maxCount = 0, maxVertex = -1;

vector<int> dfs(int u, int parent) {
    vector<int> subtree;
    for (int v : adj[u]) {
        if (v != parent) {
            vector<int> childSubtree = dfs(v, u);
            subtree.push_back(childSubtree.size());
            subtree.insert(subtree.end(), childSubtree.begin(), childSubtree.end());
        }
    }
    sort(subtree.begin(), subtree.end());
    subtreeTypes[u] = subtree;
    subtreeTypeToCount[subtree]++;
    if (subtreeTypeToCount[subtree] > maxCount) {
        maxCount = subtreeTypeToCount[subtree];
        maxVertex = u;
    }
    return subtree;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    cout << maxVertex << endl;
    
    return 0;
}