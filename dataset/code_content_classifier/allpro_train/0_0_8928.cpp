#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2 * 1e5 + 5;

vector<int> adj[MAX];
vector<int> weight(MAX);

int subtreeSize[MAX];
int ans[MAX];
int fenwick[MAX];
int queries[MAX];

void update(int idx, int val) {
    while (idx < MAX) {
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += fenwick[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void dfs(int u, int parent) {
    subtreeSize[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}

int centroid(int u, int parent, int total) {
    for (int v : adj[u]) {
        if (v != parent && subtreeSize[v] > total / 2) {
            return centroid(v, u, total);
        }
    }
    return u;
}

void decompose(int u, int parent) {
    dfs(u, -1);
    int c = centroid(u, -1, subtreeSize[u]);
    update(weight[c], 1);
    for (int v : adj[c]) {
        if (v != parent) {
            decompose(v, c);
        }
    }
    for (int q = 0; q < MAX; q++) {
        ans[q] += query(q) - query(q - weight[c]);
    }
    update(weight[c], -1);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[max(u, v)] = w;
    }

    for (int i = 1; i <= m; i++) {
        cin >> queries[i];
    }

    decompose(1, -1);

    for (int i = 1; i <= m; i++) {
        cout << ans[queries[i]] << " ";
    }

    return 0;
}