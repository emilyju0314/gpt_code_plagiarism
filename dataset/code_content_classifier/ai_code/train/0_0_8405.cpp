#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Node {
    string type;
    vector<int> inputs;
    int value = -1;
};

void evaluate(vector<Node>& nodes, int idx) {
    Node& current = nodes[idx];

    if (current.value != -1) {
        return;
    }

    for (int input : current.inputs) {
        evaluate(nodes, input);
    }

    if (current.type == "AND") {
        current.value = nodes[current.inputs[0]].value & nodes[current.inputs[1]].value;
    } else if (current.type == "OR") {
        current.value = nodes[current.inputs[0]].value | nodes[current.inputs[1]].value;
    } else if (current.type == "XOR") {
        current.value = nodes[current.inputs[0]].value ^ nodes[current.inputs[1]].value;
    } else if (current.type == "NOT") {
        current.value = !nodes[current.inputs[0]].value;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Node> nodes(n + 1);

    for (int i = 1; i <= n; i++) {
        string type;
        cin >> type;
        
        if (type == "IN") {
            int value;
            cin >> value;
            nodes[i].type = "IN";
            nodes[i].value = value;
        } else {
            int input1, input2;
            cin >> input1;
            if (type != "NOT") {
                cin >> input2;
            }

            nodes[i].type = type;
            nodes[i].inputs.push_back(input1);
            if (type != "NOT") {
                nodes[i].inputs.push_back(input2);
            }
        }
    }

    evaluate(nodes, 1);

    map<int, int> original_output;
    for (int i = 2; i <= n; i++) {
        original_output[i] = nodes[1].value;

        if (nodes[i].type == "IN") {
            nodes[1].value = nodes[1].value ^ 1;
        } else {
            nodes[i].value = nodes[i].value ^ 1;
            evaluate(nodes, 1);
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << original_output[i];
    }
    cout << endl;

    return 0;
}