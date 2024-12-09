#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges(m);
    vector<bool> visited(n, false);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[i] = {u, v};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        if(d[i] == 1) {
            for(int e : adj[i]) {
                q.push({e, 1});
            }
        }
    }

    vector<bool> taken(m, false);
    vector<int> degree(n, 0);

    while(!q.empty()) {
        int e = q.front().first;
        int type = q.front().second;
        q.pop();

        if(taken[e]) continue;

        int u = edges[e].first;
        int v = edges[e].second;

        if(d[u] == -1) d[v] == 1 ? d[v] = 0 : d[v] = 1;
        if(d[v] == -1) d[u] == 1 ? d[u] = 0 : d[u] = 1;

        taken[e] = true;

        degree[u]++;
        degree[v]++;

        if(degree[u] % 2 != d[u]) {
            q.push({e, -type});
            continue;
        }

        if(degree[v] % 2 != d[v]) {
            q.push({e, -type});
            continue;
        }

        for(int x : adj[u]) {
            if(!taken[x]) {
                q.push({x, 1});
            }
        }

        for(int x : adj[v]) {
            if(!taken[x]) {
                q.push({x, 1});
            }
        }
    }

    bool possible = true;
    for(int i = 0; i < n; i++) {
        if(d[i] != -1 && degree[i] % 2 != d[i]) {
            possible = false;
            break;
        }
    }

    if(!possible) {
        cout << -1 << endl;
    } else {
        vector<int> result;
        for(int i = 0; i < m; i++) {
            if(taken[i]) {
                result.push_back(i + 1);
            }
        }

        cout << result.size() << endl;
        for(int edge : result) {
            cout << edge << endl;
        }
    }

    return 0;
}