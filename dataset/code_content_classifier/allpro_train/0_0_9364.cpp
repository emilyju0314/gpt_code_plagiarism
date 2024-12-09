#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n+1, -1);
    vector<int> parent(n+1, -1);

    queue<int> q;
    q.push(1);
    depth[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    int x = 1;
    
    while (true) {
        // First type of query
        cout << "d " << x << endl;
        cout.flush();
        int dist;
        cin >> dist;
        
        if (dist == 0) {
            cout << "! " << x << endl;
            break;
        }

        // Second type of query
        int y = parent[x];
        cout << "s " << y << endl;
        cout.flush();
        int next;
        cin >> next;

        if (next == -1) {
            break;
        }

        if (depth[x] - depth[next] != dist) {
            x = next;
        } else {
            x = y;
        }
    }

    return 0;
}