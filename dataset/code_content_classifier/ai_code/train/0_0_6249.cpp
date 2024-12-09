#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> a, b, c;
long long total_cost = 0;

void dfs(int u, int parent_b, int parent_c) {
    int required_k = (parent_c != c[u]) ? 1 : 0;
    int curr_b = required_k ^ parent_b;
    if(curr_b != b[u]) {
        if(a[u] == 0) {
            cout << -1 << endl;
            exit(0);
        }
        total_cost += a[u];
        required_k = 1;
        curr_b = 1 - curr_b;
    }

    for(int v : adj[u]) {
        if(v != parent_b) {
            dfs(v, curr_b, c[u]);
            required_k = 1;
        }
    }
    total_cost += required_k * a[u];
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    a.resize(n + 1);
    b.resize(n + 1);
    c.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << total_cost << endl;

    return 0;
}