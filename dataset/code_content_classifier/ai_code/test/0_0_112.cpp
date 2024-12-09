#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    int parent;
    char c;
    unordered_map<char, Node*> children;
    
    Node(int p, char c) : parent(p), c(c) {}
};

void addEdge(vector<Node*>& tree, int u, int v, char c) {
    if(tree[u] == nullptr) {
        tree[u] = new Node(-1, '\0');
    }
    
    if(tree[v] == nullptr) {
        tree[v] = new Node(u, c);
    } else {
        tree[v]->parent = u;
        tree[v]->c = c;
    }
    
    tree[u]->children[c] = tree[v];
}

void dfs(vector<Node*>& tree, int u, int v, string& curPath, vector<string>& paths) {
    if(u == v) {
        paths.push_back(curPath);
        return;
    }
    
    for(auto& [c, child] : tree[u]->children) {
        curPath.push_back(c);
        dfs(tree, child->parent, v, curPath, paths);
        curPath.pop_back();
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<Node*> tree(n);
    
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addEdge(tree, u - 1, v - 1, c);
    }
    
    vector<string> strings(m);
    for(int i = 0; i < m; i++) {
        cin >> strings[i];
    }
    
    for(int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--; v--;
        
        vector<string> paths;
        string curPath;
        dfs(tree, u, v, curPath, paths);
        
        int count = 0;
        for(int j = l - 1; j < r; j++) {
            for(auto& path : paths) {
                if(strings[j].find(path) != string::npos) {
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}