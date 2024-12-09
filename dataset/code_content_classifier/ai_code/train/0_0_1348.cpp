#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> attacked;
int currAttacked = 0;
int minTime = -1;
int teleportCity = -1;

void dfs(int u, int parent, int time) {
    if(attacked[u]) {
        currAttacked++;
    }

    bool isLeaf = true;
    for(int v : adj[u]) {
        if(v != parent) {
            isLeaf = false;
            dfs(v, u, time + 1);
        }
    }

    if(isLeaf && currAttacked == attacked.size()) {
        if(minTime == -1 || time < minTime) {
            minTime = time;
            teleportCity = u;
        }
    }

    if(attacked[u]) {
        currAttacked--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);
    attacked.resize(n + 1, false);

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < m; i++) {
        int city;
        cin >> city;
        attacked[city] = true;
    }

    dfs(1, -1, 0);

    cout << teleportCity << endl;
    cout << minTime << endl;

    return 0;
}