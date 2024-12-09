#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    vector<Node*> children;
};

void dfs(Node* node, vector<int>& path, map<int, int>& count) {
    path.push_back(node->value);
    count[node->value]++;
    for (Node* child : node->children) {
        dfs(child, path, count);
    }
}

void processQuestion(Node* node, int v, int l, int k) {
    vector<int> path;
    map<int, int> count;
    dfs(node, path, count);
    
    // Count the number of occurrences of each integer
    vector<int> sequence;
    for (auto& [value, freq] : count) {
        if (freq >= l) sequence.push_back(value);
    }
    
    // Sort the sequence based on the number of occurrences
    sort(sequence.begin(), sequence.end(), [&count](int a, int b) {
        return count[a] < count[b];
    });
    
    // Output the answer for the question
    if (sequence.size() >= k) cout << sequence[k - 1] << " ";
    else cout << -1 << " ";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> values(n);
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        
        vector<int> parent(n);
        for (int i = 1; i < n; i++) {
            cin >> parent[i];
        }
        
        vector<Node*> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node{values[i], {}};
        }
        
        for (int i = 1; i < n; i++) {
            nodes[parent[i] - 1]->children.push_back(nodes[i]);
        }
        
        for (int i = 0; i < q; i++) {
            int v, l, k;
            cin >> v >> l >> k;
            processQuestion(nodes[0], v, l, k);
        }
        
        cout << endl;
    }
    
    return 0;
}