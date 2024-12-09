#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    int leftChildIndex;
    int rightChildIndex;
};

int calculateFailures(vector<TreeNode>& tree, int currentIndex, int x) {
    if(currentIndex == -1) {
        return 1;
    }

    if(tree[currentIndex].value == x) {
        return 0;
    }

    if(x < tree[currentIndex].value) {
        return calculateFailures(tree, tree[currentIndex].leftChildIndex, x);
    } else {
        return calculateFailures(tree, tree[currentIndex].rightChildIndex, x);
    }
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode> tree(n);

    for(int i = 0; i < n; i++) {
        cin >> tree[i].value >> tree[i].leftChildIndex >> tree[i].rightChildIndex;
    }

    int totalFailures = 0;

    for(int i = 0; i < n; i++) {
        totalFailures += calculateFailures(tree, 0, tree[i].value);
    }

    cout << totalFailures << endl;

    return 0;
}