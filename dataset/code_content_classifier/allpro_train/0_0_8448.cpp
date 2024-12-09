#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 300001;
vector<int> tree[MAXN];
int subtree_size[MAXN];
int centroids[MAXN];

void calculate_subtree_sizes(int node, int parent) {
    subtree_size[node] = 1;
    for (int child : tree[node]) {
        if (child != parent) {
            calculate_subtree_sizes(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

int find_centroid(int node, int parent, int total_size) {
    for (int child : tree[node]) {
        if (child != parent && subtree_size[child] > total_size / 2) {
            return find_centroid(child, node, total_size);
        }
    }
    return node;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
        tree[i].push_back(parent);
    }

    calculate_subtree_sizes(1, 0);

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << find_centroid(query, 0, subtree_size[query]) << endl;
    }

    return 0;
}