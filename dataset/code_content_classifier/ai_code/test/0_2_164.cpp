#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    char label;
    vector<int> children;
};

vector<Node> tree;
vector<char> newLabels;

void dfs(int node, int parent, int& k) {
    newLabels[node] = tree[node].label;

    for (int child : tree[node].children) {
        if (child != parent) {
            dfs(child, node, k);
            newLabels[node] = min(newLabels[node], newLabels[child]);

            if (newLabels[child] < newLabels[node] && k > 0) {
                newLabels[node] = newLabels[child];
                k--;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    tree.resize(n + 1);
    newLabels.resize(n + 1);

    string initialLabels;
    cin >> initialLabels;

    for (int i = 1; i <= n; i++) {
        tree[i].label = initialLabels[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        int leftChild, rightChild;
        cin >> leftChild >> rightChild;
        if (leftChild != 0) {
            tree[i].children.push_back(leftChild);
            tree[leftChild].children.push_back(i);
        }
        if (rightChild != 0) {
            tree[i].children.push_back(rightChild);
            tree[rightChild].children.push_back(i);
        }
    }

    dfs(1, 0, k);

    for (int i = 1; i <= n; i++) {
        cout << newLabels[i];
    }
    cout << endl;

    return 0;
}