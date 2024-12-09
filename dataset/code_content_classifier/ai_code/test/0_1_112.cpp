#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    int val;
    char c;
    map<char, Node*> children;
};

void dfs(Node* node, int parent, vector<vector<pair<int, char>>>& adjList, vector<string>& strings, vector<vector<int>>& prefixSum) {
    for (auto& [child, c] : adjList[node->val]) {
        if (child == parent) continue;
        
        Node* newNode = new Node();
        newNode->val = child;
        newNode->c = c;
        node->children[c] = newNode;
        
        dfs(newNode, node->val, adjList, strings, prefixSum);
    }
    
    prefixSum[node->val] = vector<int>(26, 0);
    
    for (int i = 0; i < 26; i++) {
        if (node->children.count('a' + i)) {
            node->children['a' + i]->children.erase(node->c);
            prefixSum[node->val][i] = 1;
            for (int j = 0; j < 26; j++) {
                prefixSum[node->val][i] += prefixSum[node->val][j];
            }
        }
    }
}

int query(Node* node, const string& s, int index) {
    if (index == s.size()) {
        return 1;
    }
    
    char c = s[index];
    int res = 0;
    if (node->children.count(c)) {
        res += query(node->children[c], s, index+1);
    }
    
    return res;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<pair<int, char>> adjList(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--; v--;
        adjList[u].push_back({v, c});
        adjList[v].push_back({u, c});
    }
    
    vector<string> strings(m);
    for (int i = 0; i < m; i++) {
        cin >> strings[i];
    }
    
    vector<vector<int>> prefixSum(n);
    Node* root = new Node();
    root->val = 0;
    root->c = 'z'; // arbitrary value
    dfs(root, -1, adjList, strings, prefixSum);
    
    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--; v--;
        l--; r--;
        
        int result = 0;
        for (int j = l; j <= r; j++) {
            result += query(root, strings[j], 0);
        }
        
        cout << result << endl;
    }
    
    return 0;
}