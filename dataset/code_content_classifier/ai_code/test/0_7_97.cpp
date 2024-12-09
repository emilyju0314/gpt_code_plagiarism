#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
vector<int> adj[MAXN];
int children_count[MAXN]; // Number of children for each vertex

void dfs(int u, int parent) {
    children_count[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            children_count[u] += children_count[v];
        }
    }
}

int solve(int v, int k) {
    int num_children = children_count[v] - 1; // Subtract 1 to exclude the parent
    int max_score = max(0, num_children - k);
    return max_score;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cin >> q;
    while (q--) {
        int v, k;
        cin >> v >> k;
        cout << solve(v, k) << endl;
    }

    return 0;
}