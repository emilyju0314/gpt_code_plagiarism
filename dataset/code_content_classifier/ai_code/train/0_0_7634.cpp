#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    string operation;
    int resistance;
    Node* left;
    Node* right;

    Node(string op) : operation(op), left(nullptr), right(nullptr) {}
    Node(string op, int res) : operation(op), resistance(res), left(nullptr), right(nullptr) {}
};

bool assignResistance(Node* node, int target_resistance) {
    if (node->operation == "*") {
        node->resistance = target_resistance;
        return true;
    }

    if (node->operation == "S") {
        // Joining circuits in series
        for (Node* child : {node->left, node->right}) {
            if (!assignResistance(child, target_resistance))
                return false;
            target_resistance -= child->resistance;
        }
        return true;
    }

    if (node->operation == "P") {
        // Joining circuits in parallel
        int total_resistance = 0;
        for (Node* child : {node->left, node->right}) {
            if (!assignResistance(child, 1))
                return false;
            total_resistance += 1 / child->resistance;
        }
        node->resistance = 1 / total_resistance;
        return true;
    }

    return false;
}

void parseAndAssignResistances(string input) {
    stringstream ss(input);
    string operation;
    int target_resistance;

    ss >> target_resistance >> operation;

    Node* root = new Node(operation);

    if (assignResistance(root, target_resistance)) {
        cout << "REVOLTING";
        vector<int> resistances;
        // In-order traversal to print the resistances
        function<void(Node*)> inorder = [&](Node* node){
            if (!node)
                return;
            inorder(node->left);
            if (node->operation == "*")
                resistances.push_back(node->resistance);
            inorder(node->right);
        };
        inorder(root);
        
        for (int res : resistances) {
            cout << " " << res;
        }
        cout << endl;
    } else {
        cout << "LOSS" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string input;
        getline(cin, input);
        parseAndAssignResistances(input);
    }

    return 0;
}