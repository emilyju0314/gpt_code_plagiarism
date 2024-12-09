#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[500005];
int subtree_size[500005];

void dfs(int v, int parent) {
    subtree_size[v] = 1;
    for(int u : adj[v]) {
        if(u != parent) {
            dfs(u, v);
            subtree_size[v] += subtree_size[u];
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    int cur = 1;
    for(int i = 1; i <= n; i++) {
        cout << cur << " " << cur + subtree_size[i] - 1 << endl;
        cur += subtree_size[i];
    }

    return 0;
}