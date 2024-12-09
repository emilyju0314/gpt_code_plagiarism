#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
};

int diameter = 0;
TreeNode* farthestNode = nullptr;

void dfs(TreeNode* node, int depth, TreeNode* parent) {
    if (depth > diameter) {
        diameter = depth;
        farthestNode = node;
    }
    
    for (TreeNode* child : node->children) {
        if (child != parent) {
            dfs(child, depth + 1, node);
        }
    }
}

vector<int> findPair(TreeNode* node) {
    diameter = 0;
    farthestNode = nullptr;
    
    dfs(node, 0, nullptr);
    
    TreeNode* endpoint1 = farthestNode;
    
    diameter = 0;
    farthestNode = nullptr;
    
    dfs(endpoint1, 0, nullptr);
    
    TreeNode* endpoint2 = farthestNode;
    
    TreeNode* other1 = nullptr;
    int maxDepth = 0;
    
    for (TreeNode* child : node->children) {
        if (child != endpoint1 && child != endpoint2) {
            diameter = 0;
            farthestNode = nullptr;
            dfs(child, 0, nullptr);
            
            if (diameter > maxDepth) {
                maxDepth = diameter;
                other1 = farthestNode;
            }
        }
    }
    
    diameter = 0;
    farthestNode = nullptr;
    
    dfs(other1, 0, nullptr);
    
    TreeNode* other2 = farthestNode;
    
    return {endpoint1->val, endpoint2->val, other1->val, other2->val};
}

int main() {
    int n;
    cin >> n;
    
    vector<TreeNode*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode({ i });
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        
        nodes[u]->children.push_back(nodes[v]);
        nodes[v]->children.push_back(nodes[u]);
    }
    
    vector<int> pairs = findPair(nodes[1]);
    
    cout << pairs[0] << " " << pairs[2] << "\n";
    cout << pairs[1] << " " << pairs[3] << "\n";
    
    return 0;
}