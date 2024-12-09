#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int node, unordered_set<int>& group) {
    visited[node] = true;
    group.insert(node);
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            dfs(adj_list, visited, neighbor, group);
        }
    }
}

int main() {
    int n, k, m;
    cin >> n >> k;

    vector<vector<int>> friends(n+1);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    cin >> m;
    vector<vector<int>> dislikes(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dislikes[u].push_back(v);
        dislikes[v].push_back(u);
    }

    vector<int> party_sizes;
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            unordered_set<int> group;
            dfs(friends, visited, i, group);

            bool valid_group = true;
            for (int person : group) {
                for (int disliked_person : dislikes[person]) {
                    if (group.find(disliked_person) != group.end()) {
                        valid_group = false;
                        break;
                    }
                }
            }

            if (valid_group) {
                party_sizes.push_back(group.size());
            }
        }
    }

    int max_party_size = 0;
    for (int size : party_sizes) {
        max_party_size = max(max_party_size, size);
    }

    cout << max_party_size << endl;

    return 0;
}