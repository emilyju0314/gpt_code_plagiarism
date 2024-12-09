#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    long long totalGold = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            long long minGold = c[i];
            visited[i] = true;

            vector<int> queue;
            queue.push_back(i);

            while (!queue.empty()) {
                int curr = queue.back();
                queue.pop_back();

                for (int j = 0; j < adj[curr].size(); j++) {
                    if (!visited[adj[curr][j]]) {
                        visited[adj[curr][j]] = true;
                        queue.push_back(adj[curr][j]);
                        minGold = min(minGold, (long long)c[adj[curr][j]]);
                    }
                }
            }

            totalGold += minGold;
        }
    }

    cout << totalGold << endl;

    return 0;
}