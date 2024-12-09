#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> a_values;
int max_points;

pair<int, int> dfs(int node, int depth) {
    if (adj[node].empty()) {
        return {a_values[node], a_values[node]}; // Leaf node, return its value as both min and max
    }

    int min_val = INT_MAX, max_val = INT_MIN;
    for (int child : adj[node]) {
        pair<int, int> child_vals = dfs(child, depth + 1);
        min_val = min(min_val, child_vals.first);
        max_val = max(max_val, child_vals.second);
    }

    if (depth % 2 == 0) { // Red coin's turn
        max_points = max(max_points, a_values[node] - min_val);
        return {min_val, max_val};
    } else { // Blue coin's turn
        max_points = max(max_points, max_val - a_values[node]);
        return {min_val, max_val};
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj.resize(n);
        a_values.resize(n);
        max_points = 0;

        for (int i = 1; i < n; i++) {
            int parent;
            cin >> parent;
            adj[parent - 1].push_back(i);
        }

        for (int i = 1; i < n; i++) {
            cin >> a_values[i];
        }

        dfs(0, 0);

        cout << max_points << endl;

        adj.clear();
        a_values.clear();
    }

    return 0;
}