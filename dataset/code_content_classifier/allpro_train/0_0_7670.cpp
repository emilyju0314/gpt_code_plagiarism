#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, w;
vector<int> weights, beauties;
vector<vector<int>> friendship;
vector<bool> visited;

int dfs(int v, int total_weight) {
    visited[v] = true;
    int total_beauty = beauties[v];

    for (int u : friendship[v]) {
        if (!visited[u]) {
            int temp_weight = dfs(u, total_weight + weights[u]);
            if (total_weight + weights[u] <= w) {
                total_beauty = max(total_beauty, temp_weight);
            }
        }
    }

    return total_beauty;
}

int main() {
    cin >> n >> m >> w;

    weights.resize(n);
    beauties.resize(n);
    friendship.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> beauties[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        friendship[x].push_back(y);
        friendship[y].push_back(x);
    }

    int max_beauty = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            max_beauty = max(max_beauty, dfs(i, weights[i]));
        }
    }

    cout << max_beauty << endl;

    return 0;
}