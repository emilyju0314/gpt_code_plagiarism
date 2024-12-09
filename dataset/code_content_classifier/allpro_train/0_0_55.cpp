#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
        if (parent[i] != 0) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
    }

    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        indegree[i] = adj[i].size();
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] % 2 == 0) {
            q.push(i);
        }
    }

    if (q.size() == n) {
        cout << "YES\n";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << endl;
            indegree[curr] = -1;
            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] % 2 == 0 && indegree[neighbor] != -1) {
                    q.push(neighbor);
                }
            }
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}