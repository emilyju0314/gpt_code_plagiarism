#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<long long> in, out;

void dfs(int u, int p) {
    in[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        in[u] += in[v];
    }
}

void dfs2(int u, int p, long long val) {
    out[u] = in[u] + val;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u, out[u] - in[v]);
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    dfs2(1, -1, 0);

    long long total_triplets = 0;
    for (int i = 1; i <= n; i++) {
        total_triplets += in[i] * (n - in[i]);
    }

    cout << total_triplets << endl;

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (in[x] > in[y]) {
            swap(x, y);
        }

        total_triplets -= in[x] * (n - in[x]);
        in[x] += in[y];
        total_triplets += in[x] * (n - in[x]);

        cout << total_triplets << endl;
    }

    return 0;
}