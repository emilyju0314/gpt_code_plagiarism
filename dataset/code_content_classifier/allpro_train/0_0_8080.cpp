#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int city, const vector<vector<int>>& adj_list, unordered_set<int>& visited) {
    visited.insert(city);
    for (int neighbor : adj_list[city]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, adj_list, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int s, l;
        cin >> s >> l;

        // Check the impact of removing each road for the current merchant
        int num_dinars = 0;
        for (int j = 1; j <= m; j++) {
            vector<vector<int>> adj_list_copy = adj_list;
            adj_list_copy[s].erase(remove(adj_list_copy[s].begin(), adj_list_copy[s].end(), j), adj_list_copy[s].end());
            adj_list_copy[j].erase(remove(adj_list_copy[j].begin(), adj_list_copy[j].end(), s), adj_list_copy[j].end());

            unordered_set<int> visited;
            dfs(s, adj_list_copy, visited);

            if (visited.find(l) == visited.end()) {
                num_dinars++;
            }
        }

        cout << num_dinars << endl;
    }

    return 0;
}