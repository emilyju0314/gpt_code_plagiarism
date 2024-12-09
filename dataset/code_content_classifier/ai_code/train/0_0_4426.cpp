#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node* parent;
    vector<Node*> children;
    char character;
    int letterCount[26] = {0};
};

void computeAnagramnity(Node* node, int depth) {
    for (Node* child : node->children) {
        for (int i = 0; i < 26; i++) {
            child->letterCount[i] += node->letterCount[i];
        }
        if (child->character != '?') {
            child->letterCount[child->character - 'a']++;
        }
        computeAnagramnity(child, depth + 1);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<Node*> nodes(n);
    nodes[0] = new Node{nullptr, vector<Node*>(), '?'};

    for (int i = 1; i < n; i++) {
        int parentIndex;
        char character;
        cin >> parentIndex >> character;
        parentIndex--;
        Node* parent = nodes[parentIndex];
        Node* newNode = new Node{parent, vector<Node*>(), character};
        nodes[i] = newNode;
        parent->children.push_back(newNode);
    }

    computeAnagramnity(nodes[0], 0);

    while (q--) {
        int v;
        char c;
        cin >> v >> c;
        v--;
        nodes[v]->character = c;
        computeAnagramnity(nodes[0], 0);

        // Check anagrammability and compute result
        bool anagrammable = true;
        int result = 0;
        for (int i = 0; i < 26; i++) {
            int maxLetterCount = 0;
            for (Node* leaf : nodes) {
                if (leaf->children.empty()) {
                    maxLetterCount = max(maxLetterCount, leaf->letterCount[i]);
                }
            }
            if (maxLetterCount > 1) {
                anagrammable = false;
                break;
            }
            result += maxLetterCount * (i + 1);
        }

        if (anagrammable) {
            cout << "Shi " << result << endl;
        } else {
            cout << "Fou" << endl;
        }
    }

    return 0;
}