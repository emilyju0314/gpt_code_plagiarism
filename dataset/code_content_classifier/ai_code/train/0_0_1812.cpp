#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
    int y, size;
    vector<int> labels;
    vector<Node*> children;
    Node* parent;

    Node(int y, int size, vector<int>& labels) : y(y), size(size), labels(labels) {}
};

Node* buildDiagram(int N, int M) {
    map<int, vector<Node*>> nodes;
    Node* startNode = new Node(0, 1, vector<int>{1});
    nodes[0].push_back(startNode);

    for (int i = 0; i < M; i++) {
        int y, L;
        cin >> y >> L;
        vector<int> labels(L);
        for (int j = 0; j < L; j++) {
            cin >> labels[j];
        }
        Node* newNode = new Node(y, L, labels);
        for (int label : labels) {
            for (Node* node : nodes[label]) {
                node->children.push_back(newNode);
                newNode->parent = node;
            }
            nodes[label].push_back(newNode);
        }
    }

    return startNode;
}

void performQueries(Node* startNode, int Q) {
    for (int i = 0; i < Q; i++) {
        int position;
        cin >> position;
        queue<Node*> q;
        q.push(startNode);
        Node* result = nullptr;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            for (Node* child : node->children) {
                if (child->y > node->y && child->size > 1) {
                    int label = child->labels[position - 1];
                    if (child->parent->size == 1 || child->parent->labels[position - 1] == label) {
                        q.push(child);
                    }
                } else {
                    result = child;
                    break;
                }
            }
            if (result != nullptr) {
                break;
            }
        }
        cout << result->labels[position - 1] << endl;
    }
}

int main() {
    int N, M, Q;
    while (cin >> N >> M >> Q && N != 0) {
        Node* startNode = buildDiagram(N, M);
        performQueries(startNode, Q);
        cout << endl;
    }

    return 0;
}