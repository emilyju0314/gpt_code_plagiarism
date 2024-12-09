#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& values, int node) {
    if (values[node] != -1) {
        return values[node];
    }
    
    int leftChild = tree[node][1];
    int rightChild = tree[node][2];
    
    int leftValue = dfs(tree, values, leftChild);
    int rightValue = dfs(tree, values, rightChild);
    
    return values[node] = max(leftValue, rightValue);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> tree(n, vector<int>(3)); // value, left child, right child
        vector<int> values(n, 0);
        
        for (int i = 0; i < n; i++) {
            int value, leftChild, rightChild;
            cin >> value >> leftChild >> rightChild;
            tree[i][0] = value;
            tree[i][1] = leftChild;
            tree[i][2] = rightChild;
        }
        
        cout << dfs(tree, values, 0) << endl;
    }
    
    return 0;
}