#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int left, right;
    char label;
};

vector<Node> tree;
string labels, result;
int duplicatesLeft;

void dfs(int node) {
    if (node == 0) return;

    dfs(tree[node].left);
    result += tree[node].label;
    dfs(tree[node].right);
}

void duplicateLabels(int node, char parentLabelDoubled) {
    if (node == 0) return;

    if (tree[node].label < parentLabelDoubled) {
        if (duplicatesLeft > 0) {
            tree[node].label += tree[node].label;
            duplicatesLeft--;
        }
    }
    
    parentLabelDoubled = max(parentLabelDoubled, tree[node].label);

    duplicateLabels(tree[node].left, parentLabelDoubled);
    duplicateLabels(tree[node].right, parentLabelDoubled);
}

int main() {
    int n, k;
    cin >> n >> k;

    tree.resize(n+1);
    
    cin >> labels;

    for (int i = 1; i <= n; i++) {
        tree[i].label = labels[i-1];
        cin >> tree[i].left >> tree[i].right;
    }

    duplicatesLeft = k;
    duplicateLabels(1, 'a');

    dfs(1);

    cout << result << endl;

    return 0;
}