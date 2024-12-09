#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500005;
vector<pair<int, int>> adj[MAXN];
int distNaruto[MAXN], distJiraiya[MAXN];

void dfs(int u, int p, int dist[], int& farthest) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int idx = edge.second;
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        if (dist[v] > dist[farthest]) {
            farthest = v;
        }
        dfs(v, u, dist, farthest);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int m;
    cin >> m;
    while (m--) {
        int id;
        cin >> id;
        int u = adj[id][0].first;
        int v = adj[id][1].first;

        // Reset distances
        distNaruto[u] = distNaruto[v] = 0;
        distJiraiya[u] = distJiraiya[v] = 0;

        int farthestU = u, farthestV = v;
        
        // DFS to find the farthest node from u and v for Naruto and Jiraiya
        dfs(u, v, distNaruto, farthestU);
        dfs(v, u, distJiraiya, farthestV);
        
        cout << max(distNaruto[v], distJiraiya[u]) << endl;
    }

    return 0;
}