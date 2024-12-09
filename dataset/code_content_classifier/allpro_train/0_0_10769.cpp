#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> adj[100005];
int vals[100005];
int total_ops;

void dfs(int node, int parent, int ops) {
    total_ops += abs(ops);
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, ops + vals[child]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
    }

    total_ops = 0;
    dfs(1, -1, vals[1]);

    cout << total_ops << endl;

    return 0;
}