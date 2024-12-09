#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int cur, int time_left, vector<vector<pair<int, int>>>& adj_list, vector<bool>& visited, vector<pair<int, int>>& restaurants) {
    visited[cur] = true;
    int max_restaurants = 0;
    for (auto neighbor : adj_list[cur]) {
        int next = neighbor.first;
        int weight = neighbor.second;
        if (!visited[next] && time_left >= weight) {
            int num_restaurants = 0;
            if (restaurants[next].second > 0) {
                num_restaurants++;
            }
            num_restaurants += dfs(next, time_left - weight, adj_list, visited, restaurants);
            max_restaurants = max(max_restaurants, num_restaurants);
        }
    }
    visited[cur] = false;
    return max_restaurants;
}

int main() {
    int n, m, l, s, t;
    while (cin >> n >> m >> l >> s >> t) {
        if (n == 0 && m == 0 && l == 0 && s == 0 && t == 0) {
            break;
        }

        vector<vector<pair<int, int>>> adj_list(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj_list[a].push_back({ b, c });
            adj_list[b].push_back({ a, c });
        }

        vector<pair<int, int>> restaurants(n + 1);
        for (int i = 0; i < l; i++) {
            int j, e;
            cin >> j >> e;
            restaurants[j] = { j, e };
        }

        vector<bool> visited(n + 1, false);
        int max_restaurants = dfs(s, t, adj_list, visited, restaurants);
        cout << max_restaurants << endl;
    }

    return 0;
}