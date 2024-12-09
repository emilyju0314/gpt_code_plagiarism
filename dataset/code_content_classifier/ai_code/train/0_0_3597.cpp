#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    int max_degree = 0;
    int max_degree_node = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > max_degree) {
            max_degree = adj[i].size();
            max_degree_node = i;
        }
    }

    int k = max_degree;
    cout << k << endl;

    for (int i = 0; i < k; i++) {
        cout << "1 " << adj[max_degree_node][i] + 1 << endl;
    }

    for (int i = 0; i < n; i++) {
        if (i != max_degree_node) {
            cout << "1 " << adj[i][0] + 1 << endl;
        }
    }

    return 0;
}