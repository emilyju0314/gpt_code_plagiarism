#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;

void dfs(int v, int p) {
    subtree_size[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            subtree_size[v] += subtree_size[u];
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    subtree_size.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        unordered_set<int> important_cities;
        for (int i = 0; i < k; i++) {
            int city;
            cin >> city;
            important_cities.insert(city);
        }

        int isolated_count = 0;
        for (int city : important_cities) {
            int largest_subtree = 0;
            for (int u : adj[city]) {
                if (important_cities.find(u) == important_cities.end()) {
                    largest_subtree = max(largest_subtree, subtree_size[u]);
                }
            }

            if (largest_subtree < subtree_size[city]) {
                isolated_count++;
            }
        }

        if (isolated_count == 0) {
            cout << "-1" << endl;
        } else {
            cout << isolated_count << endl;
        }
    }

    return 0;
}