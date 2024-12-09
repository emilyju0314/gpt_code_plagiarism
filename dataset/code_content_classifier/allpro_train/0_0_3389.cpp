#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

struct Node {
    int value;
    std::vector<Node*> children;
};

void update(Node* node, int d) {
    node->value += d;
    for (Node* child : node->children) {
        update(child, d);
    }
}

int calculateExpectedValue(Node* node) {
    int sum = node->value;
    for (Node* child : node->children) {
        sum += calculateExpectedValue(child);
    }
    return sum;
}

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        nodes[u]->children.push_back(nodes[v]);
    }

    for (int i = 0; i < q; i++) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int v, d;
            std::cin >> v >> d;
            v--;
            update(nodes[v], d);
        } else if (type == 2) {
            int v;
            std::cin >> v;
            v--;
            int expectedValue = calculateExpectedValue(nodes[v]);
            std::cout << (expectedValue % MOD + MOD) % MOD << std::endl;
        }
    }

    return 0;
}