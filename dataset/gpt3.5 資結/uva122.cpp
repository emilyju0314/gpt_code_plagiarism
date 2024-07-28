#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

int main() {
    string input;
    while (getline(cin, input)) {
        if (input == "()") {
            map<string, int> pathCost;
            bool isValid = true;
            queue<Node*> nodes;
            Node* root = new Node(-1);
            nodes.push(root);

            while (getline(cin, input)) {
                if (input == "()") {
                    break;
                }

                stringstream ss(input);
                string path, valueStr;
                ss >> path >> valueStr;
                path = path.substr(1, path.size() - 2);
                int value = stoi(valueStr);

                Node* curr = root;
                bool validPath = true;
                string direction;

                for (int i = 0; i < path.size(); i++) {
                    if (path[i] == 'L') {
                        direction += "L";
                        if (curr->left == nullptr) {
                            validPath = false;
                            Node* newNode = new Node(-1);
                            curr->left = newNode;
                        }
                        curr = curr->left;
                    }
                    else if (path[i] == 'R') {
                        direction += "R";
                        if (curr->right == nullptr) {
                            validPath = false;
                            Node* newNode = new Node(-1);
                            curr->right = newNode;
                        }
                        curr = curr->right;
                    }
                }

                if (!validPath || pathCost.count(direction) > 0) {
                    isValid = false;
                }

                pathCost[direction] = value;
            }

            if (!isValid) {
                cout << "not complete" << endl;
            }
            else {
                queue<Node*> q;
                q.push(root);

                while (!q.empty()) {
                    Node* curr = q.front();
                    q.pop();

                    if (curr == nullptr) {
                        isValid = false;
                        break;
                    }

                    if (curr->value == -1) {
                        isValid = false;
                        break;
                    }

                    if (curr->left != nullptr) {
                        q.push(curr->left);
                    }
                    if (curr->right != nullptr) {
                        q.push(curr->right);
                    }
                }

                if (!isValid) {
                    cout << "not complete" << endl;
                }
                else {
                    queue<Node*> traversal;
                    traversal.push(root);

                    while (!traversal.empty()) {
                        Node* curr = traversal.front();
                        traversal.pop();

                        if (curr->value != -1) {
                            cout << curr->value;
                        }
                        else {
                            cout << curr->value;
                        }

                        if (curr->left != nullptr) {
                            traversal.push(curr->left);
                        }
                        if (curr->right != nullptr) {
                            traversal.push(curr->right);
                        }

                        if (!traversal.empty()) {
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}