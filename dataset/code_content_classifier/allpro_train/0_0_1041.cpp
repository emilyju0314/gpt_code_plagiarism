#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int weight;
    vector<int> children;
};

vector<Node> tree;
vector<int> subtree_weight;

void calculate_subtree_weight(int node, int parent) {
    subtree_weight[node] = tree[node].weight;
    for (int child : tree[node].children) {
        if (child != parent) {
            calculate_subtree_weight(child, node);
            subtree_weight[node] += subtree_weight[child];
        }
    }
}

int find_max_weight_connected_component(int node, int parent, int a, int b) {
    int max_weight = 0;
    for (int child : tree[node].children) {
        if (child != parent) {
            int weight = find_max_weight_connected_component(child, node, a, b);
            max_weight = max(max_weight, weight);
        }
    }

    if ((node == a && parent == b) || (node == b && parent == a)) {
        return 0;
    }

    max_weight = max(max_weight, subtree_weight[node]);
    return max_weight;
}

int main() {
    int N;
    cin >> N;

    tree.resize(N);
    subtree_weight.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> tree[i].weight;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; // Convert to 0-based indexing
        v--;
        tree[u].children.push_back(v);
        tree[v].children.push_back(u);
    }

    calculate_subtree_weight(0, -1);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << find_max_weight_connected_component(0, -1, a, b) << endl;
    }

    return 0;
}