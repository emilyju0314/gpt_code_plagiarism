#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int brightness;
    vector<Node*> children;
};

void updateBrightness(Node* root, int x, int y) {
    root->brightness = y;
    for (Node* child : root->children) {
        updateBrightness(child, x, y);
    }
}

int countBrightness(Node* root, int x, int y) {
    int count = (root->brightness >= x && root->brightness <= y) ? 1 : 0;
    for (Node* child : root->children) {
        count += countBrightness(child, x, y);
    }
    return count;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<Node> nodes(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u].children.push_back(&nodes[v]);
    }

    for (int i = 0; i < q; i++) {
        int t, r, x, y;
        cin >> t >> r >> x >> y;
        if (t == 1) {
            cout << countBrightness(&nodes[r], x, y) << endl;
        } else if (t == 2) {
            updateBrightness(&nodes[r], x, y);
        }
    }

    return 0;
}