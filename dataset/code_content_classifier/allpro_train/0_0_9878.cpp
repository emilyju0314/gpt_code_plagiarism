#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    string type;
    vector<int> inputs;

    Node(string t) : type(t) {}
};

unordered_map<int, Node*> graph;
unordered_map<int, int> values;
unordered_map<int, int> output;

int evaluate(int idx) {
    if (graph[idx]->type == "IN") {
        return values[idx];
    }

    int res;
    if (graph[idx]->type == "AND") {
        res = evaluate(graph[idx]->inputs[0]) & evaluate(graph[idx]->inputs[1]);
    } else if (graph[idx]->type == "OR") {
        res = evaluate(graph[idx]->inputs[0]) | evaluate(graph[idx]->inputs[1]);
    } else if (graph[idx]->type == "XOR") {
        res = evaluate(graph[idx]->inputs[0]) ^ evaluate(graph[idx]->inputs[1]);
    } else { // NOT
        res = !evaluate(graph[idx]->inputs[0]);
    }

    return res;
}

void dfs(int idx) {
    for (int i : graph[idx]->inputs) {
        if (graph[i]->type == "IN") {
            int original = values[i];
            values[i] = 1 - original; // change value
            output[i] = evaluate(1); // re-evaluate output
            values[i] = original; // revert back to original value
        } else {
            dfs(i);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string type;
        cin >> type;

        Node* node = new Node(type);
        if (type == "IN") {
            int value;
            cin >> value;
            values[i] = value;
        } else {
            int input1, input2;
            cin >> input1;
            cin >> input2;
            node->inputs = {input1, input2};
        }

        graph[i] = node;
    }

    dfs(1);

    for (int i = 2; i <= n; ++i) {
        if (graph[i]->type == "IN") {
            cout << output[i];
        }
    }

    cout << endl;

    return 0;
}