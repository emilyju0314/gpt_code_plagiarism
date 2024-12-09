#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
    char label;
    int left, right;
};

vector<Node> tree;
string initialLabels;
int k;
set<char> duplicated;

string dfs(int u, bool parentDuplicated) {
    if (u == 0) return "";

    string left = dfs(tree[u].left, parentDuplicated || duplicated.count(tree[u].label) > 0);
    string current = string(1, tree[u].label) + (parentDuplicated ? tree[u].label : "");

    if (duplicated.count(tree[u].label) > 0) {
        duplicated.erase(tree[u].label);
        k++;
    }
    else if (k > 0) {
        k--;
        duplicated.insert(tree[u].label);
    }

    string right = dfs(tree[u].right, parentDuplicated || duplicated.count(tree[u].label) > 0);

    return left + current + right;
}

int main() {
    int n;
    cin >> n >> k;

    tree.resize(n + 1);
    cin >> initialLabels;

    for (int i = 1; i <= n; i++) {
        cin >> tree[i].left >> tree[i].right;
        tree[i].label = initialLabels[i-1];
    }

    cout << dfs(1, false) << endl;

    return 0;
}