#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> adj;
vector<int> colors;

bool isBipartite(int v, int color) {
    colors[v] = color;
    for (int u : adj[v]) {
        if (colors[u] == color) {
            return false;
        }
        if (colors[u] == -1 && !isBipartite(u, 1 - color)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    colors.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == -1 && !isBipartite(i, 0)) {
            cout << "-1" << endl;
            return 0;
        }
    }

    set<int> A, B;
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) A.insert(i+1);
        else B.insert(i+1);
    }

    cout << A.size() << endl;
    for (int a : A) {
        cout << a << " ";
    }
    cout << endl;

    cout << B.size() << endl;
    for (int b : B) {
        cout << b << " ";
    }
    cout << endl;

    return 0;
}