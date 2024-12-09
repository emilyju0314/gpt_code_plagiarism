#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    vector<Node*> children;
    int weight;
};

vector<Node> tree;

void add(int v, int w) {
    Node* node = &tree[v];
    while (node != nullptr) {
        node->weight += w;
        node = node->parent;
    }
}

int getSum(int u) {
    int sum = 0;
    Node* node = &tree[u];
    while (node != nullptr) {
        sum += node->weight;
        node = node->parent;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        tree[i].id = i;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            tree[i].children.push_back(&tree[child]);
            tree[child].parent = &tree[i];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int v, w;
            cin >> v >> w;
            add(v, w);
        } else if (type == 1) {
            int u;
            cin >> u;
            cout << getSum(u) << endl;
        }
    }

    return 0;
}