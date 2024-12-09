#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int variable;
    Node* zero_edge;
    Node* one_edge;
};

Node* createNode(int variable) {
    Node* newNode = new Node();
    newNode->variable = variable;
    newNode->zero_edge = nullptr;
    newNode->one_edge = nullptr;
    return newNode;
}

void simplifyBDD(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->zero_edge == root->one_edge) {
        Node* nextNode = root->zero_edge;
        delete root;
        root = nextNode;
        simplifyBDD(root);
    } else {
        simplifyBDD(root->zero_edge);
        simplifyBDD(root->one_edge);
    }
}

int main() {
    int N;
    string bit_line;
    cin >> N >> bit_line;

    Node* root = createNode(N);

    vector<Node*> nodes;
    nodes.push_back(root);

    int index = 0;
    for (int i = N-1; i >= 0; i--) {
        vector<Node*> newNodes;
        for (Node* node : nodes) {
            node->zero_edge = createNode(i);
            if (bit_line[index] == '0') {
                node->one_edge = node->zero_edge;
            } else {
                node->one_edge = createNode(i);
            }
            newNodes.push_back(node->zero_edge);
            newNodes.push_back(node->one_edge);
            index++;
        }
        nodes = newNodes;
    }

    simplifyBDD(root);

    cout << nodes.size() << endl;

    return 0;
}