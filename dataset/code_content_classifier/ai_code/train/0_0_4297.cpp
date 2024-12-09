#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200001];
int subtree_size[200001];
long long result = 0;

void dfs(int v, int parent, int k) {
    subtree_size[v] = 1;
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v, k);
            subtree_size[v] += subtree_size[u];
            result += min(subtree_size[u], 2*k - subtree_size[u]);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, k);

    cout << result << endl;

    return 0;
}