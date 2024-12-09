#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> a;
int k;
vector<int> aliceWins;
vector<int> subtreeSum;

void dfs(int node, int parent) {
    subtreeSum[node] = a[node];
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            subtreeSum[node] += subtreeSum[child];
        }
    }
}

void solve(int node, int parent) {
    int count = 0;
    for (int child : tree[node]) {
        if (child != parent) {
            solve(child, node);
            count += aliceWins[child];
        }
    }

    if (subtreeSum[node] >= k && (subtreeSum[node] + count) % 2 == 1) {
          aliceWins[node] = 1;
    }
}

int main() {
    int n;
    cin >> n >> k;

    tree.resize(n);
    a.resize(n);
    subtreeSum.resize(n);
    aliceWins.resize(n, 0);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int root = 0; root < n; root++) {
        dfs(root, -1);
        solve(root, -1);
        cout << aliceWins[root] << " ";
    }

    cout << endl;

    return 0;
}