#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> subtree_size;

void calculate_subtree_size(int u, int parent) {
    subtree_size[u] = 1;
    for (int v : tree[u]) {
        if (v != parent) {
            calculate_subtree_size(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

int process_query(int v, int k, int parent) {
    int max_score = max(0, subtree_size[v] - 1 - k);
    for (int u : tree[v]) {
        if (u != parent) {
            max_score = max(max_score, process_query(u, k + 1, v));
        }
    }
    return max_score;
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    subtree_size.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    calculate_subtree_size(1, 0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        cout << process_query(v, k, 0) << endl;
    }

    return 0;
}