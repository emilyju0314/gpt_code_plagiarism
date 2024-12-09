#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void findSubsetOrClique(int n, int m, int k, vector<vector<int>>& adj) {
    vector<int> degrees(n+1);
    vector<set<int>> neighbors(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degrees[u]++;
        degrees[v]++;
        neighbors[u].insert(v);
        neighbors[v].insert(u);
    }

    if (k >= n) {
        cout << "2" << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (degrees[i] >= k) {
            queue<int> q;
            vector<bool> visited(n+1, false);
            q.push(i);
            visited[i] = true;
            set<int> subset;
            subset.insert(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (degrees[v] >= k && !visited[v] && neighbors[u].count(v)) {
                        q.push(v);
                        visited[v] = true;
                        subset.insert(v);
                    }
                }

                if (subset.size() == k) {
                    cout << "1" << endl;
                    cout << subset.size() << endl;
                    for (int vertex : subset) {
                        cout << vertex << " ";
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }

    cout << "-1" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> adj(n+1);
        findSubsetOrClique(n, m, k, adj);
    }

    return 0;
}