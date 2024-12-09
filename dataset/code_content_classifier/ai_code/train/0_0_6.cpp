#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int v, vector<vector<int>>& adj, vector<int>& taxes) {
    queue<int> q;
    q.push(v);
    taxes[v] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (taxes[next] == -1) {
                taxes[next] = taxes[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> taxes(n);
    for (int i = 0; i < n; i++) {
        cin >> taxes[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }

    vector<int> tax_distances(n, -1);
    bfs(0, adj, tax_distances);

    bool win_possible = false;
    for (int i = 0; i < n; i++) {
        if (tax_distances[i] != -1 && tax_distances[i] < taxes[i]) {
            win_possible = true;
            break;
        }
    }

    if (win_possible) {
        cout << "WIN" << endl;
        for (int i = 0; i < n; i++) {
            cout << min(taxes[i], tax_distances[i]) << " ";
        }
    } else {
        cout << "LOSE" << endl;
    }

    return 0;
}