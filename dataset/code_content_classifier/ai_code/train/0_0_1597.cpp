#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

vector<vector<int>> adj;
vector<int> parent;
vector<int> subtreeSize;
vector<int> values;

void dfs(int v) {
    subtreeSize[v] = 1;
    for (int u : adj[v]) {
        dfs(u);
        subtreeSize[v] += subtreeSize[u];
    }
}

void processQuery(int type, int v, int x, int k) {
    if (type == 1) {
        values[v] = (values[v] + x) % MOD;
        int dist = 1;
        for (int u : adj[v]) {
            int delta = (x - (dist * k) + MOD) % MOD;
            processQuery(1, u, delta, k);
            dist++;
        }
    } else {
        cout << values[v] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    parent.resize(n);
    subtreeSize.resize(n);
    values.resize(n);

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p - 1].push_back(i);
        parent[i] = p - 1;
    }

    dfs(0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, x, k;
            cin >> v >> x >> k;
            processQuery(1, v - 1, x, k);
        } else {
            int v;
            cin >> v;
            processQuery(2, v - 1, 0, 0);
        }
    }

    return 0;
}