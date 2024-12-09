#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5+5;

vector<int> adj[MAXN];
int children_count[MAXN];

void dfs(int v, int p) {
    children_count[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        children_count[v] += children_count[u];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1); // Root at vertex 1

    int q;
    cin >> q;

    while (q--) {
        int v, k;
        cin >> v >> k;
        int c_v = children_count[v] - 1; // Excluding the initial parent

        if(k > c_v) {
            cout << 0 << endl;
        } else {
            cout << c_v - k << endl;
        }
    }

    return 0;
}