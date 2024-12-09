#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> subtree_sizes;
long long total_sum, max_sum;

void dfs(int node, int parent) {
    subtree_sizes[node].first = 1;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_sizes[node].first += subtree_sizes[child].first;
            total_sum += subtree_sizes[child].first;
            total_sum += subtree_sizes[child].second;
        }
    }
    subtree_sizes[node].second = total_sum;
    total_sum = 0;
}

void update(int node, int parent) {
    for (int child : adj[node]) {
        if (child != parent) {
            max_sum = max(max_sum, subtree_sizes[child].first * (long long)(adj.size() - subtree_sizes[child].first));
            update(child, node);
        }
    }
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    adj.resize(n1 + n2 + n3);
    subtree_sizes.resize(n1 + n2 + n3, {0, 0});

    for (int i = 0; i < n1 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n2 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[n1 + u].push_back(n1 + v);
        adj[n1 + v].push_back(n1 + u);
    }
    for (int i = 0; i < n3 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[n1 + n2 + u].push_back(n1 + n2 + v);
        adj[n1 + n2 + v].push_back(n1 + n2 + u);
    }

    dfs(0, -1);

    max_sum = 0;
    update(0, -1);

    cout << 2 * (total_sum + max_sum) << endl;

    return 0;
}