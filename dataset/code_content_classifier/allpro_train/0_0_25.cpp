#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n;

void dfs(int u) {
    visited[u] = true;
    n++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    double expectedTotalCost = 0.0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            n = 0;
            dfs(i);
            expectedTotalCost += n;
        }
    }

    cout << fixed << setprecision(12) << expectedTotalCost << endl;

    return 0;
}