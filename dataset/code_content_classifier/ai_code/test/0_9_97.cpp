#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 5;
vector<int> adj[maxN];
int children[maxN];

void dfs(int u, int parent) {
    children[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            children[u] += children[v];
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;

        int totalChildren = children[1];
        int ans = max(0, children[v] - k);

        cout << ans << endl;
    }

    return 0;
}