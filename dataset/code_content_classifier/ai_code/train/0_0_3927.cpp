#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[701];
int subtree_size[701];

void dfs(int node, int parent) {
    subtree_size[node] = 1;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    long long max_product = 0;
    for (int i = 1; i <= n; i++) {
        for (int child : tree[i]) {
            max_product = max(max_product, (long long)subtree_size[child] * (n - subtree_size[child]));
        }
    }

    cout << max_product << endl;

    return 0;
}