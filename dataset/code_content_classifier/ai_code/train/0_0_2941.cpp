#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    int parent;
    vector<int> children;
    int depth;
};

void dfs(vector<Node>& tree, int node_id, int depth) {
    tree[node_id].depth = depth;
    
    for (int child_id : tree[node_id].children) {
        dfs(tree, child_id, depth + 1);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<Node> tree(n);
    
    for (int i = 0; i < n; ++i) {
        int id, degree;
        cin >> id >> degree;
        
        tree[id].id = id;
        
        if (degree == 0) {
            tree[id].parent = -1;
        } else {
            int child;
            for (int j = 0; j < degree; ++j) {
                cin >> child;
                tree[id].children.push_back(child);
                tree[child].parent = id;
            }
        }
    }
    
    dfs(tree, 0, 0);
    
    for (Node& node : tree) {
        cout << "node " << node.id << ": parent = " << node.parent;
        cout << ", depth = " << node.depth;
        
        if (node.parent == -1) {
            cout << ", root, [";
        } else if (node.children.size() == 0) {
            cout << ", leaf, [";
        } else {
            cout << ", internal node, [";
        }
        
        for (int child : node.children) {
            cout << child << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}