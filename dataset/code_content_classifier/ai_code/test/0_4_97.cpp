#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
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

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);

    cin >> q;
    while (q--) {
        int v, k;
        cin >> v >> k;
        int max_score = children[v] - 1 - k;
        if (max_score < 0) max_score = 0;
        cout << max_score << endl;
    }

    return 0;
}