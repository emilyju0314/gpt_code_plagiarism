#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree1, subtree2;
set<int> commonNodes;

void dfs(int v, int p, int k1, int k2) {
    if (subtree1[v]) {
        commonNodes.insert(v);
    }

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, k1, k2);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj.clear();
        adj.resize(n);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        subtree1.assign(n, 0);
        subtree2.assign(n, 0);
        commonNodes.clear();

        int k1;
        cin >> k1;
        for (int i = 0; i < k1; i++) {
            int x;
            cin >> x;
            x--;
            subtree1[x] = 1;
        }

        int k2;
        cin >> k2;
        for (int i = 0; i < k2; i++) {
            int y;
            cin >> y;
            y--;
            subtree2[y] = 1;
        }

        cout << "B " << adj[0][0] + 1 << endl; // Ask about the label of 2nd vertex in Li Chen's subtree
        cout.flush();

        int v;
        cin >> v;
        v--;

        dfs(v, -1, k1, k2);

        if (!commonNodes.empty()) {
            cout << "C " << (*commonNodes.begin()) + 1 << endl;
        } else {
            cout << "C -1" << endl;
        }

        cout.flush();
    }

    return 0;
}