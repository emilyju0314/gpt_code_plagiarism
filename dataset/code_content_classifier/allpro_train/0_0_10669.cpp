#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int maxDegree = 0;
    for (int i = 1; i <= n; i++) {
        maxDegree = max(maxDegree, degree[i]);
    }

    cout << maxDegree - 1 << endl;

    return 0;
}