#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
int N, K;
int ans = 0;

int dfs(int u, int p) {
    int sum = 1;
    for (int v : adj[u]) {
        if (v != p) {
            sum += dfs(v, u);
        }
    }
    subtree_size[u] = sum;
    return sum;
}

void findMaxComponents(int u, int p) {
    int largest_subtree = N - subtree_size[u];
    for (int v : adj[u]) {
        if (v != p) {
            largest_subtree = max(largest_subtree, subtree_size[v]);
            findMaxComponents(v, u);
        }
    }
    ans = max(ans, max(N - subtree_size[u], largest_subtree));
}

int main() {
    cin >> N >> K;
    adj.resize(N + 1);
    subtree_size.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    findMaxComponents(1, 0);

    cout << ans - 1 << endl;

    return 0;
}