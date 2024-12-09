#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int children[MAXN];

void dfs(int v, int parent) {
    children[v] = 1;
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            children[v] += children[u];
        }
    }
}

int processQuery(int v, int parent, int k) {
    int result = children[v] - k;
    for (int u : adj[v]) {
        if (u != parent) {
            result = max(result, processQuery(u, v, k) - 1);
        }
    }
    return result;
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

    dfs(1, 0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        cout << processQuery(v, 0, k) << endl;
    }

    return 0;
}