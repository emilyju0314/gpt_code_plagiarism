#include <iostream>
#include <vector>

using namespace std;

int max_good_subtree_size(vector<vector<int>>& tree, int root, int& max_size) {
    int subtree_size = 1;
    int max_child_size = 0;

    for (int child : tree[root]) {
        if (child == root) continue;
        int child_size = max_good_subtree_size(tree, child, max_size);
        subtree_size += child_size;
        max_child_size = max(max_child_size, child_size);
    }

    max_size = max(max_size, subtree_size);

    return subtree_size;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<vector<int>> tree(n + 1);
        
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        int root = 1;
        int max_size = 0;
        max_good_subtree_size(tree, root, max_size);

        cout << max_size << endl;
    }

    return 0;
}