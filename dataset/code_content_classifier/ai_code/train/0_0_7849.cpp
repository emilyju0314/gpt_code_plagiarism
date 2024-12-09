#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ranks(n);
    for (int i = 0; i < n; i++) {
        cin >> ranks[i];
    }

    vector<int> in_degree(n, 0);
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj_list[x].push_back(y);
        in_degree[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0 && ranks[i] == 0) {
            q.push(i);
        }
    }

    vector<int> rank_count(k+1, 0);
    for (int i = 0; i < n; i++) {
        if (ranks[i] != 0) {
            rank_count[ranks[i]]++;
        }
    }

    vector<int> result(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int new_rank = 1;
        while (rank_count[new_rank] > 0) {
            new_rank++;
        }
        result[cur] = new_rank;
        rank_count[new_rank]++;
        for (int neighbor : adj_list[cur]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (in_degree[i] > 0) {
            cout << "-1";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}