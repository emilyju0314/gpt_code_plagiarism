#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    unordered_map<char, Node*> children;
};

int countNodes(Node* node) {
    int count = 1;
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        count += countNodes(it->second);
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges[n+1];
    for (int i = 0; i < n-1; i++) {
        int u, v;
        char x;
        cin >> u >> v >> x;
        edges[u].push_back({v, x});
    }

    Node* root = new Node();
    vector<pair<Node*, int>> queue = {{root, 1}};

    int maxSize = 0;

    // Build the broom
    while (!queue.empty()) {
        auto curr = queue.back();
        queue.pop_back();
        maxSize = max(maxSize, countNodes(curr.first));

        for (auto child : edges[curr.second]) {
            Node* newNode = new Node();
            curr.first->children[child.second] = newNode;
            queue.push_back({newNode, child.first});
        }
    }

    // Find the minimum size after simplification
    int minSize = INT_MAX;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        int currentSize = countNodes(root);
        if (currentSize < minSize) {
            minSize = currentSize;
            p = i;
        }
        if (edges[i].size() == 0) break;
        // Remove letter at position i from each word
        for (auto& child : edges[i]) {
            root->children.erase(child.second);
        }
    }

    cout << minSize << endl;
    cout << p << endl;

    return 0;
}