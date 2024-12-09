#include <iostream>
#include <vector>
#include <string>

struct Node {
    int id, parent, left, right;
    int depth, height;
};

int findHeight(std::vector<Node>& nodes, int node_id) {
    if (node_id == -1) return -1;

    int left_height = findHeight(nodes, nodes[node_id].left);
    int right_height = findHeight(nodes, nodes[node_id].right);

    nodes[node_id].height = std::max(left_height, right_height) + 1;

    return nodes[node_id].height;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Node> nodes(n);

    for (int i = 0; i < n; i++) {
        int id, left, right;
        std::cin >> id >> left >> right;

        nodes[id].id = id;
        nodes[id].left = left;
        nodes[id].right = right;

        if (left != -1) nodes[left].parent = id;
        if (right != -1) nodes[right].parent = id;
    }

    for (int i = 0; i < n; i++) {
        nodes[i].height = findHeight(nodes, i);
    }

    for (int i = 0; i < n; i++) {
        std::string node_type;

        if (nodes[i].parent == -1) {
            node_type = "root";
        } else if (nodes[i].left != -1 || nodes[i].right != -1) {
            node_type = "internal node";
        } else {
            node_type = "leaf";
        }

        int sibling = (nodes[nodes[i].parent].left == i) ? nodes[nodes[i].parent].right : nodes[nodes[i].parent].left;
        if (nodes[i].parent == -1) {
            sibling = -1;
        }

        std::cout << "node " << i << ": parent = " << nodes[i].parent << ", sibling = " << sibling
                  << ", degree = " << (nodes[i].left != -1) + (nodes[i].right != -1)
                  << ", depth = " << nodes[i].depth << ", height = " << nodes[i].height
                  << ", " << node_type << "\n";
    }

    return 0;
}