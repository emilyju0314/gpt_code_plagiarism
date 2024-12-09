#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> depths;
vector<int> parent;

void dfs(int v, int p, int d) {
    parent[v] = p;
    depths[v] = d;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d+1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    depths.resize(n+1);
    parent.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    int max_depth = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (depths[i] > max_depth) {
            max_depth = depths[i];
            x = i;
        }
    }

    dfs(x, 0, 0);

    int diameter = 0;
    for (int i = 1; i <= n; i++) {
        if (depths[i] > diameter) {
            diameter = depths[i];
            y = i;
        }
    }

    cout << diameter << endl;
    cout << x << " " << parent[y] << " " << y << endl;

    return 0;
}