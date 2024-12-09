#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Data structure to represent a node in the tree
struct Node {
    int val;
    vector<Node*> children;
};

// DFS function to traverse the tree and calculate G(S) values
void dfs(Node* node, vector<int>& path, map<int, int>& freq, int y, int k, int x) {
    // Calculate the path value using the given formula
    int path_val = 0;
    for (int val : path) {
        path_val = (path_val * k + val) % y;
    }
    
    // Increment frequency of the path value
    freq[path_val]++;
    
    // Recursively traverse children nodes
    for (Node* child : node->children) {
        path.push_back(child->val);
        dfs(child, path, freq, y, k, x);
        path.pop_back();
    }
}

int main() {
    int n, y, k, x;
    cin >> n >> y >> k >> x;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node {values[i]};
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 0-indexed
        nodes[u]->children.push_back(nodes[v]);
    }
    
    map<int, int> freq;
    vector<int> path = {values[0]};
    dfs(nodes[0], path, freq, y, k, x);
    
    long long ans = 0;
    for (auto& [path_val, count] : freq) {
        ans += count * (count - 1) / 2;
    }
    
    cout << ans << endl;
    
    return 0;
}