#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> subtree_size;
vector<long long> distance_sum;
vector<int> permutation;
int n;

void dfs(int v, int p) {
    subtree_size[v] = 1;
    distance_sum[v] = 0;
    for (auto& u : adj[v]) {
        if (u.first != p) {
            dfs(u.first, v);
            subtree_size[v] += subtree_size[u.first];
            distance_sum[v] += distance_sum[u.first] + 2 * u.second * subtree_size[u.first];
        }
    }
}

void find_permutation(int v, int p, long long parent_subtree_sum) {
    permutation.push_back(v);
    for (auto& u : adj[v]) {
        if (u.first != p) {
            long long new_subtree_sum = parent_subtree_sum - distance_sum[u.first] - 2 * u.second * subtree_size[u.first] + 2 * u.second * (n - subtree_size[u.first]);
            find_permutation(u.first, v, new_subtree_sum);
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    subtree_size.resize(n + 1);
    distance_sum.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, -1);
    find_permutation(1, -1, distance_sum[1]);

    long long max_sum = 0;
    for (int i = 1; i <= n; i++) {
        max_sum += distance_sum[i];
    }

    cout << max_sum << endl;
    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }

    return 0;
}