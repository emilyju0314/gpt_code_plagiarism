#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, d;
vector<int> adj[MAXN];
vector<int> rev_adj[MAXN];
vector<string> museum_schedule;
bool visited[MAXN];
vector<int> order;
vector<int> component;

void dfs(int v, vector<int> adj[], bool keep_track = false) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, keep_track);
        }
    }
    if (keep_track) {
        order.push_back(v);
    } else {
        component.push_back(v);
    }
}

void toposort() {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, true);
        }
    }
    reverse(order.begin(), order.end());
}

void find_scc() {
    memset(visited, false, sizeof(visited));
    for (int node : order) {
        if (!visited[node]) {
            component.clear();
            dfs(node, rev_adj, false);
            // process 'component'
        }
    }
}

int main() {
    cin >> n >> m >> d;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        string schedule;
        cin >> schedule;
        museum_schedule.push_back(schedule);
    }

    toposort();
    find_scc();

    return 0;
}