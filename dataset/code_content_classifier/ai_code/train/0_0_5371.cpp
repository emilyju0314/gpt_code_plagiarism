#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> subtree_size;
vector<double> expectation;

void dfs(int u, int parent) {
    subtree_size[u] = 1;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v != parent) {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
            expectation[u] += expectation[v] + subtree_size[v] * edge.second;
        }
    }
}

void solve(int n) {
    adj.resize(n);
    subtree_size.resize(n);
    expectation.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

    dfs(0, -1);

    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += expectation[i];
    }

    cout << fixed;
    cout.precision(9);
    cout << result / n << endl;
}

int main() {
    int n;
    cin >> n;
    solve(n);

    return 0;
}