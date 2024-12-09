#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> tree[n+1]; // Adjacency list to represent the tree
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    vector<int> leaves(n+1, 0); // To store the number of leaf nodes in each subtree
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (tree[curr].empty()) {
            leaves[curr] = 1;
        }

        for (int child : tree[curr]) {
            q.push(child);
            leaves[curr] += leaves[child];
        }
    }

    vector<int> ans(n+1, 0); // To store the answer

    for (int i = 1; i <= n; i++) {
        ans[i] = i - leaves[1] + 1; // Minimum number of different colors needed
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}